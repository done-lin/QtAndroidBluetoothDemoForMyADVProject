/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGridLayout *gridLayout_9;
    QVBoxLayout *verticalLayout_4;
    QPushButton *pushButton_logo;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_5;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton_manual_speed;
    QPushButton *pushButton_auto_speed;
    QPushButton *pushButton_dust_elimination;
    QPushButton *pushButton_save_setting;
    QSpacerItem *verticalSpacer_5;
    QGridLayout *gridLayout_3;
    QLabel *label_p2;
    QLabel *label_p4;
    QLabel *label_p1;
    QLabel *label_p3;
    QSlider *horizontalSlider_p1;
    QSlider *horizontalSlider_p2;
    QSlider *horizontalSlider_p3;
    QSlider *horizontalSlider_p4;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_combined_speed;
    QPushButton *pushButton_indepandent_speed;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *horizontalLayout_3;
    QCheckBox *checkBox_allowed_saving;
    QCheckBox *checkBox_auto_hibernate;
    QCheckBox *checkBox_enhanced_mode;
    QWidget *tab_2;
    QGridLayout *gridLayout_6;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout_4;
    QLabel *label_p2_2;
    QSlider *horizontalSlider_red;
    QSlider *horizontalSlider_green;
    QLabel *label_p1_2;
    QLabel *label_p3_2;
    QSlider *horizontalSlider_blue;
    QSpacerItem *verticalSpacer_2;
    QGridLayout *gridLayout_10;
    QPushButton *pushButton_color_2;
    QPushButton *pushButton_color_4;
    QPushButton *pushButton_color_1;
    QPushButton *pushButton_color_6;
    QPushButton *pushButton_color_3;
    QPushButton *pushButton_color_7;
    QPushButton *pushButton_color_5;
    QPushButton *pushButton_color_8;
    QPushButton *pushButton_color_9;
    QPushButton *pushButton_color_10;
    QPushButton *pushButton_color_11;
    QPushButton *pushButton_color_12;
    QPushButton *pushButton_color_13;
    QPushButton *pushButton_color_14;
    QSpacerItem *verticalSpacer_8;
    QGridLayout *gridLayout;
    QPushButton *pushButton_lights_off;
    QPushButton *pushButton_lights_up;
    QPushButton *pushButton_static_light;
    QPushButton *pushButton_dynamic_light;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QWidget *tab_3;
    QGridLayout *gridLayout_8;
    QVBoxLayout *verticalLayout_3;
    QListWidget *devListWidget;
    QSpacerItem *verticalSpacer_6;
    QTextBrowser *textBrowser_info;
    QSpacerItem *verticalSpacer_7;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_data;
    QLineEdit *lineEdit_data_to_be_sent;
    QGridLayout *gridLayout_7;
    QPushButton *pushButton_disconnect;
    QPushButton *pushButton_send_data;
    QPushButton *pushButton_clear;
    QPushButton *pushButton_scan;
    QCheckBox *checkBox_discoverable;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(458, 619);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Widget->sizePolicy().hasHeightForWidth());
        Widget->setSizePolicy(sizePolicy);
        gridLayout_9 = new QGridLayout(Widget);
        gridLayout_9->setSpacing(6);
        gridLayout_9->setContentsMargins(11, 11, 11, 11);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(8);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setSizeConstraint(QLayout::SetDefaultConstraint);
        pushButton_logo = new QPushButton(Widget);
        pushButton_logo->setObjectName(QStringLiteral("pushButton_logo"));

        verticalLayout_4->addWidget(pushButton_logo);

        tabWidget = new QTabWidget(Widget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setPointSize(10);
        tabWidget->setFont(font);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        gridLayout_5 = new QGridLayout(tab);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        pushButton_manual_speed = new QPushButton(tab);
        pushButton_manual_speed->setObjectName(QStringLiteral("pushButton_manual_speed"));
        sizePolicy.setHeightForWidth(pushButton_manual_speed->sizePolicy().hasHeightForWidth());
        pushButton_manual_speed->setSizePolicy(sizePolicy);
        pushButton_manual_speed->setFont(font);

        gridLayout_2->addWidget(pushButton_manual_speed, 0, 1, 1, 1);

        pushButton_auto_speed = new QPushButton(tab);
        pushButton_auto_speed->setObjectName(QStringLiteral("pushButton_auto_speed"));
        sizePolicy.setHeightForWidth(pushButton_auto_speed->sizePolicy().hasHeightForWidth());
        pushButton_auto_speed->setSizePolicy(sizePolicy);
        pushButton_auto_speed->setFont(font);

        gridLayout_2->addWidget(pushButton_auto_speed, 0, 0, 1, 1);

        pushButton_dust_elimination = new QPushButton(tab);
        pushButton_dust_elimination->setObjectName(QStringLiteral("pushButton_dust_elimination"));
        sizePolicy.setHeightForWidth(pushButton_dust_elimination->sizePolicy().hasHeightForWidth());
        pushButton_dust_elimination->setSizePolicy(sizePolicy);
        pushButton_dust_elimination->setFont(font);

        gridLayout_2->addWidget(pushButton_dust_elimination, 1, 0, 1, 1);

        pushButton_save_setting = new QPushButton(tab);
        pushButton_save_setting->setObjectName(QStringLiteral("pushButton_save_setting"));
        sizePolicy.setHeightForWidth(pushButton_save_setting->sizePolicy().hasHeightForWidth());
        pushButton_save_setting->setSizePolicy(sizePolicy);
        pushButton_save_setting->setFont(font);

        gridLayout_2->addWidget(pushButton_save_setting, 1, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout_2);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_5);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        label_p2 = new QLabel(tab);
        label_p2->setObjectName(QStringLiteral("label_p2"));
        sizePolicy.setHeightForWidth(label_p2->sizePolicy().hasHeightForWidth());
        label_p2->setSizePolicy(sizePolicy);
        label_p2->setFont(font);

        gridLayout_3->addWidget(label_p2, 1, 0, 1, 1);

        label_p4 = new QLabel(tab);
        label_p4->setObjectName(QStringLiteral("label_p4"));
        sizePolicy.setHeightForWidth(label_p4->sizePolicy().hasHeightForWidth());
        label_p4->setSizePolicy(sizePolicy);
        label_p4->setFont(font);

        gridLayout_3->addWidget(label_p4, 3, 0, 1, 1);

        label_p1 = new QLabel(tab);
        label_p1->setObjectName(QStringLiteral("label_p1"));
        sizePolicy.setHeightForWidth(label_p1->sizePolicy().hasHeightForWidth());
        label_p1->setSizePolicy(sizePolicy);
        label_p1->setFont(font);

        gridLayout_3->addWidget(label_p1, 0, 0, 1, 1);

        label_p3 = new QLabel(tab);
        label_p3->setObjectName(QStringLiteral("label_p3"));
        sizePolicy.setHeightForWidth(label_p3->sizePolicy().hasHeightForWidth());
        label_p3->setSizePolicy(sizePolicy);
        label_p3->setFont(font);

        gridLayout_3->addWidget(label_p3, 2, 0, 1, 1);

        horizontalSlider_p1 = new QSlider(tab);
        horizontalSlider_p1->setObjectName(QStringLiteral("horizontalSlider_p1"));
        sizePolicy.setHeightForWidth(horizontalSlider_p1->sizePolicy().hasHeightForWidth());
        horizontalSlider_p1->setSizePolicy(sizePolicy);
        horizontalSlider_p1->setOrientation(Qt::Horizontal);

        gridLayout_3->addWidget(horizontalSlider_p1, 0, 1, 1, 1);

        horizontalSlider_p2 = new QSlider(tab);
        horizontalSlider_p2->setObjectName(QStringLiteral("horizontalSlider_p2"));
        sizePolicy.setHeightForWidth(horizontalSlider_p2->sizePolicy().hasHeightForWidth());
        horizontalSlider_p2->setSizePolicy(sizePolicy);
        horizontalSlider_p2->setOrientation(Qt::Horizontal);

        gridLayout_3->addWidget(horizontalSlider_p2, 1, 1, 1, 1);

        horizontalSlider_p3 = new QSlider(tab);
        horizontalSlider_p3->setObjectName(QStringLiteral("horizontalSlider_p3"));
        sizePolicy.setHeightForWidth(horizontalSlider_p3->sizePolicy().hasHeightForWidth());
        horizontalSlider_p3->setSizePolicy(sizePolicy);
        horizontalSlider_p3->setOrientation(Qt::Horizontal);

        gridLayout_3->addWidget(horizontalSlider_p3, 2, 1, 1, 1);

        horizontalSlider_p4 = new QSlider(tab);
        horizontalSlider_p4->setObjectName(QStringLiteral("horizontalSlider_p4"));
        sizePolicy.setHeightForWidth(horizontalSlider_p4->sizePolicy().hasHeightForWidth());
        horizontalSlider_p4->setSizePolicy(sizePolicy);
        horizontalSlider_p4->setOrientation(Qt::Horizontal);

        gridLayout_3->addWidget(horizontalSlider_p4, 3, 1, 1, 1);

        gridLayout_3->setColumnStretch(0, 1);
        gridLayout_3->setColumnStretch(1, 9);

        verticalLayout_2->addLayout(gridLayout_3);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        pushButton_combined_speed = new QPushButton(tab);
        pushButton_combined_speed->setObjectName(QStringLiteral("pushButton_combined_speed"));
        sizePolicy.setHeightForWidth(pushButton_combined_speed->sizePolicy().hasHeightForWidth());
        pushButton_combined_speed->setSizePolicy(sizePolicy);
        pushButton_combined_speed->setFont(font);

        horizontalLayout_2->addWidget(pushButton_combined_speed);

        pushButton_indepandent_speed = new QPushButton(tab);
        pushButton_indepandent_speed->setObjectName(QStringLiteral("pushButton_indepandent_speed"));
        sizePolicy.setHeightForWidth(pushButton_indepandent_speed->sizePolicy().hasHeightForWidth());
        pushButton_indepandent_speed->setSizePolicy(sizePolicy);
        pushButton_indepandent_speed->setFont(font);

        horizontalLayout_2->addWidget(pushButton_indepandent_speed);


        verticalLayout_2->addLayout(horizontalLayout_2);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        checkBox_allowed_saving = new QCheckBox(tab);
        checkBox_allowed_saving->setObjectName(QStringLiteral("checkBox_allowed_saving"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(checkBox_allowed_saving->sizePolicy().hasHeightForWidth());
        checkBox_allowed_saving->setSizePolicy(sizePolicy1);
        checkBox_allowed_saving->setFont(font);

        horizontalLayout_3->addWidget(checkBox_allowed_saving);

        checkBox_auto_hibernate = new QCheckBox(tab);
        checkBox_auto_hibernate->setObjectName(QStringLiteral("checkBox_auto_hibernate"));
        sizePolicy1.setHeightForWidth(checkBox_auto_hibernate->sizePolicy().hasHeightForWidth());
        checkBox_auto_hibernate->setSizePolicy(sizePolicy1);
        checkBox_auto_hibernate->setFont(font);

        horizontalLayout_3->addWidget(checkBox_auto_hibernate);

        checkBox_enhanced_mode = new QCheckBox(tab);
        checkBox_enhanced_mode->setObjectName(QStringLiteral("checkBox_enhanced_mode"));
        sizePolicy1.setHeightForWidth(checkBox_enhanced_mode->sizePolicy().hasHeightForWidth());
        checkBox_enhanced_mode->setSizePolicy(sizePolicy1);
        checkBox_enhanced_mode->setFont(font);

        horizontalLayout_3->addWidget(checkBox_enhanced_mode);


        verticalLayout_2->addLayout(horizontalLayout_3);

        verticalLayout_2->setStretch(0, 3);
        verticalLayout_2->setStretch(1, 1);
        verticalLayout_2->setStretch(2, 3);
        verticalLayout_2->setStretch(3, 1);
        verticalLayout_2->setStretch(4, 1);
        verticalLayout_2->setStretch(5, 1);
        verticalLayout_2->setStretch(6, 1);

        gridLayout_5->addLayout(verticalLayout_2, 0, 0, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        gridLayout_6 = new QGridLayout(tab_2);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(6);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        label_p2_2 = new QLabel(tab_2);
        label_p2_2->setObjectName(QStringLiteral("label_p2_2"));
        sizePolicy.setHeightForWidth(label_p2_2->sizePolicy().hasHeightForWidth());
        label_p2_2->setSizePolicy(sizePolicy);
        label_p2_2->setFont(font);

        gridLayout_4->addWidget(label_p2_2, 1, 0, 1, 1);

        horizontalSlider_red = new QSlider(tab_2);
        horizontalSlider_red->setObjectName(QStringLiteral("horizontalSlider_red"));
        sizePolicy.setHeightForWidth(horizontalSlider_red->sizePolicy().hasHeightForWidth());
        horizontalSlider_red->setSizePolicy(sizePolicy);
        horizontalSlider_red->setOrientation(Qt::Horizontal);

        gridLayout_4->addWidget(horizontalSlider_red, 0, 1, 1, 1);

        horizontalSlider_green = new QSlider(tab_2);
        horizontalSlider_green->setObjectName(QStringLiteral("horizontalSlider_green"));
        sizePolicy.setHeightForWidth(horizontalSlider_green->sizePolicy().hasHeightForWidth());
        horizontalSlider_green->setSizePolicy(sizePolicy);
        horizontalSlider_green->setOrientation(Qt::Horizontal);

        gridLayout_4->addWidget(horizontalSlider_green, 1, 1, 1, 1);

        label_p1_2 = new QLabel(tab_2);
        label_p1_2->setObjectName(QStringLiteral("label_p1_2"));
        sizePolicy.setHeightForWidth(label_p1_2->sizePolicy().hasHeightForWidth());
        label_p1_2->setSizePolicy(sizePolicy);
        label_p1_2->setFont(font);

        gridLayout_4->addWidget(label_p1_2, 0, 0, 1, 1);

        label_p3_2 = new QLabel(tab_2);
        label_p3_2->setObjectName(QStringLiteral("label_p3_2"));
        sizePolicy.setHeightForWidth(label_p3_2->sizePolicy().hasHeightForWidth());
        label_p3_2->setSizePolicy(sizePolicy);
        label_p3_2->setFont(font);

        gridLayout_4->addWidget(label_p3_2, 2, 0, 1, 1);

        horizontalSlider_blue = new QSlider(tab_2);
        horizontalSlider_blue->setObjectName(QStringLiteral("horizontalSlider_blue"));
        sizePolicy.setHeightForWidth(horizontalSlider_blue->sizePolicy().hasHeightForWidth());
        horizontalSlider_blue->setSizePolicy(sizePolicy);
        horizontalSlider_blue->setOrientation(Qt::Horizontal);

        gridLayout_4->addWidget(horizontalSlider_blue, 2, 1, 1, 1);

        gridLayout_4->setRowStretch(0, 1);
        gridLayout_4->setRowStretch(1, 1);
        gridLayout_4->setRowStretch(2, 1);
        gridLayout_4->setColumnStretch(0, 1);
        gridLayout_4->setColumnStretch(1, 6);

        verticalLayout->addLayout(gridLayout_4);

        verticalSpacer_2 = new QSpacerItem(20, 30, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        gridLayout_10 = new QGridLayout();
        gridLayout_10->setSpacing(6);
        gridLayout_10->setObjectName(QStringLiteral("gridLayout_10"));
        pushButton_color_2 = new QPushButton(tab_2);
        pushButton_color_2->setObjectName(QStringLiteral("pushButton_color_2"));
        sizePolicy.setHeightForWidth(pushButton_color_2->sizePolicy().hasHeightForWidth());
        pushButton_color_2->setSizePolicy(sizePolicy);
        pushButton_color_2->setMinimumSize(QSize(0, 80));

        gridLayout_10->addWidget(pushButton_color_2, 0, 1, 1, 1);

        pushButton_color_4 = new QPushButton(tab_2);
        pushButton_color_4->setObjectName(QStringLiteral("pushButton_color_4"));
        sizePolicy.setHeightForWidth(pushButton_color_4->sizePolicy().hasHeightForWidth());
        pushButton_color_4->setSizePolicy(sizePolicy);
        pushButton_color_4->setMinimumSize(QSize(0, 80));

        gridLayout_10->addWidget(pushButton_color_4, 0, 3, 1, 1);

        pushButton_color_1 = new QPushButton(tab_2);
        pushButton_color_1->setObjectName(QStringLiteral("pushButton_color_1"));
        sizePolicy.setHeightForWidth(pushButton_color_1->sizePolicy().hasHeightForWidth());
        pushButton_color_1->setSizePolicy(sizePolicy);
        pushButton_color_1->setMinimumSize(QSize(0, 80));

        gridLayout_10->addWidget(pushButton_color_1, 0, 0, 1, 1);

        pushButton_color_6 = new QPushButton(tab_2);
        pushButton_color_6->setObjectName(QStringLiteral("pushButton_color_6"));
        sizePolicy.setHeightForWidth(pushButton_color_6->sizePolicy().hasHeightForWidth());
        pushButton_color_6->setSizePolicy(sizePolicy);
        pushButton_color_6->setMinimumSize(QSize(0, 80));

        gridLayout_10->addWidget(pushButton_color_6, 0, 5, 1, 1);

        pushButton_color_3 = new QPushButton(tab_2);
        pushButton_color_3->setObjectName(QStringLiteral("pushButton_color_3"));
        sizePolicy.setHeightForWidth(pushButton_color_3->sizePolicy().hasHeightForWidth());
        pushButton_color_3->setSizePolicy(sizePolicy);
        pushButton_color_3->setMinimumSize(QSize(0, 80));

        gridLayout_10->addWidget(pushButton_color_3, 0, 2, 1, 1);

        pushButton_color_7 = new QPushButton(tab_2);
        pushButton_color_7->setObjectName(QStringLiteral("pushButton_color_7"));
        sizePolicy.setHeightForWidth(pushButton_color_7->sizePolicy().hasHeightForWidth());
        pushButton_color_7->setSizePolicy(sizePolicy);
        pushButton_color_7->setMinimumSize(QSize(0, 80));

        gridLayout_10->addWidget(pushButton_color_7, 0, 6, 1, 1);

        pushButton_color_5 = new QPushButton(tab_2);
        pushButton_color_5->setObjectName(QStringLiteral("pushButton_color_5"));
        sizePolicy.setHeightForWidth(pushButton_color_5->sizePolicy().hasHeightForWidth());
        pushButton_color_5->setSizePolicy(sizePolicy);
        pushButton_color_5->setMinimumSize(QSize(0, 80));

        gridLayout_10->addWidget(pushButton_color_5, 0, 4, 1, 1);

        pushButton_color_8 = new QPushButton(tab_2);
        pushButton_color_8->setObjectName(QStringLiteral("pushButton_color_8"));
        sizePolicy.setHeightForWidth(pushButton_color_8->sizePolicy().hasHeightForWidth());
        pushButton_color_8->setSizePolicy(sizePolicy);
        pushButton_color_8->setMinimumSize(QSize(0, 80));

        gridLayout_10->addWidget(pushButton_color_8, 1, 0, 1, 1);

        pushButton_color_9 = new QPushButton(tab_2);
        pushButton_color_9->setObjectName(QStringLiteral("pushButton_color_9"));
        sizePolicy.setHeightForWidth(pushButton_color_9->sizePolicy().hasHeightForWidth());
        pushButton_color_9->setSizePolicy(sizePolicy);
        pushButton_color_9->setMinimumSize(QSize(0, 80));

        gridLayout_10->addWidget(pushButton_color_9, 1, 1, 1, 1);

        pushButton_color_10 = new QPushButton(tab_2);
        pushButton_color_10->setObjectName(QStringLiteral("pushButton_color_10"));
        sizePolicy.setHeightForWidth(pushButton_color_10->sizePolicy().hasHeightForWidth());
        pushButton_color_10->setSizePolicy(sizePolicy);
        pushButton_color_10->setMinimumSize(QSize(0, 80));

        gridLayout_10->addWidget(pushButton_color_10, 1, 2, 1, 1);

        pushButton_color_11 = new QPushButton(tab_2);
        pushButton_color_11->setObjectName(QStringLiteral("pushButton_color_11"));
        sizePolicy.setHeightForWidth(pushButton_color_11->sizePolicy().hasHeightForWidth());
        pushButton_color_11->setSizePolicy(sizePolicy);
        pushButton_color_11->setMinimumSize(QSize(0, 80));

        gridLayout_10->addWidget(pushButton_color_11, 1, 3, 1, 1);

        pushButton_color_12 = new QPushButton(tab_2);
        pushButton_color_12->setObjectName(QStringLiteral("pushButton_color_12"));
        sizePolicy.setHeightForWidth(pushButton_color_12->sizePolicy().hasHeightForWidth());
        pushButton_color_12->setSizePolicy(sizePolicy);
        pushButton_color_12->setMinimumSize(QSize(0, 80));

        gridLayout_10->addWidget(pushButton_color_12, 1, 4, 1, 1);

        pushButton_color_13 = new QPushButton(tab_2);
        pushButton_color_13->setObjectName(QStringLiteral("pushButton_color_13"));
        sizePolicy.setHeightForWidth(pushButton_color_13->sizePolicy().hasHeightForWidth());
        pushButton_color_13->setSizePolicy(sizePolicy);
        pushButton_color_13->setMinimumSize(QSize(0, 80));

        gridLayout_10->addWidget(pushButton_color_13, 1, 5, 1, 1);

        pushButton_color_14 = new QPushButton(tab_2);
        pushButton_color_14->setObjectName(QStringLiteral("pushButton_color_14"));
        sizePolicy.setHeightForWidth(pushButton_color_14->sizePolicy().hasHeightForWidth());
        pushButton_color_14->setSizePolicy(sizePolicy);
        pushButton_color_14->setMinimumSize(QSize(0, 80));

        gridLayout_10->addWidget(pushButton_color_14, 1, 6, 1, 1);


        verticalLayout->addLayout(gridLayout_10);

        verticalSpacer_8 = new QSpacerItem(20, 30, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_8);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pushButton_lights_off = new QPushButton(tab_2);
        pushButton_lights_off->setObjectName(QStringLiteral("pushButton_lights_off"));
        sizePolicy.setHeightForWidth(pushButton_lights_off->sizePolicy().hasHeightForWidth());
        pushButton_lights_off->setSizePolicy(sizePolicy);
        pushButton_lights_off->setFont(font);

        gridLayout->addWidget(pushButton_lights_off, 0, 1, 1, 1);

        pushButton_lights_up = new QPushButton(tab_2);
        pushButton_lights_up->setObjectName(QStringLiteral("pushButton_lights_up"));
        sizePolicy.setHeightForWidth(pushButton_lights_up->sizePolicy().hasHeightForWidth());
        pushButton_lights_up->setSizePolicy(sizePolicy);
        pushButton_lights_up->setFont(font);

        gridLayout->addWidget(pushButton_lights_up, 0, 0, 1, 1);

        pushButton_static_light = new QPushButton(tab_2);
        pushButton_static_light->setObjectName(QStringLiteral("pushButton_static_light"));
        sizePolicy.setHeightForWidth(pushButton_static_light->sizePolicy().hasHeightForWidth());
        pushButton_static_light->setSizePolicy(sizePolicy);
        pushButton_static_light->setFont(font);

        gridLayout->addWidget(pushButton_static_light, 1, 0, 1, 1);

        pushButton_dynamic_light = new QPushButton(tab_2);
        pushButton_dynamic_light->setObjectName(QStringLiteral("pushButton_dynamic_light"));
        sizePolicy.setHeightForWidth(pushButton_dynamic_light->sizePolicy().hasHeightForWidth());
        pushButton_dynamic_light->setSizePolicy(sizePolicy);
        pushButton_dynamic_light->setFont(font);

        gridLayout->addWidget(pushButton_dynamic_light, 1, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        verticalSpacer = new QSpacerItem(20, 30, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        checkBox = new QCheckBox(tab_2);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        sizePolicy1.setHeightForWidth(checkBox->sizePolicy().hasHeightForWidth());
        checkBox->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(checkBox);

        checkBox_2 = new QCheckBox(tab_2);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));
        sizePolicy1.setHeightForWidth(checkBox_2->sizePolicy().hasHeightForWidth());
        checkBox_2->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(checkBox_2);


        verticalLayout->addLayout(horizontalLayout);

        verticalLayout->setStretch(0, 3);
        verticalLayout->setStretch(1, 1);
        verticalLayout->setStretch(2, 3);
        verticalLayout->setStretch(3, 1);
        verticalLayout->setStretch(4, 3);
        verticalLayout->setStretch(5, 1);
        verticalLayout->setStretch(6, 1);

        gridLayout_6->addLayout(verticalLayout, 0, 0, 1, 1);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        gridLayout_8 = new QGridLayout(tab_3);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        devListWidget = new QListWidget(tab_3);
        devListWidget->setObjectName(QStringLiteral("devListWidget"));
        sizePolicy.setHeightForWidth(devListWidget->sizePolicy().hasHeightForWidth());
        devListWidget->setSizePolicy(sizePolicy);
        devListWidget->setMaximumSize(QSize(1000000, 1000000));
        QFont font1;
        font1.setFamily(QStringLiteral("Arial"));
        devListWidget->setFont(font1);

        verticalLayout_3->addWidget(devListWidget);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_6);

        textBrowser_info = new QTextBrowser(tab_3);
        textBrowser_info->setObjectName(QStringLiteral("textBrowser_info"));
        QFont font2;
        font2.setFamily(QStringLiteral("Arial"));
        font2.setBold(true);
        font2.setWeight(75);
        textBrowser_info->setFont(font2);

        verticalLayout_3->addWidget(textBrowser_info);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_7);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_data = new QLabel(tab_3);
        label_data->setObjectName(QStringLiteral("label_data"));

        horizontalLayout_4->addWidget(label_data);

        lineEdit_data_to_be_sent = new QLineEdit(tab_3);
        lineEdit_data_to_be_sent->setObjectName(QStringLiteral("lineEdit_data_to_be_sent"));

        horizontalLayout_4->addWidget(lineEdit_data_to_be_sent);

        horizontalLayout_4->setStretch(1, 5);

        verticalLayout_3->addLayout(horizontalLayout_4);

        gridLayout_7 = new QGridLayout();
        gridLayout_7->setSpacing(6);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        pushButton_disconnect = new QPushButton(tab_3);
        pushButton_disconnect->setObjectName(QStringLiteral("pushButton_disconnect"));
        sizePolicy.setHeightForWidth(pushButton_disconnect->sizePolicy().hasHeightForWidth());
        pushButton_disconnect->setSizePolicy(sizePolicy);
        pushButton_disconnect->setMinimumSize(QSize(0, 0));
        QFont font3;
        font3.setFamily(QStringLiteral("Arial"));
        font3.setBold(false);
        font3.setWeight(50);
        pushButton_disconnect->setFont(font3);

        gridLayout_7->addWidget(pushButton_disconnect, 0, 1, 1, 1);

        pushButton_send_data = new QPushButton(tab_3);
        pushButton_send_data->setObjectName(QStringLiteral("pushButton_send_data"));
        sizePolicy.setHeightForWidth(pushButton_send_data->sizePolicy().hasHeightForWidth());
        pushButton_send_data->setSizePolicy(sizePolicy);
        pushButton_send_data->setMinimumSize(QSize(0, 0));
        pushButton_send_data->setFont(font1);

        gridLayout_7->addWidget(pushButton_send_data, 0, 0, 1, 1);

        pushButton_clear = new QPushButton(tab_3);
        pushButton_clear->setObjectName(QStringLiteral("pushButton_clear"));
        sizePolicy.setHeightForWidth(pushButton_clear->sizePolicy().hasHeightForWidth());
        pushButton_clear->setSizePolicy(sizePolicy);
        pushButton_clear->setMinimumSize(QSize(0, 0));
        pushButton_clear->setFont(font1);

        gridLayout_7->addWidget(pushButton_clear, 1, 0, 1, 1);

        pushButton_scan = new QPushButton(tab_3);
        pushButton_scan->setObjectName(QStringLiteral("pushButton_scan"));
        sizePolicy.setHeightForWidth(pushButton_scan->sizePolicy().hasHeightForWidth());
        pushButton_scan->setSizePolicy(sizePolicy);
        pushButton_scan->setFont(font3);

        gridLayout_7->addWidget(pushButton_scan, 1, 1, 1, 1);

        checkBox_discoverable = new QCheckBox(tab_3);
        checkBox_discoverable->setObjectName(QStringLiteral("checkBox_discoverable"));
        sizePolicy.setHeightForWidth(checkBox_discoverable->sizePolicy().hasHeightForWidth());
        checkBox_discoverable->setSizePolicy(sizePolicy);

        gridLayout_7->addWidget(checkBox_discoverable, 2, 0, 1, 1);

        gridLayout_7->setRowStretch(0, 1);
        gridLayout_7->setRowStretch(1, 1);
        gridLayout_7->setRowStretch(2, 1);
        gridLayout_7->setColumnStretch(0, 1);
        gridLayout_7->setColumnStretch(1, 1);
        gridLayout_7->setRowMinimumHeight(0, 1);
        gridLayout_7->setRowMinimumHeight(1, 1);
        gridLayout_7->setRowMinimumHeight(2, 1);

        verticalLayout_3->addLayout(gridLayout_7);

        verticalLayout_3->setStretch(0, 4);
        verticalLayout_3->setStretch(1, 1);
        verticalLayout_3->setStretch(2, 4);
        verticalLayout_3->setStretch(3, 1);
        verticalLayout_3->setStretch(4, 2);

        gridLayout_8->addLayout(verticalLayout_3, 0, 0, 1, 1);

        tabWidget->addTab(tab_3, QString());

        verticalLayout_4->addWidget(tabWidget);

        verticalLayout_4->setStretch(0, 1);
        verticalLayout_4->setStretch(1, 7);

        gridLayout_9->addLayout(verticalLayout_4, 1, 1, 1, 2);


        retranslateUi(Widget);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
        pushButton_logo->setText(QString());
        pushButton_manual_speed->setText(QApplication::translate("Widget", "Manual speed", Q_NULLPTR));
        pushButton_auto_speed->setText(QApplication::translate("Widget", "Auto speed", Q_NULLPTR));
        pushButton_dust_elimination->setText(QApplication::translate("Widget", "Dust elimination", Q_NULLPTR));
        pushButton_save_setting->setText(QApplication::translate("Widget", "Save settings", Q_NULLPTR));
        label_p2->setText(QApplication::translate("Widget", "P2", Q_NULLPTR));
        label_p4->setText(QApplication::translate("Widget", "P4", Q_NULLPTR));
        label_p1->setText(QApplication::translate("Widget", "P1", Q_NULLPTR));
        label_p3->setText(QApplication::translate("Widget", "P3", Q_NULLPTR));
        pushButton_combined_speed->setText(QApplication::translate("Widget", "Combined speed", Q_NULLPTR));
        pushButton_indepandent_speed->setText(QApplication::translate("Widget", "Independent speed", Q_NULLPTR));
        checkBox_allowed_saving->setText(QApplication::translate("Widget", "Allowed saving", Q_NULLPTR));
        checkBox_auto_hibernate->setText(QApplication::translate("Widget", "Auto hibernate", Q_NULLPTR));
        checkBox_enhanced_mode->setText(QApplication::translate("Widget", "Enhanced mode", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Widget", "Fans", Q_NULLPTR));
        label_p2_2->setText(QApplication::translate("Widget", "GREEN", Q_NULLPTR));
        label_p1_2->setText(QApplication::translate("Widget", "RED", Q_NULLPTR));
        label_p3_2->setText(QApplication::translate("Widget", "BLUE", Q_NULLPTR));
        pushButton_color_2->setText(QString());
        pushButton_color_4->setText(QString());
        pushButton_color_1->setText(QString());
        pushButton_color_6->setText(QString());
        pushButton_color_3->setText(QString());
        pushButton_color_7->setText(QString());
        pushButton_color_5->setText(QString());
        pushButton_color_8->setText(QString());
        pushButton_color_9->setText(QString());
        pushButton_color_10->setText(QString());
        pushButton_color_11->setText(QString());
        pushButton_color_12->setText(QString());
        pushButton_color_13->setText(QString());
        pushButton_color_14->setText(QString());
        pushButton_lights_off->setText(QApplication::translate("Widget", "Lights off", Q_NULLPTR));
        pushButton_lights_up->setText(QApplication::translate("Widget", "Lights up", Q_NULLPTR));
        pushButton_static_light->setText(QApplication::translate("Widget", "Static light", Q_NULLPTR));
        pushButton_dynamic_light->setText(QApplication::translate("Widget", "Dynamic light", Q_NULLPTR));
        checkBox->setText(QApplication::translate("Widget", "Allowed saving", Q_NULLPTR));
        checkBox_2->setText(QApplication::translate("Widget", "Auto hibernate", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Widget", "Lights", Q_NULLPTR));
        label_data->setText(QApplication::translate("Widget", "data", Q_NULLPTR));
        pushButton_disconnect->setText(QApplication::translate("Widget", "Disconnect", Q_NULLPTR));
        pushButton_send_data->setText(QApplication::translate("Widget", "Send Data", Q_NULLPTR));
        pushButton_clear->setText(QApplication::translate("Widget", "Clear List", Q_NULLPTR));
        pushButton_scan->setText(QApplication::translate("Widget", "Scan Device", Q_NULLPTR));
        checkBox_discoverable->setText(QApplication::translate("Widget", "Discoverable", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("Widget", "BlueTooth Info", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
