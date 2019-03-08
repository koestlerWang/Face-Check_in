/********************************************************************************
** Form generated from reading UI file 'logindlg.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDLG_H
#define UI_LOGINDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_loginDlg
{
public:
    QLineEdit *userLineEdit;
    QLineEdit *pwdLineEdit;
    QLabel *label_3;
    QLabel *label_4;
    QCommandLinkButton *commandLinkButton;
    QCommandLinkButton *commandLinkButton_2;
    QGraphicsView *graphicsView;
    QGraphicsView *graphicsView_2;

    void setupUi(QDialog *loginDlg)
    {
        if (loginDlg->objectName().isEmpty())
            loginDlg->setObjectName(QStringLiteral("loginDlg"));
        loginDlg->resize(943, 662);
        QIcon icon;
        icon.addFile(QStringLiteral(":/iamges/san2.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        loginDlg->setWindowIcon(icon);
        loginDlg->setStyleSheet(QStringLiteral("#loginDlg{background-image: url(:/iamges/BA.jpg);}"));
        userLineEdit = new QLineEdit(loginDlg);
        userLineEdit->setObjectName(QStringLiteral("userLineEdit"));
        userLineEdit->setGeometry(QRect(230, 210, 221, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font.setPointSize(15);
        userLineEdit->setFont(font);
        pwdLineEdit = new QLineEdit(loginDlg);
        pwdLineEdit->setObjectName(QStringLiteral("pwdLineEdit"));
        pwdLineEdit->setGeometry(QRect(230, 280, 221, 41));
        pwdLineEdit->setFont(font);
        label_3 = new QLabel(loginDlg);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(210, 80, 381, 44));
        label_3->setStyleSheet(QString::fromUtf8("font: 25pt \"\345\215\216\346\226\207\350\241\214\346\245\267\";"));
        label_4 = new QLabel(loginDlg);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(820, 640, 111, 20));
        commandLinkButton = new QCommandLinkButton(loginDlg);
        commandLinkButton->setObjectName(QStringLiteral("commandLinkButton"));
        commandLinkButton->setGeometry(QRect(160, 420, 131, 61));
        commandLinkButton->setStyleSheet(QString::fromUtf8("font: 20pt \"\345\215\216\346\226\207\346\245\267\344\275\223\";"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/iamges/login.png"), QSize(), QIcon::Normal, QIcon::Off);
        commandLinkButton->setIcon(icon1);
        commandLinkButton->setIconSize(QSize(50, 40));
        commandLinkButton_2 = new QCommandLinkButton(loginDlg);
        commandLinkButton_2->setObjectName(QStringLiteral("commandLinkButton_2"));
        commandLinkButton_2->setGeometry(QRect(360, 420, 121, 61));
        commandLinkButton_2->setStyleSheet(QString::fromUtf8("font: 20pt \"\345\215\216\346\226\207\346\245\267\344\275\223\";"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/iamges/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        commandLinkButton_2->setIcon(icon2);
        commandLinkButton_2->setIconSize(QSize(50, 40));
        graphicsView = new QGraphicsView(loginDlg);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(180, 210, 41, 41));
        graphicsView->setStyleSheet(QStringLiteral("border-image: url(:/iamges/head.png);"));
        graphicsView_2 = new QGraphicsView(loginDlg);
        graphicsView_2->setObjectName(QStringLiteral("graphicsView_2"));
        graphicsView_2->setGeometry(QRect(180, 280, 41, 41));
        graphicsView_2->setStyleSheet(QStringLiteral("border-image: url(:/iamges/pass.png);"));

        retranslateUi(loginDlg);

        QMetaObject::connectSlotsByName(loginDlg);
    } // setupUi

    void retranslateUi(QDialog *loginDlg)
    {
        loginDlg->setWindowTitle(QApplication::translate("loginDlg", "welcome", Q_NULLPTR));
        label_3->setText(QApplication::translate("loginDlg", "\347\224\265\345\255\220\346\265\213\351\207\217\347\253\231\350\200\203\345\213\244\347\263\273\347\273\237", Q_NULLPTR));
        label_4->setText(QApplication::translate("loginDlg", "copyright@2018", Q_NULLPTR));
        commandLinkButton->setText(QApplication::translate("loginDlg", "\347\231\273\345\275\225", Q_NULLPTR));
        commandLinkButton_2->setText(QApplication::translate("loginDlg", "\351\200\200\345\207\272", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class loginDlg: public Ui_loginDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDLG_H
