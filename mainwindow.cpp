#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QAxObject>
#include <cv.h>
#include "highgui.h"
#include <QVariant.h>
#include <QTableWidget>
#include <QFileDialog>
#include <QDesktopServices>
#include <QMessageBox>
#include <QTextEdit>
#include <QTextStream>
#include <fstream>
#include <qiodevice.h>
#include <QFile>
#include <QTextCodec>
#include <QDebug>
#include <QVBoxLayout>
#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/face.hpp>
#include <opencv2/face/facerec.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <Qdir>
#include <QDateTime>
#include <windows.h>
#include <vector>

using namespace cv;
using namespace std;
using namespace face;
bool ifclick1=false;
bool ifclick2=false;

void Table2Excel(QTableWidget *table,QString title);
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(5);
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_commandLinkButton_clicked()
{
    QFile file( "partners.txt" );
    if ( file.exists())
    {
        if(!file.open(QIODevice::ReadOnly))
        {
            qDebug() << "partners.txt" << "该文件不能打开";
            return ;
        }
        QTextStream in(&file);
        QString All[100][3]={"\0"};
        int len_all=0;
        while(!in.atEnd())
        {
            QString line=in.readLine();
            QStringList LINE=line.split(' ');
            All[len_all][0]=LINE[0];
            All[len_all][1]=LINE[1];
            All[len_all][2]=LINE[2];
            len_all++;
        }
        //QString str = ui->tableWidget->item(0,0)->text();//获取表格内容
        //ui->tableWidget->setItem(24,2,new QTableWidgetItem(str));
        ui->stackedWidget->setCurrentIndex(0);
        ui->tableWidget->setRowCount(len_all);
        ui->tableWidget->setColumnCount(3);
        ui->tableWidget->setWindowTitle("QTableWidget & Item");
        ui->tableWidget->resize(701, 571);  //设置表格
        QStringList header;
        header<<"姓名"<<"职务"<<"党团员";   //表头
        ui->tableWidget->setHorizontalHeaderLabels(header);
        for (int i =0;i<len_all;i++)
        {
            ui->tableWidget->setItem(i,0,new QTableWidgetItem(All[i][0]));
            ui->tableWidget->setItem(i,1,new QTableWidgetItem(All[i][1]));
            ui->tableWidget->setItem(i,2,new QTableWidgetItem(All[i][2]));

        }
        ui->tableWidget->show();
        //QVBoxLayout *verticalLayout;
        //verticalLayout->addWidget(ui->tableWidget);
        //Table2Excel(ui->tableWidget,"年报表");
    }
    file.close();
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void MainWindow::on_commandLinkButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

}

void MainWindow::on_commandLinkButton_5_clicked()
{
    exit(0);
}

void MainWindow::on_commandLinkButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_commandLinkButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    ui->comboBox->setCurrentIndex(3);
    ui->comboBox_2->setCurrentIndex(13);
}

void MainWindow::on_commandLinkButton_10_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);

}
void MainWindow::Table2ExcelByTxt(QTableWidget *table)
{
    QString filepath = QFileDialog::getSaveFileName(this, tr("Save as..."),
                                                    QString(), tr("EXCEL files (*.xls *.xlsx);;HTML-Files (*.txt);;"));

    int row = table->rowCount();
    int col = table->columnCount();
    QList<QString> list;
    //添加列标题
    QString HeaderRow;
    for(int i=0;i<col;i++)
    {
        HeaderRow.append(table->horizontalHeaderItem(i)->text()+"\t");
    }
    list.push_back(HeaderRow);
    for(int i=0;i<row;i++)
    {
        QString rowStr = "";
        for(int j=0;j<col;j++){
            rowStr += table->item(i,j)->text() + "\t";
        }
        list.push_back(rowStr);
    }
    QTextEdit textEdit;
    for(int i=0;i<list.size();i++)
    {
        textEdit.append(list.at(i));
    }

    QFile file(filepath);
    if(file.open(QFile::WriteOnly | QIODevice::Text))
    {
        QTextStream ts(&file);
        ts.setCodec("UTF-8");
        ts<<textEdit.document()->toPlainText();
        file.close();
    }
}

void MainWindow::Table2Excel(QTableWidget *table,QString title)
{
    QString fileName = QFileDialog::getSaveFileName(table, "保存",
                                                    QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation),
                                                    "Excel 文件(*.xls *.xlsx)");
    if (fileName!="")
    {
        QAxObject *excel = new QAxObject;
        if (excel->setControl("Excel.Application")) //连接Excel控件
        {
            excel->dynamicCall("SetVisible (bool Visible)","false");//不显示窗体
            excel->setProperty("DisplayAlerts", false);//不显示任何警告信息。如果为true那么在关闭是会出现类似“文件已修改，是否保存”的提示
            QAxObject *workbooks = excel->querySubObject("WorkBooks");//获取工作簿集合
            workbooks->dynamicCall("Add");//新建一个工作簿
            QAxObject *workbook = excel->querySubObject("ActiveWorkBook");//获取当前工作簿
            QAxObject *worksheet = workbook->querySubObject("Worksheets(int)", 1);
            int i,j,colcount=table->columnCount();
            QAxObject *cell,*col;
            //标题行
            cell=worksheet->querySubObject("Cells(int,int)", 1, 1);
            cell->dynamicCall("SetValue(const QString&)", title);
            cell->querySubObject("Font")->setProperty("Size", 18);
            //调整行高
            worksheet->querySubObject("Range(const QString&)", "1:1")->setProperty("RowHeight", 30);
            //合并标题行
            QString cellTitle;
            cellTitle.append("A1:");
            cellTitle.append(QChar(colcount - 1 + 'A'));
            cellTitle.append(QString::number(1));
            QAxObject *range = worksheet->querySubObject("Range(const QString&)", cellTitle);
            range->setProperty("WrapText", true);
            range->setProperty("MergeCells", true);
            range->setProperty("HorizontalAlignment", -4108);//xlCenter
            range->setProperty("VerticalAlignment", -4108);//xlCenter
            //列标题
            for(i=0;i<colcount;i++)
            {
                QString columnName;
                columnName.append(QChar(i  + 'A'));
                columnName.append(":");
                columnName.append(QChar(i + 'A'));
                col = worksheet->querySubObject("Columns(const QString&)", columnName);
                col->setProperty("ColumnWidth", table->columnWidth(i)/6);
                cell=worksheet->querySubObject("Cells(int,int)", 2, i+1);
                columnName=table->horizontalHeaderItem(i)->text();
                cell->dynamicCall("SetValue(const QString&)", columnName);
                cell->querySubObject("Font")->setProperty("Bold", true);
                cell->querySubObject("Interior")->setProperty("Color",QColor(191, 191, 191));
                cell->setProperty("HorizontalAlignment", -4108);//xlCenter
                cell->setProperty("VerticalAlignment", -4108);//xlCenter
            }
            //数据区
            for(i=0;i<table->rowCount();i++){
                for (j=0;j<colcount;j++)
                {
                    worksheet->querySubObject("Cells(int,int)", i+3, j+1)->dynamicCall("SetValue(const QString&)", table->item(i,j)?table->item(i,j)->text():"");
                }
            }
            //画框线
            QString lrange;
            lrange.append("A2:");
            lrange.append(colcount - 1 + 'A');
            lrange.append(QString::number(table->rowCount() + 2));
            range = worksheet->querySubObject("Range(const QString&)", lrange);
            range->querySubObject("Borders")->setProperty("LineStyle", QString::number(1));
            range->querySubObject("Borders")->setProperty("Color", QColor(0, 0, 0));
            //调整数据区行高
            QString rowsName;
            rowsName.append("2:");
            rowsName.append(QString::number(table->rowCount() + 2));
            range = worksheet->querySubObject("Range(const QString&)", rowsName);
            range->setProperty("RowHeight", 20);
            workbook->dynamicCall("SaveAs(const QString&)",QDir::toNativeSeparators(fileName));//保存至fileName
            workbook->dynamicCall("Close()");//关闭工作簿
            excel->dynamicCall("Quit()");//关闭excel
            delete excel;
            excel=NULL;
            if (QMessageBox::question(NULL,"完成","文件已经导出，是否现在打开？",QMessageBox::Yes|QMessageBox::No)==QMessageBox::Yes)
            {
                QDesktopServices::openUrl(QUrl("file:///" + QDir::toNativeSeparators(fileName)));
            }
        }
        else
        {
            QMessageBox::warning(NULL,"错误","未能创建 Excel 对象，请安装 Microsoft Excel。",QMessageBox::Apply);
        }
    }
}

