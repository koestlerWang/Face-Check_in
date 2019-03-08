/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QCommandLinkButton *commandLinkButton;
    QCommandLinkButton *commandLinkButton_2;
    QCommandLinkButton *commandLinkButton_3;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QTableWidget *tableWidget;
    QCommandLinkButton *commandLinkButton_15;
    QCommandLinkButton *commandLinkButton_16;
    QWidget *page_2;
    QLineEdit *lineEdit;
    QLabel *label;
    QCommandLinkButton *commandLinkButton_11;
    QCommandLinkButton *commandLinkButton_12;
    QCommandLinkButton *commandLinkButton_9;
    QTableWidget *tableWidget_2;
    QWidget *page_3;
    QCommandLinkButton *commandLinkButton_6;
    QTableWidget *tableWidget_3;
    QLabel *label_11;
    QLineEdit *lineEdit_3;
    QPushButton *pushButton_2;
    QLabel *label_12;
    QLineEdit *lineEdit_4;
    QPushButton *pushButton_3;
    QLabel *label_14;
    QLineEdit *lineEdit_5;
    QPushButton *pushButton_4;
    QCommandLinkButton *commandLinkButton_7;
    QPushButton *pushButton;
    QCommandLinkButton *commandLinkButton_8;
    QPushButton *pushButton_5;
    QWidget *page_4;
    QLineEdit *lineEdit_2;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QComboBox *comboBox;
    QLabel *label_10;
    QCommandLinkButton *commandLinkButton_13;
    QComboBox *comboBox_2;
    QCommandLinkButton *commandLinkButton_14;
    QWidget *page_5;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QWidget *page_6;
    QCommandLinkButton *commandLinkButton_4;
    QCommandLinkButton *commandLinkButton_5;
    QFrame *line;
    QFrame *line_2;
    QCommandLinkButton *commandLinkButton_10;
    QFrame *line_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1033, 755);
        QIcon icon;
        icon.addFile(QStringLiteral("san.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setToolTipDuration(-2);
        MainWindow->setStyleSheet(QStringLiteral(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        commandLinkButton = new QCommandLinkButton(centralwidget);
        commandLinkButton->setObjectName(QStringLiteral("commandLinkButton"));
        commandLinkButton->setGeometry(QRect(30, 20, 181, 61));
        commandLinkButton->setStyleSheet(QString::fromUtf8("font: 12pt \"\351\273\221\344\275\223\";\n"
""));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/iamges/home.png"), QSize(), QIcon::Normal, QIcon::Off);
        commandLinkButton->setIcon(icon1);
        commandLinkButton->setIconSize(QSize(50, 50));
        commandLinkButton_2 = new QCommandLinkButton(centralwidget);
        commandLinkButton_2->setObjectName(QStringLiteral("commandLinkButton_2"));
        commandLinkButton_2->setGeometry(QRect(30, 230, 191, 71));
        commandLinkButton_2->setStyleSheet(QString::fromUtf8("font: 12pt \"\351\273\221\344\275\223\";"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/iamges/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        commandLinkButton_2->setIcon(icon2);
        commandLinkButton_2->setIconSize(QSize(50, 50));
        commandLinkButton_3 = new QCommandLinkButton(centralwidget);
        commandLinkButton_3->setObjectName(QStringLiteral("commandLinkButton_3"));
        commandLinkButton_3->setGeometry(QRect(30, 340, 211, 71));
        commandLinkButton_3->setStyleSheet(QString::fromUtf8("font: 12pt \"\351\273\221\344\275\223\";"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/iamges/notes.png"), QSize(), QIcon::Normal, QIcon::Off);
        commandLinkButton_3->setIcon(icon3);
        commandLinkButton_3->setIconSize(QSize(50, 50));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(260, 10, 761, 671));
        QFont font;
        font.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font.setPointSize(10);
        stackedWidget->setFont(font);
        stackedWidget->setStyleSheet(QLatin1String("#page_5{border-image: url(:/iamges/shuimo21.jpg);}\n"
"#page_6{border-image: url(:/iamges/san2.jpg);}\n"
"#page_4{background-image: url(:/iamges/eye.jpg);}\n"
"#page_2{background-image: url(:/iamges/A.jpg);}\n"
"#page_3{border-image: url(:/iamges/SM2.jpg);}"));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        tableWidget = new QTableWidget(page);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(30, 10, 701, 571));
        commandLinkButton_15 = new QCommandLinkButton(page);
        commandLinkButton_15->setObjectName(QStringLiteral("commandLinkButton_15"));
        commandLinkButton_15->setGeometry(QRect(70, 600, 181, 61));
        commandLinkButton_15->setStyleSheet(QString::fromUtf8("\n"
"font: 12pt \"\345\215\216\346\226\207\346\245\267\344\275\223\";"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/iamges/edit_group.png"), QSize(), QIcon::Normal, QIcon::Off);
        commandLinkButton_15->setIcon(icon4);
        commandLinkButton_15->setIconSize(QSize(40, 40));
        commandLinkButton_16 = new QCommandLinkButton(page);
        commandLinkButton_16->setObjectName(QStringLiteral("commandLinkButton_16"));
        commandLinkButton_16->setGeometry(QRect(560, 600, 101, 61));
        commandLinkButton_16->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\215\216\346\226\207\346\245\267\344\275\223\";"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/iamges/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        commandLinkButton_16->setIcon(icon5);
        commandLinkButton_16->setIconSize(QSize(40, 40));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        lineEdit = new QLineEdit(page_2);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(220, 30, 241, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font1.setPointSize(13);
        lineEdit->setFont(font1);
        label = new QLabel(page_2);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 30, 201, 31));
        label->setStyleSheet(QString::fromUtf8("font: 15pt \"\346\245\267\344\275\223\";"));
        commandLinkButton_11 = new QCommandLinkButton(page_2);
        commandLinkButton_11->setObjectName(QStringLiteral("commandLinkButton_11"));
        commandLinkButton_11->setGeometry(QRect(20, 310, 171, 71));
        commandLinkButton_11->setStyleSheet(QString::fromUtf8("font: 15pt \"\345\215\216\346\226\207\346\245\267\344\275\223\";"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/iamges/zhi.png"), QSize(), QIcon::Normal, QIcon::Off);
        commandLinkButton_11->setIcon(icon6);
        commandLinkButton_11->setIconSize(QSize(50, 50));
        commandLinkButton_12 = new QCommandLinkButton(page_2);
        commandLinkButton_12->setObjectName(QStringLiteral("commandLinkButton_12"));
        commandLinkButton_12->setGeometry(QRect(20, 210, 171, 51));
        commandLinkButton_12->setStyleSheet(QString::fromUtf8("font: 15pt \"\345\215\216\346\226\207\346\245\267\344\275\223\";"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/iamges/key.png"), QSize(), QIcon::Normal, QIcon::Off);
        commandLinkButton_12->setIcon(icon7);
        commandLinkButton_12->setIconSize(QSize(50, 50));
        commandLinkButton_9 = new QCommandLinkButton(page_2);
        commandLinkButton_9->setObjectName(QStringLiteral("commandLinkButton_9"));
        commandLinkButton_9->setGeometry(QRect(50, 490, 111, 71));
        commandLinkButton_9->setStyleSheet(QString::fromUtf8("font: 15pt \"\345\215\216\346\226\207\346\245\267\344\275\223\";"));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/iamges/confirm.png"), QSize(), QIcon::Normal, QIcon::Off);
        commandLinkButton_9->setIcon(icon8);
        commandLinkButton_9->setIconSize(QSize(50, 50));
        tableWidget_2 = new QTableWidget(page_2);
        tableWidget_2->setObjectName(QStringLiteral("tableWidget_2"));
        tableWidget_2->setGeometry(QRect(200, 120, 531, 541));
        tableWidget_2->setStyleSheet(QString::fromUtf8("font: 12pt \"\346\245\267\344\275\223\";"));
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        commandLinkButton_6 = new QCommandLinkButton(page_3);
        commandLinkButton_6->setObjectName(QStringLiteral("commandLinkButton_6"));
        commandLinkButton_6->setGeometry(QRect(11, 20, 151, 61));
        commandLinkButton_6->setStyleSheet(QString::fromUtf8("font: 12pt \"\346\245\267\344\275\223\";"));
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/iamges/sea.png"), QSize(), QIcon::Normal, QIcon::Off);
        commandLinkButton_6->setIcon(icon9);
        commandLinkButton_6->setIconSize(QSize(50, 50));
        tableWidget_3 = new QTableWidget(page_3);
        tableWidget_3->setObjectName(QStringLiteral("tableWidget_3"));
        tableWidget_3->setGeometry(QRect(170, 11, 571, 651));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        tableWidget_3->setFont(font2);
        tableWidget_3->setFocusPolicy(Qt::TabFocus);
        label_11 = new QLabel(page_3);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(40, 320, 91, 20));
        label_11->setStyleSheet(QString::fromUtf8("font: 12pt \"\346\245\267\344\275\223\";"));
        lineEdit_3 = new QLineEdit(page_3);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(11, 350, 151, 30));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font3.setPointSize(12);
        lineEdit_3->setFont(font3);
        pushButton_2 = new QPushButton(page_3);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(10, 390, 151, 28));
        pushButton_2->setStyleSheet(QString::fromUtf8("font: 10pt \"\351\273\221\344\275\223\";"));
        label_12 = new QLabel(page_3);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(20, 440, 131, 20));
        label_12->setStyleSheet(QString::fromUtf8("font: 12pt \"\346\245\267\344\275\223\";"));
        lineEdit_4 = new QLineEdit(page_3);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(11, 470, 151, 30));
        lineEdit_4->setFont(font3);
        pushButton_3 = new QPushButton(page_3);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(10, 510, 151, 28));
        pushButton_3->setStyleSheet(QString::fromUtf8("font: 10pt \"\351\273\221\344\275\223\";"));
        label_14 = new QLabel(page_3);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(40, 560, 100, 20));
        label_14->setStyleSheet(QString::fromUtf8("font: 12pt \"\346\245\267\344\275\223\";"));
        lineEdit_5 = new QLineEdit(page_3);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(10, 590, 151, 30));
        lineEdit_5->setFont(font3);
        pushButton_4 = new QPushButton(page_3);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(10, 630, 151, 28));
        pushButton_4->setStyleSheet(QString::fromUtf8("font: 10pt \"\351\273\221\344\275\223\";"));
        commandLinkButton_7 = new QCommandLinkButton(page_3);
        commandLinkButton_7->setObjectName(QStringLiteral("commandLinkButton_7"));
        commandLinkButton_7->setGeometry(QRect(10, 80, 151, 71));
        commandLinkButton_7->setStyleSheet(QString::fromUtf8("font: 12pt \"\346\245\267\344\275\223\";"));
        QIcon icon10;
        icon10.addFile(QStringLiteral("bu.png"), QSize(), QIcon::Normal, QIcon::Off);
        commandLinkButton_7->setIcon(icon10);
        commandLinkButton_7->setIconSize(QSize(50, 50));
        pushButton = new QPushButton(page_3);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(20, 150, 131, 28));
        pushButton->setStyleSheet(QString::fromUtf8("font: 10pt \"\351\273\221\344\275\223\";"));
        commandLinkButton_8 = new QCommandLinkButton(page_3);
        commandLinkButton_8->setObjectName(QStringLiteral("commandLinkButton_8"));
        commandLinkButton_8->setGeometry(QRect(10, 190, 151, 71));
        commandLinkButton_8->setStyleSheet(QString::fromUtf8("font: 12pt \"\346\245\267\344\275\223\";"));
        QIcon icon11;
        icon11.addFile(QStringLiteral("lu.png"), QSize(), QIcon::Normal, QIcon::Off);
        commandLinkButton_8->setIcon(icon11);
        commandLinkButton_8->setIconSize(QSize(50, 50));
        pushButton_5 = new QPushButton(page_3);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(20, 260, 131, 28));
        pushButton_5->setStyleSheet(QString::fromUtf8("font: 10pt \"\351\273\221\344\275\223\";"));
        stackedWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName(QStringLiteral("page_4"));
        lineEdit_2 = new QLineEdit(page_4);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(80, 160, 161, 31));
        lineEdit_2->setFont(font);
        label_7 = new QLabel(page_4);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(130, 130, 71, 31));
        label_7->setStyleSheet(QString::fromUtf8("font: 15pt \"\345\215\216\346\226\207\346\245\267\344\275\223\";"));
        label_8 = new QLabel(page_4);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(130, 210, 72, 31));
        label_8->setStyleSheet(QString::fromUtf8("font: 15pt \"\345\215\216\346\226\207\346\245\267\344\275\223\";"));
        label_9 = new QLabel(page_4);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(80, 320, 81, 31));
        label_9->setStyleSheet(QString::fromUtf8("font: 15pt \"\345\215\216\346\226\207\346\245\267\344\275\223\";"));
        comboBox = new QComboBox(page_4);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(170, 320, 71, 31));
        comboBox->setStyleSheet(QString::fromUtf8("font: 10pt \"\351\273\221\344\275\223\";"));
        label_10 = new QLabel(page_4);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(80, 50, 251, 51));
        label_10->setStyleSheet(QString::fromUtf8("font: 20pt \"\345\215\216\346\226\207\346\245\267\344\275\223\";"));
        commandLinkButton_13 = new QCommandLinkButton(page_4);
        commandLinkButton_13->setObjectName(QStringLiteral("commandLinkButton_13"));
        commandLinkButton_13->setGeometry(QRect(210, 450, 241, 71));
        commandLinkButton_13->setStyleSheet(QString::fromUtf8("font: 18pt \"\345\215\216\346\226\207\346\245\267\344\275\223\";"));
        QIcon icon12;
        icon12.addFile(QStringLiteral(":/iamges/ren.png"), QSize(), QIcon::Normal, QIcon::Off);
        commandLinkButton_13->setIcon(icon12);
        commandLinkButton_13->setIconSize(QSize(50, 50));
        comboBox_2 = new QComboBox(page_4);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));
        comboBox_2->setGeometry(QRect(80, 250, 161, 31));
        comboBox_2->setStyleSheet(QString::fromUtf8("font: 10pt \"\351\273\221\344\275\223\";"));
        comboBox_2->setEditable(true);
        commandLinkButton_14 = new QCommandLinkButton(page_4);
        commandLinkButton_14->setObjectName(QStringLiteral("commandLinkButton_14"));
        commandLinkButton_14->setGeometry(QRect(240, 550, 191, 71));
        commandLinkButton_14->setStyleSheet(QString::fromUtf8("font: 18pt \"\345\215\216\346\226\207\346\245\267\344\275\223\";"));
        QIcon icon13;
        icon13.addFile(QStringLiteral(":/iamges/Down.png"), QSize(), QIcon::Normal, QIcon::Off);
        commandLinkButton_14->setIcon(icon13);
        commandLinkButton_14->setIconSize(QSize(50, 50));
        stackedWidget->addWidget(page_4);
        page_5 = new QWidget();
        page_5->setObjectName(QStringLiteral("page_5"));
        label_2 = new QLabel(page_5);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 90, 651, 91));
        label_2->setStyleSheet(QString::fromUtf8("font: 15pt \"\345\215\216\346\226\207\346\245\267\344\275\223\";"));
        label_3 = new QLabel(page_5);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 200, 621, 61));
        label_3->setStyleSheet(QString::fromUtf8("font: 15pt \"\345\215\216\346\226\207\346\245\267\344\275\223\";"));
        label_4 = new QLabel(page_5);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 280, 621, 61));
        label_4->setStyleSheet(QString::fromUtf8("font: 15pt \"\345\215\216\346\226\207\346\245\267\344\275\223\";\n"
""));
        label_5 = new QLabel(page_5);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(20, 360, 541, 91));
        label_5->setStyleSheet(QString::fromUtf8("font: 15pt \"\345\215\216\346\226\207\346\245\267\344\275\223\";"));
        label_6 = new QLabel(page_5);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(260, 20, 141, 41));
        label_6->setStyleSheet(QString::fromUtf8("\n"
"font: 20pt \"\351\273\221\344\275\223\";"));
        stackedWidget->addWidget(page_5);
        page_6 = new QWidget();
        page_6->setObjectName(QStringLiteral("page_6"));
        stackedWidget->addWidget(page_6);
        commandLinkButton_4 = new QCommandLinkButton(centralwidget);
        commandLinkButton_4->setObjectName(QStringLiteral("commandLinkButton_4"));
        commandLinkButton_4->setGeometry(QRect(30, 120, 181, 71));
        commandLinkButton_4->setStyleSheet(QString::fromUtf8("font: 12pt \"\351\273\221\344\275\223\";"));
        QIcon icon14;
        icon14.addFile(QStringLiteral(":/iamges/add_user.png"), QSize(), QIcon::Normal, QIcon::Off);
        commandLinkButton_4->setIcon(icon14);
        commandLinkButton_4->setIconSize(QSize(50, 50));
        commandLinkButton_5 = new QCommandLinkButton(centralwidget);
        commandLinkButton_5->setObjectName(QStringLiteral("commandLinkButton_5"));
        commandLinkButton_5->setGeometry(QRect(40, 600, 181, 71));
        commandLinkButton_5->setStyleSheet(QString::fromUtf8("font: 15pt \"\351\273\221\344\275\223\";"));
        QIcon icon15;
        icon15.addFile(QStringLiteral(":/iamges/ko.png"), QSize(), QIcon::Normal, QIcon::Off);
        commandLinkButton_5->setIcon(icon15);
        commandLinkButton_5->setIconSize(QSize(50, 50));
        line = new QFrame(centralwidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(240, 0, 21, 451));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(centralwidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(0, 436, 251, 31));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        commandLinkButton_10 = new QCommandLinkButton(centralwidget);
        commandLinkButton_10->setObjectName(QStringLiteral("commandLinkButton_10"));
        commandLinkButton_10->setGeometry(QRect(40, 510, 181, 71));
        commandLinkButton_10->setStyleSheet(QString::fromUtf8("font: 15pt \"\351\273\221\344\275\223\";"));
        QIcon icon16;
        icon16.addFile(QStringLiteral(":/iamges/faq.png"), QSize(), QIcon::Normal, QIcon::Off);
        commandLinkButton_10->setIcon(icon16);
        commandLinkButton_10->setIconSize(QSize(50, 50));
        line_3 = new QFrame(centralwidget);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setGeometry(QRect(230, 450, 41, 231));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1033, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\347\224\265\345\255\220\346\265\213\351\207\217\347\253\231\350\200\203\345\213\244\347\263\273\347\273\237", Q_NULLPTR));
        commandLinkButton->setText(QApplication::translate("MainWindow", "\347\253\231\346\210\220\345\221\230\346\237\245\350\257\242", Q_NULLPTR));
        commandLinkButton_2->setText(QApplication::translate("MainWindow", "\346\226\260\345\273\272\350\257\276\347\250\213\350\200\203\345\213\244", Q_NULLPTR));
        commandLinkButton_3->setText(QApplication::translate("MainWindow", "\350\200\203\345\213\244\346\237\245\350\257\242\344\270\216\350\241\245\345\275\225", Q_NULLPTR));
        commandLinkButton_15->setText(QApplication::translate("MainWindow", "\347\202\271\345\207\273\344\277\256\346\224\271\344\277\241\346\201\257", Q_NULLPTR));
        commandLinkButton_16->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230", Q_NULLPTR));
        lineEdit->setText(QString());
        label->setText(QApplication::translate("MainWindow", "\350\257\267\350\276\223\345\205\245\350\257\276\347\250\213\345\220\215\347\247\260\357\274\232", Q_NULLPTR));
        commandLinkButton_11->setText(QApplication::translate("MainWindow", "\344\272\272\350\204\270\350\200\203\345\213\244", Q_NULLPTR));
        commandLinkButton_12->setText(QApplication::translate("MainWindow", "\346\211\213\345\267\245\345\275\225\345\205\245", Q_NULLPTR));
        commandLinkButton_9->setText(QApplication::translate("MainWindow", "\347\241\256\350\256\244", Q_NULLPTR));
        commandLinkButton_6->setText(QApplication::translate("MainWindow", "\346\212\245\350\241\250\346\237\245\350\257\242", Q_NULLPTR));
        label_11->setText(QApplication::translate("MainWindow", "\345\247\223\345\220\215\346\237\245\350\257\242\357\274\232", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "\347\202\271\345\207\273\346\237\245\350\257\242", Q_NULLPTR));
        label_12->setText(QApplication::translate("MainWindow", "\350\257\276\347\250\213\345\220\215\347\247\260\346\237\245\350\257\242\357\274\232", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("MainWindow", "\347\202\271\345\207\273\346\237\245\350\257\242", Q_NULLPTR));
        label_14->setText(QApplication::translate("MainWindow", "\346\227\245\346\234\237\346\237\245\350\257\242\357\274\232", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("MainWindow", "\347\202\271\345\207\273\346\237\245\350\257\242", Q_NULLPTR));
        commandLinkButton_7->setText(QApplication::translate("MainWindow", "\346\211\213\345\212\250\350\241\245\345\275\225", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "\346\211\213\345\212\250\350\241\245\345\275\225\345\256\214\346\210\220", Q_NULLPTR));
        commandLinkButton_8->setText(QApplication::translate("MainWindow", "\344\272\272\350\204\270\350\241\245\345\275\225", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("MainWindow", "\344\272\272\350\204\270\350\241\245\345\275\225\345\256\214\346\210\220", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "\345\247\223\345\220\215\357\274\232", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "\350\201\214\345\212\241\357\274\232", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "\345\205\232\345\233\242\345\221\230", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\345\205\232\345\221\230", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\345\233\242\345\221\230", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\347\276\244\344\274\227", Q_NULLPTR)
         << QString()
        );
        label_10->setText(QApplication::translate("MainWindow", "\350\257\267\350\276\223\345\205\245\344\270\213\345\210\227\344\277\241\346\201\257\357\274\232", Q_NULLPTR));
        commandLinkButton_13->setText(QApplication::translate("MainWindow", "\344\272\272\350\204\270\346\231\272\350\203\275\345\275\225\345\205\245", Q_NULLPTR));
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\345\212\251\347\220\206\345\267\245\347\250\213\345\270\210", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\345\267\245\347\250\213\345\270\210", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\351\230\237\351\225\277", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\346\225\231\345\257\274\345\221\230", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\344\270\200\347\272\247\345\206\233\345\243\253\351\225\277", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\344\272\214\347\272\247\345\206\233\345\243\253\351\225\277", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\344\270\211\347\272\247\345\206\233\345\243\253\351\225\277", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\345\233\233\347\272\247\345\206\233\345\243\253\351\225\277", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\344\270\212\345\243\253", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\344\270\255\345\243\253", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\344\270\213\345\243\253", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\344\270\212\347\255\211\345\205\265", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\345\210\227\345\205\265", Q_NULLPTR)
         << QString()
        );
        commandLinkButton_14->setText(QApplication::translate("MainWindow", "\347\233\264\346\216\245\345\275\225\345\205\245", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "1.\347\253\231\346\210\220\345\221\230\346\237\245\350\257\242\346\217\220\344\276\233\345\275\223\345\211\215\347\253\231\345\206\205\346\211\200\346\234\211\346\210\220\345\221\230\347\232\204\350\212\261\345\220\215\345\206\214\345\222\214\344\277\241\346\201\257\344\277\256\346\224\271\357\274\214\n"
"\345\217\257\344\273\245\345\234\250\346\255\244\346\237\245\347\234\213\346\226\260\346\210\220\345\221\230\346\230\257\345\220\246\346\267\273\345\212\240\346\210\220\345\212\237\343\200\202\345\210\240\351\231\244\346\225\264\350\241\214\357\274\214\345\210\231\345\210\240\351\231\244\345\257\271\n"
"\345\272\224\346\210\220\345\221\230\343\200\202", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "2.\344\275\277\347\224\250\346\226\260\345\273\272\350\257\276\347\250\213\350\200\203\345\213\244\346\235\245\346\267\273\345\212\240\346\225\231\350\202\262\350\257\276\347\250\213\345\222\214\350\200\203\345\213\244\357\274\214\350\200\203\345\213\244\345\217\257\344\273\245\346\211\213\n"
"\345\267\245\344\271\237\345\217\257\344\273\245\344\272\272\350\204\270\350\257\206\345\210\253\346\267\273\345\212\240\343\200\202", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "3.\350\200\203\345\213\244\346\212\245\350\241\250\346\237\245\350\257\242\346\217\220\344\276\233\346\214\211\346\227\266\351\227\264\343\200\201\345\247\223\345\220\215\345\222\214\350\257\276\347\250\213\345\220\215\347\247\260\346\237\245\350\257\242\357\274\214\345\271\266\346\217\220\n"
"\344\276\233\350\241\245\350\257\276\347\255\211\346\223\215\344\275\234\343\200\202", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "4.\346\226\260\346\210\220\345\221\230\345\275\225\345\205\245\351\207\207\345\217\226\347\224\265\350\204\221\350\207\252\345\270\246\347\232\204\346\221\204\345\203\217\345\244\264\351\207\207\n"
"\351\233\206\344\272\272\350\204\270\344\277\241\346\201\257\357\274\214\350\213\245\350\246\201\346\216\245\345\244\226\350\256\276\346\221\204\345\203\217\345\244\264\357\274\214\350\257\267\n"
"\345\260\206\345\244\226\350\256\276\346\221\204\345\203\217\345\244\264\350\256\276\347\275\256\346\210\220\351\273\230\350\256\244\346\211\223\345\274\200\346\226\271\345\274\217\343\200\202", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "\345\270\256\345\212\251\344\277\241\346\201\257", Q_NULLPTR));
        commandLinkButton_4->setText(QApplication::translate("MainWindow", "\346\226\260\346\210\220\345\221\230\345\275\225\345\205\245", Q_NULLPTR));
        commandLinkButton_5->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272\347\263\273\347\273\237", Q_NULLPTR));
        commandLinkButton_10->setText(QApplication::translate("MainWindow", "\345\270\256\345\212\251", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
