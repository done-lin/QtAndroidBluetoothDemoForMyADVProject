#ifndef ADVGETWEBINFO_H
#define ADVGETWEBINFO_H

#include <QObject>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QNetworkAccessManager>
#include <Qtimer>
#include <QString>

class AdvGetWebInfo : public QObject
{
    Q_OBJECT
public:
    explicit AdvGetWebInfo(QObject *parent = 0);
    void sendRequest(const QString& strUrl);//根据url发起http请求
signals:
    void signal_requestFinished(bool bSuccess,const QString& strResult); //http请求结束
public slots:
    void slot_requestFinished(); //http请求结束
    void slot_requestTimeout();  //请求超时
    //void slot_http_read_ready();
private:
    QNetworkAccessManager m_NetworkManager;//网络管理类
    QNetworkReply* m_pNetworkReply; //封装请求返回信息
    QTimer* m_pTimer; //请求超时计时器
    QString m_strUrl; //记录当前请求的ur
    bool check_network_permission(void);
signals:

public slots:

};

#endif // ADVGETWEBINFO_H