void MainWindow::on_commandLinkButton_15_clicked()
{
    ui->tableWidget->setEditTriggers(QAbstractItemView::AllEditTriggers);
}

void MainWindow::on_commandLinkButton_16_clicked()
{
    int length=ui->tableWidget->rowCount();
    int cow=length-1;
    while(ui->tableWidget->item(cow,0)->text().isEmpty()&&ui->tableWidget->item(cow,1)->text().isEmpty()&&ui->tableWidget->item(cow,2)->text().isEmpty())
    {
        cow--;
        if(cow==-1)
            break;
    }
    if(cow!=-1)
    {
        QFile file( "partners.txt" );
        if ( file.exists())
        {
            if(!file.open(QFile::WriteOnly | QIODevice::Truncate))
            {
                qDebug() << "partners.txt" << "该文件不能打开";
                return ;
            }
            QTextStream in(&file);
            for (int i = 0;i<cow ;i++)
            {
                QString str  = ui->tableWidget->item(i,0)->text();//获取表格内容
                QString str2 = ui->tableWidget->item(i,1)->text();//获取表格内容
                QString str3 = ui->tableWidget->item(i,2)->text();//获取表格内容
                if(str.isEmpty()&&str2.isEmpty()&&str3.isEmpty())
                {
                    continue;
                }
                else
                {
                    in<<str<<' '<<str2<<' '<<str3<<' '<<i<<"\n";
                }

            }
            QString str  = ui->tableWidget->item(cow,0)->text();//获取表格内容
            QString str2 = ui->tableWidget->item(cow,1)->text();//获取表格内容
            QString str3 = ui->tableWidget->item(cow,2)->text();//获取表格内容
            in<<str<<' '<<str2<<' '<<str3<<' '<<cow;

        }
        file.close();
    }
    else if(cow==-1)
    {
        QFile file("partners.txt");
        file.open(QFile::WriteOnly|QFile::Truncate);
        file.close();
    }
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void MainWindow::on_commandLinkButton_13_clicked()//人脸录入
{
    QString input1 = ui->lineEdit_2->text();
    QString input2 = ui->comboBox->currentText();
    QString input3 = ui->comboBox_2->currentText();
    if(input1.isEmpty()||input2.isEmpty()||input3.isEmpty())
    {
        QMessageBox::critical(0 , "Warning" , "请先输入完整信息！", QMessageBox::Ok | QMessageBox::Default , QMessageBox::Cancel | QMessageBox::Escape , 	0 );
    }
    else
    {
        CascadeClassifier faceCascade;
        VideoCapture capture(0);

        if(!capture.isOpened())
        {
            QMessageBox::critical(0 , "Warning" , "不能打开摄像头！", QMessageBox::Ok | QMessageBox::Default , QMessageBox::Cancel | QMessageBox::Escape , 0 );
        }
        else
        {
            if(!faceCascade.load("cascade/haarcascade_frontalface_alt.xml"))
            {
                //加载脸部分类器失败！
                QMessageBox::about(this,tr("提示信息"),tr("加载脸部分类器失败"));
                return;
            }
            QDir dir;

            VideoCapture cam(0);
            //namedWindow("window",WINDOW_OPENGL);
            namedWindow("window");
            //this->setWindowFlags(Qt::FramelessWindowHint);
            Mat frame;
            Mat imgGray;
            Mat facesROI;
            vector<Rect> faces;
            int countnum =0;
            //然后直接数据流
            int len_all=0;
            QFile Ha( "partners.txt" );
            if ( Ha.exists())
            {
                if(!Ha.open(QIODevice::ReadOnly))
                {
                    qDebug() << "partners.txt" << "该文件不能打开";
                    return ;
                }
                QTextStream in(&Ha);

                while(!in.atEnd())
                {
                    len_all++;
                    in.readLine();
                }
            }
            Ha.close();
            QString R = QString::number(len_all, 10);
            dir.cd("facelib");  //进入某文件夹
            if(!dir.exists(R))//判断需要创建的文件夹是否存在
            {
                dir.mkdir(R); //创建文件夹
            }

            while(true)
            {
                cam>>imgGray;
                cvtColor(imgGray, frame, CV_RGB2GRAY);
                faceCascade.detectMultiScale(frame,faces,1.1,2,0|CV_HAAR_SCALE_IMAGE,Size(60,60));
                for(size_t i=0;i<faces.size();++i)
                {
                    //绘制矩形 BGR。
                    rectangle(frame,faces[i],Scalar(0,0,255),1);
                    //截取人脸。
                    facesROI = frame(faces[i]);
                    //图像缩放。
                    cv::resize(facesROI,facesROI,Size(200,200),0,0,cv::INTER_LINEAR);
                    //保存图像。
                    string  str = "facelib/"+to_string(len_all)+format("/[%d].jpg",countnum);
                    imwrite(str,facesROI);
                    countnum++;
                    if(countnum==10)
                        break;
                }
                waitKey(300);
                imshow("window",frame);
                if(countnum==10)
                    break;
            }
            cvDestroyWindow("window");


            QFile file( "partners.txt" );
            if ( file.exists())
            {

                if(!file.open(QFile::WriteOnly | QIODevice::Append))
                {
                    qDebug() << "partners.txt" << "该文件不能打开";
                    QMessageBox::about(this,tr("提示信息"),tr("录入失败"));
                    return ;
                }
                QTextStream in(&file);
                if(len_all==0)
                    in<<input1<<' '<<input3<<' '<<input2<<' '<<len_all;
                else
                    in<<'\n'<<input1<<' '<<input3<<' '<<input2<<' '<<len_all;
                //Table2Excel(ui->tableWidget,"年报表");
                file.close();
                QMessageBox::about(this,tr("提示信息"),tr("录入成功"));
            }
        }
    }
}

void MainWindow::on_commandLinkButton_14_clicked()
{
    QString input1 = ui->lineEdit_2->text();
    QString input2 = ui->comboBox->currentText();
    QString input3 = ui->comboBox_2->currentText();
    if(input1.isEmpty()||input2.isEmpty()||input3.isEmpty())
    {
        QMessageBox::critical(0 , "Warning" , "请先输入完整信息！", QMessageBox::Ok | QMessageBox::Default , QMessageBox::Cancel | QMessageBox::Escape , 	0 );

    }
    else
    {
        int len_all=0;
        QFile Ha( "partners.txt" );
        if ( Ha.exists())
        {
            if(!Ha.open(QIODevice::ReadOnly))
            {
                qDebug() << "partners.txt" << "该文件不能打开";
                return ;
            }
            QTextStream in(&Ha);

            while(!in.atEnd())
            {
                len_all++;
                in.readLine();
            }
        }
        Ha.close();
        QFile file( "partners.txt" );
        if ( file.exists())
        {

            if(!file.open(QFile::WriteOnly | QIODevice::Append))
            {
                qDebug() << "partners.txt" << "该文件不能打开";
                QMessageBox::about(this,tr("提示信息"),tr("录入失败"));
                return ;
            }
            QTextStream in(&file);
            if(len_all==0)
                in<<input1<<' '<<input3<<' '<<input2<<' '<<len_all;
            else
                in<<'\n'<<input1<<' '<<input3<<' '<<input2<<' '<<len_all;
            //Table2Excel(ui->tableWidget,"年报表");
            file.close();
            QMessageBox::about(this,tr("提示信息"),tr("录入成功"));
        }

    }
}

void MainWindow::on_commandLinkButton_12_clicked()//手工录入
{
    QString co=ui->lineEdit->text();
    if(co.isEmpty())
    {
        QMessageBox::critical(0 , "Warning" , "请先输入课程名称！", QMessageBox::Ok | QMessageBox::Default , QMessageBox::Cancel | QMessageBox::Escape , 	0 );

    }
    else
    {
        QFile file( "partners.txt" );
        if ( file.exists())
        {
            if(!file.open(QIODevice::ReadOnly))
            {
                qDebug() << "partners.txt" << "该文件不能打开";
                return ;
            }
            QTextStream in(&file);
            QString All[100][3]={"\0"};
            int len_all=0;
            while(!in.atEnd())
            {
                QString line=in.readLine();
                QStringList LINE=line.split(' ');
                All[len_all][0]=LINE[0];
                len_all++;
            }
            //QString str = ui->tableWidget->item(0,0)->text();//获取表格内容
            //ui->tableWidget->setItem(24,2,new QTableWidgetItem(str));
            ui->tableWidget_2->setRowCount(len_all);
            ui->tableWidget_2->setColumnCount(2);
            ui->tableWidget_2->setWindowTitle("QTableWidget_2 & Item");
            ui->tableWidget_2->resize(531, 541);  //设置表格
            QStringList header;
            header<<"姓名"<<"考勤状态";   //表头
            ui->tableWidget_2->setHorizontalHeaderLabels(header);
            for (int i =0;i<len_all;i++)
            {
                ui->tableWidget_2->setItem(i,0,new QTableWidgetItem(All[i][0]));
                QTableWidgetItem *check=new QTableWidgetItem;
                check->setCheckState (Qt::Unchecked);
                ui->tableWidget_2->setItem(i,1,check); //插入复选框
            }
            ui->tableWidget_2->show();
            //QVBoxLayout *verticalLayout;
            //verticalLayout->addWidget(ui->tableWidget);
            //Table2Excel(ui->tableWidget,"年报表");
        }
        file.close();
    }
}

void MainWindow::on_commandLinkButton_11_clicked()//人脸识别
{
    QString co=ui->lineEdit->text();
    if(co.isEmpty())
    {
        QMessageBox::critical(0 , "Warning" , "请先输入课程名称！", QMessageBox::Ok | QMessageBox::Default , QMessageBox::Cancel | QMessageBox::Escape , 	0 );

    }
    else
    {
        QFile file( "partners.txt" );
        if ( file.exists())
        {
            if(!file.open(QIODevice::ReadOnly))
            {
                qDebug() << "partners.txt" << "该文件不能打开";
                return ;
            }
            QTextStream in(&file);
            QString All[100][3]={"\0"};
            int len_all=0;
            while(!in.atEnd())
            {
                QString line=in.readLine();
                QStringList LINE=line.split(' ');
                All[len_all][0]=LINE[0];
                len_all++;
            }
            //QString str = ui->tableWidget->item(0,0)->text();//获取表格内容
            //ui->tableWidget->setItem(24,2,new QTableWidgetItem(str));
            ui->tableWidget_2->setRowCount(len_all);
            ui->tableWidget_2->setColumnCount(2);
            ui->tableWidget_2->setWindowTitle("QTableWidget_2 & Item");
            ui->tableWidget_2->resize(531, 541);  //设置表格
            QStringList header;
            header<<"姓名"<<"识别结果";   //表头
            ui->tableWidget_2->setHorizontalHeaderLabels(header);
            for (int i =0;i<len_all;i++)
            {
                ui->tableWidget_2->setItem(i,0,new QTableWidgetItem(All[i][0]));
                QTableWidgetItem *check=new QTableWidgetItem;
                check->setCheckState (Qt::Unchecked);
                ui->tableWidget_2->setItem(i,1,check); //插入复选框
            }

            //QVBoxLayout *verticalLayout;
            //verticalLayout->addWidget(ui->tableWidget);
            //Table2Excel(ui->tableWidget,"年报表");
        }
        file.close();
        QDir Dir;
        Dir.cd("facelib");
        vector<int>labels;
        vector<Mat>images;
        QStringList number=Dir.entryList();
        for(int i=2;i<number.count();i++)
        {
            int label=number[i].toInt();
            for(int j=0;j<10;j++)
                labels.push_back(label);
            QDir d;
            d.cd("facelib/"+number[i]);
            QStringList pictures=d.entryList();
            for(int k=2;k<12;k++)
            {

                Mat a=imread("facelib/"+number[i].toStdString()+"/"+pictures[k].toStdString(),CV_LOAD_IMAGE_GRAYSCALE);
                images.push_back(a);
            }

        }
        Ptr<FaceRecognizer> modelPCA = createEigenFaceRecognizer();

        modelPCA->train(images,labels);
        //Mat a=imread("facelib/1/[1].jpg",CV_LOAD_IMAGE_GRAYSCALE);
        //Mat b=imread("lv[0].jpg",CV_LOAD_IMAGE_GRAYSCALE);
        //start
        CascadeClassifier faceCascade;
        if(!faceCascade.load("cascade/haarcascade_frontalface_alt.xml"))
        {
            //加载脸部分类器失败！
            QMessageBox::about(this,tr("提示信息"),tr("加载脸部分类器失败"));
            return;
        }
        VideoCapture cam(0);
        namedWindow("人脸录取中...");
        Mat frame;
        Mat imgGray;
        Mat facesROI;
        vector<Rect> faces;
        while(true)
        {
            cam>>imgGray;
            cvtColor(imgGray, frame, CV_RGB2GRAY);
            faceCascade.detectMultiScale(frame,faces,1.1,2,0|CV_HAAR_SCALE_IMAGE,Size(60,60));
            for(size_t i=0;i<faces.size();++i)
            {
                //绘制矩形 BGR。
                rectangle(frame,faces[i],Scalar(0,0,255),1);
                //截取人脸。
                facesROI = frame(faces[i]);
                //图像缩放。
                cv::resize(facesROI,facesROI,Size(200,200),0,0,cv::INTER_LINEAR);
                //保存图像。
                int predicted_label_PCA = -1;
                double predicted_confidence_PCA = 0.0;
                //Sleep(1000);
                modelPCA->predict(facesROI, predicted_label_PCA, predicted_confidence_PCA);

                if(predicted_label_PCA!=-1&&predicted_confidence_PCA<2000)//1000-10000
                {
                    QTableWidgetItem *check=new QTableWidgetItem;
                    check->setCheckState (Qt::Checked);
                    ui->tableWidget_2->setItem(predicted_label_PCA,1,check);
                    putText(frame,to_string(predicted_label_PCA+1), Point(faces[i].x, faces[i].y), FONT_HERSHEY_SIMPLEX, 1.5, Scalar(0, 0, 255), 2);
                }
            }
            char c=cvWaitKey(50);
            if(c==27)
            {
                cvDestroyAllWindows();
                break;
            }
            imshow("人脸录取中...",frame);
        }
        //end
        //->train(images,labels);
        //modelZFT->train(images,labels);
        //int label=modelPCA->predict(a);
        /*int label;
        double predicted_confidence_PCA;
        modelPCA->predict(a, label, predicted_confidence_PCA);
        if(-100<predicted_confidence_PCA&&predicted_confidence_PCA<100)
        {
            QTableWidgetItem *check=new QTableWidgetItem;
            check->setCheckState (Qt::Checked);
            ui->tableWidget_2->setItem(label,1,check);

        }*/
        ui->tableWidget_2->show();


    }
}

void MainWindow::on_commandLinkButton_9_clicked()//考勤确认按键
{
    QString co=ui->lineEdit->text();
    if(co.isEmpty())
    {
        QMessageBox::critical(0 , "Warning" , "请先输入课程名称！", QMessageBox::Ok | QMessageBox::Default , QMessageBox::Cancel | QMessageBox::Escape , 	0 );

    }
    else
    {
        QDateTime current_date_time =QDateTime::currentDateTime();
        QString current_date =current_date_time.toString("yyyyMMdd");
        int len_all=0;
        QFile file( "kaoqing.txt" );
        if ( file.exists())
        {
            if(!file.open(QIODevice::ReadOnly))
            {
                qDebug() << "partners.txt" << "该文件不能打开";
                return ;
            }
            QTextStream in(&file);
            while(!in.atEnd())
            {
                in.readLine();
                len_all++;
            }
            file.close();
        }
        QFile Oh( "kaoqing.txt" );
        int length;
        if(Oh.exists())
        {
            if(!Oh.open(QFile::WriteOnly | QIODevice::Append))
            {
                qDebug() << "kaoqing.txt" << "该文件不能打开";
                return ;
            }

            QTextStream in(&Oh);
            if(len_all==0)
            {
                in<<current_date<<'\n';
            }
            else
            {
                in<<'\n'<<current_date<<'\n';
            }
            in<<co<<'\n';
            length=ui->tableWidget_2->rowCount();
            for (int i = 0;i<length-1 ;i++)
            {
                QString str  = ui->tableWidget_2->item(i,0)->text();//获取表格内容
                if(ui->tableWidget_2->item(i,1)->checkState()==Qt::Checked)
                {
                    in<<str<<"YES";
                }
                else
                {
                    in<<str<<"NO";
                }
            }
            QString str  = ui->tableWidget_2->item(length-1,0)->text();//获取表格内容
            if(ui->tableWidget_2->item(length-1,1)->checkState()==Qt::Checked)
            {
                in<<str<<"YES";
            }
            else
            {
                in<<str<<"NO";
            }
        }
        Oh.close();
        QMessageBox::about(this,tr("提示信息"),tr("保存成功"));
        for(int j=0;j<length;j++)
        {
            ui->tableWidget_2->item(j,1)->setCheckState(Qt::Unchecked);
        }

    }


}

void MainWindow::on_commandLinkButton_6_clicked()//报表查询
{
    QStringList header;
    QFile file1( "partners.txt" );
    if ( file1.exists())
    {
        if(!file1.open(QIODevice::ReadOnly))
        {
            qDebug() << "partners.txt" << "该文件不能打开";
            return ;
        }
        QTextStream in(&file1);
        QString All[100][1]={"\0"};
        int len_all=0;
        while(!in.atEnd())
        {
            QString line=in.readLine();
            QStringList LINE=line.split(' ');
            All[len_all][0]=LINE[0];
            len_all++;
        }
        //QString str = ui->tableWidget->item(0,0)->text();//获取表格内容
        //ui->tableWidget->setItem(24,2,new QTableWidgetItem(str));
        ui->tableWidget_3->setRowCount(0);
        ui->tableWidget_3->setColumnCount(len_all+1);
        ui->tableWidget_3->setWindowTitle("QTableWidget_3 & Item");
        ui->tableWidget_3->resize(571, 651);  //设置表格
        header<<"课程\\姓名";   //表头
        for (int i =0;i<len_all;i++)
        {
            header<<All[i][0];
        }
        ui->tableWidget_3->setHorizontalHeaderLabels(header);
        ui->tableWidget_3->horizontalHeader()->setStyleSheet("QHeaderView::section{font:10pt '楷体';color: black;};");
        ui->tableWidget_3->horizontalHeader()->setStretchLastSection(true);
        ui->tableWidget_3->horizontalHeader()->setFixedHeight(30);
        for(int j=1;j<=len_all;j++)
        {
            ui->tableWidget_3->horizontalHeader()->resizeSection(j,60);
        }
    }
    file1.close();
    QFile file( "kaoqing.txt" );
    if ( file.exists())
    {
        if(!file.open(QIODevice::ReadOnly))
        {
            qDebug() << "partners.txt" << "该文件不能打开";
            return ;
        }
        QTextStream in(&file);
        QString Name;
        QString Time;
        int rowIndex;
        int len_all=0;
        while(!in.atEnd())
        {
            QString line=in.readLine();
            len_all++;
            if((len_all%3)==1)
            {
                rowIndex = ui->tableWidget_3->rowCount();
                ui->tableWidget_3->setRowCount(rowIndex + 1);//总行数增加1
                Time=line;
            }
            else if((len_all%3)==2)
            {
                Name=line;
            }
            else if((len_all%3)==0)
            {
                ui->tableWidget_3->setItem(rowIndex,0,new QTableWidgetItem(Time+"\n"+Name));
                for(int i=1;i<ui->tableWidget_3->columnCount();i++)
                {
                    int j=line.indexOf(header[i]+"YES");
                    if(j==-1)
                    {
                        QTableWidgetItem *check=new QTableWidgetItem;
                        check->setCheckState (Qt::Unchecked);
                        ui->tableWidget_3->setItem(rowIndex,i,new QTableWidgetItem("×")); //插入复选框
                        ui->tableWidget_3->item(rowIndex, i)->setTextAlignment(Qt::AlignCenter);
                    }
                    else
                    {
                        QTableWidgetItem *check=new QTableWidgetItem;
                        check->setCheckState (Qt::Checked);
                        ui->tableWidget_3->setItem(rowIndex,i,new QTableWidgetItem("√")); //插入复选框
                        ui->tableWidget_3->item(rowIndex, i)->setTextAlignment(Qt::AlignCenter);
                    }
                }
            }

        }
        ui->tableWidget_3->show();
    }
    file.close();
    //connect(ui->tableWidget_3->horizontalHeader(), SIGNAL(sectionClicked(int)), this, SLOT(sort(int)));
    ui->tableWidget_3->setEditTriggers(QAbstractItemView::NoEditTriggers);
}
/*void MainWindow::sort(int col)
{
    ui->tableWidget_3->sortItems(col, Qt::AscendingOrder);
}*/
void MainWindow::on_pushButton_2_clicked()//姓名查询
{
    QString strname=ui->lineEdit_3->text();
    bool ifexist=false;
    if(strname.isEmpty())
    {
        QMessageBox::critical(0 , "Warning" , "请先输入姓名！", QMessageBox::Ok | QMessageBox::Default , QMessageBox::Cancel | QMessageBox::Escape , 	0 );

    }
    else
    {
        QStringList header;
        QFile file1( "partners.txt" );
        if ( file1.exists())
        {
            if(!file1.open(QIODevice::ReadOnly))
            {
                qDebug() << "partners.txt" << "该文件不能打开";
                return ;
            }
            QTextStream in(&file1);
            QString All[100][1]={"\0"};
            int len_all=0;
            while(!in.atEnd())
            {
                QString line=in.readLine();
                QStringList LINE=line.split(' ');
                All[len_all][0]=LINE[0];
                if(strname==LINE[0])
                    ifexist=true;
                len_all++;
            }
            if(ifexist==false)
            {
                QMessageBox::critical(0 , "Warning" , "找不到对象！", QMessageBox::Ok | QMessageBox::Default , QMessageBox::Cancel | QMessageBox::Escape , 	0 );
                return;
            }
            //QString str = ui->tableWidget->item(0,0)->text();//获取表格内容
            //ui->tableWidget->setItem(24,2,new QTableWidgetItem(str));
            ui->tableWidget_3->setRowCount(0);
            ui->tableWidget_3->setColumnCount(2);
            ui->tableWidget_3->setWindowTitle("QTableWidget_3 & Item");
            ui->tableWidget_3->resize(571, 651);  //设置表格
            header<<"课程\\姓名"<<strname;   //表头

            ui->tableWidget_3->setHorizontalHeaderLabels(header);
            ui->tableWidget_3->horizontalHeader()->setStyleSheet("QHeaderView::section{font:10pt '楷体';color: black;};");
            ui->tableWidget_3->horizontalHeader()->setStretchLastSection(true);
            ui->tableWidget_3->horizontalHeader()->setFixedHeight(30);
            ui->tableWidget_3->horizontalHeader()->resizeSection(1,60);
        }
        file1.close();
        QFile file( "kaoqing.txt" );
        if ( file.exists())
        {
            if(!file.open(QIODevice::ReadOnly))
            {
                qDebug() << "partners.txt" << "该文件不能打开";
                return ;
            }
            QTextStream in(&file);
            QString Name;
            QString Time;
            int rowIndex;
            int len_all=0;
            while(!in.atEnd())
            {
                QString line=in.readLine();
                len_all++;
                if((len_all%3)==1)
                {
                    rowIndex = ui->tableWidget_3->rowCount();
                    ui->tableWidget_3->setRowCount(rowIndex + 1);//总行数增加1
                    Time=line;
                }
                else if((len_all%3)==2)
                {
                    Name=line;
                }
                else if((len_all%3)==0)
                {
                    ui->tableWidget_3->setItem(rowIndex,0,new QTableWidgetItem(Time+"\n"+Name));
                    int j=line.indexOf(strname+"YES");
                    if(j==-1)
                    {
                        QTableWidgetItem *check=new QTableWidgetItem;
                        check->setCheckState (Qt::Unchecked);
                        ui->tableWidget_3->setItem(rowIndex,1,new QTableWidgetItem("×")); //插入复选框
                        ui->tableWidget_3->item(rowIndex, 1)->setTextAlignment(Qt::AlignCenter);
                    }
                    else
                    {
                        QTableWidgetItem *check=new QTableWidgetItem;
                        check->setCheckState (Qt::Checked);
                        ui->tableWidget_3->setItem(rowIndex,1,new QTableWidgetItem("√")); //插入复选框
                        ui->tableWidget_3->item(rowIndex, 1)->setTextAlignment(Qt::AlignCenter);
                    }
                }

            }
            ui->tableWidget_3->show();
        }
        file.close();
        ui->tableWidget_3->setEditTriggers(QAbstractItemView::NoEditTriggers);
    }
}

void MainWindow::on_pushButton_3_clicked()//课程名称查询
{
    QString kechengname=ui->lineEdit_4->text();
    if(kechengname.isEmpty())
    {
        QMessageBox::critical(0 , "Warning" , "请先输入课程名！", QMessageBox::Ok | QMessageBox::Default , QMessageBox::Cancel | QMessageBox::Escape , 	0 );
        return;
    }
    QStringList header;
    QFile file1( "partners.txt" );
    bool ifE=false;
    QFile filee( "kaoqing.txt" );
    if ( filee.exists())
    {
        if(!filee.open(QIODevice::ReadOnly))
        {
            qDebug() << "partners.txt" << "该文件不能打开";
            return ;
        }
        QTextStream in(&filee);
        QString Name;
        int len_all=0;
        while(!in.atEnd())
        {
            QString line=in.readLine();
            len_all++;

            if((len_all%3)==2)
            {
                Name=line;
                if(kechengname==Name)
                    ifE=true;

            }
        }
        if(!ifE)
        {
            QMessageBox::critical(0 , "Warning" , "找不到对象！", QMessageBox::Ok | QMessageBox::Default , QMessageBox::Cancel | QMessageBox::Escape , 	0 );
            return;
        }
    }
    filee.close();
    ifE=false;
    if ( file1.exists())
    {
        if(!file1.open(QIODevice::ReadOnly))
        {
            qDebug() << "partners.txt" << "该文件不能打开";
            return ;
        }
        QTextStream in(&file1);
        QString All[100][1]={"\0"};
        int len_all=0;
        while(!in.atEnd())
        {
            QString line=in.readLine();
            QStringList LINE=line.split(' ');
            All[len_all][0]=LINE[0];
            len_all++;
        }
        //QString str = ui->tableWidget->item(0,0)->text();//获取表格内容
        //ui->tableWidget->setItem(24,2,new QTableWidgetItem(str));
        ui->tableWidget_3->setRowCount(0);
        ui->tableWidget_3->setColumnCount(len_all+1);
        ui->tableWidget_3->setWindowTitle("QTableWidget_3 & Item");
        ui->tableWidget_3->resize(571, 651);  //设置表格
        header<<"课程\\姓名";   //表头
        for (int i =0;i<len_all;i++)
        {
            header<<All[i][0];
        }
        ui->tableWidget_3->setHorizontalHeaderLabels(header);
        ui->tableWidget_3->horizontalHeader()->setStyleSheet("QHeaderView::section{font:10pt '楷体';color: black;};");
        ui->tableWidget_3->horizontalHeader()->setStretchLastSection(true);
        ui->tableWidget_3->horizontalHeader()->setFixedHeight(30);
        for(int j=1;j<=len_all;j++)
        {
            ui->tableWidget_3->horizontalHeader()->resizeSection(j,60);
        }
    }
    file1.close();
    QFile file( "kaoqing.txt" );
    if ( file.exists())
    {
        if(!file.open(QIODevice::ReadOnly))
        {
            qDebug() << "partners.txt" << "该文件不能打开";
            return ;
        }
        QTextStream in(&file);
        QString Name;
        QString Time;
        int rowIndex;
        int len_all=0;
        while(!in.atEnd())
        {
            QString line=in.readLine();
            len_all++;
            if((len_all%3)==1)
            {

                Time=line;
            }
            else if((len_all%3)==2)
            {
                Name=line;
                if(kechengname==Name)
                    ifE=true;

            }
            else if((len_all%3)==0&&ifE)
            {
                rowIndex = ui->tableWidget_3->rowCount();
                ui->tableWidget_3->setRowCount(rowIndex + 1);//总行数增加1
                ui->tableWidget_3->setItem(rowIndex,0,new QTableWidgetItem(Time+"\n"+Name));
                for(int i=1;i<ui->tableWidget_3->columnCount();i++)
                {
                    int j=line.indexOf(header[i]+"YES");
                    if(j==-1)
                    {
                        QTableWidgetItem *check=new QTableWidgetItem;
                        check->setCheckState (Qt::Unchecked);
                        ui->tableWidget_3->setItem(rowIndex,i,new QTableWidgetItem("×")); //插入复选框
                        ui->tableWidget_3->item(rowIndex, i)->setTextAlignment(Qt::AlignCenter);
                    }
                    else
                    {
                        QTableWidgetItem *check=new QTableWidgetItem;
                        check->setCheckState (Qt::Checked);
                        ui->tableWidget_3->setItem(rowIndex,i,new QTableWidgetItem("√")); //插入复选框
                        ui->tableWidget_3->item(rowIndex, i)->setTextAlignment(Qt::AlignCenter);
                    }
                }
                ifE=false;
            }

        }
        ui->tableWidget_3->show();
    }
    file.close();
    ui->tableWidget_3->setEditTriggers(QAbstractItemView::NoEditTriggers);

}

void MainWindow::on_pushButton_4_clicked()//日期查询
{
    QString time=ui->lineEdit_5->text();
    if(time.isEmpty())
    {
        QMessageBox::critical(0 , "Warning" , "请先输入日期！", QMessageBox::Ok | QMessageBox::Default , QMessageBox::Cancel | QMessageBox::Escape , 	0 );
        return;
    }
    QStringList header;
    QFile file1( "partners.txt" );
    bool ifE=false;
    QFile filee( "kaoqing.txt" );
    if ( filee.exists())
    {
        if(!filee.open(QIODevice::ReadOnly))
        {
            qDebug() << "partners.txt" << "该文件不能打开";
            return ;
        }
        QTextStream in(&filee);
        QString Name;
        int len_all=0;
        while(!in.atEnd())
        {
            QString line=in.readLine();
            len_all++;

            if((len_all%3)==1)
            {
                Name=line;
                if(time==Name)
                    ifE=true;

            }
        }
        if(!ifE)
        {
            QMessageBox::critical(0 , "Warning" , "找不到对象！", QMessageBox::Ok | QMessageBox::Default , QMessageBox::Cancel | QMessageBox::Escape , 	0 );
            return;
        }
    }
    filee.close();
    ifE=false;
    if ( file1.exists())
    {
        if(!file1.open(QIODevice::ReadOnly))
        {
            qDebug() << "partners.txt" << "该文件不能打开";
            return ;
        }
        QTextStream in(&file1);
        QString All[100][1]={"\0"};
        int len_all=0;
        while(!in.atEnd())
        {
            QString line=in.readLine();
            QStringList LINE=line.split(' ');
            All[len_all][0]=LINE[0];
            len_all++;
        }
        //QString str = ui->tableWidget->item(0,0)->text();//获取表格内容
        //ui->tableWidget->setItem(24,2,new QTableWidgetItem(str));
        ui->tableWidget_3->setRowCount(0);
        ui->tableWidget_3->setColumnCount(len_all+1);
        ui->tableWidget_3->setWindowTitle("QTableWidget_3 & Item");
        ui->tableWidget_3->resize(571, 651);  //设置表格
        header<<"课程\\姓名";   //表头
        for (int i =0;i<len_all;i++)
        {
            header<<All[i][0];
        }
        ui->tableWidget_3->setHorizontalHeaderLabels(header);
        ui->tableWidget_3->horizontalHeader()->setStyleSheet("QHeaderView::section{font:10pt '楷体';color: black;};");
        ui->tableWidget_3->horizontalHeader()->setStretchLastSection(true);
        ui->tableWidget_3->horizontalHeader()->setFixedHeight(30);
        for(int j=1;j<=len_all;j++)
        {
            ui->tableWidget_3->horizontalHeader()->resizeSection(j,60);
        }
    }
    file1.close();
    QFile file( "kaoqing.txt" );
    if ( file.exists())
    {
        if(!file.open(QIODevice::ReadOnly))
        {
            qDebug() << "partners.txt" << "该文件不能打开";
            return ;
        }
        QTextStream in(&file);
        QString Name;
        QString Time;
        int rowIndex;
        int len_all=0;
        while(!in.atEnd())
        {
            QString line=in.readLine();
            len_all++;
            if((len_all%3)==1)
            {

                Time=line;
                if(time==Time)
                    ifE=true;
            }
            else if((len_all%3)==2)
            {
                Name=line;


            }
            else if((len_all%3)==0&&ifE)
            {
                rowIndex = ui->tableWidget_3->rowCount();
                ui->tableWidget_3->setRowCount(rowIndex + 1);//总行数增加1
                ui->tableWidget_3->setItem(rowIndex,0,new QTableWidgetItem(Time+"\n"+Name));
                for(int i=1;i<ui->tableWidget_3->columnCount();i++)
                {
                    int j=line.indexOf(header[i]+"YES");
                    if(j==-1)
                    {
                        QTableWidgetItem *check=new QTableWidgetItem;
                        check->setCheckState (Qt::Unchecked);
                        ui->tableWidget_3->setItem(rowIndex,i,new QTableWidgetItem("×")); //插入复选框
                        ui->tableWidget_3->item(rowIndex, i)->setTextAlignment(Qt::AlignCenter);
                    }
                    else
                    {
                        QTableWidgetItem *check=new QTableWidgetItem;
                        check->setCheckState (Qt::Checked);
                        ui->tableWidget_3->setItem(rowIndex,i,new QTableWidgetItem("√")); //插入复选框
                        ui->tableWidget_3->item(rowIndex, i)->setTextAlignment(Qt::AlignCenter);
                    }
                }
                ifE=false;
            }

        }
        ui->tableWidget_3->show();
    }
    file.close();
    ui->tableWidget_3->setEditTriggers(QAbstractItemView::NoEditTriggers);
}


void MainWindow::on_commandLinkButton_7_clicked()//手动补录
{
    ifclick1=true;
    ifclick2=false;
    QStringList header;
    QFile file1( "partners.txt" );
    if ( file1.exists())
    {
        if(!file1.open(QIODevice::ReadOnly))
        {
            qDebug() << "partners.txt" << "该文件不能打开";
            return ;
        }
        QTextStream in(&file1);
        QString All[100][1]={"\0"};
        int len_all=0;
        while(!in.atEnd())
        {
            QString line=in.readLine();
            QStringList LINE=line.split(' ');
            All[len_all][0]=LINE[0];
            len_all++;
        }
        //QString str = ui->tableWidget->item(0,0)->text();//获取表格内容
        //ui->tableWidget->setItem(24,2,new QTableWidgetItem(str));
        ui->tableWidget_3->setRowCount(0);
        ui->tableWidget_3->setColumnCount(len_all+1);
        ui->tableWidget_3->setWindowTitle("QTableWidget_3 & Item");
        ui->tableWidget_3->resize(571, 651);  //设置表格
        header<<"课程\\姓名";   //表头
        for (int i =0;i<len_all;i++)
        {
            header<<All[i][0];
        }
        ui->tableWidget_3->setHorizontalHeaderLabels(header);
        ui->tableWidget_3->horizontalHeader()->setStyleSheet("QHeaderView::section{font:10pt '楷体';color: black;};");
        ui->tableWidget_3->horizontalHeader()->setStretchLastSection(true);
        ui->tableWidget_3->horizontalHeader()->setFixedHeight(30);
        for(int j=1;j<=len_all;j++)
        {
            ui->tableWidget_3->horizontalHeader()->resizeSection(j,60);
        }
    }
    file1.close();
    QFile file( "kaoqing.txt" );
    if ( file.exists())
    {
        if(!file.open(QIODevice::ReadOnly))
        {
            qDebug() << "partners.txt" << "该文件不能打开";
            return ;
        }
        QTextStream in(&file);
        QString Name;
        QString Time;
        int rowIndex;
        int len_all=0;
        while(!in.atEnd())
        {
            QString line=in.readLine();
            len_all++;
            if((len_all%3)==1)
            {
                rowIndex = ui->tableWidget_3->rowCount();
                ui->tableWidget_3->setRowCount(rowIndex + 1);//总行数增加1
                Time=line;
            }
            else if((len_all%3)==2)
            {
                Name=line;
            }
            else if((len_all%3)==0)
            {
                ui->tableWidget_3->setItem(rowIndex,0,new QTableWidgetItem(Time+"\n"+Name));
                for(int i=1;i<ui->tableWidget_3->columnCount();i++)
                {
                    int j=line.indexOf(header[i]+"YES");
                    if(j==-1)
                    {
                        QTableWidgetItem *check=new QTableWidgetItem;
                        check->setCheckState (Qt::Unchecked);
                        ui->tableWidget_3->setItem(rowIndex,i,new QTableWidgetItem("×")); //插入复选框
                        ui->tableWidget_3->item(rowIndex, i)->setTextAlignment(Qt::AlignCenter);
                    }
                    else
                    {
                        QTableWidgetItem *check=new QTableWidgetItem;
                        check->setCheckState (Qt::Checked);
                        ui->tableWidget_3->setItem(rowIndex,i,new QTableWidgetItem("√")); //插入复选框
                        ui->tableWidget_3->item(rowIndex, i)->setTextAlignment(Qt::AlignCenter);
                    }
                }
            }

        }
        ui->tableWidget_3->show();
    }
    file.close();
    //connect(ui->tableWidget_3->horizontalHeader(), SIGNAL(sectionClicked(int)), this, SLOT(sort(int)));
    ui->tableWidget_3->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->tableWidget_3->setEditTriggers(QAbstractItemView::AllEditTriggers);
    int row=ui->tableWidget_3->rowCount();
    int column=ui->tableWidget_3->columnCount();
    for(int i=0;i<row;i++)
    {
        ui->tableWidget_3->item(i,0)->setFlags(Qt::NoItemFlags);
        // ui->tableWidget_3->item(i,0)->setBackgroundColor("green");
        for(int j=1;j<column;j++)
        {
            QComboBox *comBox = new QComboBox();
            if(ui->tableWidget_3->item(i,j)->text()=="×")
            {
                comBox->addItem("×");
                comBox->addItem("√");
                ui->tableWidget_3->setCellWidget(i,j,comBox);
                //ui->tableWidget_3->setItem(i,j,new QTableWidgetItem("×"));
            }
            else if(ui->tableWidget_3->item(i,j)->text()=="√")
            {
                comBox->addItem("√");
                comBox->addItem("×");
                ui->tableWidget_3->setCellWidget(i,j,comBox);
                //ui->tableWidget_3->setItem(i,j,new QTableWidgetItem("×"));
            }

        }
    }


}

void MainWindow::on_pushButton_clicked()//手动补录完成
{
    if(!ifclick1)
    {
        return;
    }
    QStringList comp;
    QStringList comp2;
    int len_all=0;
    int row=ui->tableWidget_3->rowCount();
    int column=ui->tableWidget_3->columnCount();

    QFile file( "kaoqing.txt" );
    if ( file.exists())
    {
        if(!file.open(QIODevice::ReadOnly))
        {
            qDebug() << "partners.txt" << "该文件不能打开";
            return ;
        }
        QTextStream in(&file);
        while(!in.atEnd())
        {
            comp<<in.readLine();
            len_all++;
        }
        file.close();
    }//将文件内容读入缓存comp
    for(int i=0;i<comp.count()/3;i++)
    {
        comp2<<comp[i*3+0]+"\n"+comp[i*3+1];
        comp2<<comp[i*3+2];
    }//success
    for(int i=0;i<row;i++)
    {
        QString kechen=ui->tableWidget_3->item(i,0)->text();
        int index=comp2.indexOf(kechen);//定位到需要改变的考勤人员前一行
        QString haha=comp2[index+1];//初始化
        for(int j=1;j<column;j++)
        {
            QString replace=NULL;
            QTableWidgetItem *check=new QTableWidgetItem;
            check=ui->tableWidget_3->horizontalHeaderItem(j);//获取表头元素
            QString name=check->text();
            QString kaoqing;
            QWidget * widget=ui->tableWidget_3->cellWidget(i,j);//获得widget
            QComboBox *combox=(QComboBox*)widget;//强制转化为QComboBox
            kaoqing= combox->currentText();
            //qDebug()<<string;
            if(kaoqing=="√")
            {
                replace=name+"NO";
                int id=haha.indexOf(replace);
                if(id!=-1)
                {
                    haha.replace(id+name.length(),2,"YES");
                }

            }
            else if(kaoqing=="×")
            {
                replace=name+"YES";
                int id=haha.indexOf(replace);
                if(id!=-1)
                {
                    haha.replace(id+name.length(),3,"NO");
                }

            }
        }
        comp2[index+1]=haha;
    }

    QFile Oh( "kaoqing.txt" );
    if(Oh.exists())
    {
        if(!Oh.open(QFile::WriteOnly | QIODevice::Truncate))
        {
            qDebug() << "kaoqing.txt" << "该文件不能打开";
            return ;
        }
        QTextStream in(&Oh);
        for(int i=0;i<comp2.count()-1;i++)
        {
            if(i%2==0)
            {
                in<<comp2[i]<<"\n";
            }
            else if(i%2==1)
            {
                in<<comp2[i]<<"\n";
            }
        }
        in<<comp2[comp2.count()-1];

    }
    Oh.close();
    QMessageBox::about(this,tr("提示信息"),tr("保存成功"));
    ui->tableWidget_3->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void MainWindow::on_commandLinkButton_8_clicked()//人脸补录
{
    ifclick2=true;
    ifclick1=false;
    QStringList header;
    QFile file1( "partners.txt" );
    if ( file1.exists())
    {
        if(!file1.open(QIODevice::ReadOnly))
        {
            qDebug() << "partners.txt" << "该文件不能打开";
            return ;
        }
        QTextStream in(&file1);
        QString All[100][1]={"\0"};
        int len_all=0;
        while(!in.atEnd())
        {
            QString line=in.readLine();
            QStringList LINE=line.split(' ');
            All[len_all][0]=LINE[0];
            len_all++;
        }
        //QString str = ui->tableWidget->item(0,0)->text();//获取表格内容
        //ui->tableWidget->setItem(24,2,new QTableWidgetItem(str));
        ui->tableWidget_3->setRowCount(0);
        ui->tableWidget_3->setColumnCount(len_all+1);
        ui->tableWidget_3->setWindowTitle("QTableWidget_3 & Item");
        ui->tableWidget_3->resize(571, 651);  //设置表格
        header<<"课程\\姓名";   //表头
        for (int i =0;i<len_all;i++)
        {
            header<<All[i][0];
        }
        ui->tableWidget_3->setHorizontalHeaderLabels(header);
        ui->tableWidget_3->horizontalHeader()->setStyleSheet("QHeaderView::section{font:10pt '楷体';color: black;};");
        ui->tableWidget_3->horizontalHeader()->setStretchLastSection(true);
        ui->tableWidget_3->horizontalHeader()->setFixedHeight(30);
        for(int j=1;j<=len_all;j++)
        {
            ui->tableWidget_3->horizontalHeader()->resizeSection(j,60);
        }
    }
    file1.close();
    QFile file( "kaoqing.txt" );
    if ( file.exists())
    {
        if(!file.open(QIODevice::ReadOnly))
        {
            qDebug() << "kaoqing.txt" << "该文件不能打开";
            return ;
        }
        QTextStream in(&file);
        QString Name;
        QString Time;
        int rowIndex;
        int len_all=0;
        while(!in.atEnd())
        {
            QString line=in.readLine();
            len_all++;
            if((len_all%3)==1)
            {
                rowIndex = ui->tableWidget_3->rowCount();
                ui->tableWidget_3->setRowCount(rowIndex + 1);//总行数增加1
                Time=line;
            }
            else if((len_all%3)==2)
            {
                Name=line;
            }
            else if((len_all%3)==0)
            {
                QPushButton *pBtn = new QPushButton();
                connect(pBtn, SIGNAL(clicked()), this, SLOT(OnBtnClicked()));
                pBtn->setText(Time+"\n"+Name);
                ui->tableWidget_3->setCellWidget(rowIndex,0,pBtn);
                for(int i=1;i<ui->tableWidget_3->columnCount();i++)
                {
                    int j=line.indexOf(header[i]+"YES");
                    if(j==-1)
                    {
                        QTableWidgetItem *check=new QTableWidgetItem;
                        check->setCheckState (Qt::Unchecked);
                        ui->tableWidget_3->setItem(rowIndex,i,new QTableWidgetItem("×")); //插入复选框
                        ui->tableWidget_3->item(rowIndex, i)->setTextAlignment(Qt::AlignCenter);
                    }
                    else
                    {
                        QTableWidgetItem *check=new QTableWidgetItem;
                        check->setCheckState (Qt::Checked);
                        ui->tableWidget_3->setItem(rowIndex,i,new QTableWidgetItem("√")); //插入复选框
                        ui->tableWidget_3->item(rowIndex, i)->setTextAlignment(Qt::AlignCenter);
                    }
                }
            }

        }
        ui->tableWidget_3->show();
    }
    file.close();
    ui->tableWidget_3->setEditTriggers(QAbstractItemView::NoEditTriggers);

}
void MainWindow::OnBtnClicked(void)
{

    QPushButton *senderObj=qobject_cast<QPushButton*>(sender());
    if(senderObj == nullptr)
    {
        return;
    }
    QModelIndex idx=ui->tableWidget_3->indexAt(QPoint(senderObj->frameGeometry().x(),senderObj->frameGeometry().y()));
    int rowIndex=idx.row();
    // 其他响应信息......

    QDir Dir;
    Dir.cd("facelib");
    vector<int>labels;
    vector<Mat>images;
    Mat frame;
    Mat imgGray;
    Mat facesROI;
    vector<Rect> faces;
    QStringList number=Dir.entryList();
    for(int i=2;i<number.count();i++)
    {
        int label=number[i].toInt();
        for(int j=0;j<10;j++)
            labels.push_back(label);
        QDir d;
        d.cd("facelib\\"+number[i]);
        QStringList pictures=d.entryList();
        for(int k=2;k<12;k++)
        {

            Mat a=imread("facelib\\"+number[i].toStdString()+"\\"+pictures[k].toStdString(),CV_RGB2GRAY);
            images.push_back(a);
        }

    }
    Ptr<FaceRecognizer> modelPCA = createEigenFaceRecognizer();
    modelPCA->train(images,labels);
    CascadeClassifier faceCascade;
    if(!faceCascade.load("cascade\\haarcascade_frontalface_alt.xml"))
    {
        QMessageBox::about(this,tr("提示信息"),tr("加载脸部分类器失败"));
        return;
    }
    VideoCapture cam(0);
    namedWindow("adding...",WINDOW_AUTOSIZE);

    while(true)
    {
        cam>>imgGray;
        cvtColor(imgGray, frame, CV_RGB2GRAY);
        faceCascade.detectMultiScale(frame,faces,1.1,2,0|CV_HAAR_SCALE_IMAGE,Size(60,60));
        for(size_t i=0;i<faces.size();++i)
        {
            //绘制矩形 BGR。
            rectangle(frame,faces[i],Scalar(0,0,255),1);
            //截取人脸。
            facesROI = frame(faces[i]);
            //图像缩放。
            cv::resize(facesROI,facesROI,Size(200,200),0,0,cv::INTER_LINEAR);
            //保存图像。
            int predicted_label_PCA = -1;
            double predicted_confidence_PCA = 0.0;
            //Sleep(1000);
            modelPCA->predict(facesROI, predicted_label_PCA, predicted_confidence_PCA);

            if(predicted_label_PCA!=-1&&predicted_confidence_PCA<2000)//1000-10000
            {
                ui->tableWidget_3->setItem(rowIndex,predicted_label_PCA+1,new QTableWidgetItem("√"));
                ui->tableWidget_3->item(rowIndex, predicted_label_PCA+1)->setTextAlignment(Qt::AlignCenter);
                putText(frame,to_string(predicted_label_PCA+1), Point(faces[i].x, faces[i].y), FONT_HERSHEY_SIMPLEX, 1.5, Scalar(0, 0, 255), 2);
            }
        }
        char c=cvWaitKey(50);
        if(c==27)
        {
            cvDestroyAllWindows();
            break;
        }
        imshow("adding...",frame);
    }

}

void MainWindow::on_pushButton_5_clicked()//人脸补录完成
{
    if(!ifclick2)
    {
        return;
    }
    QStringList comp;
    QStringList comp2;
    int len_all=0;
    int row=ui->tableWidget_3->rowCount();
    int column=ui->tableWidget_3->columnCount();

    QFile file( "kaoqing.txt" );
    if ( file.exists())
    {
        if(!file.open(QIODevice::ReadOnly))
        {
            qDebug() << "partners.txt" << "该文件不能打开";
            return ;
        }
        QTextStream in(&file);
        while(!in.atEnd())
        {
            comp<<in.readLine();
            len_all++;
        }
        file.close();
    }//将文件内容读入缓存comp
    for(int i=0;i<comp.count()/3;i++)
    {
        comp2<<comp[i*3+0]+"\n"+comp[i*3+1];
        comp2<<comp[i*3+2];
    }//success
    for(int i=0;i<row;i++)
    {
        QWidget * widget=ui->tableWidget_3->cellWidget(i,0);//获得widget
        QPushButton *combox=(QPushButton*)widget;//强制转化为QComboBox
        QString kechen=combox->text();
        int index=comp2.indexOf(kechen);//定位到需要改变的考勤人员前一行
        QString haha=comp2[index+1];//初始化
        for(int j=1;j<column;j++)
        {
            QString replace=NULL;
            QTableWidgetItem *check=new QTableWidgetItem;
            check=ui->tableWidget_3->horizontalHeaderItem(j);//获取表头元素
            QString name=check->text();
            QString kaoqing;
           //获得widget
            kaoqing=ui->tableWidget_3->item(i,j)->text();
            //qDebug()<<string;
            if(kaoqing=="√")
            {
                replace=name+"NO";
                int id=haha.indexOf(replace);
                if(id!=-1)
                {
                    haha.replace(id+name.length(),2,"YES");
                }

            }
            else if(kaoqing=="×")
            {
                replace=name+"YES";
                int id=haha.indexOf(replace);
                if(id!=-1)
                {
                    haha.replace(id+name.length(),3,"NO");
                }

            }
        }
        comp2[index+1]=haha;
    }

    QFile Oh( "kaoqing.txt" );
    if(Oh.exists())
    {
        if(!Oh.open(QFile::WriteOnly | QIODevice::Truncate))
        {
            qDebug() << "kaoqing.txt" << "该文件不能打开";
            return ;
        }
        QTextStream in(&Oh);
        for(int i=0;i<comp2.count()-1;i++)
        {
            if(i%2==0)
            {
                in<<comp2[i]<<"\n";
            }
            else if(i%2==1)
            {
                in<<comp2[i]<<"\n";
            }
        }
        in<<comp2[comp2.count()-1];

    }
    Oh.close();
    QMessageBox::about(this,tr("提示信息"),tr("保存成功"));
    ui->tableWidget_3->setEditTriggers(QAbstractItemView::NoEditTriggers);
}
