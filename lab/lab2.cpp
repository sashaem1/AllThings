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


class lerner
{
 protected:
	string Surname;
	string Name;
	string MiddleName;
	int Genger;
	date DateOfBirth;
	string Telephone;
	string Adress;
public:
	lerner() : Surname("Ivanov"), Name("Ivan"), MiddleName("Ivanovich"), Genger(man), Telephone("89191234636"), Adress("Orel, lenina 4"){}
	lerner(string Sn, string Na, string Mn, int Gen, int Da,int Mo,int Ye, string Tl, string Ad) : Surname(Sn), Name(Na), MiddleName(Mn), 
	Genger(Gen), DateOfBirth(Da,Mo,Ye), Telephone(Tl), Adress(Ad){}
    lerner(const lerner &stud) : Surname(stud.Surname), Name(stud.Name), MiddleName(stud.MiddleName), Genger(stud.Genger), Telephone(stud.Telephone), Adress(stud.Adress){}
	virtual void show()
  	{
  		cout<< setw(10) << Surname <<setw(10) << Name <<setw(13) << MiddleName <<setw(8)<< ((Genger == man)? "man" : "women") <<setw(7)<<DateOfBirth
		<<setw(13)  << Telephone <<setw(40) << Adress;
	}
	virtual string GetSurname()
	{
		return Surname;
	}
	virtual string GetName()
	{
		return Name;
	}
	virtual date GetDate()
	{
		return DateOfBirth;
	}
	virtual int GetSex()
	{
		return Genger;
	}
};

class schoolboy : protected lerner
{
 protected:
	int Cod;
	string Class;
	bool BadMarks;
	static string NameOfSchool;
 public: 
 	schoolboy() : Cod(102), lerner() , Class("11a"), BadMarks(false) {}
	schoolboy(int C, string Sn, string Na, string Mn, int Gen, int Da,int Mo,int Ye, string Tl, string Ad, string Cl, bool BM) : Cod(C), lerner(Sn, Na, Mn, Gen, Da, Mo, Ye, Tl, Ad) , Class(Cl), BadMarks(BM){}
    //schoolboy(const schoolboy &stud) : Cod(stud.Surname), Surname(stud.Surname), Name(stud.Name), MiddleName(stud.MiddleName), Genger(stud.Genger), Telephone(stud.Telephone), Adress(stud.Adress), Class(stud.Class), BadMarks(stud.BadMarks){}
  	virtual void Show()
  	{
  		cout<<setw(3) << Cod << setw(10) << Surname <<setw(10) << Name <<setw(13) << MiddleName <<setw(8)<< ((Genger == man)? "man" : "women") <<setw(7)<<DateOfBirth
		<<setw(13)  << Telephone <<setw(40) << Adress <<setw(6) << Class <<setw(17) << ((BadMarks == true)? "yes" : "no") <<setw(15) << NameOfSchool << endl;
	}
	virtual int GetCod()
	{
		return Cod;
	}
	virtual string GetSurname()
	{
		return Surname;
	}
	virtual string GetName()
	{
		return Name;
	}
	virtual date GetDate()
	{
		return DateOfBirth;
	}
	virtual int GetSex()
	{
		return Genger;
	}
	virtual bool GetBadMarks()
	{
		return BadMarks;
	}
	static void EditNameOfSchool(string NewNameOfSchool)
	{
		NameOfSchool = NewNameOfSchool;
	}
};

string schoolboy :: NameOfSchool = "Lyceum 22";

