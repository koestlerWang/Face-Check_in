#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <QFileDialog>
#include <QDesktopServices>
#include <QMessageBox>
#include <QAxObject>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_commandLinkButton_clicked();

    void on_commandLinkButton_2_clicked();

    void on_commandLinkButton_5_clicked();

    void on_commandLinkButton_3_clicked();

    void on_commandLinkButton_4_clicked();

    void on_commandLinkButton_10_clicked();

    void Table2ExcelByTxt(QTableWidget *table);

    void Table2Excel(QTableWidget *table,QString title);

    void on_commandLinkButton_15_clicked();

    void on_commandLinkButton_16_clicked();

    void on_commandLinkButton_13_clicked();

    void on_commandLinkButton_14_clicked();

    void on_commandLinkButton_12_clicked();

    void on_commandLinkButton_11_clicked();

    void on_commandLinkButton_9_clicked();

    void on_commandLinkButton_6_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

   // void on_commandLinkButton_7_clicked();

    void on_commandLinkButton_7_clicked();

    void on_pushButton_clicked();

    void on_commandLinkButton_8_clicked();
    void OnBtnClicked();

    void on_pushButton_5_clicked();

private:
    Ui::MainWindow *ui;


};

#endif // MAINWINDOW_H
