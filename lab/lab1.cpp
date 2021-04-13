#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <Windows.h>
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
 public: 
 	student() : Cod(102), Surname("Ivanov"), Name("Ivan"), MiddleName("Ivanovich"), Genger(man), Telephone("89191234636"), Adress("Orel, lenina 4"), Class("11a"), BadMarks(false) {}
	student(int C, string Sn, string Na, string Mn, int Gen, int Da,int Mo,int Ye, string Tl, string Ad, string Cl, bool BM) : Cod(C), Surname(Sn), Name(Na), MiddleName(Mn), 
	Genger(Gen), DateOfBirth(Da,Mo,Ye), Telephone(Tl), Adress(Ad), Class(Cl), BadMarks(BM){}
  	void show()
  	{
  		cout<<setw(3) << Cod << setw(10) << Surname <<setw(10) << Name <<setw(13) << MiddleName <<setw(8)<< ((Genger == man)? "man" : "women") <<setw(7)<<DateOfBirth
		<<setw(13)  << Telephone <<setw(40) << Adress <<setw(6) << Class <<setw(17) << ((BadMarks == true)? "yes" : "no") <<setw(15) << NameOfSchool << endl;
	}
	int GetCod()
	{
		return Cod;
	}
	string GetSurname()
	{
		return Surname;
	}
	string GetName()
	{
		return Name;
	}
	date GetDate()
	{
		return DateOfBirth;
	}
	int GetSex()
	{
		return Genger;
	}
	bool GetBadMarks()
	{
		return BadMarks;
	}
	static void EditNameOfSchool(string NewNameOfSchool)
	{
		NameOfSchool = NewNameOfSchool;
	}
};

string student :: NameOfSchool = "Lyceum 22";

