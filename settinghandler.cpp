#include "settinghandler.h"
#include "QtAndroidExtras/QtAndroid"
#include "QStandardPaths"
#include <QMessageBox>
#include <permissions.h>

SettingHandler::SettingHandler(QObject *parent) : QObject(parent)
{
    if(check_android_writable_location().isEmpty()){
        ;
    }else{
       init_config_data_settings_file(DEF_CONFIG_INI_FILE_PATH);
    }


}

USB_HID_DATA SettingHandler::load_config_data_from_setting_file(QString fileName)
{
    QString tmpNewFileName;
    tmpNewFileName = writableLocationString+fileName;
    QSettings settings(tmpNewFileName, QSettings::NativeFormat);
    settings.beginGroup("config");
    mConfigData.encryption = settings.value("encryption").toUInt();
    mConfigData.DirtyFlag = settings.value("DirtyFlag").toUInt();
    mConfigData.fansMode = settings.value("fansMode").toUInt();
    mConfigData.lightsMode = settings.value("lightsMode").toUInt();
    mConfigData.memMode = settings.value("memMode").toUInt();
    mConfigData.ctrlFansMode = settings.value("ctrlFansMode").toUInt();
    mConfigData.CtrlAllAutoSpeedUpMode = settings.value("CtrlAllAutoSpeedUpMode").toUInt();
    mConfigData.bootingMode = settings.value("bootingMode").toUInt();

    mConfigData.P1PWM = settings.value("P1PWM").toUInt();
    mConfigData.P2PWM = settings.value("P2PWM").toUInt();
    mConfigData.P3PWM = settings.value("P3PWM").toUInt();
    mConfigData.P4PWM = settings.value("P4PWM").toUInt();

    mConfigData.Light1_Red_PWM = settings.value("Light1_Red_PWM").toUInt();
    mConfigData.Light1_Green_PWM = settings.value("Light1_Green_PWM").toUInt();
    mConfigData.Light1_Blue_PWM = settings.value("Light1_Blue_PWM").toUInt();

    mConfigData.Light2_Red_PWM = settings.value("Light2_Red_PWM").toUInt();
    mConfigData.Light2_Green_PWM = settings.value("Light2_Green_PWM").toUInt();
    mConfigData.Light2_Blue_PWM = settings.value("Light2_Blue_PWM").toUInt();

    mConfigData.Light3_Red_PWM = settings.value("Light3_Red_PWM").toUInt();
    mConfigData.Light3_Green_PWM = settings.value("Light3_Green_PWM").toUInt();
    mConfigData.Light3_Blue_PWM = settings.value("Light3_Blue_PWM").toUInt();

    mConfigData.Light4_Red_PWM = settings.value("Light4_Red_PWM").toUInt();
    mConfigData.Light4_Green_PWM = settings.value("Light4_Green_PWM").toUInt();
    mConfigData.Light4_Blue_PWM = settings.value("Light4_Blue_PWM").toUInt();

    mConfigData.Light1_Red_Breath_Interval = settings.value("Light1_Red_Breath_Interval").toUInt();
    mConfigData.Light2_Red_Breath_Interval = settings.value("Light2_Red_Breath_Interval").toUInt();
    mConfigData.Light3_Red_Breath_Interval = settings.value("Light3_Red_Breath_Interval").toUInt();
    mConfigData.Light4_Red_Breath_Interval = settings.value("Light4_Red_Breath_Interval").toUInt();

    mConfigData.Light1_Green_Breath_Interval = settings.value("Light1_Green_Breath_Interval").toUInt();
    mConfigData.Light2_Green_Breath_Interval = settings.value("Light2_Green_Breath_Interval").toUInt();
    mConfigData.Light3_Green_Breath_Interval = settings.value("Light3_Green_Breath_Interval").toUInt();
    mConfigData.Light4_Green_Breath_Interval = settings.value("Light4_Green_Breath_Interval").toUInt();

    mConfigData.Light1_Blue_Breath_Interval = settings.value("Light1_Blue_Breath_Interval").toUInt();
    mConfigData.Light2_Blue_Breath_Interval = settings.value("Light2_Blue_Breath_Interval").toUInt();
    mConfigData.Light3_Blue_Breath_Interval = settings.value("Light3_Blue_Breath_Interval").toUInt();
    mConfigData.Light4_Blue_Breath_Interval = settings.value("Light4_Blue_Breath_Interval").toUInt();
    mConfigData.reserved[27] = settings.value("reserved").toUInt();
    settings.endGroup();
    return mConfigData;
}

