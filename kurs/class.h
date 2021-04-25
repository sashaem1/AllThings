#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class worker
{
 protected:
    string fullName;
    string working_time;
    string telephone;
    string salaru; 
 public:
    worker(): fullName("Ivanov I.I."), working_time("14:00-20:00"), telephone("89534775254"), salaru("50000") {}
    worker(string _fullName, string _working_time, string _telephone, string _salaru): fullName(_fullName), working_time(_working_time){}
    virtual void show()
    {
        cout << fullName  << " " << working_time << endl;
    }
    virtual void push(ofstream &fout)
    {
        fout << fullName  << " " << working_time << endl;
    }
};

class doctor : public worker
{
 private:
    string specialty;
    string cabinet; 
 public:
    doctor():worker(), specialty("surgeon"), cabinet("202"){}
    doctor(string _fullName, string _cabinet, string _working_time, string _speciality, string _telephone, string _salaru) : worker(_fullName, _working_time, _telephone, _salaru), 
    cabinet(_cabinet), specialty(_speciality){}
    void show()
    {
        cout << fullName << " " << cabinet << " " << working_time << " " << specialty << endl;
    }
    void push(ofstream &fout)
    {
        fout << 1 << " " << fullName << "; " << cabinet << "; " << working_time << "; " << specialty << ";" << endl;
    }
    void pull(ifstream &fin)
    {
        getline(fin,fullName,';');
        // fin >> cabinet;
        getline(fin,cabinet,';');
        getline(fin,working_time,';');
        getline(fin,specialty,';');
        cout << " pull complit \n";
    }
};

class receptionist : public worker
{
 private:
 public :
    receptionist(): worker(){}
    receptionist(string _fullName, string _working_time, string _telephone, string _salaru): worker(_fullName, _working_time, _telephone, _salaru){}
    void show()
    {
        cout << fullName  << " " << working_time << " " << telephone << endl;
    }
    void push(ofstream &fout)
    {
        fout << 2 << " " <<  fullName  << " " << working_time << " " << telephone << endl;
    }
};

class ambulance_driver : public worker
{
 public :
    ambulance_driver() : worker(){}
    ambulance_driver(string _fullName, string _working_time, string _telephone, string _salaru): worker(_fullName, _working_time, _telephone, _salaru){}
    void show()
    {
        cout << fullName  << " " << working_time << " " << telephone << endl;
    }
    void push(ofstream &fout)
    {
        fout << 3 << " " << fullName  << " " << working_time << " " << telephone << endl;
    } 
};

class List
{
 public:
    List();
    ~List();
    void push_back(worker* data);
    int GetSize() {return size;}
    worker*& operator[](const int index);
   
 private:
    class Node
    {
     public:
        Node *pNext;
        worker *data;
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