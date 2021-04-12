#include<iostream>
#include<string>
#include<iomanip>
#include<cstdlib>
#include<Windows.h>
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
	else cout<<DATE.day<< ".";
	if(DATE.month<10) cout << 0 <<DATE.month<< ".";
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

enum gender { мужчина, женщина};

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
 	student() : Cod(102), Surname("Иванов"), Name("Иван"), MiddleName("Иванович"), Genger(мужчина), Telephone("89191234636"), Adress("Орёл, ул. ленина, д 4"), Class("11Б"), BadMarks(false) {}
	student(int C, string Sn, string Na, string Mn, int Gen, int Da,int Mo,int Ye, string Tl, string Ad, string Cl, bool BM) : Cod(C), Surname(Sn), Name(Na), MiddleName(Mn), 
	Genger(Gen), DateOfBirth(Da,Mo,Ye), Telephone(Tl), Adress(Ad), Class(Cl), BadMarks(BM){}
  	void show()
  	{
  		cout<<setw(3) << Cod << setw(10) << Surname <<setw(10) << Name <<setw(10) << MiddleName <<setw(8)<< ((Genger == мужчина)? "мужской" : "женский") <<setw(7)<<DateOfBirth
		<<setw(13)  << Telephone <<setw(40) << Adress <<setw(6) << Class <<setw(15) << ((BadMarks == true)? "есть" : "нет") <<setw(15) << NameOfSchool << endl;
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
	static void EditNameOfSchool(string NewNameOfSchool)
	{
		NameOfSchool = NewNameOfSchool;
	}
};
string student :: NameOfSchool = "Лицей №22";
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
	cout<<setw(3) << "Код" << setw(10) << "Фамилия" <<setw(10) << "Имя" <<setw(10) << "Отчество" <<setw(8)<< "Пол" <<setw(15)<<"Дата рождения"
	<<setw(13)  << "Телефон" <<setw(40) << "Адресс" <<setw(6) << "Класс" <<setw(15) << "Наличие троек" <<setw(15) << "Название школы" << endl;
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

int main ()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");
	string DeleteName, DeleteSurname;
	int n = 6, DeleteCod;
	student *Student = new student[n]{student(),
	student(103, "Каменюк", "Михаил", "Андреевич", мужчина, 10, 2, 2001, "89536563322", "Орёл, ул. Приборостроительная, д 12", "11A", true),
	student(203, "Михайлов", "Генадий", "Петрович", мужчина, 21, 6, 2004, "89536465522", "Орёл, ул. Наугорское шоссе, д 17", "7A", false),
	student(404, "Алёшина", "Светлана", "Юрьевна", женщина, 21, 6, 2001, "89536465522", "Орёл, ул. Наугорское шоссе, д 56", "11A", true),
	student(222, "Щекотихин", "Иван", "Сергеевич", мужчина, 21, 6, 2002, "89536465522", "Орёл, ул. Московское шоссе, д 76", "10A", false),
	student(313, "Алёшин", "Дмирий", "Петрович", мужчина, 21, 6, 2005, "89536465522", "Орёл, ул. Ленина, д 88", "2A", false)
	};
	char ch;
	do
	{
		cout << "Что вы хотите сделать?\n Введите A для добавления ученика в список \n Введите D для удаления ученика из списка \n"
		<<" Введите S для отображения всего списа \n Введете C для для изменения школы \n Введете E для завершения работы программы \n";
		cin >> ch;
		switch (ch)
		{
		case 'A':
		{
			cout << "Введите данные для нового ученика : код, фамилию, имя, отчество, пол, дату рождения, телефон, адресс, класс, и наличие троек \n";
			int AddCod, AddGender, AddDay, AddMonth, AddYear;
			string AddSurname, AddName, AddMiddleName, AddTelephone, AddAdress, AddClass;
			bool AddBadMarks;
			cin >> AddCod >> AddSurname >> AddName >> AddMiddleName >> AddGender >> AddDay >> AddMonth >> AddYear >> AddTelephone >> AddAdress >> AddClass >> AddBadMarks;
			student stud(AddCod, AddSurname, AddName, AddMiddleName, AddGender,  AddDay, AddMonth , AddYear, AddTelephone , AddAdress, AddClass, AddBadMarks);
			Add(Student, stud, n);
			break;
		}
		case 'D':
		{
			cout << "По каким критериям вы хотите удалить человека из списка? \n 1) По коду \n 2) ПО фамилии и имени \n 3) По Коду и фамилии \n";
			cin >> ch;
			switch (ch)
			{
				case '1':
				{
					cout << "Введите код ученика\n";
					cin >> DeleteCod;
					for(int i = 0; i<n;i++)
					{
						if(Student[i].GetCod() == DeleteCod) Delete(Student, i, n);
					}
					break;	
				}
				case '2':
				{
					cout << "Введите Фамилию и имя ученика\n";
					cin >> DeleteSurname >> DeleteName;
					for(int i = 0; i<n;i++)
					{
						if(Student[i].GetName() == DeleteName && Student[i].GetSurname() == DeleteSurname ) Delete(Student, i, n);
					}
					break;	
				}
				case '3':
				{
					cout << "Введите код и фамилию ученика\n";
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
			cout << "Введите название школы \n";
			string newNameOfSchool;
			cin.ignore(32767, '\n');
			getline(std::cin, newNameOfSchool);
			student :: EditNameOfSchool(newNameOfSchool);
			break;
		}
		case 'P':
		{
			cout << "Введите дату рождения: ";
			int SearchDay, SearchMonth, SearchYear;
			cin >> SearchDay >> SearchMonth >> SearchYear;
			Search(Student, n, date( SearchDay, SearchMonth, SearchYear));
			break;
		}
	}
	}while (ch!='E');
	
	// system("pause");
}
