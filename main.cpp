#include <QApplication>
#include "logindlg.h"
#include "mainwindow.h"
#include <QAxObject>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow H;
    loginDlg login;
    if(login.exec()==QDialog::Accepted)
    {
        H.show();
        return a.exec();
    }
    else
        return 0;

}
