#include <QWidget>
#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
#include <QApplication>
#include <QThread>
#include <QTimer>
#include <QDesktopServices>
#include "settinghandler.h"


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget),
    eliminateFansStatusFlag(0)
{
    ui->setupUi(this);

    discoveryAgent = new QBluetoothDeviceDiscoveryAgent();//蓝牙发现用的
    localDevice = new QBluetoothLocalDevice();
    socket = new QBluetoothSocket(QBluetoothServiceInfo::RfcommProtocol);//创建一个socket，用于蓝牙通信

    g_DontSendLightFlag[0] = 0;
    g_DontSendLightFlag[1] = 0;
    g_DontSendLightFlag[2] = 0;

    comStr.clear();//情况通信用的数据数组
    mItems.clear();//清空用于搜索蓝牙设备的item（QListWidgetItem）
    eliminatTimer = new QTimer();
    updateBtTimer = new QTimer();

    bluetoothConnectedFlag = false;

    if( localDevice->hostMode() == QBluetoothLocalDevice::HostDiscoverable ) {//如果可以被发现
        ui->checkBox_discoverable->setCheckable(true);//那么被发现checkbox打勾
    }else {
        ui->checkBox_discoverable->setCheckable(false);//不打勾
    }
    get_screen_size();//获得deskRect和screenRect数据，大多数情况，两个数据的长宽是一样的
    init_all_sliders();//初始化各个slider
    init_all_light_sliders();//初始化各个灯的滑动条
    ui->textBrowser_info->setText("Data Received:\n");
    ui->textBrowser_info->append(QString().sprintf("deskRect: W %d, H %d\n", deskRect.width(), deskRect.height()));
    ui->textBrowser_info->append(QString().sprintf("screenRect: W %d, H %d", deskRect.width(), deskRect.height()));
    slot_turn_on_bluetooth();//打开蓝牙函数
    init_all_signals_and_slots();//初始化相关信号与槽
    this->setStyleSheet(loadStyleSheetQString(":/dark.qss"));
    set_ui_disable(true);
    on_pushButton_scan_clicked();//打开程序马上扫描蓝牙设备
    widget_get_cfg_data();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::init_all_pushbutton()
{
    ui->pushButton_auto_speed->setDisabled(true);
}

void Widget::on_pushButton_scan_clicked()//扫描附近的蓝牙设备
{
    discoveryAgent->start();
    QTimer::singleShot(12000, this, SLOT(slot_stop_agent_discovering()));
    ui->pushButton_scan->setEnabled(false);
}

//添加寻找的蓝牙设备item到widgetList
void Widget::addBlueToothDevicesToList( const QBluetoothDeviceInfo &info )
{
    QString tmplabel = QString("%1 %2").arg(info.address().toString()).arg(info.name());//把新发现的info的内容放到tmplabel
    //tmplabel存放着：蓝牙地址+空格+蓝牙名字

    mItems.clear();//每次添加前，清空以前的item
    mItems = ui->devListWidget->findItems(tmplabel, Qt::MatchExactly);//在现有的list查找刚刚找到的字符串，如果发现了，那么不添加，


    //如果未发现，就是新的，需要往devlistwidget里面添加
    //如果发现有，不添加，我们指望QWidgetList添加新的Item
    if (mItems.empty()) {
        QListWidgetItem *item = new QListWidgetItem(tmplabel);//tmplabel就是存放蓝牙地址+蓝牙名字的 字符串
        QBluetoothLocalDevice::Pairing pairingStatus = localDevice->pairingStatus(info.address());//查询蓝牙是否被枚举过
        if (pairingStatus == QBluetoothLocalDevice::Paired || pairingStatus == QBluetoothLocalDevice::AuthorizedPaired ){
            item->setTextColor(QColor(Qt::green));//如果此地址的蓝牙是配对过的，显示绿色
            if(tmplabel.endsWith("ADVGENE_BT")){//如果查询到名字是adv的，我们自动连接
                set_ui_disable(false);
                emit signal_connect_bluetooth_with_addr(info.address());
            }
        } else {
            item->setTextColor(QColor(10,2,240));//如果此地址的蓝牙没配对，显示黑色
        }
        ui->devListWidget->addItem(item);//添加qlist item到方框中显示
    }

}


void Widget::slot_turn_on_bluetooth()
{
    localDevice->powerOn();
    ui->pushButton_scan->setEnabled(true);
    for(int i=0; i<8; i++){//轮询八次，打开蓝牙电源
        if(localDevice->hostMode() == QBluetoothLocalDevice::HostPoweredOff){
            QThread::sleep(1);
            localDevice->powerOn();
        }
    }
}

void Widget::slot_connect_bluteooth(QBluetoothAddress BtAddress)
{
    socket->connectToService(BtAddress, QBluetoothUuid(serviceUuid) ,QIODevice::ReadWrite);
}


void Widget::on_pushButton_closeDevice_clicked()
{
    localDevice->setHostMode(QBluetoothLocalDevice::HostPoweredOff);
    ui->pushButton_scan->setEnabled(false);
}

void Widget::itemActivated(QListWidgetItem *item)
{
    QString text = item->text();

    int index = text.indexOf(' ');

    if (index == -1)
        return;

    QBluetoothAddress address(text.left(index));//截取左边的蓝牙地址，用于蓝牙连接
    //QString name(text.mid(index + 1));
    qDebug() << "You has choice the bluetooth address is " << address;
    qDebug() << "The device is connneting.... ";
    QMessageBox::information(this,tr("Info"),tr("The device is connecting..."));
    socket->connectToService(address, QBluetoothUuid(serviceUuid) ,QIODevice::ReadWrite);

}


void Widget::readBluetoothDataEvent()//读出蓝牙发过来的数据
{

    QByteArray line = socket->readAll();
    QString strData(QString::fromStdString(line.toStdString()));
    comStr.append(strData);
    ui->textBrowser_info->append(comStr + "\n");
    comStr.clear();
}

void Widget::bluetoothConnectedEvent()//蓝牙连接成功提示
{
    qDebug() << "The android device has been connected successfully!";
    set_ui_disable(false);
    QMessageBox::information(this,tr("Info"),tr("Successful connection!"), QMessageBox::Ok);
    updateBtTimer->start(3000);
    send_cfg_data_to_dev(gpCfgData);
}

void Widget::bluetoothDisconnectedEvent()//蓝牙断开连接提示
{
    qDebug() << "The android device has been disconnected successfully!";
    updateBtTimer->stop();
    QMessageBox::information(this,tr("Info"),tr("Bluetooth Disconnected!"), QMessageBox::Ok);
}

void Widget::on_pushButton_disconnect_clicked()//蓝牙断开连接
{
    socket->disconnectFromService();
    for(int i = 0; i < 5; i ++){//轮询5次，看是否断开了
        if(socket->isWritable() && socket->isOpen()){
            QThread::msleep(100);
            socket->disconnectFromService();
        }
    }
}


void Widget::on_pushButton_clear_clicked()//清除列表的内容，清除两个列表的内容
{
    ui->textBrowser_info->clear();
    ui->devListWidget->clear();
}

void Widget::slot_send_slider_value_1(int val)//发送风扇1的转速数据
{
    int tmpVal = val;
    if(val > 255 * 0.50f){
        if(ui->checkBox_enhanced_mode->isChecked()){
            ui->horizontalSlider_p1->blockSignals(true);
            tmpVal = (int)(255*0.50f);
            ui->horizontalSlider_p1->setValue(tmpVal);
            ui->horizontalSlider_p1->blockSignals(false);
        }
    }


        QByteArray data;
        data.clear();

        char urData[]={static_cast<int8_t>(0xff), 0x05, 0x04, 0x01, 0x02, 0x03, 0x04, 0x00};
        urData[3] =(unsigned char)tmpVal;
        urData[4] =(unsigned char)ui->horizontalSlider_p2->value();
        urData[5] =(unsigned char)ui->horizontalSlider_p3->value();
        urData[6] =(unsigned char)ui->horizontalSlider_p4->value();
        urData[7] = urData[0]^urData[1]^urData[2]^urData[3]^urData[4]^urData[5]^urData[6];

        data.append(urData);
        if(socket->isOpen() && socket->isWritable()){
            socket->write(data);
        }else{
            //QMessageBox::critical(this, tr("Error"), tr("[slider 1]:Can't write dev, Error!"));
        }

        if(ui->checkBox_allowed_saving->isChecked()){
            btCfgData->save_fans_config_data_to_setting_file(DEF_CONFIG_INI_FILE_PATH, gpCfgData);
        }
}

void Widget::slot_send_slider_value_2(int val)//发送风扇2的转速数据
{
    int tmpVal = val;
    if(val > 255 * 0.50f){
        if(ui->checkBox_enhanced_mode->isChecked()){
            ui->horizontalSlider_p2->blockSignals(true);
            tmpVal = (int)(255*0.50f);
            ui->horizontalSlider_p2->setValue(tmpVal);
            ui->horizontalSlider_p2->blockSignals(false);
        }
    }

    QByteArray data;
    data.clear();

    char urData[]={static_cast<int8_t>(0xff), 0x06, 0x04, 0x01, 0x02, 0x03, 0x04, 0x00};
    urData[3] =(unsigned char)ui->horizontalSlider_p1->value();
    urData[4] =(unsigned char)tmpVal;
    urData[5] =(unsigned char)ui->horizontalSlider_p3->value();
    urData[6] =(unsigned char)ui->horizontalSlider_p4->value();
    urData[7] = urData[0]^urData[1]^urData[2]^urData[3]^urData[4]^urData[5]^urData[6];

    data.append(urData);
    if(socket->isOpen() && socket->isWritable()){
        socket->write(data);
    }else{
        //QMessageBox::critical(this, tr("Error"), tr("[slider 1]:Can't write dev, Error!"));
    }
    if(ui->checkBox_allowed_saving->isChecked()){
        btCfgData->save_fans_config_data_to_setting_file(DEF_CONFIG_INI_FILE_PATH, gpCfgData);
    }
}

void Widget::slot_send_slider_value_3(int val)//发送风扇3的转速数据
{
    int tmpVal = val;
    if(val > 255 * 0.50f){
        if(ui->checkBox_enhanced_mode->isChecked()){
            ui->horizontalSlider_p3->blockSignals(true);
            tmpVal = (int)(255*0.50f);
            ui->horizontalSlider_p3->setValue(tmpVal);
            ui->horizontalSlider_p3->blockSignals(false);
        }
    }

    QByteArray data;
    data.clear();

    char urData[]={static_cast<int8_t>(0xff), 0x07, 0x04, 0x01, 0x02, 0x03, 0x04, 0x00};
    urData[3] =(unsigned char)ui->horizontalSlider_p1->value();
    urData[4] =(unsigned char)ui->horizontalSlider_p2->value();
    urData[5] =(unsigned char)val;
    urData[6] =(unsigned char)ui->horizontalSlider_p4->value();
    urData[7] = urData[0]^urData[1]^urData[2]^urData[3]^urData[4]^urData[5]^urData[6];

    data.append(urData);
    if(socket->isOpen() && socket->isWritable()){
        socket->write(data);
    }else{
        //QMessageBox::critical(this, tr("Error"), tr("[slider 1]:Can't write dev, Error!"));
    }

    if(ui->checkBox_allowed_saving->isChecked()){
        btCfgData->save_fans_config_data_to_setting_file(DEF_CONFIG_INI_FILE_PATH, gpCfgData);
    }
}

void Widget::slot_send_slider_value_4(int val)//发送风扇4的转速数据
{
    int tmpVal = val;
    if(val > 255 * 0.50f){
        if(ui->checkBox_enhanced_mode->isChecked()){
            ui->horizontalSlider_p4->blockSignals(true);
            tmpVal = (int)(255*0.50f);
            ui->horizontalSlider_p4->setValue(tmpVal);
            ui->horizontalSlider_p4->blockSignals(false);
        }
    }

    QByteArray data;
    data.clear();

    char urData[]={static_cast<int8_t>(0xff), 0x08, 0x04, 0x01, 0x02, 0x03, 0x04, 0x00};
    urData[3] =(unsigned char)ui->horizontalSlider_p1->value();
    urData[4] =(unsigned char)ui->horizontalSlider_p2->value();
    urData[5] =(unsigned char)ui->horizontalSlider_p3->value();
    urData[6] =(unsigned char)tmpVal;
    urData[7] = urData[0]^urData[1]^urData[2]^urData[3]^urData[4]^urData[5]^urData[6];

    data.append(urData);
    if(socket->isOpen() && socket->isWritable()){
        socket->write(data);
    }else{
        //QMessageBox::critical(this, tr("Error"), tr("[slider 1]:Can't write dev, Error!"));
    }

    if(ui->checkBox_allowed_saving->isChecked()){
        btCfgData->save_fans_config_data_to_setting_file(DEF_CONFIG_INI_FILE_PATH, gpCfgData);
    }
}

void Widget::slot_send_light_red_value_1(int val)
{
    if(g_DontSendLightFlag[0] == 1){
        g_DontSendLightFlag[0] = 0;
        return;
    }
    QByteArray data;
    data.clear();

    char urData[]={static_cast<int8_t>(0xff), 16, 0x03, 0x01, 0x02, 0x03, 0x00};
    urData[3] =(unsigned char)val;
    urData[4] =(unsigned char)ui->horizontalSlider_green->value();
    urData[5] =(unsigned char)ui->horizontalSlider_blue->value();
    urData[6] = urData[0]^urData[1]^urData[2]^urData[3]^urData[4]^urData[5];

    data.append(urData);
    if(socket->isOpen() && socket->isWritable()){
        socket->write(data);
    }else{
        QMessageBox::critical(this, tr("Error"), tr("[static light]:Can't write dev, Error!"));
    }
}

void Widget::slot_send_light_green_value_1(int val)
{
    if(g_DontSendLightFlag[1] == 1){
        g_DontSendLightFlag[1] = 0;
        return;
    }
    QByteArray data;
    data.clear();

    char urData[]={static_cast<int8_t>(0xff), 17, 0x03, 0x01, 0x02, 0x03, 0x00};
    urData[3] =(unsigned char)ui->horizontalSlider_red->value();
    urData[4] =(unsigned char)val;
    urData[5] =(unsigned char)ui->horizontalSlider_blue->value();
    urData[6] = urData[0]^urData[1]^urData[2]^urData[3]^urData[4]^urData[5];

    data.append(urData);
    if(socket->isOpen() && socket->isWritable()){
        socket->write(data);
    }else{
        QMessageBox::critical(this, tr("Error"), tr("[static light]:Can't write dev, Error!"));
    }
}

void Widget::slot_send_light_blue_value_1(int val)
{
    if(g_DontSendLightFlag[2] == 1){
        g_DontSendLightFlag[2] = 0;
        return;
    }
    QByteArray data;
    data.clear();

    char urData[]={static_cast<int8_t>(0xff), 18, 0x03, 0x01, 0x02, 0x03, 0x00};
    urData[3] =(unsigned char)ui->horizontalSlider_red->value();
    urData[4] =(unsigned char)ui->horizontalSlider_green->value();
    urData[5] =(unsigned char)val;
    urData[6] = urData[0]^urData[1]^urData[2]^urData[3]^urData[4]^urData[5];

    data.append(urData);
    if(socket->isOpen() && socket->isWritable()){
        socket->write(data);
    }else{
        QMessageBox::critical(this, tr("Error"), tr("[static light]:Can't write dev, Error!"));
    }
}

void Widget::slot_stop_agent_discovering()
{

    discoveryAgent->stop();
    for(int c=0; c<3; c++){
        if(discoveryAgent->isActive()){
            QThread::msleep(100);
            discoveryAgent->stop();
        }
    }
    ui->pushButton_scan->setEnabled(true);

}

void Widget::slot_eliminate_dust_timeout()
{
    if(1 == eliminateFansStatusFlag || 3 == eliminateFansStatusFlag || 5 == eliminateFansStatusFlag){
        eliminateFansStatusFlag++;
        if(eliminateFansStatusFlag>5){
            eliminateFansStatusFlag = 0;
            eliminatTimer->stop();
            QThread::msleep(1000);
            on_pushButton_manual_speed_clicked();
            return;
        }
        send_fans_pwm_data(0x03, 1, 1, 1, 1);
    }else{
        eliminateFansStatusFlag++;
        if(eliminateFansStatusFlag>5){
            eliminateFansStatusFlag = 0;
            eliminatTimer->stop();
            return;
        }
        send_fans_pwm_data(0x03, (unsigned char)254, (unsigned char)254,(unsigned char)254, (unsigned char)254);
    }
}

void Widget::slot_upate_bt()
{

    QByteArray data;
    data.clear();

    char urData[]={static_cast<int8_t>(0xff), 0xbb, 0x02, 0xaa, 0x55, 0x00};
    urData[5] = urData[0]^urData[1]^urData[2]^urData[3]^urData[4];

    data.append(urData);
    if(socket->isOpen() && socket->isWritable() && false == socket->isTransactionStarted()){
        socket->write(data);
    }else{
        QMessageBox::critical(this, tr("Error"), tr("[bt update]:Can't write dev, Error!"));
    }
}

void Widget::init_all_signals_and_slots()
{
    connect(discoveryAgent, SIGNAL(deviceDiscovered(QBluetoothDeviceInfo)),//每次发现就会调用添加槽函数
            this, SLOT(addBlueToothDevicesToList(QBluetoothDeviceInfo)));

    connect(ui->devListWidget, SIGNAL(itemActivated(QListWidgetItem*)),//双击连接蓝牙
            this, SLOT(itemActivated(QListWidgetItem*)));

    connect(socket, SIGNAL(readyRead()),
            this, SLOT(readBluetoothDataEvent()));//读取蓝牙串口信息

    connect(socket, SIGNAL(connected()),
            this, SLOT(bluetoothConnectedEvent()));//成功连接蓝牙

    connect(socket,SIGNAL(disconnected()),
            this, SLOT(bluetoothDisconnectedEvent()));//蓝牙连接掉线

    connect(this, SIGNAL(signal_connect_bluetooth_with_addr(QBluetoothAddress)), this, SLOT(slot_connect_bluteooth(QBluetoothAddress)));


    connect_all_fans_slider_signals();
    connect_all_lights_signals();

    connect(eliminatTimer, SIGNAL(timeout()), SLOT(slot_eliminate_dust_timeout()));
    connect(updateBtTimer, SIGNAL(timeout()), SLOT(slot_upate_bt()));
}

void Widget::init_all_sliders()//初始化各个slider，初始化步进和范围
{
    ui->horizontalSlider_p1->setRange(1, 255);
    ui->horizontalSlider_p2->setRange(1, 255);
    ui->horizontalSlider_p3->setRange(1, 255);
    ui->horizontalSlider_p4->setRange(1, 255);

    ui->horizontalSlider_p1->setSingleStep(255/15);
    ui->horizontalSlider_p2->setSingleStep(255/15);
    ui->horizontalSlider_p3->setSingleStep(255/15);
    ui->horizontalSlider_p4->setSingleStep(255/15);
}

void Widget::init_all_light_sliders()
{
    ui->horizontalSlider_red->setRange(1, 255);
    ui->horizontalSlider_green->setRange(1, 255);
    ui->horizontalSlider_blue->setRange(1, 255);

    ui->horizontalSlider_red->setSingleStep(255/15);
    ui->horizontalSlider_green->setSingleStep(255/15);
    ui->horizontalSlider_blue->setSingleStep(255/15);
}


QRect Widget::get_screen_size()
{
    QDesktopWidget *devWdiget = QApplication::desktop();
    deskRect = devWdiget->availableGeometry();
    screenRect = devWdiget->screenGeometry();
    return screenRect;
}

QString Widget::loadStyleSheetQString(const QString &sheetName)//载入qss风格文件
{
    QFile file(sheetName);

    if(!file.open(QFile::ReadOnly)){
        QMessageBox::critical(this, tr("Error!"), tr("Load style string failed"));
    }
    QString styleSheet = QString::fromLatin1(file.readAll());

    return styleSheet;
}

void Widget::set_ui_disable(bool trueOrFlase)
{
    ui->pushButton_auto_speed->setDisabled(true);
    ui->pushButton_manual_speed->setDisabled(trueOrFlase);
    ui->pushButton_dust_elimination->setDisabled(trueOrFlase);
    ui->pushButton_save_setting->setDisabled(trueOrFlase);

    ui->horizontalSlider_p1->setDisabled(trueOrFlase);
    ui->horizontalSlider_p1->setDisabled(trueOrFlase);
    ui->horizontalSlider_p1->setDisabled(trueOrFlase);
    ui->horizontalSlider_p1->setDisabled(trueOrFlase);

    ui->horizontalSlider_red->setDisabled(trueOrFlase);
    ui->horizontalSlider_green->setDisabled(trueOrFlase);
    ui->horizontalSlider_blue->setDisabled(trueOrFlase);
}

void Widget::send_fans_pwm_data(quint8 CMD, quint8 P1, quint8 P2, quint8 P3, quint8 P4)
{

    QByteArray data;
    data.clear();

    char urData[]={static_cast<int8_t>(0xff), 0xaa, 0x04, 0x00, 0x01, 0x02, 0x03, 0x00};
    urData[1] = CMD;
    urData[3] = P1;
    urData[4] = P2;
    urData[5] = P3;
    urData[6] = P4;
    urData[7] = urData[0]^urData[1]^urData[2]^urData[3]^urData[4]^urData[5]^urData[6];

    data.append(urData);
    if(socket->isOpen() && socket->isWritable()){
        socket->write(data);
    }else{
        QMessageBox::critical(this, tr("Error"), tr("[send_fans_pwm_data]:Can't write dev, Error!"));
    }
}

void Widget::send_lights_rgb_data(quint8 CMD, quint8 R, quint8 G, quint8 B)
{
    QByteArray data;
    data.clear();

    char urData[]={static_cast<int8_t>(0xff), 0xaa, 0x03, 0x00, 0x01, 0x02, 0x03};
    urData[1] = CMD;
    urData[3] = R;
    urData[4] = G;
    urData[5] = B;
    urData[6] = urData[0]^urData[1]^urData[2]^urData[3]^urData[4]^urData[5];

    data.append(urData);
    if(socket->isOpen() && socket->isWritable()){
        socket->write(data);
    }else{
        QMessageBox::critical(this, tr("Error"), tr("[send_lights_rgb_data]:Can't write dev, Error!"));
    }
}

void Widget::disconnect_all_lights_signals()
{
    disconnect(ui->horizontalSlider_red, SIGNAL(valueChanged(int)), this, SLOT(slot_send_light_red_value_1(int)));
    disconnect(ui->horizontalSlider_green, SIGNAL(valueChanged(int)), this, SLOT(slot_send_light_green_value_1(int)));
    disconnect(ui->horizontalSlider_blue, SIGNAL(valueChanged(int)), this, SLOT(slot_send_light_blue_value_1(int)));
}

void Widget::connect_all_lights_signals()
{
    connect(ui->horizontalSlider_red, SIGNAL(valueChanged(int)), this, SLOT(slot_send_light_red_value_1(int)));
    connect(ui->horizontalSlider_green, SIGNAL(valueChanged(int)), this, SLOT(slot_send_light_green_value_1(int)));
    connect(ui->horizontalSlider_blue, SIGNAL(valueChanged(int)), this, SLOT(slot_send_light_blue_value_1(int)));
}

void Widget::connect_all_fans_slider_signals()
{
    connect(ui->horizontalSlider_p1, SIGNAL(valueChanged(int)), this, SLOT(slot_send_slider_value_1(int)));
    connect(ui->horizontalSlider_p2, SIGNAL(valueChanged(int)), this, SLOT(slot_send_slider_value_2(int)));
    connect(ui->horizontalSlider_p3, SIGNAL(valueChanged(int)), this, SLOT(slot_send_slider_value_3(int)));
    connect(ui->horizontalSlider_p4, SIGNAL(valueChanged(int)), this, SLOT(slot_send_slider_value_4(int)));
}

void Widget::disconnect_all_fans_slider_signals()
{
    disconnect(ui->horizontalSlider_p1, SIGNAL(valueChanged(int)), this, SLOT(slot_send_slider_value_1(int)));
    disconnect(ui->horizontalSlider_p2, SIGNAL(valueChanged(int)), this, SLOT(slot_send_slider_value_2(int)));
    disconnect(ui->horizontalSlider_p3, SIGNAL(valueChanged(int)), this, SLOT(slot_send_slider_value_3(int)));
    disconnect(ui->horizontalSlider_p4, SIGNAL(valueChanged(int)), this, SLOT(slot_send_slider_value_4(int)));
}

void Widget::send_cfg_data_to_dev(pUSB_HID_DATA pData)
{
    //////////////// fans ///////////////
    ui->horizontalSlider_p1->blockSignals(true);
    ui->horizontalSlider_p2->blockSignals(true);
    ui->horizontalSlider_p3->blockSignals(true);
    ui->horizontalSlider_p4->blockSignals(true);
    slot_send_slider_value_3(pData->P3PWM);
    ui->horizontalSlider_p1->setValue(pData->P1PWM);
    ui->horizontalSlider_p1->setValue(pData->P2PWM);
    ui->horizontalSlider_p1->setValue(pData->P3PWM);
    ui->horizontalSlider_p1->setValue(pData->P4PWM);
            
    ui->horizontalSlider_p1->blockSignals(false);
    ui->horizontalSlider_p2->blockSignals(false);
    ui->horizontalSlider_p3->blockSignals(false);
    ui->horizontalSlider_p4->blockSignals(false);
    //////////////// lights /////////////////
    if(pData->lightsMode != 1){
        ui->horizontalSlider_red->blockSignals(true);
        ui->horizontalSlider_green->blockSignals(true);
        ui->horizontalSlider_blue->blockSignals(true);

        ui->horizontalSlider_red->setValue(pData->Light1_Red_PWM);
        ui->horizontalSlider_green->setValue(pData->Light1_Green_PWM);
        ui->horizontalSlider_blue->setValue(pData->Light1_Blue_PWM);

        send_lights_rgb_data(22, pData->Light1_Red_PWM, pData->Light1_Green_PWM, pData->Light1_Blue_PWM);

        ui->horizontalSlider_red->blockSignals(false);
        ui->horizontalSlider_green->blockSignals(false);
        ui->horizontalSlider_blue->blockSignals(false);

        if(pData->lightsMode == 3){
            on_pushButton_dynamic_light_clicked();
        }else if(pData->lightsMode == 2){
            on_pushButton_static_light_clicked();
        }else{
            on_pushButton_lights_off_clicked();
        }
    }else{
        on_pushButton_lights_off_clicked();
    }


}

void Widget::widget_get_cfg_data()
{
    btCfgData = new SettingHandler();
    memset(&gCfgData, 0, sizeof(USB_HID_DATA));
    gCfgData = btCfgData->load_config_data_from_setting_file(DEF_CONFIG_INI_FILE_PATH);
    gpCfgData = &gCfgData;
}

void Widget::on_pushButton_lights_off_clicked()//按下关灯按钮
{
    QByteArray data;
    data.clear();

    char urData[]={static_cast<int8_t>(0xff),20,0x01,0x01,0x00};
    urData[4] = urData[0]^urData[1]^urData[2]^urData[3];

    data.append(urData);
    if(socket->isOpen() && socket->isWritable()){
        socket->write(data);
    }else{
        QMessageBox::critical(this, tr("Error"), tr("[light off]:Can't write dev, Error!"));
    }
}

void Widget::on_pushButton_lights_up_clicked()//按下开灯按钮
{
//    QByteArray data;
//    data.clear();

//    char urData[]={static_cast<int8_t>(0xff), 19, 0x04, 0x00, 0x01, 0x02, 0x03, 0x00};
//    urData[4] =(unsigned char)ui->horizontalSlider_red->value();
//    urData[5] =(unsigned char)ui->horizontalSlider_green->value();
//    urData[6] =(unsigned char)ui->horizontalSlider_blue->value();
//    urData[7] = urData[0]^urData[1]^urData[2]^urData[3]^urData[4]^urData[5]^urData[6];

//    data.append(urData);
//    if(socket->isOpen() && socket->isWritable()){
//        socket->write(data);
//    }else{
//        QMessageBox::critical(this, tr("Error"), tr("[static light]:Can't write dev, Error!"));
//    }
    on_pushButton_static_light_clicked();
}

void Widget::on_pushButton_static_light_clicked()//常量灯按下
{
    QByteArray data;
    data.clear();

    char urData[]={static_cast<int8_t>(0xff), 19, 0x04, 0x02, 0x01, 0x02, 0x03, 0x00};
    urData[4] =(unsigned char)ui->horizontalSlider_red->value();
    urData[5] =(unsigned char)ui->horizontalSlider_green->value();
    urData[6] =(unsigned char)ui->horizontalSlider_blue->value();
    urData[7] = urData[0]^urData[1]^urData[2]^urData[3]^urData[4]^urData[5]^urData[6];

    data.append(urData);
    if(socket->isOpen() && socket->isWritable()){
        socket->write(data);
    }else{
        QMessageBox::critical(this, tr("Error"), tr("[const light]:Can't write dev, Error!"));
    }
}

void Widget::on_pushButton_dynamic_light_clicked()//呼吸灯按下
{
    QByteArray data;
    data.clear();

    char urData[]={static_cast<int8_t>(0xff), 21, 0x04, 0x03, 0x01, 0x02, 0x03, 0x00};
    urData[4] =(unsigned char)ui->horizontalSlider_red->value();
    urData[5] =(unsigned char)ui->horizontalSlider_green->value();
    urData[6] =(unsigned char)ui->horizontalSlider_blue->value();
    urData[7] = urData[0]^urData[1]^urData[2]^urData[3]^urData[4]^urData[5]^urData[6];

    data.append(urData);
    if(socket->isOpen() && socket->isWritable()){
        socket->write(data);
    }else{
        QMessageBox::critical(this, tr("Error"), tr("[breath light]:Can't write dev, Error!"));
    }
}

void Widget::on_pushButton_send_data_clicked()//数据发送键按下，获取text linedit的数据发送出去
{
    QByteArray arrayData = ui->lineEdit_data_to_be_sent->text().toUtf8();
    if(socket->isOpen() && socket->isWritable()){
        socket->write(arrayData);
    }else{
        QMessageBox::critical(this, tr("Error"), tr("Erro! Device unreachable!"), QMessageBox::Ok);
    }
}

void Widget::on_pushButton_auto_speed_clicked()
{
    ui->pushButton_manual_speed->setStyleSheet(loadStyleSheetQString(":/button_unselected.qss"));
    ui->pushButton_auto_speed->setStyleSheet(loadStyleSheetQString(":/button_selected.qss"));
    ui->pushButton_manual_speed->setStyleSheet(loadStyleSheetQString(":/button_unselected.qss"));
    ui->pushButton_save_setting->setStyleSheet(loadStyleSheetQString(":/button_unselected.qss"));
}

void Widget::on_pushButton_manual_speed_clicked()
{
    ui->pushButton_manual_speed->setStyleSheet(loadStyleSheetQString(":/button_selected.qss"));
    ui->pushButton_auto_speed->setStyleSheet(loadStyleSheetQString(":/button_unselected.qss"));
    ui->pushButton_dust_elimination->setStyleSheet(loadStyleSheetQString(":/button_unselected.qss"));
    ui->pushButton_save_setting->setStyleSheet(loadStyleSheetQString(":/button_unselected.qss"));
    eliminatTimer->stop();
   send_fans_pwm_data(0x02, (unsigned char)ui->horizontalSlider_p1->value(), (unsigned char)ui->horizontalSlider_p2->value(),
                      (unsigned char)ui->horizontalSlider_p3->value(), (unsigned char)ui->horizontalSlider_p4->value());
}

void Widget::on_pushButton_dust_elimination_clicked()
{
    ui->pushButton_dust_elimination->setStyleSheet(loadStyleSheetQString(":/button_selected.qss"));
    ui->pushButton_auto_speed->setStyleSheet(loadStyleSheetQString(":/button_unselected.qss"));
    ui->pushButton_manual_speed->setStyleSheet(loadStyleSheetQString(":/button_unselected.qss"));
    ui->pushButton_save_setting->setStyleSheet(loadStyleSheetQString(":/button_unselected.qss"));

    send_fans_pwm_data(0x03, (unsigned char)254, (unsigned char)254,(unsigned char)254, (unsigned char)254);
    eliminateFansStatusFlag = 1;
    if(eliminatTimer->isActive())
        eliminatTimer->stop();
    eliminatTimer->start(2500);
}

void Widget::on_pushButton_logo_clicked()
{
    QDesktopServices::openUrl(QUrl::fromLocalFile("http://www.advgene.com/"));//qt打开超链接，qt打开网页
}

void Widget::on_pushButton_color_1_clicked()
{
    g_DontSendLightFlag[0] = 1;
    g_DontSendLightFlag[1] = 1;
    g_DontSendLightFlag[2] = 1;

    ui->horizontalSlider_red->setValue(1);
    ui->horizontalSlider_green->setValue(255);
    ui->horizontalSlider_blue->setValue(1);

    send_lights_rgb_data(22, 1, 255, 1);

}

void Widget::on_pushButton_color_2_clicked()
{
    g_DontSendLightFlag[0] = 1;
    g_DontSendLightFlag[1] = 1;
    g_DontSendLightFlag[2] = 1;

    ui->horizontalSlider_red->setValue(255);
    ui->horizontalSlider_green->setValue(255);
    ui->horizontalSlider_blue->setValue(1);

    send_lights_rgb_data(22, 255, 255, 1);
}

void Widget::on_pushButton_color_3_clicked()
{

    g_DontSendLightFlag[0] = 1;
    g_DontSendLightFlag[1] = 1;
    g_DontSendLightFlag[2] = 1;

    ui->horizontalSlider_red->setValue(255);
    ui->horizontalSlider_green->setValue(150);
    ui->horizontalSlider_blue->setValue(1);

    send_lights_rgb_data(22, 255, 150, 1);
}

void Widget::on_pushButton_color_4_clicked()
{
    g_DontSendLightFlag[0] = 1;
    g_DontSendLightFlag[1] = 1;
    g_DontSendLightFlag[2] = 1;

    ui->horizontalSlider_red->setValue(255);
    ui->horizontalSlider_green->setValue(50);
    ui->horizontalSlider_blue->setValue(1);

    send_lights_rgb_data(22, 255, 50, 1);
}

void Widget::on_pushButton_color_5_clicked()
{
    g_DontSendLightFlag[0] = 1;
    g_DontSendLightFlag[1] = 1;
    g_DontSendLightFlag[2] = 1;

    ui->horizontalSlider_red->setValue(255);
    ui->horizontalSlider_green->setValue(1);
    ui->horizontalSlider_blue->setValue(1);

    send_lights_rgb_data(22, 255, 1, 1);
}

void Widget::on_pushButton_color_6_clicked()
{
    g_DontSendLightFlag[0] = 1;
    g_DontSendLightFlag[1] = 1;
    g_DontSendLightFlag[2] = 1;

    ui->horizontalSlider_red->setValue(50);
    ui->horizontalSlider_green->setValue(1);
    ui->horizontalSlider_blue->setValue(140);

    send_lights_rgb_data(22, 50, 1, 140);
}

void Widget::on_pushButton_color_7_clicked()
{
    g_DontSendLightFlag[0] = 1;
    g_DontSendLightFlag[1] = 1;
    g_DontSendLightFlag[2] = 1;

    ui->horizontalSlider_red->setValue(255);
    ui->horizontalSlider_green->setValue(1);
    ui->horizontalSlider_blue->setValue(50);

    send_lights_rgb_data(22, 255, 1, 50);
}

void Widget::on_pushButton_color_8_clicked()
{
    g_DontSendLightFlag[0] = 1;
    g_DontSendLightFlag[1] = 1;
    g_DontSendLightFlag[2] = 1;

    ui->horizontalSlider_red->setValue(255);
    ui->horizontalSlider_green->setValue(1);
    ui->horizontalSlider_blue->setValue(255);

    send_lights_rgb_data(22, 255, 1, 255);
}

void Widget::on_pushButton_color_9_clicked()
{
    g_DontSendLightFlag[0] = 1;
    g_DontSendLightFlag[1] = 1;
    g_DontSendLightFlag[2] = 1;

    ui->horizontalSlider_red->setValue(255);
    ui->horizontalSlider_green->setValue(255);
    ui->horizontalSlider_blue->setValue(255);

    send_lights_rgb_data(22, 255, 255, 255);
}

void Widget::on_pushButton_color_10_clicked()
{
    g_DontSendLightFlag[0] = 1;
    g_DontSendLightFlag[1] = 1;
    g_DontSendLightFlag[2] = 1;

    ui->horizontalSlider_red->setValue(1);
    ui->horizontalSlider_green->setValue(160);
    ui->horizontalSlider_blue->setValue(255);

    send_lights_rgb_data(22, 1, 160, 255);
}

void Widget::on_pushButton_color_11_clicked()
{
    g_DontSendLightFlag[0] = 1;
    g_DontSendLightFlag[1] = 1;
    g_DontSendLightFlag[2] = 1;

    ui->horizontalSlider_red->setValue(1);
    ui->horizontalSlider_green->setValue(255);
    ui->horizontalSlider_blue->setValue(255);

    send_lights_rgb_data(22, 1, 255, 255);
}

void Widget::on_pushButton_color_12_clicked()
{
    g_DontSendLightFlag[0] = 1;
    g_DontSendLightFlag[1] = 1;
    g_DontSendLightFlag[2] = 1;

    ui->horizontalSlider_red->setValue(1);
    ui->horizontalSlider_green->setValue(100);
    ui->horizontalSlider_blue->setValue(255);

    send_lights_rgb_data(22, 1, 100, 255);
}

void Widget::on_pushButton_color_13_clicked()
{
    g_DontSendLightFlag[0] = 1;
    g_DontSendLightFlag[1] = 1;
    g_DontSendLightFlag[2] = 1;

    ui->horizontalSlider_red->setValue(255);
    ui->horizontalSlider_green->setValue(50);
    ui->horizontalSlider_blue->setValue(1);

    send_lights_rgb_data(22, 1, 30, 255);
}

void Widget::on_pushButton_color_14_clicked()
{
    g_DontSendLightFlag[0] = 1;
    g_DontSendLightFlag[1] = 1;
    g_DontSendLightFlag[2] = 1;

    ui->horizontalSlider_red->setValue(1);
    ui->horizontalSlider_green->setValue(1);
    ui->horizontalSlider_blue->setValue(255);

    send_lights_rgb_data(22, 1, 1, 255);
}

void Widget::on_pushButton_combined_speed_clicked()
{
    ui->pushButton_combined_speed->setStyleSheet(loadStyleSheetQString(":/button_selected.qss"));
    ui->pushButton_indepandent_speed->setStyleSheet(loadStyleSheetQString(":/button_unselected.qss"));
    combineSpeedFlag = 1;
}

void Widget::on_pushButton_indepandent_speed_clicked()
{
    ui->pushButton_indepandent_speed->setStyleSheet(loadStyleSheetQString(":/button_selected.qss"));
    ui->pushButton_combined_speed->setStyleSheet(loadStyleSheetQString(":/button_unselected.qss"));
    combineSpeedFlag = 0;
}
