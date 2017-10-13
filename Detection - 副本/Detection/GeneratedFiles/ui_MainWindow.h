/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DetectionClass
{
public:
    QAction *actioncamera;
    QAction *actiontemplate;
    QAction *actionparameter;
    QAction *actionconnection;
    QAction *actionsystem;
    QAction *actionhistory;
    QWidget *centralWidget;
    QPushButton *pushButton;
    QGroupBox *groupBox;
    QLabel *label_3;
    QGroupBox *groupBox_3;
    QLabel *label_7;
    QLabel *masterlabel;
    QLabel *label_11;
    QLabel *masterlabel_2;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *masterlabel_3;
    QLabel *masterlabel_4;
    QLabel *masterlabel_5;
    QGroupBox *groupBox_4;
    QLabel *Lsenlabel;
    QLabel *Rsenlabel;
    QLabel *label_19;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *label_16;
    QLabel *label_15;
    QLabel *Rsenlabel_2;
    QLabel *Rsenlabel_3;
    QLabel *Rsenlabel_4;
    QGroupBox *groupBox_5;
    QLabel *label_2;
    QLabel *resultlabel;
    QGroupBox *groupBox_6;
    QLabel *label_8;
    QGroupBox *groupBox_2;
    QLabel *label_4;
    QGroupBox *groupBox_7;
    QLabel *label_9;
    QGroupBox *groupBox_8;
    QLabel *label_10;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *DetectionClass)
    {
        if (DetectionClass->objectName().isEmpty())
            DetectionClass->setObjectName(QStringLiteral("DetectionClass"));
        DetectionClass->resize(1080, 597);
        QIcon icon;
        icon.addFile(QStringLiteral(":/Detection/Resources/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        DetectionClass->setWindowIcon(icon);
        actioncamera = new QAction(DetectionClass);
        actioncamera->setObjectName(QStringLiteral("actioncamera"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Detection/Resources/14.png"), QSize(), QIcon::Normal, QIcon::Off);
        actioncamera->setIcon(icon1);
        actiontemplate = new QAction(DetectionClass);
        actiontemplate->setObjectName(QStringLiteral("actiontemplate"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/Detection/Resources/15.png"), QSize(), QIcon::Normal, QIcon::Off);
        actiontemplate->setIcon(icon2);
        actionparameter = new QAction(DetectionClass);
        actionparameter->setObjectName(QStringLiteral("actionparameter"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/Detection/Resources/6.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionparameter->setIcon(icon3);
        actionconnection = new QAction(DetectionClass);
        actionconnection->setObjectName(QStringLiteral("actionconnection"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/Detection/Resources/5.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionconnection->setIcon(icon4);
        actionsystem = new QAction(DetectionClass);
        actionsystem->setObjectName(QStringLiteral("actionsystem"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/Detection/Resources/10.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionsystem->setIcon(icon5);
        actionhistory = new QAction(DetectionClass);
        actionhistory->setObjectName(QStringLiteral("actionhistory"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/Detection/Resources/4.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionhistory->setIcon(icon6);
        centralWidget = new QWidget(DetectionClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(870, 490, 131, 71));
        QFont font;
        font.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        pushButton->setFont(font);
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/Detection/Resources/12.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon7);
        pushButton->setIconSize(QSize(48, 48));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(0, 10, 261, 351));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font1.setPointSize(16);
        font1.setBold(true);
        font1.setWeight(75);
        groupBox->setFont(font1);
        groupBox->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 20, 240, 320));
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(310, 380, 181, 191));
        QFont font2;
        font2.setFamily(QStringLiteral("Agency FB"));
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setWeight(75);
        groupBox_3->setFont(font2);
        label_7 = new QLabel(groupBox_3);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 30, 111, 31));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font3.setPointSize(11);
        font3.setBold(false);
        font3.setWeight(50);
        label_7->setFont(font3);
        masterlabel = new QLabel(groupBox_3);
        masterlabel->setObjectName(QStringLiteral("masterlabel"));
        masterlabel->setGeometry(QRect(140, 30, 31, 31));
        label_11 = new QLabel(groupBox_3);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(10, 60, 121, 31));
        label_11->setFont(font3);
        masterlabel_2 = new QLabel(groupBox_3);
        masterlabel_2->setObjectName(QStringLiteral("masterlabel_2"));
        masterlabel_2->setGeometry(QRect(140, 60, 31, 31));
        label_12 = new QLabel(groupBox_3);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(10, 90, 121, 31));
        label_12->setFont(font3);
        label_13 = new QLabel(groupBox_3);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(10, 120, 111, 31));
        label_13->setFont(font3);
        label_14 = new QLabel(groupBox_3);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(10, 150, 101, 31));
        label_14->setFont(font3);
        masterlabel_3 = new QLabel(groupBox_3);
        masterlabel_3->setObjectName(QStringLiteral("masterlabel_3"));
        masterlabel_3->setGeometry(QRect(140, 90, 31, 31));
        masterlabel_4 = new QLabel(groupBox_3);
        masterlabel_4->setObjectName(QStringLiteral("masterlabel_4"));
        masterlabel_4->setGeometry(QRect(140, 120, 31, 31));
        masterlabel_5 = new QLabel(groupBox_3);
        masterlabel_5->setObjectName(QStringLiteral("masterlabel_5"));
        masterlabel_5->setGeometry(QRect(140, 150, 31, 31));
        groupBox_4 = new QGroupBox(centralWidget);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(560, 380, 221, 191));
        groupBox_4->setFont(font2);
        Lsenlabel = new QLabel(groupBox_4);
        Lsenlabel->setObjectName(QStringLiteral("Lsenlabel"));
        Lsenlabel->setGeometry(QRect(170, 30, 31, 31));
        Rsenlabel = new QLabel(groupBox_4);
        Rsenlabel->setObjectName(QStringLiteral("Rsenlabel"));
        Rsenlabel->setGeometry(QRect(170, 60, 31, 31));
        label_19 = new QLabel(groupBox_4);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(10, 150, 121, 31));
        label_19->setFont(font3);
        label_17 = new QLabel(groupBox_4);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(10, 60, 151, 31));
        label_17->setFont(font3);
        label_18 = new QLabel(groupBox_4);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(10, 120, 121, 31));
        label_18->setFont(font3);
        label_16 = new QLabel(groupBox_4);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(10, 30, 131, 31));
        label_16->setFont(font3);
        label_15 = new QLabel(groupBox_4);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(10, 90, 141, 31));
        label_15->setFont(font3);
        Rsenlabel_2 = new QLabel(groupBox_4);
        Rsenlabel_2->setObjectName(QStringLiteral("Rsenlabel_2"));
        Rsenlabel_2->setGeometry(QRect(170, 90, 31, 31));
        Rsenlabel_3 = new QLabel(groupBox_4);
        Rsenlabel_3->setObjectName(QStringLiteral("Rsenlabel_3"));
        Rsenlabel_3->setGeometry(QRect(170, 120, 31, 31));
        Rsenlabel_4 = new QLabel(groupBox_4);
        Rsenlabel_4->setObjectName(QStringLiteral("Rsenlabel_4"));
        Rsenlabel_4->setGeometry(QRect(170, 150, 31, 31));
        groupBox_5 = new QGroupBox(centralWidget);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setGeometry(QRect(860, 380, 151, 91));
        groupBox_5->setFont(font2);
        label_2 = new QLabel(groupBox_5);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 40, 81, 31));
        label_2->setFont(font3);
        resultlabel = new QLabel(groupBox_5);
        resultlabel->setObjectName(QStringLiteral("resultlabel"));
        resultlabel->setGeometry(QRect(110, 40, 31, 31));
        groupBox_6 = new QGroupBox(centralWidget);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        groupBox_6->setGeometry(QRect(270, 10, 261, 351));
        groupBox_6->setFont(font1);
        groupBox_6->setAlignment(Qt::AlignCenter);
        label_8 = new QLabel(groupBox_6);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(10, 20, 240, 320));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(540, 10, 261, 351));
        groupBox_2->setFont(font1);
        groupBox_2->setAlignment(Qt::AlignCenter);
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 20, 240, 320));
        groupBox_7 = new QGroupBox(centralWidget);
        groupBox_7->setObjectName(QStringLiteral("groupBox_7"));
        groupBox_7->setGeometry(QRect(810, 10, 261, 351));
        groupBox_7->setFont(font1);
        groupBox_7->setAlignment(Qt::AlignCenter);
        label_9 = new QLabel(groupBox_7);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(10, 20, 240, 320));
        groupBox_8 = new QGroupBox(centralWidget);
        groupBox_8->setObjectName(QStringLiteral("groupBox_8"));
        groupBox_8->setGeometry(QRect(0, 380, 261, 191));
        groupBox_8->setFont(font1);
        groupBox_8->setAlignment(Qt::AlignCenter);
        label_10 = new QLabel(groupBox_8);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(10, 20, 240, 161));
        DetectionClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(DetectionClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        DetectionClass->setStatusBar(statusBar);

        retranslateUi(DetectionClass);
        QObject::connect(actioncamera, SIGNAL(triggered()), DetectionClass, SLOT(camera_set()));
        QObject::connect(actionconnection, SIGNAL(triggered()), DetectionClass, SLOT(connection_set()));
        QObject::connect(actionhistory, SIGNAL(triggered()), DetectionClass, SLOT(history_display()));
        QObject::connect(actionparameter, SIGNAL(triggered()), DetectionClass, SLOT(paramter_set()));
        QObject::connect(actiontemplate, SIGNAL(triggered()), DetectionClass, SLOT(template_set()));
        QObject::connect(actionsystem, SIGNAL(triggered()), DetectionClass, SLOT(system_set()));

        QMetaObject::connectSlotsByName(DetectionClass);
    } // setupUi

    void retranslateUi(QMainWindow *DetectionClass)
    {
        DetectionClass->setWindowTitle(QApplication::translate("DetectionClass", "Surface Defects Detection", 0));
        actioncamera->setText(QApplication::translate("DetectionClass", "\347\233\270\346\234\272\350\256\276\347\275\256", 0));
        actiontemplate->setText(QApplication::translate("DetectionClass", "\346\250\241\346\235\277\350\256\276\347\275\256", 0));
        actionparameter->setText(QApplication::translate("DetectionClass", "\345\217\202\346\225\260\350\256\276\347\275\256", 0));
        actionconnection->setText(QApplication::translate("DetectionClass", "\350\277\236\346\216\245\350\256\276\347\275\256", 0));
        actionsystem->setText(QApplication::translate("DetectionClass", "\347\263\273\347\273\237\350\256\276\347\275\256", 0));
        actionhistory->setText(QApplication::translate("DetectionClass", "\345\216\206\345\217\262\344\277\241\346\201\257", 0));
        pushButton->setText(QApplication::translate("DetectionClass", "\345\274\200\345\247\213\346\243\200\346\265\213", 0));
        groupBox->setTitle(QApplication::translate("DetectionClass", "\346\234\272\346\237\234\346\255\243\351\235\242", 0));
        label_3->setText(QString());
        groupBox_3->setTitle(QApplication::translate("DetectionClass", "\347\275\221\347\273\234\350\277\236\346\216\245\347\212\266\346\200\201", 0));
        label_7->setText(QApplication::translate("DetectionClass", "\346\255\243\351\235\242\344\273\216\346\234\272\351\200\232\350\256\257\357\274\232", 0));
        masterlabel->setText(QString());
        label_11->setText(QApplication::translate("DetectionClass", "\345\267\246\344\276\247\351\235\242\344\273\216\346\234\272\351\200\232\350\256\257\357\274\232", 0));
        masterlabel_2->setText(QString());
        label_12->setText(QApplication::translate("DetectionClass", "\345\217\263\344\276\247\351\235\242\344\273\216\346\234\272\351\200\232\350\256\257\357\274\232", 0));
        label_13->setText(QApplication::translate("DetectionClass", "\350\203\214\351\235\242\344\273\216\346\234\272\351\200\232\350\256\257\357\274\232", 0));
        label_14->setText(QApplication::translate("DetectionClass", "\351\241\266\351\235\242\344\273\216\346\234\272\351\200\232\350\256\257\357\274\232", 0));
        masterlabel_3->setText(QString());
        masterlabel_4->setText(QString());
        masterlabel_5->setText(QString());
        groupBox_4->setTitle(QApplication::translate("DetectionClass", "\346\234\272\346\237\234\344\275\215\347\275\256\347\212\266\346\200\201", 0));
        Lsenlabel->setText(QString());
        Rsenlabel->setText(QString());
        label_19->setText(QApplication::translate("DetectionClass", "\351\241\266\351\235\242\344\273\216\346\234\272\344\274\240\346\204\237\345\231\250\357\274\232", 0));
        label_17->setText(QApplication::translate("DetectionClass", "\345\267\246\344\276\247\351\235\242\344\273\216\346\234\272\344\274\240\346\204\237\345\231\250\357\274\232", 0));
        label_18->setText(QApplication::translate("DetectionClass", "\350\203\214\351\235\242\344\273\216\346\234\272\344\274\240\346\204\237\345\231\250\357\274\232", 0));
        label_16->setText(QApplication::translate("DetectionClass", "\346\255\243\351\235\242\344\273\216\346\234\272\344\274\240\346\204\237\345\231\250\357\274\232", 0));
        label_15->setText(QApplication::translate("DetectionClass", "\345\217\263\344\276\247\351\235\242\344\273\216\346\234\272\344\274\240\346\204\237\345\231\250\357\274\232", 0));
        Rsenlabel_2->setText(QString());
        Rsenlabel_3->setText(QString());
        Rsenlabel_4->setText(QString());
        groupBox_5->setTitle(QApplication::translate("DetectionClass", "\347\274\272\351\231\267\346\243\200\346\265\213\347\273\223\346\236\234", 0));
        label_2->setText(QApplication::translate("DetectionClass", "\346\243\200\346\265\213\347\273\223\346\236\234\357\274\232", 0));
        resultlabel->setText(QString());
        groupBox_6->setTitle(QApplication::translate("DetectionClass", "\346\234\272\346\237\234\345\267\246\344\276\247\351\235\242", 0));
        label_8->setText(QString());
        groupBox_2->setTitle(QApplication::translate("DetectionClass", "\346\234\272\346\237\234\345\217\263\344\276\247\351\235\242", 0));
        label_4->setText(QString());
        groupBox_7->setTitle(QApplication::translate("DetectionClass", "\346\234\272\346\237\234\350\203\214\351\235\242", 0));
        label_9->setText(QString());
        groupBox_8->setTitle(QApplication::translate("DetectionClass", "\346\234\272\346\237\234\351\241\266\351\235\242", 0));
        label_10->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class DetectionClass: public Ui_DetectionClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
