#ifndef LOGINDLG_H
#define LOGINDLG_H

#include <QDialog>

namespace Ui {
class loginDlg;
}

class loginDlg : public QDialog
{
    Q_OBJECT
    
public:
    explicit loginDlg(QWidget *parent = 0);
    ~loginDlg();
    
private slots:

    void on_commandLinkButton_clicked();

    void on_commandLinkButton_2_clicked();

private:
    Ui::loginDlg *ui;
};

#endif // LOGINDLG_H
