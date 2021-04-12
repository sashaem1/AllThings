#include <iostream>
#include <string>
#include <locale.h>
#include <Windows.h>
#include <cstdlib>
using namespace std;

enum e_number { f = 1, s = 2 };

class Data
{
public:
	int Day;
	int Month;
	int Year;
	Data() : Day(12), Month(6), Year(2002) {}
	Data(int day, int month, int year) : Day(day), Month(month), Year(year) {}
};

class Lekarstvo
{

private:
	int Kod;
	int E_Number;
	string Name_Lek;
	float Coast;
	bool Recept;
	string Opicanie;
	static string Apteka;
	Data Date;

public:
	Lekarstvo() : E_Number(f), Kod(1), Coast(3000), Recept(true), Date(), Opicanie("От живота"), Name_Lek("Активированный уголь") {}

	Lekarstvo(int kod, int e_number, string name_lek, float coast, bool recept, string opicanie, int d, int m, int y) :
		Kod(kod), E_Number(e_number), Name_Lek(name_lek), Coast(coast), Recept(recept), Opicanie(opicanie), Date(d, m, y) {}

	void show()
	{
		cout << "Код:" << Kod << endl << "Название аптеки: " << Apteka << endl << "Дата выпуска: " << Date.Day << "." << Date.Month << "." << Date.Year << endl << "Стоимость:  " << Coast << endl
			<< "Отдел: " << E_Number << endl;
		if (Recept)
			cout << "Наличие рецепта: Да";
		else cout << "Наличие рецепта: Нет";
		cout << endl << "Название лекарства: " << Name_Lek << endl << "Описание: " << Opicanie << endl << endl;
	}

};

string Lekarstvo::Apteka = "Virtus Pro";

void print()
{
	cout << "Введите A для добавления лекарства.\n";
	cout << "Введите S для поиса нужного лекарства.\n";
	cout << "Введите D для удаления лекарства.\n";
	cout << "Введите E для выхода из программы.\n";
	cout << "Вы ввели: ";
}

void addElements(int &max, Lekarstvo*& names,Lekarstvo oi)
{
	Lekarstvo* names1 = new Lekarstvo[max++];
	for (int i = 0; i < max-1; i++)
	{
		names[i] = names1[i];
	}
	names1[max-1] = oi;		
	names = names1;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "rus");
	int max = 2;
	Lekarstvo* names = new Lekarstvo[max];
	names[0] = Lekarstvo();
	names[1] = Lekarstvo(102, f, "tasm", 2500, 0, "ius", 12, 11, 13);
	char x;
	while (x != 'E')
	{
		print();
		cin >> x;
		if (x == 'A')
		{
			bool recept;
			int E_Number;
			int kod, coast, day, month, year;
			string Name_Lek;
			string Opicanie;
			cin >> kod >> coast >> day >> month >> year >> recept;
			cin >> E_Number;
			getline(cin, Name_Lek);
			cin.ignore(32767, '\n');
			getline(cin, Opicanie);
			Lekarstvo news;
			news = Lekarstvo(kod, E_Number, Name_Lek, coast, recept, Opicanie, day, month, year);
			cout << "sa";
			addElements(max, names, news);
			//delete& news;
			//names[2].show();
			cout << "as";
		}

		else if (x == 'S')
		{
			cout << "MAX: ";
			cout << max << endl;
			for (int i = 0; i < max; i++)
			{
				names[i].show();
			}
		}

	}
	cout << "Вы вышли из программы.";
}
