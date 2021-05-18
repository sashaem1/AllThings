#include <iostream>
#include <string>
#include <locale.h>
using namespace std;



class worker
{
 private:
class Firm
{
 private:
    string Name;
    string Adress;
    string Telephone;
 public:
    Firm(): Name("HP"), Adress("Orel, Lenina 4"), Telephone("89524884623"){}
    Firm(string name, string adress, string telephone): Name(name), Adress(adress), Telephone(telephone){}
    void Change(string name, string adress, string telephone)
    {
        Name = name;
        Adress = adress;
        Telephone = telephone;
    }
    friend std :: ostream& operator<<(std :: ostream& out, const Firm &firm)
    {
        out << firm.Name << " " << firm.Adress << " " << firm.Telephone << endl;
        return out;
    }
};

    Firm firm;
    string Fio;
 public:
    worker(): firm(),  Fio("Ivanon I.I"){}
    worker(string nameFirm, string adress, string telephone, string fio): firm( nameFirm, adress, telephone), Fio(fio){ }
    void ChangeFirm(string name, string adress, string telephone)
    {
        firm.Change(name, adress, telephone);
    }
    void Show()
    {
        cout << Fio << " " << firm;
    }
};

int main()
{
    worker w1;
    w1.Show();
}