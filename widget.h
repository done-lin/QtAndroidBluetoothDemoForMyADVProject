#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QList>
#include <QListWidgetItem>
#include <QtBluetooth/qbluetoothglobal.h>
#include <QtBluetooth/qbluetoothlocaldevice.h>
#include <qbluetoothaddress.h>
#include <qbluetoothdevicediscoveryagent.h>
#include <qbluetoothlocaldevice.h>
#include <qbluetoothsocket.h>
#include <QWidget>
#include <QSlider>
#include <QSize>
#include <QString>
#include <QScreen>
#include <QRect>
#include <QDesktopWidget>
#include <QTimer>
#include "settinghandler.h"


#define MAX_LENGTH 256

namespace Ui {
class Widget;
}

const QLatin1String serviceUuid("00001101-0000-1000-8000-00805F9B34FB");

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    void init_all_pushbutton(void);
    void init_all_signals_and_slots(void);
    void init_all_sliders(void);
    void init_all_light_sliders(void);
    USB_HID_DATA gCfgData;
    pUSB_HID_DATA gpCfgData;
    QRect get_screen_size();
    QString loadStyleSheetQString(const QString &sheetName);

    QRect deskRect;
    QRect screenRect;
    bool bluetoothConnectedFlag;
    void set_ui_disable(bool trueOrFlase);
    void send_fans_pwm_data(quint8 CMD, quint8 P1, quint8 P2, quint8 P3, quint8 P4);
    void send_lights_rgb_data(quint8 CMD, quint8 R, quint8 G, quint8 B);
    void send_destory_cmd(int cmd);
    void disconnect_all_lights_signals(void);
    void connect_all_lights_signals(void);
    void connect_all_fans_slider_signals(void);
    void disconnect_all_fans_slider_signals(void);
    void send_cfg_data_to_dev(pUSB_HID_DATA pData);
    void widget_get_cfg_data(void);
    SettingHandler *btCfgData;
    QBluetoothAddress g_BtAddress;
signals:
    void signal_connect_bluetooth_with_addr(QBluetoothAddress BtAddress);

public slots:

    void on_pushButton_scan_clicked();
    void addBlueToothDevicesToList(const QBluetoothDeviceInfo&);
    void slot_turn_on_bluetooth();
    void slot_connect_bluteooth(QBluetoothAddress BtAddress);
    void on_pushButton_closeDevice_clicked();
    void itemActivated(QListWidgetItem *item);
    void readBluetoothDataEvent();
    void bluetoothConnectedEvent();
    void bluetoothDisconnectedEvent();
    void on_pushButton_disconnect_clicked();

    void on_pushButton_clear_clicked();
    void slot_send_slider_value_1(int val);
    void slot_send_slider_value_2(int val);
    void slot_send_slider_value_3(int val);
    void slot_send_slider_value_4(int val);

    void slot_send_light_red_value_1(int val);
    void slot_send_light_green_value_1(int val);
    void slot_send_light_blue_value_1(int val);

    void slot_stop_agent_discovering(void);
    void slot_eliminate_dust_timeout(void);
    void slot_upate_bt(void);
    void slot_reconnect_bt(void);
private slots:

    void on_pushButton_lights_off_clicked();

    void on_pushButton_lights_up_clicked();

    void on_pushButton_static_light_clicked();

    void on_pushButton_dynamic_light_clicked();

    void on_pushButton_send_data_clicked();

    void on_pushButton_auto_speed_clicked();

    void on_pushButton_manual_speed_clicked();

    void on_pushButton_dust_elimination_clicked();

    void on_pushButton_logo_clicked();

    void on_pushButton_color_1_clicked();

    void on_pushButton_color_2_clicked();

    void on_pushButton_color_3_clicked();

    void on_pushButton_color_4_clicked();

    void on_pushButton_color_5_clicked();

    void on_pushButton_color_6_clicked();

    void on_pushButton_color_7_clicked();

    void on_pushButton_color_8_clicked();

    void on_pushButton_color_9_clicked();

    void on_pushButton_color_10_clicked();

    void on_pushButton_color_11_clicked();

    void on_pushButton_color_12_clicked();

    void on_pushButton_color_13_clicked();

    void on_pushButton_color_14_clicked();

    void on_pushButton_combined_speed_clicked();

    void on_pushButton_indepandent_speed_clicked();

private:

    Ui::Widget *ui;
    QBluetoothDeviceDiscoveryAgent *discoveryAgent;
    QBluetoothLocalDevice *localDevice;
    QBluetoothSocket *socket;
    QList<QListWidgetItem *> mItems;
    unsigned char comBuffer[15];
    unsigned int  comCount;
    QString comStr;
    QTimer *eliminatTimer;
    QTimer *updateBtTimer;
    QTimer *reconnectBtTimer;
    qint32 eliminateFansStatusFlag;
    qint8 g_DontSendLightFlag[3];
    qint32 combineSpeedFlag;
};

#endif // WIDGET_H
