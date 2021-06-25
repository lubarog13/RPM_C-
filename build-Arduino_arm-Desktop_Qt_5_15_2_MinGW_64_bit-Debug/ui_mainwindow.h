/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *cmbPort;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_8;
    QLabel *positions;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *save;
    QPushButton *run;
    QPushButton *reset;
    QLabel *label_9;
    QFrame *formFrame;
    QFormLayout *formLayout;
    QLabel *label_2;
    QLabel *label_3;
    QSlider *servo_05;
    QLabel *label_4;
    QSlider *servo_04;
    QLabel *label_5;
    QSlider *servo_03;
    QLabel *label_6;
    QSlider *servo_02;
    QLabel *label_7;
    QSlider *servo_01;
    QSlider *servo_06;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(595, 363);
        MainWindow->setStyleSheet(QString::fromUtf8(".QMainWindow {background-image: url(:/images/f9f39370b1c41477371f02aa1e3e9082.jpg);}\n"
"#centralwidget {background-image: url(:/images/f9f39370b1c41477371f02aa1e3e9082.jpg);}\n"
".QPushButton {\n"
"	background-color: rgb(38, 67, 255);\n"
"     border-style: outset;\n"
"     border-width: 2px;\n"
"     border-radius: 10px;\n"
"     border-color: beige;\n"
"     font: bold 14px;\n"
"     min-width: 5em;\n"
"	color: rgb(238, 238, 238);\n"
"     padding: 6px;\n"
" }\n"
".QPushButton::hover {\n"
"	background-color: rgb(21, 0, 255);\n"
"}"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setStyleSheet(QString::fromUtf8(".QWidget {background-image: url(:/images/f9f39370b1c41477371f02aa1e3e9082.jpg);}"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        cmbPort = new QComboBox(centralwidget);
        cmbPort->setObjectName(QString::fromUtf8("cmbPort"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(40);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(cmbPort->sizePolicy().hasHeightForWidth());
        cmbPort->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(cmbPort);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setStyleSheet(QString::fromUtf8("font: 75 10pt \"MS Shell Dlg 2\";"));

        horizontalLayout_3->addWidget(label_8);

        positions = new QLabel(centralwidget);
        positions->setObjectName(QString::fromUtf8("positions"));
        positions->setStyleSheet(QString::fromUtf8("font: 75 10pt \"MS Shell Dlg 2\";\n"
"text-decoration: underline;"));

        horizontalLayout_3->addWidget(positions);


        gridLayout->addLayout(horizontalLayout_3, 0, 1, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        save = new QPushButton(centralwidget);
        save->setObjectName(QString::fromUtf8("save"));
        save->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_2->addWidget(save);

        run = new QPushButton(centralwidget);
        run->setObjectName(QString::fromUtf8("run"));

        horizontalLayout_2->addWidget(run);

        reset = new QPushButton(centralwidget);
        reset->setObjectName(QString::fromUtf8("reset"));

        horizontalLayout_2->addWidget(reset);


        gridLayout->addLayout(horizontalLayout_2, 2, 1, 1, 1);

        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setMinimumSize(QSize(200, 200));
        label_9->setStyleSheet(QString::fromUtf8("image: url(:/images/Arduino-Robotic-Arm-3D-Printed-768x801.jpg);"));
        label_9->setFrameShape(QFrame::WinPanel);
        label_9->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(label_9, 1, 0, 1, 1);

        formFrame = new QFrame(centralwidget);
        formFrame->setObjectName(QString::fromUtf8("formFrame"));
        formFrame->setAcceptDrops(false);
        formFrame->setAutoFillBackground(false);
        formFrame->setStyleSheet(QString::fromUtf8(".QFrame {\n"
"background-color: qlineargradient(spread:pad, x1:0.223881, y1:0.966, x2:0.224, y2:0.88, stop:0 rgba(38, 0, 255, 255), stop:0.78607 rgba(255, 255, 255, 255));\n"
"}"));
        formFrame->setFrameShape(QFrame::NoFrame);
        formFrame->setFrameShadow(QFrame::Plain);
        formLayout = new QFormLayout(formFrame);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label_2 = new QLabel(formFrame);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_2);

        label_3 = new QLabel(formFrame);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_3);

        servo_05 = new QSlider(formFrame);
        servo_05->setObjectName(QString::fromUtf8("servo_05"));
        servo_05->setMaximum(180);
        servo_05->setSliderPosition(85);
        servo_05->setOrientation(Qt::Horizontal);

        formLayout->setWidget(1, QFormLayout::FieldRole, servo_05);

        label_4 = new QLabel(formFrame);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_4);

        servo_04 = new QSlider(formFrame);
        servo_04->setObjectName(QString::fromUtf8("servo_04"));
        servo_04->setMaximum(180);
        servo_04->setValue(140);
        servo_04->setOrientation(Qt::Horizontal);

        formLayout->setWidget(2, QFormLayout::FieldRole, servo_04);

        label_5 = new QLabel(formFrame);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_5);

        servo_03 = new QSlider(formFrame);
        servo_03->setObjectName(QString::fromUtf8("servo_03"));
        servo_03->setMinimum(20);
        servo_03->setMaximum(160);
        servo_03->setValue(35);
        servo_03->setOrientation(Qt::Horizontal);

        formLayout->setWidget(3, QFormLayout::FieldRole, servo_03);

        label_6 = new QLabel(formFrame);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_6);

        servo_02 = new QSlider(formFrame);
        servo_02->setObjectName(QString::fromUtf8("servo_02"));
        servo_02->setMinimum(100);
        servo_02->setMaximum(180);
        servo_02->setOrientation(Qt::Horizontal);

        formLayout->setWidget(4, QFormLayout::FieldRole, servo_02);

        label_7 = new QLabel(formFrame);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_7);

        servo_01 = new QSlider(formFrame);
        servo_01->setObjectName(QString::fromUtf8("servo_01"));
        servo_01->setMaximum(180);
        servo_01->setValue(80);
        servo_01->setOrientation(Qt::Horizontal);

        formLayout->setWidget(5, QFormLayout::FieldRole, servo_01);

        servo_06 = new QSlider(formFrame);
        servo_06->setObjectName(QString::fromUtf8("servo_06"));
        servo_06->setAutoFillBackground(false);
        servo_06->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        servo_06->setMaximum(180);
        servo_06->setValue(80);
        servo_06->setOrientation(Qt::Horizontal);

        formLayout->setWidget(0, QFormLayout::FieldRole, servo_06);


        gridLayout->addWidget(formFrame, 1, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        formFrame->raise();
        label->raise();
        cmbPort->raise();
        save->raise();
        run->raise();
        reset->raise();
        label_8->raise();
        positions->raise();
        label_9->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 595, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\321\200\321\202", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\265\320\275\320\275\321\213\320\265 \320\277\320\276\320\267\320\270\321\206\320\270\320\270:", nullptr));
        positions->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        save->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        run->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\321\207\320\260\321\202\321\214", nullptr));
        reset->setText(QCoreApplication::translate("MainWindow", "\320\241\320\261\321\200\320\276\321\201\320\270\321\202\321\214", nullptr));
        label_9->setText(QString());
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\232\320\270\321\201\321\202\321\214", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\277\321\217\321\201\321\202\321\214\320\265", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\262\320\276\321\200\320\276\321\202 \320\267\320\260\320\277\321\217\321\201\321\202\321\214\321\217", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\320\233\320\276\320\272\320\276\321\202\321\214", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\320\237\320\273\320\265\321\207\320\276", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\262\320\276\321\200\320\276\321\202", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
