#ifndef SETTINGHANDLER_H
#define SETTINGHANDLER_H

#include <QObject>
#include <QSettings>
#include <data_type.h>
#include <QString>

class SettingHandler : public QObject
{
    Q_OBJECT
public:
    explicit SettingHandler(QObject *parent = nullptr);
    USB_HID_DATA load_config_data_from_setting_file(QString fileName);
    void save_config_data_to_setting_file(QString fileName, pUSB_HID_DATA pData);
    void init_config_data_settings_file(QString fileName);
    void save_fans_config_data_to_setting_file(QString fileName, pUSB_HID_DATA pData);
    void save_lights_config_data_to_setting_file(QString fileName, pUSB_HID_DATA pData);
    QString check_android_writable_location(void);
    bool check_SDCard_permission();
signals:

public slots:

private:
    USB_HID_DATA mConfigData;
    QString writableLocationString;
};

#endif // SETTINGHANDLER_H
