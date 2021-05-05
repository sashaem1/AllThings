#include "mainwindow.h"
#include "class.h"
//#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QTextStream>
#include <QFile>
#include<QFileDialog>

void pushFile(List ls);
void pullFile();
void clearList();

List list1;
QString File_name ="";
int FileSaveStatus = 0;
int AcepptStatus = 0;
int CanselStatus = 0;
int NomberOfCangeElement = -1;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->groupBox->hide();
    ui->groupBox2->hide();
    ui->groupBox3->hide();
    ui->groupBox4->hide();
    ui->groupBox5->hide();
    ui->groupBox_2->hide();
    ui->CancelButton->hide();
    ui->Aceppt->hide();
    ui->tableWidget->setColumnCount(6);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Full Name" << "cabinet/window" <<"working time" << "speciality" << "telephone" << "salaru");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void pushFile()
{
    QFile file(File_name);
    if (file.open(QIODevice::WriteOnly))
    {
    for(int i = 0; i < list1.GetSize(); i++)
        list1[i]->pushFile(file);
    }
    file.close();
}

void ShowTable(QTableWidget *TW)
{
    TW->setRowCount(list1.GetSize());
    TW->setColumnCount(6);
    TW->setHorizontalHeaderLabels(QStringList() << "Full Name" << "cabinet/window" <<"working time" << "speciality" << "telephone" << "salaru");
    for(int j =0; j < list1.GetSize(); j++ )
    {
        list1[j]->show(TW, j);
    }
}
void MainWindow::on_ShowTable_clicked()
{
    ShowTable(ui->tableWidget);
}
void clearList()
{
    while(list1.GetSize()>0)
        list1.pop_back();
}
void pullFile()
{
    QFile file(File_name);
    if((file.exists())&&file.open(QIODevice::ReadOnly))
    {
        int ReadStatus = -1;
        while(!file.atEnd())
        {
            ReadStatus = file.readLine().toInt();
            if (ReadStatus == 1)
            {
                QString addFullName, addCabinet, addWorkingTime, addSpeciality, addTelephone, addsalaru;
                addFullName = file.readLine().trimmed();
                addCabinet = file.readLine().trimmed();
                addWorkingTime = file.readLine().trimmed();
                addSpeciality = file.readLine().trimmed();
                addTelephone = file.readLine().trimmed();
                addsalaru =file.readLine().trimmed();
                doctor doc(addFullName, addCabinet, addWorkingTime, addSpeciality, addTelephone, addsalaru);
                worker *p = new doctor(addFullName, addCabinet, addWorkingTime, addSpeciality, addTelephone, addsalaru);
//                p->pushConsol();
                list1.push_back(p);
            }
            if (ReadStatus == 2)
            {
                QString addFullName, addCabinet, addWorkingTime, addTelephone, addsalaru;
                addFullName = file.readLine().trimmed();
                addCabinet = file.readLine().trimmed();
                addWorkingTime = file.readLine().trimmed();
                addTelephone = file.readLine().trimmed();
                addsalaru =file.readLine().trimmed();
                worker *p = new receptionist(addFullName, addCabinet, addWorkingTime, addTelephone, addsalaru);
//                p->pushConsol();
                list1.push_back(p);
            }
            if (ReadStatus == 3)
            {
                QString addFullName, addWorkingTime, addTelephone, addsalaru;
                addFullName = file.readLine().trimmed();
                addWorkingTime = file.readLine().trimmed();
                addTelephone = file.readLine().trimmed();
                addsalaru =file.readLine().trimmed();
                worker *p = new ambulance_driver(addFullName, addWorkingTime, addTelephone, addsalaru);
//                p->pushConsol();
                list1.push_back(p);
            }
        }
    }
}
void MainWindow :: on_addButton_clicked()
{
    ui->groupBox2->show();
    ui->Aceppt->show();
    ui->CancelButton->show();
    ui->addButton->setEnabled(false);
    ui->DeleteElement->setEnabled(false);
    ui->SerchButton->setEnabled(false);
    ui->ChangeButton->setEnabled(false);
    AcepptStatus = 1;
    CanselStatus = 1;

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
        CanselStatus = 2;
    // добавление
    } else if( AcepptStatus == 2)
    {
     bool check, errorStasus = false;
    if (ui->AddRes->isChecked())
    {
        if(
        ui->lineEditfullname1->text().toInt(&check)!=0 ||
        ui->lineEditcabinet1->text().toInt(&check)!=0 ||
        ui->lineEditworkingtime1->text().toInt(&check)!=0 ||
        ui->lineEdittelephone1->text().toInt(&check)==0 ||
        ui->lineEditsalaru1->text().toInt(&check)==0
        ) errorStasus = true;
        if (
        ui->lineEditfullname1->text()=="" ||
        ui->lineEditcabinet1->text()=="" ||
        ui->lineEditworkingtime1->text()=="" ||
        ui->lineEdittelephone1->text()=="" ||
        ui->lineEditsalaru1->text()==""
        ) errorStasus = true;
        if (errorStasus == false)
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
        else
        {
            QMessageBox:: warning(this, "Ошибка", "Данные введены некоректно или введены не все данные");
        }

    }
    if (ui->AddDoc->isChecked())
    {
        if(
        ui->lineEditfullname1->text().toInt(&check)!=0 ||
        ui->lineEditcabinet1->text().toInt(&check)!=0 ||
        ui->lineEditworkingtime1->text().toInt(&check)!=0 ||
        ui->lineEdittelephone1->text().toInt(&check)==0 ||
        ui->lineEditsalaru1->text().toInt(&check)==0 ||
        ui->lineEditspecialyti1->text().toInt(&check)!=0
        ) errorStasus = true;
        if (
        ui->lineEditfullname1->text()=="" ||
        ui->lineEditcabinet1->text()=="" ||
        ui->lineEditworkingtime1->text()=="" ||
        ui->lineEdittelephone1->text()=="" ||
        ui->lineEditsalaru1->text()=="" ||
        ui->lineEditspecialyti1->text()==""
        ) errorStasus = true;
        if (errorStasus == false)
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
//            ui->lineEditspecialyti1->show();
//            ui->label_4->show();
        }
        else
        {
            QMessageBox:: warning(this, "Ошибка", "Данные введены некоректно или введены не все данные");
        }

    }
    if (ui->AddAmb->isChecked())
    {
        if(
        ui->lineEditfullname1->text().toInt(&check)!=0 ||
        ui->lineEditworkingtime1->text().toInt(&check)!=0 ||
        ui->lineEdittelephone1->text().toInt(&check)==0 ||
        ui->lineEditsalaru1->text().toInt(&check)==0
        ) errorStasus = true;
        if (
        ui->lineEditfullname1->text()=="" ||
        ui->lineEditworkingtime1->text()=="" ||
        ui->lineEdittelephone1->text()=="" ||
        ui->lineEditsalaru1->text()==""
        ) errorStasus = true;
        if (errorStasus == false)
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
        else
        {
            QMessageBox:: warning(this, "Ошибка", "Данные введены некоректно или введены не все данные");
        }
    }
    if (errorStasus == false)
    {
        ui->lineEditfullname1->clear();
        ui->lineEditcabinet1->clear();
        ui->lineEditworkingtime1->clear();
        ui->lineEditspecialyti1->clear();
        ui->lineEdittelephone1->clear();
        ui->lineEditsalaru1->clear();
        ui->groupBox->hide();
        ui->Aceppt->hide();
        ui->CancelButton->hide();
        AcepptStatus = 0;
        ShowTable(ui->tableWidget);
        ui->DeleteElement->setEnabled(true);
        ui->SerchButton->setEnabled(true);
        ui->ChangeButton->setEnabled(true);
        ui->addButton->setEnabled(true);
    }
    }
    //поиск
    else if(AcepptStatus == 3)
    {
        if (ui->SerchFullNameRadio->isChecked())
        {
            ui->tableWidget->clearContents();
            ui->tableWidget->setColumnCount(6);
            int i = 0;
            for(int j =0; j < list1.GetSize(); j++ )
            {
                if (list1[j]->GetFullName() == ui->lineEditSerchFullName->text())
                {
                    i++;
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
            ui->tableWidget->clearContents();
            ui->tableWidget->setColumnCount(6);
            int i = 0;
            for(int j =0; j < list1.GetSize(); j++ )
            {
                if (list1[j]->GetSalaru() == ui->lineEditSerchSalaru->text())
                {
                    i++;
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
            ui->tableWidget->clearContents();
            ui->tableWidget->setColumnCount(6);
            int i = 0;
            for(int j =0; j < list1.GetSize(); j++ )
            {
                qDebug() <<j;
                qDebug() <<list1[j]->GetTelephone();
                qDebug() <<ui->lineEditSerchTelephone->text();
                if (list1[j]->GetTelephone() == ui->lineEditSerchTelephone->text())
                {
                    i++;
//                    qDebug() << i;
                    ui->tableWidget->setRowCount(i);
                    list1[j]->show(MainWindow::ui->tableWidget, i-1);
                }
            }
            ui->lineEditSerchTelephone->clear();
            ui->lineEditSerchFullName->show();
            ui->label_7->show();
            ui->lineEditSerchSalaru->show();
            ui->label_8->show();
        }
        AcepptStatus = 0;
        ui->lineEditSerchFullName->clear();
        ui->groupBox3->hide();
        ui->Aceppt->hide();
        ui->CancelButton->hide();
        ui->DeleteElement->setEnabled(true);
        ui->addButton->setEnabled(true);
        ui->ChangeButton->setEnabled(true);
        ui->SerchButton->setEnabled(true);
    // выбор поиска
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
        CanselStatus = 3;
     // удаление
     } else if(AcepptStatus == 5)
    {
        int poz = ui->lineEditDeleteNomber->text().toInt();
        if(poz != 0)
        {
            if(poz <= list1.GetSize())list1.removeAt(poz-1);
            else QMessageBox:: warning(this, "Ошибка", "Элемента с таким номером не существует");
        } else QMessageBox:: warning(this, "Ошибка", "Вы не ввели значение");
        ui->groupBox5->hide();
        ui->lineEditDeleteNomber->clear();
        AcepptStatus=1;
        ShowTable(ui->tableWidget);
        ui->Aceppt->hide();
        ui->CancelButton->hide();
        ui->addButton->setEnabled(true);
        ui->SerchButton->setEnabled(true);
        ui->ChangeButton->setEnabled(true);
    // Редактирование
    } else if(AcepptStatus == 6)
    {
        if (ui->lineEditfullname1_2->text() != "" || ui->lineEditfullname1_2->text().toInt()!=0) list1[NomberOfCangeElement]->SetFullName(ui->lineEditfullname1_2->text());
        else if (ui->lineEditfullname1_2->text().toInt()==0 && ui->lineEditfullname1_2->text() != "" ) QMessageBox:: warning(this, "Ошибка", "Некорректно введено фио");
        if (ui->lineEditworkingtime1_2->text() != "" || ui->lineEditworkingtime1_2->text().toInt()!=0) list1[NomberOfCangeElement]->SetWorking_time(ui->lineEditworkingtime1_2->text());
        else if (ui->lineEditworkingtime1_2->text().toInt()==0 && ui->lineEditworkingtime1_2->text() != "") QMessageBox:: warning(this, "Ошибка", "Некорректно введено рабочее время");
        if (ui->lineEdittelephone1_2->text()!= "" && ui->lineEdittelephone1_2->text().toInt()!=0) list1[NomberOfCangeElement]->SetTelephone(ui->lineEdittelephone1_2->text());
        else if (ui->lineEdittelephone1_2->text().toInt()==0 && ui->lineEdittelephone1_2->text()!= "" ) QMessageBox:: warning(this, "Ошибка", "Некорректно введен телефон");
        if (ui->lineEditsalaru1_2->text()!= "" && ui->lineEditsalaru1_2->text().toInt()!=0)list1[NomberOfCangeElement]->SetSalaru(ui->lineEditsalaru1_2->text());
        else if (ui->lineEditsalaru1_2->text().toInt()==0 && ui->lineEditsalaru1_2->text()!= "") QMessageBox:: warning(this, "Ошибка", "Некорректно введена зарплата");
        if (ui->lineEditspecialyti1_2->text() !="" || ui->lineEditspecialyti1_2->text().toInt()!=0)
        {
            if(list1[NomberOfCangeElement]->Setspecialty(ui->lineEditspecialyti1_2->text())) list1[NomberOfCangeElement]->Setspecialty(ui->lineEditspecialyti1_2->text());
            else QMessageBox:: warning(this, "Ошибка", "У этого элемента нет поля специальность");
        } else if (ui->lineEditspecialyti1_2->text().toInt()==0 && ui->lineEditspecialyti1_2->text() !="") QMessageBox:: warning(this, "Ошибка", "Некорректно введена специальность");
        if (ui->lineEditcabinet1_2->text()!= "" || ui->lineEditcabinet1_2->text().toInt()!=0 )
        {
            if(list1[NomberOfCangeElement]->SetCabinet(ui->lineEditcabinet1_2->text())) list1[NomberOfCangeElement]->SetCabinet(ui->lineEditcabinet1_2->text());
            else QMessageBox:: warning(this, "Ошибка", "У этого элемента нет поля кабинет или окно");
        } else if (ui->lineEditcabinet1_2->text().toInt()==0 && ui->lineEditcabinet1_2->text()!= "") QMessageBox:: warning(this, "Ошибка", "Некорректно введен кабинет или окно");
        ui->groupBox_2->hide();
        ShowTable(ui->tableWidget);
        ui->Aceppt->hide();
        ui->CancelButton->hide();
        ui->lineEditfullname1_2->clear();
        ui->lineEditcabinet1_2->clear();
        ui->lineEditworkingtime1_2->clear();
        ui->lineEditspecialyti1_2->clear();
        ui->lineEdittelephone1_2->clear();
        ui->lineEditsalaru1_2->clear();
        ui->DeleteElement->setEnabled(true);
        ui->addButton->setEnabled(true);
        ui->SerchButton->setEnabled(true);
        AcepptStatus = 0;
    }

}
void MainWindow:: on_DeleteElement_clicked()
{
    ui->groupBox5->show();
    ui->Aceppt->show();
    ui->CancelButton->show();
    ui->addButton->setEnabled(false);
    ui->SerchButton->setEnabled(false);
    ui->ChangeButton->setEnabled(false);
    AcepptStatus= 5;
    CanselStatus = 5;
}

void MainWindow::on_SerchButton_clicked()
{
    ui->groupBox4->show();
    ui->Aceppt->show();
    ui->CancelButton->show();
    ui->DeleteElement->setEnabled(false);
    ui->addButton->setEnabled(false);
    ui->ChangeButton->setEnabled(false);
    ui->SerchButton->setEnabled(false);
    AcepptStatus = 4;
    CanselStatus = 4;
}

void MainWindow::on_ChangeButton_clicked()
{
    if (ui->tableWidget->item(ui->tableWidget->currentRow(),3)!= NULL)
    {
        NomberOfCangeElement = ui->tableWidget->currentItem()->row();
        ui->groupBox_2->show();
        ui->CancelButton->show();
        ui->Aceppt->show();
        ui->DeleteElement->setEnabled(false);
        ui->addButton->setEnabled(false);
        ui->SerchButton->setEnabled(false);
        AcepptStatus = 6;
        CanselStatus = 6;
    }

}

void MainWindow::on_CancelButton_clicked()
{
    if(CanselStatus == 1)
    {
        ui->groupBox2->hide();
        ui->Aceppt->hide();
        ui->CancelButton->hide();
        ui->addButton->setEnabled(true);
        ui->DeleteElement->setEnabled(true);
        ui->SerchButton->setEnabled(true);
        ui->ChangeButton->setEnabled(true);
        AcepptStatus = 0;
    } else if(CanselStatus == 2)
    {
        ui->lineEditfullname1->clear();
        ui->lineEditcabinet1->clear();
        ui->lineEditworkingtime1->clear();
        ui->lineEditspecialyti1->clear();
        ui->lineEdittelephone1->clear();
        ui->lineEditsalaru1->clear();
        ui->groupBox->hide();
        ui->Aceppt->hide();
        ui->CancelButton->hide();
        AcepptStatus = 0;
//        ShowTable(ui->tableWidget);
        ui->addButton->setEnabled(true);
        ui->DeleteElement->setEnabled(true);
        ui->SerchButton->setEnabled(true);
        ui->ChangeButton->setEnabled(true);
        ui->lineEditspecialyti1->show();
        ui->label_4->show();
        ui->lineEditcabinet1->show();
        ui->label_2->show();
    } else if(CanselStatus == 4)
    {
        ui->groupBox4->hide();
        ui->Aceppt->hide();
        ui->CancelButton->hide();
        ui->DeleteElement->setEnabled(true);
        ui->addButton->setEnabled(true);
        ui->ChangeButton->setEnabled(true);
        ui->SerchButton->setEnabled(true);

        AcepptStatus = 0;
        CanselStatus = 0;
    } else if(CanselStatus == 3)
    {
        ui->groupBox3->hide();
        ui->lineEditSerchFullName->clear();
        ui->groupBox3->hide();
        ui->Aceppt->hide();
        ui->CancelButton->hide();
        ui->lineEditSerchTelephone->clear();
        ui->lineEditSerchFullName->show();
        ui->label_7->show();
        ui->lineEditSerchSalaru->show();
        ui->label_8->show();
        ui->lineEditSerchSalaru->clear();
        ui->lineEditSerchTelephone->show();
        ui->label_9->show();
        ui->lineEditSerchFullName->clear();
        ui->DeleteElement->setEnabled(true);
        ui->addButton->setEnabled(true);
        ui->ChangeButton->setEnabled(true);
        ui->SerchButton->setEnabled(true);
        AcepptStatus = 0;
        CanselStatus = 0;
    } else if(CanselStatus == 5)
    {
        ui->groupBox5->hide();
        ui->Aceppt->hide();
        ui->CancelButton->hide();
        ui->addButton->setEnabled(true);
        ui->SerchButton->setEnabled(true);
        ui->ChangeButton->setEnabled(true);
        ui->lineEditDeleteNomber->clear();
        AcepptStatus = 0;
        CanselStatus = 0;
    } else if(CanselStatus == 6)
    {
        if (ui->tableWidget->item(ui->tableWidget->currentRow(),3)!= NULL)
        {
//            NomberOfCangeElement = ui->tableWidget->currentItem()->row();
            ui->groupBox_2->hide();
            ui->CancelButton->hide();
            ui->Aceppt->hide();
            ui->lineEditfullname1_2->clear();
            ui->lineEditcabinet1_2->clear();
            ui->lineEditworkingtime1_2->clear();
            ui->lineEditspecialyti1_2->clear();
            ui->lineEdittelephone1_2->clear();
            ui->lineEditsalaru1_2->clear();
            ui->DeleteElement->setEnabled(true);
            ui->addButton->setEnabled(true);
            ui->SerchButton->setEnabled(true);
            AcepptStatus =0;
            CanselStatus = 0;
        }

    }
}
void MainWindow::on_Save_triggered()
{
    if(File_name!="")
    {
        pushFile();
        QMessageBox:: information(this, "Сохранение", "Файл успешно сохранён");
    } else on_Save_as_triggered();


}
void MainWindow::on_Open_triggered()
{
    QString NewFileName = "";
    NewFileName = QFileDialog::getOpenFileName(this, "Open file", "C://","Text File (*.txt)");
    if(NewFileName != "")
    {
        clearList();
        File_name = NewFileName;
        pullFile();
        ShowTable(ui->tableWidget);
    } else QMessageBox:: warning(this, "Ошибка", "Файл не открыт");
}
void MainWindow::on_Save_as_triggered()
{
    QString NewFileName = "";
    NewFileName = QFileDialog::getSaveFileName(this, "Save file", "C://","Text File (*.txt)");
    if(NewFileName != "")
    {
        File_name = NewFileName;
        pushFile();
        QMessageBox:: information(this, "Сохранение", "Файл успешно сохранён");
    } else QMessageBox:: warning(this, "Ошибка", "Файл не сохранён");
}

void MainWindow::on_Create_triggered()
{
    QString NewFileName = "";
    NewFileName = QFileDialog::getSaveFileName(this, "Creat file", "C://","Text File (*.txt)");
    if(NewFileName != "")
    {
        File_name = NewFileName;
        QMessageBox:: information(this, "Cоздание", "Файл успешно создан");
    } else QMessageBox:: warning(this, "Ошибка", "Файл не создан");
}

void MainWindow::on_Exit_triggered()
{
    close();
}