void Add(student *&mas, student Stud, int &N)
{
	student *mas1 = new student[++N];
	for (int i = 0; i < N-1;i++) mas1[i]=mas[i];
	mas1[N-1]= Stud;
	mas = mas1;
}
void Delete(student *&mas, int a, int &N)
{
	student *mas1 = new student[--N];
	for(int i = 0; i<N;i++)
	{
		if (i==a) 
		{
			for(; i<N;i++) mas1[i] = mas[i+1];
			break;
		}
		else mas1[i] = mas[i];
	}
	mas = mas1;
}
void Show(student *&mas,const int &N)
{
	cout<<setw(3) << "Cod" << setw(10) << "Surname" <<setw(10) << "Name" <<setw(13) << "MiddleName" <<setw(8)<< "Sex" <<setw(15)<<"Date of birth"
	<<setw(13)  << "Telephon" <<setw(40) << "Adress" <<setw(6) << "Class" <<setw(17) << "Having bad marks" <<setw(15) << "Name of school" << endl;
	for(int i = 0; i<N;i++)
	{
		mas[i].show();
	}
}
void Search(student *&mas, int &N, date Date)
{
	for(int i = 0; i<N;i++)
	{	
		if(mas[i].GetDate()==Date) mas[i].show();
	}
	
}
int NomberOfGirls(student *&mas, int &N)
{
	int count = 0;
	for(int i = 0; i<N;i++)
	{	
		if(mas[i].GetSex()==women && mas[i].GetBadMarks()==false) count++;
	}
	return count;
}
int main ()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");
	string DeleteName, DeleteSurname;
	int n = 6, DeleteCod;
	student *Student = new student[n]{student(),
	student(103, "Baranov", "Mikhail", "Andreevich", man, 10, 2, 2001, "89536563322", "Orel, priboroctroitelnaya, 78", "11a", true),
	student(203, "Michailov", "Genadiy", "Petrovich", man, 21, 6, 2004, "89536465522", "Orel, Naygorskoe shosse, 12", "7a", false),
	student(404, "Aleshina", "Svetlana", "Alecsndrovna", women, 21, 6, 2001, "89536465522", "Orel, Naygorskoe shosse, 59", "11b", false),
	student(222, "Minailov", "Ivan", "Sergeevich", man, 21, 6, 2002, "89536465522", "Orel, Moscovskoe shosse, 12", "10c", false),
	student(313, "Aleshin", "Dmitriy", "Petrovich", man, 21, 6, 2005, "89536465522", "Orel, lenina 88", "2d", false)
    };
    char ch;
	do
	{
		cout << "What do you want to do? \n Enter A to add a student to the list \n Enter D to remove a student from the list \n Enter T to see the number of girls without bad marks \n"
		<<" Enter S to display the entire list \n Enter C to change the school \n Enter P to serch student \n Enter E to quit the program \n ";
		cin >> ch;
		switch (ch)
		{
		case 'A':
		{
			//cout << "Enter the data for the new student: code, last name, first name, middelname, gender, telephon , date of birth, address, class, Having bad marks \n";
			int AddCod, AddGender, AddDay, AddMonth, AddYear;
			string AddSurname, AddName, AddMiddleName, AddTelephone, AddAdress, AddClass;
			bool AddBadMarks;
			//cin >> AddCod >> AddSurname >> AddName >> AddMiddleName >> AddGender >> AddDay >> AddMonth >> AddYear >> AddTelephone;
			cout << "Enter cod "; cin >> AddCod;
			cout << "Enter surname "; cin >> AddSurname;
			cout << "Enter name "; cin >> AddName;
			cout << "Enter middelename "; cin >>AddMiddleName;
			cout << "Enter genger (0 - man, 1 - women) "; cin >> AddGender; if(AddGender!=0 && AddGender!=1){cout<<"Incorrect value\n"; break;}
			cout << "Enter date of birth "; cin >> AddDay >> AddMonth >> AddYear; if(AddDay>12 && AddMonth>12 && AddYear>2021){cout<<"Incorrect value\n"; break;}
			cout << "Enter telephon "; cin >> AddTelephone;
			cout << "Enter adress ";
			cin.ignore(32767, '\n');
			getline(std::cin, AddAdress);
			cout << "Enter class "; cin >>AddClass;
			cout << "Enter having bad marks  (0 - no, 1 - yes) "; cin >> AddBadMarks;if(AddBadMarks!=0 && AddBadMarks!=1){cout<<"Incorrect value\n"; break;}
			student stud(AddCod, AddSurname, AddName, AddMiddleName, AddGender,  AddDay, AddMonth , AddYear, AddTelephone , AddAdress, AddClass, AddBadMarks);
			Add(Student, stud, n);
			break;
		}
		case 'D':
		{
			cout << "What criteria do you use to remove a person from the list? \n 1) By code \n 2) By surname and first name \n 3) By code and surname \n";
			cin >> ch;
			switch (ch)
			{
				case '1':
				{
					cout << "Enter Cod\n";
					cin >> DeleteCod;
					for(int i = 0; i<n;i++)
					{
						if(Student[i].GetCod() == DeleteCod) Delete(Student, i, n);
					}
					break;	
				}
				case '2':
				{
					cout << "Enter surname and name\n";
					cin >> DeleteSurname >> DeleteName;
					for(int i = 0; i<n;i++)
					{
						if(Student[i].GetName() == DeleteName && Student[i].GetSurname() == DeleteSurname ) Delete(Student, i, n);
					}
					break;	
				}
				case '3':
				{
					cout << "Enter cod and surname \n";
					cin >> DeleteCod >> DeleteSurname;
					for(int i = 0; i<n;i++)
					{
						if(Student[i].GetCod() == DeleteCod && Student[i].GetSurname() == DeleteSurname ) Delete(Student, i, n);
					}
					break;	
				}	
			}
			break;
		}
		case 'S':
		{
			Show(Student,n);
			break;
		}
		case 'C':
		{
			cout << "Enter name of school \n";
			string newNameOfSchool;
			// cin >> newNameOfSchool;
			cin.ignore(32767, '\n');
			getline(std::cin, newNameOfSchool);
			student :: EditNameOfSchool(newNameOfSchool);
			// EditNameOfSchool(newNameOfSchool);
			break;
		}
		case 'P':
		{
			cout << "Enter date \n";
			int SerchDay, SerchMonth, SerchYear;
			cin >> SerchDay >> SerchMonth >> SerchYear;
			date SearchDate(SerchDay, SerchMonth, SerchYear);
			Search(Student, n, SearchDate);
			break;
		}
		case 'T':
		{
			cout << "The number of girls without bad marks:" << NomberOfGirls(Student, n) << endl;
			
			break;
		}
	}
	}while (ch!='E');
}