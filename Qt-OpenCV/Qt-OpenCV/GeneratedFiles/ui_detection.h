/********************************************************************************
** Form generated from reading UI file 'detection.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DETECTION_H
#define UI_DETECTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_detectionClass
{
public:
    QWidget *centralWidget;
    QGroupBox *groupBox;
    QLabel *label;
    QGroupBox *groupBox_2;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QLineEdit *lineEdit;
    QLabel *label_3;
    QLabel *label_4;
    QGroupBox *groupBox_3;
    QTextEdit *textEdit;
    QTextBrowser *textBrowser;

    void setupUi(QMainWindow *detectionClass)
    {
        if (detectionClass->objectName().isEmpty())
            detectionClass->setObjectName(QStringLiteral("detectionClass"));
        detectionClass->resize(981, 643);
        QIcon icon;
        icon.addFile(QStringLiteral(":/detection/Resources/www.ico.la_3c07078ec5f3c03e57f1364925bee7ac_128X128.ico"), QSize(), QIcon::Normal, QIcon::Off);
        detectionClass->setWindowIcon(icon);
        centralWidget = new QWidget(detectionClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(-1, 9, 701, 511));
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        groupBox->setFont(font);
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 40, 661, 411));
        label->setContextMenuPolicy(Qt::ActionsContextMenu);
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(710, 10, 271, 241));
        groupBox_2->setFont(font);
        pushButton_2 = new QPushButton(groupBox_2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(140, 90, 121, 41));
        QFont font1;
        font1.setFamily(QStringLiteral("Arial"));
        font1.setPointSize(11);
        font1.setBold(true);
        font1.setWeight(75);
        pushButton_2->setFont(font1);
        pushButton_3 = new QPushButton(groupBox_2);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(10, 140, 121, 41));
        pushButton_3->setFont(font1);
        pushButton = new QPushButton(groupBox_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(10, 90, 121, 41));
        pushButton->setFont(font1);
        pushButton_4 = new QPushButton(groupBox_2);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(140, 140, 121, 41));
        QFont font2;
        font2.setFamily(QStringLiteral("Arial"));
        font2.setPointSize(11);
        pushButton_4->setFont(font2);
        pushButton_5 = new QPushButton(groupBox_2);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(10, 190, 121, 41));
        pushButton_5->setFont(font2);
        pushButton_5->setFocusPolicy(Qt::NoFocus);
        pushButton_6 = new QPushButton(groupBox_2);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(140, 190, 121, 41));
        pushButton_6->setFont(font2);
        radioButton = new QRadioButton(groupBox_2);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setGeometry(QRect(110, 30, 71, 21));
        radioButton->setFont(font2);
        radioButton_2 = new QRadioButton(groupBox_2);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        radioButton_2->setGeometry(QRect(190, 30, 71, 21));
        radioButton_2->setFont(font2);
        lineEdit = new QLineEdit(groupBox_2);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(140, 60, 121, 21));
        QFont font3;
        font3.setFamily(QStringLiteral("Arial"));
        font3.setPointSize(12);
        font3.setBold(false);
        font3.setWeight(50);
        lineEdit->setFont(font3);
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 30, 101, 21));
        label_3->setFont(font2);
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 60, 121, 21));
        label_4->setFont(font2);
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(709, 259, 271, 261));
        groupBox_3->setFont(font);
        textEdit = new QTextEdit(groupBox_3);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(10, 30, 251, 221));
        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(10, 520, 961, 121));
        detectionClass->setCentralWidget(centralWidget);

        retranslateUi(detectionClass);
        QObject::connect(pushButton, SIGNAL(clicked()), detectionClass, SLOT(openCamera()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), detectionClass, SLOT(closeCamera()));
        QObject::connect(pushButton_3, SIGNAL(clicked()), detectionClass, SLOT(takingPictures()));

        QMetaObject::connectSlotsByName(detectionClass);
    } // setupUi

    void retranslateUi(QMainWindow *detectionClass)
    {
        detectionClass->setWindowTitle(QApplication::translate("detectionClass", "EMERSON Surface Defects Detection", 0));
        groupBox->setTitle(QApplication::translate("detectionClass", "Camera", 0));
        label->setText(QString());
        groupBox_2->setTitle(QApplication::translate("detectionClass", "Operation", 0));
        pushButton_2->setText(QApplication::translate("detectionClass", "CloseCamera\n"
"\345\205\263\351\227\255\346\221\204\345\203\217\345\244\264", 0));
        pushButton_3->setText(QApplication::translate("detectionClass", "TakingPictures\n"
"\350\216\267\345\217\226\345\233\276\347\211\207", 0));
        pushButton->setText(QApplication::translate("detectionClass", "OpenCamera\n"
"\346\211\223\345\274\200\346\221\204\345\203\217\345\244\264", 0));
        pushButton_4->setText(QApplication::translate("detectionClass", "DetecteDefect\n"
"\346\243\200\346\265\213\347\274\272\351\231\267", 0));
        pushButton_5->setText(QApplication::translate("detectionClass", "IdentifyDefects\n"
"\350\257\206\345\210\253\347\274\272\351\231\267", 0));
        pushButton_6->setText(QApplication::translate("detectionClass", "Continue\n"
"\347\273\247\347\273\255", 0));
        radioButton->setText(QApplication::translate("detectionClass", "Type A", 0));
        radioButton_2->setText(QApplication::translate("detectionClass", "Type B", 0));
        label_3->setText(QApplication::translate("detectionClass", "Cabinet type:", 0));
        label_4->setText(QApplication::translate("detectionClass", "Cabinet number:", 0));
        groupBox_3->setTitle(QApplication::translate("detectionClass", "Output", 0));
        textBrowser->setHtml(QApplication::translate("detectionClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><img src=\":/detection/Resources/logo.png\" /><img src=\":/detection/Resources/emc.jpg\" /></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Times New Roman'; font-size:10pt;\">Copyright of the interface is reserved by Shenzhen Key Laboratory of Elect"
                        "romagnetic Control</span></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class detectionClass: public Ui_detectionClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DETECTION_H
