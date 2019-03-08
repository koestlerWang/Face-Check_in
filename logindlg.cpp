#include "logindlg.h"
#include "ui_logindlg.h"
#include <QtGui>
#include<QMessageBox>
loginDlg::loginDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loginDlg)
{
    ui->setupUi(this);
    ui->pwdLineEdit->setEchoMode(QLineEdit::Password);
}

loginDlg::~loginDlg()
{
    delete ui;
}

void loginDlg::on_commandLinkButton_clicked()
{
    if(ui->userLineEdit->text().trimmed()==tr("dzclz")&&ui->pwdLineEdit->text()==tr("123456")) //判断用户名和密码是否正确
        accept();
    else
    {
        QMessageBox::warning(this,tr("Warning"),tr("user name or password error!"),QMessageBox::Yes); //如果不正确，弹出警告对话框
        ui->userLineEdit->clear();//清空用户名输入框
        ui->pwdLineEdit->clear();//清空密码输入框
        ui->userLineEdit->setFocus();//将光标转到用户名输入框
    }
}

void loginDlg::on_commandLinkButton_2_clicked()
{
     exit(0);
}
