#include "mainwindow.h"
#include "class.h"
#include "ui_mainwindow.h"
#include <QTextStream>
#include <QFile>

void pushFile(List ls);
List pullFile();

List list1;
//void Start(worker *&w3, worker *&w4,  worker *&w5,  worker *&w6)
//{
////    worker *w3, *w4, *w5, *w6;
//    doctor b1, b2, b3;
//    receptionist a1;
//    list1.push_back(w3);
//    list1.push_back(w4);
//    list1.push_back(w5);
//    list1.push_back(w6);
//}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow)
{

//    worker *w3, *w4, *w5, *w6;

//    doctor b1, b2, b3;
//    receptionist a1;
//    w3 = &a1;
//    w4 = &b1;
//    w5 = &b2;
//    w6 = &b3;
//        Start(w3, w4, w5, w6);
//    list1.push_back(w3);
//    list1.push_back(w4);
//    list1.push_back(w5);
//    list1.push_back(w6);
    QFile file("kurs.txt");
    ui->setupUi(this);
    ui->groupBox->hide();
    ui->Aceppt->hide();
    ui->tableWidget->setRowCount(list1.GetSize());
    ui->tableWidget->setColumnCount(6);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Full Name" << "cabinet/window" <<"working time" << "speciality" << "telephone" << "salaru");
    List list2;
    for (int i = 0; i< list1.GetSize(); i++)
        list2.push_back(list1[i]);
    for(int j =0; j < list2.GetSize(); j++ )
    {
    list2[j]->show(ui->tableWidget, j);
            qDebug()<<"жэпа";
    }


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ShowTable_clicked()
{
    qDebug()<<"хуй тебе";
        List list2 = pullFile();
    qDebug() << list2.GetSize();
    ui->tableWidget->setRowCount(list2.GetSize());
    ui->tableWidget->setColumnCount(6);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Full Name" << "cabinet/window" <<"working time" << "speciality" << "telephone" << "salaru");
//    List list2 = pullFile();
    for(int j =0; j < list2.GetSize(); j++ )
    {
    qDebug()<<"жэпа";
    list2[j]->show(MainWindow::ui->tableWidget, j);
    }
}
List pullFile()
{

    QFile file("C:\\oop\\kurs\\kurs\\kurs.txt");
    if((file.exists())&&file.open(QIODevice::ReadOnly))
    {
        List ls;
        qDebug()<<"открылся для чтения";
        while(!file.atEnd())
        {
            QString addFullName, addCabinet, addWorkingTime, addSpeciality, addTelephone, addsalaru;
            addFullName = file.readLine();
            addCabinet = file.readLine();
            addWorkingTime = file.readLine();
            addSpeciality = file.readLine();
            addTelephone = file.readLine();
            addsalaru =file.readLine();
            doctor doc(addFullName, addCabinet, addWorkingTime, addSpeciality, addTelephone, addsalaru);
            worker *p = &doc;
            ls.push_back(p);
        }
        return ls;
    }
}
void MainWindow :: on_addButton_clicked()
{
//    qDebug()<<"хуй";
    ui->groupBox->show();
    ui->Aceppt->show();

}

void MainWindow:: on_Aceppt_clicked()
{
    qDebug()<<"хуй";
    worker *p;
    QString addFullName = ui->lineEditfullname1->text();
    QString addCabinet = ui->lineEditcabinet1->text();
    QString addWorkingTime = ui->lineEditworkingtime1->text();
    QString addSpeciality = ui->lineEditspecialyti1->text();
    QString addTelephone = ui->lineEdittelephone1->text();
    QString addsalaru = ui->lineEditsalaru1->text();
    doctor doc(addFullName, addCabinet, addWorkingTime, addSpeciality, addTelephone, addsalaru);
    p = &doc;
    list1.push_back(p);
    ui->groupBox->hide();
    ui->Aceppt->hide();
    qDebug() << list1.GetSize();
    pushFile(list1);
}

void pushFile(List ls)
{
//    QFile file("kurs.txt");
//    QTextStream out(&file);
    for (int i = 0; i <ls.GetSize(); i++)
    {
        qDebug() << "попытка " << i;
        ls[i]->pushFile();
        qDebug() << "успешно";
    }

}
