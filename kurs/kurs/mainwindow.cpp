#include "mainwindow.h"
#include "class.h"
#include "ui_mainwindow.h"
#include <QTextStream>
#include <QFile>

void pushFile(List ls);
List pullFile();

List list1;
int AcepptStatus = 1;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow)
{

    worker *w3 = new doctor(),
            *w4 = new doctor(),
            *w5 = new doctor(),
            *w6 = new doctor(),
            *w7 = new ambulance_driver(),
            *w8 = new receptionist();
    list1.push_back(w3);
    list1.push_back(w4);
    list1.push_back(w5);
    list1.push_back(w6);
    list1.push_back(w7);
    list1.push_back(w8);
    QFile file("kurs.txt");
    ui->setupUi(this);
    ui->groupBox->hide();
    ui->groupBox2->hide();
    ui->groupBox3->hide();
    ui->groupBox4->hide();
    ui->groupBox5->hide();
    ui->Aceppt->hide();
    ui->tableWidget->setColumnCount(6);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Full Name" << "cabinet/window" <<"working time" << "speciality" << "telephone" << "salaru");


}

MainWindow::~MainWindow()
{
    delete ui;
}
void ShowTable(QTableWidget *TW)
{
    TW->setRowCount(list1.GetSize());
    TW->setColumnCount(6);
    TW->setHorizontalHeaderLabels(QStringList() << "Full Name" << "cabinet/window" <<"working time" << "speciality" << "telephone" << "salaru");
//    for(int j =0; j < list1.GetSize(); j++ ) list1[j]->pushConsol();
    for(int j =0; j < list1.GetSize(); j++ )
    {
        list1[j]->show(TW, j);
    }
}
void MainWindow::on_ShowTable_clicked()
{
    ShowTable(ui->tableWidget);
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
    ui->groupBox2->show();
    ui->Aceppt->show();

}

