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
    QRect get_screen_size();
    QString loadStyleSheetQString(const QString &sheetName);

    QRect deskRect;
    QRect screenRect;
    bool bluetoothConnectedFlag;
    void set_ui_disable(bool trueOrFlase);
    void send_fans_pwm_data(quint8 CMD, quint8 P1, quint8 P2, quint8 P3, quint8 P4);
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
    qint32 eliminateFansStatusFlag;
};

#endif // WIDGET_H