void SettingHandler::save_config_data_to_setting_file(QString fileName, pUSB_HID_DATA pData)
{
    QString tmpNewFileName;
    tmpNewFileName = writableLocationString+fileName;
    QSettings settings(tmpNewFileName, QSettings::NativeFormat);
    settings.beginGroup("config");
    settings.setValue("encryption", pData->encryption);
    settings.setValue("DirtyFlag", pData->DirtyFlag);
    settings.setValue("fansMode", pData->fansMode);
    settings.setValue("lightsMode", pData->lightsMode);
    settings.setValue("memMode", pData->memMode);
    settings.setValue("ctrlFansMode", pData->ctrlFansMode);
    settings.setValue("CtrlAllAutoSpeedUpMode", pData->CtrlAllAutoSpeedUpMode);
    settings.setValue("bootingMode", pData->bootingMode);

    settings.setValue("P1PWM", pData->P1PWM);
    settings.setValue("P2PWM", pData->P2PWM);
    settings.setValue("P3PWM", pData->P3PWM);
    settings.setValue("P4PWM", pData->P4PWM);

    settings.setValue("Light1_Red_PWM", pData->Light1_Red_PWM);
    settings.setValue("Light1_Green_PWM", pData->Light1_Green_PWM);
    settings.setValue("Light1_Blue_PWM", pData->Light1_Blue_PWM);

    settings.setValue("Light2_Red_PWM", pData->Light2_Red_PWM);
    settings.setValue("Light2_Green_PWM", pData->Light2_Green_PWM);
    settings.setValue("Light2_Blue_PWM", pData->Light2_Blue_PWM);

    settings.setValue("Light3_Red_PWM", pData->Light3_Red_PWM);
    settings.setValue("Light3_Green_PWM", pData->Light3_Green_PWM);
    settings.setValue("Light3_Blue_PWM", pData->Light3_Blue_PWM);

    settings.setValue("Light4_Red_PWM", pData->Light4_Red_PWM);
    settings.setValue("Light4_Green_PWM", pData->Light4_Green_PWM);
    settings.setValue("Light4_Blue_PWM", pData->Light4_Blue_PWM);

    settings.setValue("Light1_Red_Breath_Interval", pData->Light1_Red_Breath_Interval);
    settings.setValue("Light2_Red_Breath_Interval", pData->Light2_Red_Breath_Interval);
    settings.setValue("Light3_Red_Breath_Interval", pData->Light3_Red_Breath_Interval);
    settings.setValue("Light4_Red_Breath_Interval", pData->Light4_Red_Breath_Interval);

    settings.setValue("Light1_Green_Breath_Interval", pData->Light1_Green_Breath_Interval);
    settings.setValue("Light2_Green_Breath_Interval", pData->Light2_Green_Breath_Interval);
    settings.setValue("Light3_Green_Breath_Interval", pData->Light3_Green_Breath_Interval);
    settings.setValue("Light4_Green_Breath_Interval", pData->Light4_Green_Breath_Interval);

    settings.setValue("Light1_Blue_Breath_Interval", pData->Light1_Blue_Breath_Interval);
    settings.setValue("Light2_Blue_Breath_Interval", pData->Light2_Blue_Breath_Interval);
    settings.setValue("Light3_Blue_Breath_Interval", pData->Light3_Blue_Breath_Interval);
    settings.setValue("Light4_Blue_Breath_Interval", pData->Light4_Blue_Breath_Interval);
    settings.setValue("reserved", pData->reserved[27]);
    settings.endGroup();
    settings.sync();
}

void SettingHandler::init_config_data_settings_file(QString fileName)
{
    QString tmpNewFileName;
    tmpNewFileName = writableLocationString+fileName;
    QSettings settings(tmpNewFileName, QSettings::NativeFormat);
    settings.beginGroup("config");

    if(settings.value("flag").toInt() != 1024){
        QMessageBox::warning(0, tr("Localtion"), "Data not exisit!\n"+tmpNewFileName, QMessageBox::Ok);
        settings.setValue("flag", 1024);
        settings.setValue("encryption", 0);
        settings.setValue("DirtyFlag", 0);
        settings.setValue("fansMode", 1);
        settings.setValue("lightsMode", 3);
        settings.setValue("memMode", 1);
        settings.setValue("ctrlFansMode", 1);
        settings.setValue("CtrlAllAutoSpeedUpMode", 1);
        settings.setValue("bootingMode", 1);

        settings.setValue("P1PWM", 128);
        settings.setValue("P2PWM", 128);
        settings.setValue("P3PWM", 128);
        settings.setValue("P4PWM", 128);

        settings.setValue("Light1_Red_PWM", 128);
        settings.setValue("Light1_Green_PWM", 128);
        settings.setValue("Light1_Blue_PWM", 128);

        settings.setValue("Light2_Red_PWM", 128);
        settings.setValue("Light2_Green_PWM", 128);
        settings.setValue("Light2_Blue_PWM", 128);

        settings.setValue("Light3_Red_PWM", 128);
        settings.setValue("Light3_Green_PWM", 128);
        settings.setValue("Light3_Blue_PWM", 128);

        settings.setValue("Light4_Red_PWM", 128);
        settings.setValue("Light4_Green_PWM", 128);
        settings.setValue("Light4_Blue_PWM", 128);

        settings.setValue("Light1_Red_Breath_Interval", 0);
        settings.setValue("Light2_Red_Breath_Interval", 0);
        settings.setValue("Light3_Red_Breath_Interval", 0);
        settings.setValue("Light4_Red_Breath_Interval", 0);

        settings.setValue("Light1_Green_Breath_Interval", 0);
        settings.setValue("Light2_Green_Breath_Interval", 0);
        settings.setValue("Light3_Green_Breath_Interval", 0);
        settings.setValue("Light4_Green_Breath_Interval", 0);

        settings.setValue("Light1_Blue_Breath_Interval", 0);
        settings.setValue("Light2_Blue_Breath_Interval", 0);
        settings.setValue("Light3_Blue_Breath_Interval", 0);
        settings.setValue("Light4_Blue_Breath_Interval", 0);
    }
    settings.endGroup();
    settings.sync();
}