void MainWindow:: on_Aceppt_clicked()
{
    // выбор добавления
    if (AcepptStatus == 1)
    {
        if (ui->AddRes->isChecked())
        {
            ui->lineEditspecialyti1->hide();
            ui->label_4->hide();
        }
        if (ui->AddAmb->isChecked())
        {
            ui->lineEditspecialyti1->hide();
            ui->label_4->hide();
            ui->lineEditcabinet1->hide();
            ui->label_2->hide();
        }
        ui->groupBox2->hide();
        ui->groupBox->show();
        AcepptStatus = 2;
    // добавление
    } else if( AcepptStatus == 2)
    {
    if (ui->AddRes->isChecked())
    {
        worker *p;
        QString addFullName = ui->lineEditfullname1->text();
        QString addCabinet = ui->lineEditcabinet1->text();
        QString addWorkingTime = ui->lineEditworkingtime1->text();
        QString addTelephone = ui->lineEdittelephone1->text();
        QString addsalaru = ui->lineEditsalaru1->text();
        p = new receptionist(addFullName, addCabinet, addWorkingTime, addTelephone, addsalaru);
        list1.push_back(p);
        ui->lineEditspecialyti1->show();
        ui->label_4->show();
    }
    if (ui->AddDoc->isChecked())
    {
    worker *p;
    QString addFullName = ui->lineEditfullname1->text();
    QString addCabinet = ui->lineEditcabinet1->text();
    QString addWorkingTime = ui->lineEditworkingtime1->text();
    QString addSpeciality = ui->lineEditspecialyti1->text();
    QString addTelephone = ui->lineEdittelephone1->text();
    QString addsalaru = ui->lineEditsalaru1->text();
    p = new doctor(addFullName, addCabinet, addWorkingTime, addSpeciality, addTelephone, addsalaru);
    list1.push_back(p);
    }
    if (ui->AddAmb->isChecked())
    {
        worker *p;
        QString addFullName = ui->lineEditfullname1->text();
        QString addWorkingTime = ui->lineEditworkingtime1->text();
        QString addTelephone = ui->lineEdittelephone1->text();
        QString addsalaru = ui->lineEditsalaru1->text();
        p = new ambulance_driver(addFullName, addWorkingTime, addTelephone, addsalaru);
        list1.push_back(p);
        ui->lineEditspecialyti1->show();
        ui->label_4->show();
        ui->lineEditcabinet1->show();
        ui->label_2->show();

    }
    ui->lineEditfullname1->clear();
    ui->lineEditcabinet1->clear();
    ui->lineEditworkingtime1->clear();
    ui->lineEditspecialyti1->clear();
    ui->lineEdittelephone1->clear();
    ui->lineEditsalaru1->clear();
    ui->groupBox->hide();
    ui->Aceppt->hide();
    AcepptStatus = 1;
    ShowTable(ui->tableWidget);
    }
    //поиск
    else if(AcepptStatus == 3)
    {
        if (ui->SerchFullNameRadio->isChecked())
        {
            qDebug() <<ui->lineEditSerchFullName->text();
            ui->tableWidget->clearContents();
            ui->tableWidget->setColumnCount(6);
            int i = 0;
            for(int j =0; j < list1.GetSize(); j++ )
            {
                if (list1[j]->GetFullName() == ui->lineEditSerchFullName->text())
                {
                    i++;
                    qDebug() << i;
                    ui->tableWidget->setRowCount(i);
                    list1[j]->show(MainWindow::ui->tableWidget, i-1);
                }
            }
            ui->lineEditSerchSalaru->show();
            ui->label_8->show();
            ui->lineEditSerchTelephone->show();
            ui->label_9->show();
            ui->lineEditSerchFullName->clear();
        }
        if (ui->SerchSalaruRadio->isChecked())
        {
            qDebug() <<ui->lineEditSerchSalaru->text();
            ui->tableWidget->clearContents();
            ui->tableWidget->setColumnCount(6);
            int i = 0;
            for(int j =0; j < list1.GetSize(); j++ )
            {
                if (list1[j]->GetSalaru() == ui->lineEditSerchSalaru->text())
                {
                    i++;
//                    qDebug() << i;
                    ui->tableWidget->setRowCount(i);
                    list1[j]->show(MainWindow::ui->tableWidget, i-1);
                }
            }
            ui->lineEditSerchFullName->show();
            ui->label_7->show();
            ui->lineEditSerchTelephone->show();
            ui->label_9->show();
            ui->lineEditSerchSalaru->clear();
        }
        if (ui->SerchTelephoneRadio->isChecked())
        {
            qDebug() <<ui->lineEditSerchTelephone->text();
            ui->tableWidget->clearContents();
            ui->tableWidget->setColumnCount(6);
            int i = 0;
            for(int j =0; j < list1.GetSize(); j++ )
            {
                if (list1[j]->GetTelephone() == ui->lineEditSerchTelephone->text())
                {
                    i++;
//                    qDebug() << i;
                    ui->tableWidget->setRowCount(i);
                    list1[j]->show(MainWindow::ui->tableWidget, i-1);
                }
//                ui->SerchTelephoneRadio->clearFocus();
                ui->lineEditSerchTelephone->clear();
            }
            ui->lineEditSerchFullName->show();
            ui->label_7->show();
            ui->lineEditSerchSalaru->show();
            ui->label_8->show();
        }
        AcepptStatus = 1;
        ui->lineEditSerchFullName->clear();
        ui->groupBox3->hide();
        ui->Aceppt->hide();
    }else if(AcepptStatus == 4)
     {
        if (ui->SerchFullNameRadio->isChecked())
        {
            ui->lineEditSerchSalaru->hide();
            ui->label_8->hide();
            ui->lineEditSerchTelephone->hide();
            ui->label_9->hide();
        }
        if (ui->SerchSalaruRadio->isChecked())
        {
            ui->lineEditSerchFullName->hide();
            ui->label_7->hide();
            ui->lineEditSerchTelephone->hide();
            ui->label_9->hide();
        }
        if (ui->SerchTelephoneRadio->isChecked())
        {
            ui->lineEditSerchFullName->hide();
            ui->label_7->hide();
            ui->lineEditSerchSalaru->hide();
            ui->label_8->hide();
        }
        ui->groupBox3->show();
        ui->groupBox4->hide();
        AcepptStatus = 3;
     } else if(AcepptStatus == 5)
    {
        int poz = ui->lineEditDeleteNomber->text().toInt();
        list1.removeAt(poz-1);
        ui->groupBox5->hide();
        ui->lineEditDeleteNomber->clear();
        AcepptStatus=1;
        ShowTable(ui->tableWidget);
        ui->Aceppt->hide();
    }
}
void MainWindow:: on_DeleteElement_clicked()
{
//    QTableWidgetItem *inm = ui->tableWidget->currentItem();
//    qDebug() << inm->row();
//    qDebug() << inm->column();
    ui->groupBox5->show();
    ui->Aceppt->show();
    AcepptStatus= 5;
}

void pushFile(List ls)
{
    for (int i = 0; i <ls.GetSize(); i++)
    {
        qDebug() << "попытка " << i;
        ls[i]->pushFile();
        qDebug() << "успешно";
    }

}

void MainWindow::on_SerchButton_clicked()
{
    ui->groupBox4->show();
    ui->Aceppt->show();
    AcepptStatus = 4;
}
