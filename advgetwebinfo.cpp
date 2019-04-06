#include "advgetwebinfo.h"
#include <QTimer>
#include <QTextCodec>
#include <permissions.h>
#include <QMessageBox>

const int nHTTP_TIME = 10000; //10秒

AdvGetWebInfo::AdvGetWebInfo(QObject *parent) : QObject(parent)
{
    m_pNetworkReply = NULL;
    m_pTimer = new QTimer;
    m_pTimer->stop();
    connect(m_pTimer,SIGNAL(timeout()),this,SLOT(slot_requestTimeout()));//超时信号
    if(false == check_network_permission()){
        QMessageBox::warning(0, tr("Get network permission"), "no network permission", QMessageBox::Ok);
        return ;
    }
}

void AdvGetWebInfo::sendRequest(const QString &strUrl)
{
    m_strUrl = strUrl;
    QNetworkRequest netRequest;
        netRequest.setRawHeader("Accept","*/*");
        netRequest.setRawHeader("Accept-Language","zh-CN,zh;q=0.8,en-US;q=0.5,en;q=0.3");
        netRequest.setUrl(QUrl(strUrl)); //地址信息
        if(strUrl.toLower().startsWith("https"))//libeay32.dll和ssleay32.dll
        {
            QSslConfiguration sslConfig;
            sslConfig.setPeerVerifyMode(QSslSocket::VerifyNone);
            sslConfig.setProtocol(QSsl::TlsV1_1);
            netRequest.setSslConfiguration(sslConfig);
        }
        m_NetworkManager.clearAccessCache();
        m_pNetworkReply = m_NetworkManager.get(netRequest); //发起get请求
        connect(m_pNetworkReply,SIGNAL(finished()),this,SLOT(slot_requestFinished())); //请求完成信号
        m_pTimer->start(nHTTP_TIME);
}

void AdvGetWebInfo::slot_requestFinished()
{
    m_pTimer->stop();//关闭定时器
    QByteArray resultContent = m_pNetworkReply->readAll();
    QTextCodec* pCodec = QTextCodec::codecForName("UTF-8");
    QString strResult = pCodec->toUnicode(resultContent);
    int nHttpCode = m_pNetworkReply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();//http返回码
    if(nHttpCode == 200)//成功
    {
        qDebug("LinDbg, get web success!");
        QMessageBox::warning(0, tr("Get network permission"), "slot webinfo finished, web Code 200 OK", QMessageBox::Ok);
        qDebug()<<"LinDbg, data length:"<<resultContent.length();
        emit signal_requestFinished(true,strResult);//请求成功
    }else{
        qDebug("get web error!");
        QMessageBox::warning(0, tr("Get network permission"), "slot webinfo finished, web Code error", QMessageBox::Ok);
        emit signal_requestFinished(false,strResult);//请求失败
    }
    m_pNetworkReply->deleteLater();
    //this->deleteLater();
}

void AdvGetWebInfo::slot_requestTimeout()
{
    emit signal_requestFinished(false,"timeout");//请求失败
    m_pNetworkReply->deleteLater();
    //this->deleteLater();//释放内存
}

bool AdvGetWebInfo::check_network_permission()
{

        QtAndroid::PermissionResult r = QtAndroid::checkPermission("android.permission.INTERNET");
        if(r == QtAndroid::PermissionResult::Denied) {
            QtAndroid::requestPermissionsSync( QStringList() << "android.permission.INTERNET" );
            r = QtAndroid::checkPermission("android.permission.INTERNET");
            if(r == QtAndroid::PermissionResult::Denied) {
                 return false;
            }
       }
       return true;

}