void SettingHandler::save_fans_config_data_to_setting_file(QString fileName, pUSB_HID_DATA pData)
{
    QString tmpNewFileName;
    tmpNewFileName = writableLocationString+fileName;
    QSettings settings(tmpNewFileName, QSettings::NativeFormat);

    QMessageBox::warning(0, tr("saving fans"), tmpNewFileName, QMessageBox::Ok);
    settings.beginGroup("config");

    settings.setValue("fansMode", pData->fansMode);

    settings.setValue("memMode", pData->memMode);
    settings.setValue("ctrlFansMode", pData->ctrlFansMode);
    settings.setValue("CtrlAllAutoSpeedUpMode", pData->CtrlAllAutoSpeedUpMode);

    settings.setValue("P1PWM", pData->P1PWM);
    settings.setValue("P2PWM", pData->P2PWM);
    settings.setValue("P3PWM", pData->P3PWM);
    settings.setValue("P4PWM", pData->P4PWM);

    settings.endGroup();
    settings.sync();
}

void SettingHandler::save_lights_config_data_to_setting_file(QString fileName, pUSB_HID_DATA pData)
{
    QString tmpNewFileName;
    tmpNewFileName = writableLocationString+fileName;
    QSettings settings(tmpNewFileName, QSettings::NativeFormat);

    QMessageBox::warning(0, tr("saving lights"), tmpNewFileName, QMessageBox::Ok);
    settings.beginGroup("config");

    settings.setValue("lightsMode", pData->lightsMode);
    settings.setValue("memMode", pData->memMode);
    settings.setValue("CtrlAllAutoSpeedUpMode", pData->CtrlAllAutoSpeedUpMode);

    settings.setValue("Light1_Red_PWM", pData->Light1_Red_PWM);
    settings.setValue("Light1_Green_PWM", pData->Light1_Green_PWM);
    settings.setValue("Light1_Blue_PWM", pData->Light1_Blue_PWM);

    settings.setValue("Light1_Red_Breath_Interval", pData->Light1_Red_Breath_Interval);


    settings.setValue("Light1_Green_Breath_Interval", pData->Light4_Green_Breath_Interval);


    settings.endGroup();
    settings.sync();
}

QString SettingHandler::check_android_writable_location()
{
    writableLocationString.clear();
    if(false == check_SDCard_permission()){
        QMessageBox::critical(0, tr("Error"), "No SDCard permission! exit", QMessageBox::Ok);
        return writableLocationString;
    }
    if(QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation).isEmpty()){
        //QMessageBox::critical(0, tr("Error"), "No Android writable locations is empty", QMessageBox::Ok);
        writableLocationString.clear();
    }else{
        writableLocationString.clear();
        writableLocationString.append(QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation));
        writableLocationString.append('/');
        //QMessageBox::warning(0, tr("Get Localtion OK"), writableLocationString, QMessageBox::Ok);
    }
    return writableLocationString;
}



bool SettingHandler::check_SDCard_permission() {
    QtAndroid::PermissionResult r = QtAndroid::checkPermission("android.permission.WRITE_EXTERNAL_STORAGE");
    if(r == QtAndroid::PermissionResult::Denied) {
        QtAndroid::requestPermissionsSync( QStringList() << "android.permission.WRITE_EXTERNAL_STORAGE" );
        r = QtAndroid::checkPermission("android.permission.WRITE_EXTERNAL_STORAGE");
        if(r == QtAndroid::PermissionResult::Denied) {
             return false;
        }
   }
   return true;
}