class highSchoolboy : private schoolboy
{
 private:
	string Exams;
 public:
 	highSchoolboy() : schoolboy(), Exams("maths, russian language, computer science") {}
	highSchoolboy(int C, string Sn, string Na, string Mn, int Gen, int Da,int Mo,int Ye, string Tl, string Ad, string Cl, bool BM, string Ex) : 
	schoolboy(C, Sn, Na, Mn, Gen, Da, Mo, Ye, Tl, Ad, Cl, BM), Exams(Ex){}
	void Show()
	{
  		cout<<setw(3) << Cod << setw(10) << Surname <<setw(10) << Name <<setw(13) << MiddleName <<setw(8)<< ((Genger == man)? "man" : "women") <<setw(7)<<DateOfBirth
		<<setw(13)  << Telephone <<setw(40) << Adress <<setw(6) << Class <<setw(17) << ((BadMarks == true)? "yes" : "no") <<setw(50) << Exams <<setw(15) << NameOfSchool << endl;
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

};

class student : public lerner
{
 private:
	int NomberRecordBook;
	string Specialty;
	bool Arrears;
	static string NameOfUniversitu;
 public:
	student() : NomberRecordBook(208035), lerner(), Specialty("programming") , Arrears(false) {}
	student(int NRB, string Sn, string Na, string Mn, int Gen, int Da,int Mo,int Ye, string Tl, string Ad, string Sp, bool Ar) : NomberRecordBook(NRB), lerner(Sn, Na, Mn, Gen, Da, Mo, Ye, Tl, Ad) , Specialty(Sp), Arrears(Ar){}
    void Show()
  	{
  		cout<< setw(11) << NomberRecordBook << setw(10) << Surname <<setw(10) << Name <<setw(13) << MiddleName <<setw(8)<< ((Genger == man)? "man" : "women") <<setw(7)<<DateOfBirth
		<<setw(30)  << Specialty <<setw(13)  << Telephone <<setw(40) << Adress <<setw(15) << ((Arrears == true)? "yes" : "no") <<setw(20) << NameOfUniversitu << endl;
	}
	int GetNomberRecordBook()
	{
		return NomberRecordBook;
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
	static void EditNameOfUniversitu(string NewNameOfUniversitu)
	{
		NameOfUniversitu = NewNameOfUniversitu;
	}
};

string student :: NameOfUniversitu = "Orel Uniersity";

void Add(schoolboy *&mas, schoolboy school, int &N)
{
	schoolboy *mas1 = new schoolboy[++N];
	for (int i = 0; i < N-1;i++) mas1[i]=mas[i];
	mas1[N-1]= school;
	delete[] mas;
	mas = mas1;
}

void Add(highSchoolboy *&mas, highSchoolboy school, int &N)
{
	highSchoolboy *mas1 = new highSchoolboy[++N];
	for (int i = 0; i < N-1;i++) mas1[i]=mas[i];
	mas1[N-1]= school;
	delete[] mas;
	mas = mas1;
}

void Add(student *&mas, student school, int &N)
{
	student *mas1 = new student[++N];
	for (int i = 0; i < N-1;i++) mas1[i]=mas[i];
	mas1[N-1]= school;
	delete[] mas;
	mas = mas1;
}

void Delete(schoolboy *&mas, int a, int &N)
{
	schoolboy *mas1 = new schoolboy[--N];
	for(int i = 0; i<N;i++)
	{
		if (i==a) 
		{
			for(; i<N;i++) mas1[i] = mas[i+1];
			break;
		}
		else mas1[i] = mas[i];
	}
	delete[] mas;
	mas = mas1;
}

void Delete(highSchoolboy *&mas, int a, int &N)
{
	highSchoolboy *mas1 = new highSchoolboy[--N];
	for(int i = 0; i<N;i++)
	{
		if (i==a) 
		{
			for(; i<N;i++) mas1[i] = mas[i+1];
			break;
		}
		else mas1[i] = mas[i];
	}
	delete[] mas;
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
	delete[] mas;
	mas = mas1;

}

void Show(schoolboy *&mas,const int &N)
{
	cout<<setw(3) << "Cod" << setw(10) << "Surname" <<setw(10) << "Name" <<setw(13) << "MiddleName" <<setw(8)<< "Sex" <<setw(15)<<"Date of birth"
	<<setw(13)  << "Telephon" <<setw(40) << "Adress" <<setw(6) << "Class" <<setw(17) << "Having bad marks" <<setw(15) << "Name of school" << endl;
	for(int i = 0; i<N;i++)
	{
		mas[i].Show();
	}
}

void Show(highSchoolboy *&mas,const int &N)
{
	cout<<setw(3) << "Cod" << setw(10) << "Surname" <<setw(10) << "Name" <<setw(13) << "MiddleName" <<setw(8)<< "Sex" <<setw(15)<<"Date of birth"
	<<setw(13)  << "Telephon" <<setw(40) << "Adress" <<setw(6) << "Class" <<setw(17) << "Having bad marks"<<setw(50) << "Exams" <<setw(15) << "Name of school" << endl;
	for(int i = 0; i<N;i++)
	{
		mas[i].Show();
	}
}

void Show(student *&mas,const int &N)
{
	cout<<setw(11) << "Record Book" << setw(10) << "Surname" <<setw(10) << "Name" <<setw(13) << "MiddleName" <<setw(8)<< "Sex" <<setw(15)<<"Date of birth"
	<<setw(30)  << "Specialty" <<setw(13)  << "Telephon" <<setw(40) << "Adress" <<setw(15) << "Having Arrears" <<setw(20) << "Name of University" << endl;
	for(int i = 0; i<N;i++)
	{
		mas[i].Show();
	}
}


void Search(schoolboy *&mas, int &N, date Date)
{
	for(int i = 0; i<N;i++)
	{	
		if(mas[i].GetDate()==Date) mas[i].Show();
	}
	
}
int NomberOfGirls(schoolboy *&mas, int &N)
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
	int n1 = 6, n2 = 6, n3 = 6, DeleteCod;
	schoolboy *Schoolboy = new schoolboy[n1]{schoolboy(),
	schoolboy(103, "Baranov", "Mikhail", "Andreevich", man, 10, 2, 2001, "89536563322", "Orel, priboroctroitelnaya, 78", "11a", true),
	schoolboy(203, "Michailov", "Genadiy", "Petrovich", man, 21, 6, 2004, "89536465522", "Orel, Naygorskoe shosse, 12", "7a", false),
	schoolboy(404, "Aleshina", "Svetlana", "Alecsndrovna", women, 21, 6, 2001, "89536465522", "Orel, Naygorskoe shosse, 59", "11b", false),
	schoolboy(222, "Minailov", "Ivan", "Sergeevich", man, 21, 6, 2002, "89536465522", "Orel, Moscovskoe shosse, 12", "10c", false),
	schoolboy(313, "Aleshin", "Dmitriy", "Petrovich", man, 21, 6, 2005, "89536465522", "Orel, lenina 88", "2d", false)
    };
	highSchoolboy *HighSchoolboy = new highSchoolboy[n2]{highSchoolboy(),
	highSchoolboy(103, "Baranov", "Mikhail", "Andreevich", man, 10, 2, 2001, "89536563322", "Orel, priboroctroitelnaya, 78", "11a", true, "maths"),
	highSchoolboy(203, "Michailov", "Genadiy", "Petrovich", man, 21, 6, 2004, "89536465522", "Orel, Naygorskoe shosse, 12", "7a", false, "maths"),
	highSchoolboy(404, "Aleshina", "Svetlana", "Alecsndrovna", women, 21, 6, 2001, "89536465522", "Orel, Naygorskoe shosse, 59", "11b", false, "maths"),
	highSchoolboy(222, "Minailov", "Ivan", "Sergeevich", man, 21, 6, 2002, "89536465522", "Orel, Moscovskoe shosse, 12", "10c", false, "maths"),
	highSchoolboy(313, "Aleshin", "Dmitriy", "Petrovich", man, 21, 6, 2005, "89536465522", "Orel, lenina 88", "2d", false, "maths") 
	};
	student *Students  = new student [n2]{student(),
	student (200255, "Baranov", "Mikhail", "Andreevich", man, 10, 2, 2001, "89536563322", "Orel, priboroctroitelnaya, 78", "programming",true),
	student (209563, "Michailov", "Genadiy", "Petrovich", man, 21, 6, 2004, "89536465522", "Orel, Naygorskoe shosse, 12", "programming", false),
	student (445526, "Aleshina", "Svetlana", "Alecsndrovna", women, 21, 6, 2001, "89536465522", "Orel, Naygorskoe shosse, 59", "programming", false),
	student (222265, "Minailov", "Ivan", "Sergeevich", man, 21, 6, 2002, "89536465522", "Orel, Moscovskoe shosse, 12", "programming", false),
	student (313668, "Aleshin", "Dmitriy", "Petrovich", man, 21, 6, 2005, "89536465522", "Orel, lenina 88", "programming", false) 
	};
    char ch;
	do
	{
		cout << "What do you want to do? \n Enter A to add a schoolboy to the list \n Enter D to remove a schoolboy from the list \n Enter T to see the number of girls without bad marks \n"
		<<" Enter S to display the entire list \n Enter C to change the school \n Enter P to serch schoolboy \n Enter E to quit the program \n ";
		cin >> ch;
		switch (ch)
		{
		case 'A':
		{
			cout << "What list do you want to add? \n Enter 1 to add a schoolboy to the list \n Enter 2 to add a highschoolboy to the list \n Enter 3 to add a students to the list \n";
			cin >> ch;
			switch (ch)
			{
			case '3':
			{
				int AddNomberRecordBook, AddDay, AddMonth, AddYear;
				int AddGender;
				string AddSurname, AddName, AddMiddleName, AddTelephone, AddAdress, AddSpecialty;
				bool AddArrears;
				cout << "Enter Nomber Record Book "; cin >> AddNomberRecordBook;
				cout << "Enter surname "; cin >> AddSurname;
				cout << "Enter name "; cin >> AddName;
				cout << "Enter middelename "; cin >>AddMiddleName;
				cout << "Enter genger (0 - man, 1 - women) "; cin >> AddGender; if(AddGender!=0 && AddGender!=1){cout<<"Incorrect value\n"; break;}
				cout << "Enter date of birth "; cin >> AddDay >> AddMonth >> AddYear; if(AddDay>12 && AddMonth>12 && AddYear>2021){cout<<"Incorrect value\n"; break;}
				cout << "Enter telephon "; cin >> AddTelephone;
				cout << "Enter adress ";
				cin.ignore(32767, '\n');
				getline(std::cin, AddAdress);
				cout << "Enter Specialty "; cin >>AddSpecialty;
				cout << "Enter having bad marks  (0 - no, 1 - yes) "; cin >> AddArrears; if(AddArrears!=0 && AddArrears!=1){cout<<"Incorrect value\n"; break;}
				student stud(AddNomberRecordBook, AddSurname, AddName, AddMiddleName, AddGender,  AddDay, AddMonth , AddYear, AddTelephone , AddAdress, AddSpecialty, AddArrears);
				Add(Students, stud, n3);
				break;
			}	
			case '2':
			{
				int AddCod, AddDay, AddMonth, AddYear;
				int AddGender;
				string AddSurname, AddName, AddMiddleName, AddTelephone, AddAdress, AddClass, AddExams;
				bool AddBadMarks;
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
				cout << "Enter exams";
				cin.ignore(32767, '\n');
				getline(std::cin, AddExams);
				highSchoolboy stud(AddCod, AddSurname, AddName, AddMiddleName, AddGender,  AddDay, AddMonth , AddYear, AddTelephone , AddAdress, AddClass, AddBadMarks, AddExams);
				Add(HighSchoolboy, stud, n2);
				break;
			}
			case '1':
			{
				int AddCod, AddDay, AddMonth, AddYear;
				int AddGender;
				string AddSurname, AddName, AddMiddleName, AddTelephone, AddAdress, AddSpecialty;
				bool AddBadMarks;
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
				cout << "Enter class "; cin >>AddSpecialty;
				cout << "Enter having bad marks  (0 - no, 1 - yes) "; cin >> AddBadMarks; if(AddBadMarks!=0 && AddBadMarks!=1){cout<<"Incorrect value\n"; break;}
				schoolboy stud(AddCod, AddSurname, AddName, AddMiddleName, AddGender,  AddDay, AddMonth , AddYear, AddTelephone , AddAdress, AddSpecialty, AddBadMarks);
				Add(Schoolboy, stud, n1);
				break;
			}
			}
			break;
		}
		case 'D':
		{
			int DeleteCod,DeleteNomberRecordBook;
			string DeleteSurname, DeleteName;
			cout << "What list do you want to delete? \n Enter 1 to delete a schoolboy to the list \n Enter 2 to delete a highschoolboy to the list \n Enter 3 to delete a students to the list \n";
			cin >> ch;
			switch (ch)
			{
			case '1':
			{
				cout << "What criteria do you use to remove a person from the list? \n 1) By code \n 2) By surname and first name \n 3) By code and surname \n";
				cin >> ch;
				switch (ch)
				{
					case '1':
					{
						cout << "Enter Cod\n";
						//int DeleteCod;
						cin >> DeleteCod;
						for(int i = 0; i<n1;i++)
						{
							if(Schoolboy[i].GetCod() == DeleteCod) Delete(Schoolboy, i, n1);
						}
						break;	
					}
					case '2':
					{
						cout << "Enter surname and name\n";
						//string DeleteSurname, DeleteName;
						cin >> DeleteSurname >> DeleteName;
						for(int i = 0; i<n1;i++)
						{
							if(Schoolboy[i].GetName() == DeleteName && Schoolboy[i].GetSurname() == DeleteSurname ) Delete(Schoolboy, i, n1);
						}
						break;	
					}
					case '3':
					{
						cout << "Enter cod and surname \n";
						//int DeleteCod;
						//string DeleteSurname;
						cin >> DeleteCod >> DeleteSurname;
						for(int i = 0; i<n1;i++)
						{
							if(Schoolboy[i].GetCod() == DeleteCod && Schoolboy[i].GetSurname() == DeleteSurname ) Delete(Schoolboy, i, n1);
						}
						break;	
					}	
				}
				break;
			}
			case '2':
			{
				cout << "What criteria do you use to remove a person from the list? \n 1) By code \n 2) By surname and first name \n 3) By code and surname \n";
				cin >> ch;
				switch (ch)
				{
					case '1':
					{
						cout << "Enter Cod\n";
						//int DeleteCod;
						cin >> DeleteCod;
						for(int i = 0; i<n2;i++)
						{
							if(HighSchoolboy[i].GetCod() == DeleteCod) Delete(HighSchoolboy, i, n2);
						}
						break;	
					}
					case '2':
					{
						cout << "Enter surname and name\n";
						//string DeleteSurname, DeleteName;
						cin >> DeleteSurname >> DeleteName;
						for(int i = 0; i<n2;i++)
						{
							if(HighSchoolboy[i].GetName() == DeleteName && HighSchoolboy[i].GetSurname() == DeleteSurname ) Delete(HighSchoolboy, i, n2);
						}
						break;	
					}
					case '3':
					{
						cout << "Enter cod and surname \n";
						//int DeleteCod;
						//string DeleteSurname;
						cin >> DeleteCod >> DeleteSurname;
						for(int i = 0; i<n2;i++)
						{
							if(HighSchoolboy[i].GetCod() == DeleteCod && HighSchoolboy[i].GetSurname() == DeleteSurname ) Delete(HighSchoolboy, i, n2);
						}
						break;	
					}	
				}
				break;
			}
			case '3':
			{
				cout << "What criteria do you use to remove a person from the list? \n 1) By code \n 2) By surname and first name \n 3) By code and surname \n";
				cin >> ch;
				switch (ch)
				{
					case '1':
					{
						cout << "Enter Nomber Record Book\n";
						//int DeleteNomberRecordBook;
						cin >> DeleteNomberRecordBook;
						for(int i = 0; i<n3;i++)
						{
							if(Students[i].GetNomberRecordBook() == DeleteNomberRecordBook) Delete(Students, i, n3);
						}
						break;	
					}
					case '2':
					{
						cout << "Enter surname and name\n";
						//string DeleteSurname, DeleteName;
						cin >> DeleteSurname >> DeleteName;
						for(int i = 0; i<n3;i++)
						{
							if(Students[i].GetName() == DeleteName && Students[i].GetSurname() == DeleteSurname ) Delete(Students, i, n3);
						}
						break;	
					}
					case '3':
					{
						cout << "Enter cod and surname \n";
						//int DeleteNomberRecordBook;
						//string DeleteSurname;
						cin >> DeleteNomberRecordBook >> DeleteSurname;
						for(int i = 0; i<n3;i++)
						{
							if(Students[i].GetNomberRecordBook() == DeleteNomberRecordBook && Students[i].GetSurname() == DeleteSurname ) Delete(Students, i, n3);
						}
						break;	
					}	
				}
				break;
			}
			}
				break;
		}
		case 'S':
		{
			cout << "What list do you want to see ? \n 1) School \n 2) high school \n 3) students \n";
			cin >> ch;
			switch (ch)
			{
				case '1':
				{
					Show(Schoolboy,n1);
					break;	
				}
				case '2':
				{
					Show(HighSchoolboy,n2);
					break;	
				}
				case '3':
				{
					Show(Students,n3);
					break;	
				}	
			}
			break;
		}
		case 'C':
		{
			cout << "Enter name of school \n";
			string newNameOfSchool;
			// cin >> newNameOfSchool;
			cin.ignore(32767, '\n');
			getline(std::cin, newNameOfSchool);
			schoolboy :: EditNameOfSchool(newNameOfSchool);
			// EditNameOfSchool(newNameOfSchool);
			break;
		}
		case 'P':
		{
			cout << "Enter date \n";
			int SerchDay, SerchMonth, SerchYear;
			cin >> SerchDay >> SerchMonth >> SerchYear;
			date SearchDate(SerchDay, SerchMonth, SerchYear);
			Search(Schoolboy, n1, SearchDate);
			break;
		}
		case 'T':
		{
			cout << "The number of girls without bad marks:" << NomberOfGirls(Schoolboy, n1) << endl;
			
			break;
		}
		case 'Q':
		{
			cout << "123123" << endl;
			schoolboy sc1(Schoolboy[4]);
			sc1.Show();
			highSchoolboy sc2;
			sc2.Show();
			break;
		}
	}
	}while (ch!='E');
}