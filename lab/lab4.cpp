#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class date

{
 private:
	int day;
	int month;
	int year;
 public:
	date():day(12),month(12),year(2002){}
	date(int DAY, int MONTH, int YEAR):	day(DAY),month(MONTH),year(YEAR) {}
	friend ostream& operator<< (std::ostream &out, const date &DATE);
	friend bool operator== (date Date1, date Date2);
};

ostream& operator<< (std::ostream &out, const date &DATE)
{
	if(DATE.day<10) cout << 0 <<DATE.day << ".";
	else cout<<DATE.day<<".";
	if(DATE.month<10) cout << 0 <<DATE.month<<".";
	else cout<<DATE.month<< ".";
	cout<<DATE.year;
	return out;
}
bool operator== (date Date1, date Date2)
{
	if (Date1.day == Date2.day && Date1.month == Date2.month && Date1.year == Date2.year)
	{
		return true;
	} else return false;
}

enum gender { man, women};

class student
{
 private:
	int Cod;
	string Surname;
	string Name;
	string MiddleName;
	int Genger;
	date DateOfBirth;
	string Telephone;
	string Adress;
	string Class;
	bool BadMarks;
	static string NameOfSchool;
    friend ostream& operator<< (std::ostream &out, const student &student);
 public: 
 	student() : Cod(102), Surname("Ivanov"), Name("Ivan"), MiddleName("Ivanovich"), Genger(man), Telephone("89191234636"), Adress("Orel, lenina 4"), Class("11a"), BadMarks(false) {}
	student(int C, string Sn, string Na, string Mn, int Gen, int Da,int Mo,int Ye, string Tl, string Ad, string Cl, bool BM) : Cod(C), Surname(Sn), Name(Na), MiddleName(Mn), 
	Genger(Gen), DateOfBirth(Da,Mo,Ye), Telephone(Tl), Adress(Ad), Class(Cl), BadMarks(BM){}
  	void show()const
  	{
  		cout<<setw(3) << Cod << setw(10) << Surname <<setw(10) << Name <<setw(13) << MiddleName <<setw(8)<< ((Genger == man)? "man" : "women") <<setw(7)<<DateOfBirth
		<<setw(13)  << Telephone <<setw(40) << Adress <<setw(6) << Class <<setw(17) << ((BadMarks == true)? "yes" : "no") <<setw(15) << NameOfSchool << endl;
	}
	// int GetCod()
	// {
	// 	return Cod;
	// }
	// string GetSurname()
	// {
	// 	return Surname;
	// }
	// string GetName()
	// {
	// 	return Name;
	// }
	// date GetDate()
	// {
	// 	return DateOfBirth;
	// }
	// int GetSex()
	// {
	// 	return Genger;
	// }
	// bool GetBadMarks()
	// {
	// 	return BadMarks;
	// }
	// static void EditNameOfSchool(string NewNameOfSchool)
	// {
	// 	NameOfSchool = NewNameOfSchool;
	// }
};

string student :: NameOfSchool = "Lyceum 22";

ostream& operator<< (std::ostream &out, const student &student)
{
    student.show();
}

template <typename ty>
class List
{
 public:
    List();
    ~List();
    void push_back(ty data);
    void push_front(ty data);
    void pop_front();
    void pop_back();
    void insert(ty data, int index);
    void removeAt(int index);
    void clear();
    int GetSize() {return size;}
    ty& operator[](const int index);

 private:
    template <typename t>
    class Node
    {
     public:
        t data;
        Node *pNext;
        Node(t _data, Node *_pNext=nullptr): data(_data), pNext(_pNext){}
    };
    int size;
    Node<ty> *head;
};

template <typename ty>
List<ty>:: List()
{
    size = 0;
    head = nullptr;
}

template <typename ty>
List<ty>:: ~List()
{
    clear();
}

template <typename ty>
void List<ty>:: push_back(ty data)
{
    if(head == nullptr)
    {
        head = new Node<ty>(data);
    }
    else
    {
        Node<ty> *current = this->head;
        while ( current->pNext != nullptr)
        {
            current = current->pNext;
        }
        current->pNext = new Node<ty>(data);
    }
    size++;
}
template <typename ty>
void List<ty>:: push_front(ty data)
{
    head = new Node<ty>(data,head);
    size++;
}
template <typename ty>
void List<ty>:: pop_front()
{
    Node<ty> *temp =head;
    head = head->pNext;
    delete temp;
    size--;

}
template <typename ty>
void List<ty>:: pop_back()
{
    removeAt(size - 1);
}
template <typename ty>
void List<ty>::insert(ty data, int index)
{
    if (index == 0)
    {
        push_front(data);
    }
    else
    {
        Node<ty> *previouse = this->head;
        for (int i = 0; i < index-1; i++)
        {
            previouse = previouse->pNext;
        }
        Node<ty> *NewNode = new Node<ty>(data, previouse->pNext);
        previouse->pNext = NewNode;
        size++; 
    }

}
template <typename ty>
void List<ty>:: removeAt(int index)
{
     if (index == 0)
     {
         pop_front();
     }
     else
     {
         Node<ty> *previous = this->head;
         for (int i = 0; i < index-1; i++)
         {
             previous = previous->pNext;
         }
         Node<ty> *ToDelete = previous->pNext;
         previous->pNext = ToDelete->pNext;
         delete ToDelete;
         size--;
     }
}
template <typename ty>
void List<ty>:: clear()
{
    while (size!=0)
    {
        this->pop_front();
    }
    
}
template <typename ty>
ty& List<ty>:: operator[](const int index)
{
    int coutner = 0;
    Node<ty> *current = this->head;
    while (current!= nullptr)
    {
        if(coutner == index) return current->data;
        current = current->pNext;
        coutner++;

    }

}

int main()
{
    List<int> list1;
    List<float> list2;
    List<student> list3;
    list1.push_back(1);
    list1.push_back(2);
    list1.push_back(3);
    list2.push_back(1.2);
    list2.push_back(2.3);
    list2.push_back(3.4);
    list3.push_back(student());
    // list2.push_front(33.1);
    list1.insert(22,2);
    for (int i = 0; i < list1.GetSize(); i++)
    {
        cout << list1[i] << endl;
    }
    cout << "----------------------\n";
    for (int i = 0; i < list2.GetSize(); i++)
    {
        cout << list2[i] << endl;
    }
     cout << "----------------------\n";
    // list1.clear();
    for (int i = 0; i < list3.GetSize(); i++)
    {
        cout << list3[i] << endl;
    }
     cout << "----------------------\n";
}