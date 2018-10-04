#ifndef DATA_TYPE_H
#define DATA_TYPE_H

#define DEF_CONFIG_INI_FILE_PATH "./AdvGene_cfg_17RV01.ini"
//usb控制通信，并行角度来讲，就是分3种控制：1：控制风扇，2：控制灯；3：控制存储
typedef struct usb_communication_data{
    unsigned char encryption;//usb通信数据用的明文加密钥匙1:  目前xor加密即可
    unsigned char DirtyFlag;//dirtyFlag:  0--255循环，初始化为0， dirtyFlag发生改变，表示下发东西；同样，dirtyFlag发生改变，表示上传东西

    unsigned char fansMode;//风扇的模式:  0.自动调速； 1.手动调速； 2.设备除尘
    unsigned char lightsMode;//led灯的控制模式： 1.lights off全部关灯； 0.ligth up全部开灯(全部常亮，每个等看pwm而定颜色)； 2.常亮，3全部呼吸灯； 4.快速闪动； 5. 乱闪
    unsigned char memMode;//低4位风扇记忆控制：0.启用记忆； 1.不启用记忆， 2.删除记忆； 高4位灯记忆控制：0.灯启用记忆，1灯不启用记忆，3.灯删除记忆；
    unsigned char ctrlFansMode;//风扇组合模式，0，组合调速； 1.分离调速； 2.全部一体调速
    unsigned char CtrlAllAutoSpeedUpMode;//{低4位控制风扇休眠：0.风扇自动休眠; 1.风扇不自动休眠；2.风扇变档加速，3风扇不变档加速} {高4位控制灯休眠： 0.灯自动休眠; 0.灯不自动休眠}
    unsigned char bootingMode;//0，开机自动，1开机手动；

    unsigned char P1PWM;///风扇1速度,占空比0--255
    unsigned char P2PWM;//风扇2速度,占空比0--255
    unsigned char P3PWM;//风扇3速度,占空比0--255
    unsigned char P4PWM;//风扇4速度,占空比0--255

    unsigned char Light1_Red_PWM;////灯1的红色占空比0--255
    unsigned char Light1_Green_PWM;//灯1的绿色占空比0--255
    unsigned char Light1_Blue_PWM;//灯1的蓝色占空比0--255

    unsigned char Light2_Red_PWM;////灯2的红色占空比0--255
    unsigned char Light2_Green_PWM;//灯2的绿色占空比0--255
    unsigned char Light2_Blue_PWM;//灯2的蓝色占空比0--255

    unsigned char Light3_Red_PWM;////灯3的红色占空比0--255
    unsigned char Light3_Green_PWM;//灯3的绿色占空比0--255
    unsigned char Light3_Blue_PWM;//灯3的蓝色占空比0--255

    unsigned char Light4_Red_PWM;////灯4的红色占空比0--255
    unsigned char Light4_Green_PWM;//灯4的绿色占空比0--255
    unsigned char Light4_Blue_PWM;//灯4的蓝色占空比0--255

    unsigned char Light1_Red_Breath_Interval;//红色led灯条1的呼吸间隔，即pwm递增递减量，一般0--50
    unsigned char Light2_Red_Breath_Interval;//在led快速闪动模式下面，这个变成闪烁的时间间隔，单位ms；
    unsigned char Light3_Red_Breath_Interval;
    unsigned char Light4_Red_Breath_Interval;

    unsigned char Light1_Green_Breath_Interval;//绿色led灯条1的呼吸间隔，即pwm递增递减量，一般0--50
    unsigned char Light2_Green_Breath_Interval;//在led快速闪动模式下面，这个变成闪烁的时间间隔，单位ms；
    unsigned char Light3_Green_Breath_Interval;
    unsigned char Light4_Green_Breath_Interval;

    unsigned char Light1_Blue_Breath_Interval;//蓝色led灯条1的呼吸间隔，即pwm递增递减量，一般0--50
    unsigned char Light2_Blue_Breath_Interval;//在led快速闪动模式下面，这个变成闪烁的时间间隔，单位ms；
    unsigned char Light3_Blue_Breath_Interval;
    unsigned char Light4_Blue_Breath_Interval;

    unsigned char reserved[28];//保证结构体64字节

}USB_HID_DATA, *pUSB_HID_DATA;



#endif // DATA_TYPE_H
