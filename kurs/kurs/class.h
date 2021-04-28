#include <iostream>
#include <string>
#include <fstream>
#include <QTextStream>
#include <QFile>
#include <QTableWidget>
#include <QMessageBox>
#include "ui_mainwindow.h"
using namespace std;

class worker
{
 protected:
//    public:
    QString fullName;
    QString working_time;
    QString telephone;
    QString salaru;
 public:
    worker(): fullName("Ivanov I.I."), working_time("14:00-20:00"), telephone("89534775254"), salaru("50000") {}
    worker(QString _fullName, QString _working_time, QString _telephone, QString _salaru): fullName(_fullName), working_time(_working_time),
        telephone(_telephone), salaru(_salaru){}
    virtual void show(QTableWidget *TW, int i)
    {
        TW->setItem( i , 0 , new QTableWidgetItem( fullName ) );
        TW->setItem( i , 1 , new QTableWidgetItem( "------" ) );
        TW->setItem( i , 2 , new QTableWidgetItem( working_time ) );
        TW->setItem( i , 3 , new QTableWidgetItem( "------" ) );
        TW->setItem( i , 4 , new QTableWidgetItem( telephone ) );
        TW->setItem( i , 5 , new QTableWidgetItem( salaru ) );
    }
    virtual void pushFile(){}
    virtual void pushConsol(){}
    QString GetFullName()
    {
        return fullName;
    }
    QString GetSalaru()
    {
        return salaru;
    }
    QString GetTelephone()
    {
        return telephone;
    }
    void SetFullName(QString NewName)
    {
        fullName= NewName;
    }
//    virtual void SetCabinet(QString Newcabinet, Ui::MainWindow *ui)
//    {

//    }
};

class doctor : public worker
{
 private:
//    public:
    QString cabinet;
    QString specialty;
 public:
    doctor():worker(), cabinet("202"), specialty("surgeon"){}
    doctor(QString _fullName, QString _cabinet, QString _working_time, QString _specialty, QString _telephone, QString _salaru) : worker(_fullName, _working_time, _telephone, _salaru), cabinet(_cabinet), specialty(_specialty){}
    void show(QTableWidget *TW, int i)
    {
        TW->setItem( i , 0 , new QTableWidgetItem( fullName ) );
        TW->setItem( i , 1 , new QTableWidgetItem( cabinet ) );
        TW->setItem( i , 2 , new QTableWidgetItem( working_time ) );
        TW->setItem( i , 3 , new QTableWidgetItem( specialty ) );
        TW->setItem( i , 4 , new QTableWidgetItem( telephone ) );
        TW->setItem( i , 5 , new QTableWidgetItem( salaru ) );
    }
    QString  GetFullName()
    {
        return fullName;
    }
    void pushFile()
    {
        qDebug() << " попытка открыть";
        QFile file("C:\\oop\\kurs\\kurs\\kurs.txt");
        if (file.open(QIODevice::WriteOnly))
        {
        QTextStream  out (&file);
        out << fullName << '\n';
        out << cabinet << '\n';
        out << working_time << '\n';
        out << telephone << '\n';
        out << specialty << '\n';
        out << salaru << '\n';
        file.close();
        qDebug() << " ну открыл и че";
        } else qDebug() << " нихуя не открылось";
    }
    void pushConsol()
    {
        qDebug() <<fullName << " " << cabinet << " " << working_time << " " << telephone << " " << specialty << " " << salaru;
    }
//    void SetCabinet(QString Newcabinet, Ui::MainWindow *ui)
//    {
//        cabinet = Newcabinet;
//    }
};

class receptionist : public worker
{
 private:
    QString window;
 public :
    receptionist(): worker(),window("1") {}
    receptionist(QString _fullName, QString _working_time, QString _telephone, QString _salaru, QString _window): worker(_fullName, _working_time, _telephone, _salaru), window(_window){}
    void show(QTableWidget *TW, int i)
    {
        TW->setItem( i , 0 , new QTableWidgetItem( fullName ) );
        TW->setItem( i , 1 , new QTableWidgetItem( window ) );
        TW->setItem( i , 2 , new QTableWidgetItem( working_time ) );
        TW->setItem( i , 3 , new QTableWidgetItem( "-----" ) );
        TW->setItem( i , 4 , new QTableWidgetItem( telephone ) );
        TW->setItem( i , 5 , new QTableWidgetItem( salaru ) );
    }
};

class ambulance_driver : public worker
{
 public :
    ambulance_driver() : worker(){}
    ambulance_driver(QString _fullName, QString _working_time, QString _telephone, QString _salaru): worker(_fullName, _working_time, _telephone, _salaru){}

    void show(QTableWidget *TW, int i)
    {
        TW->setItem( i , 0 , new QTableWidgetItem( fullName ) );
        TW->setItem( i , 1 , new QTableWidgetItem( "-----" ) );
        TW->setItem( i , 2 , new QTableWidgetItem( working_time ) );
        TW->setItem( i , 3 , new QTableWidgetItem( "-----" ) );
        TW->setItem( i , 4 , new QTableWidgetItem( telephone ) );
        TW->setItem( i , 5 , new QTableWidgetItem( salaru ) );
    }
//    void SetCabinet(QString Newcabinet, Ui::MainWindow *ui)
//    {
//        QMessageBox::information(ui, "ошибка ввода","Некоректно введены данные");
//    }
};

class List
{
 public:
    List();
    ~List();
    void push_back(worker* data);
    void pop_front();
    void pop_back();
    void removeAt(int index);
    int GetSize() {return size;}
    worker*& operator[](const int index);

 private:
    class Node
    {
     public:
        worker *data;
        Node *pNext;
        Node(worker* _data, Node *_pNext=nullptr): data(_data), pNext(_pNext){}
    };
    int size;
    Node *head;
};


List:: List()
{
    size = 0;
    head = nullptr;
}


List:: ~List()
{

}


void List:: push_back(worker* data)
{
    if(head == nullptr)
    {
        head = new Node(data);
    }
    else
    {
        Node *current = this->head;
        while ( current->pNext != nullptr)
        {
            current = current->pNext;
        }
        current->pNext = new Node(data);
    }
    size++;
}
void List:: pop_front()
{
    Node *temp =head;
    head = head->pNext;
    delete temp;
    size--;

}

void List:: pop_back()
{
    removeAt(size - 1);
}

void List:: removeAt(int index)
{
     if (index == 0)
     {
         pop_front();
     }
     else
     {
         Node *previous = this->head;
         for (int i = 0; i < index-1; i++)
         {
             previous = previous->pNext;
         }
         Node *ToDelete = previous->pNext;
         previous->pNext = ToDelete->pNext;
         delete ToDelete;
         size--;
     }
}

worker*& List:: operator[](const int index)
{
    int coutner = 0;
    Node *current = this->head;
    while (current!= nullptr)
    {
        if(coutner == index) return current->data;
        current = current->pNext;
        coutner++;

    }

}
