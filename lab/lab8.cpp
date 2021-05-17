#include <iostream>
#include <string>
using namespace std;

//интерфейс
class Interface 
{
 public:
    virtual void Show() = 0;
};

class human : public Interface
{
 private: 
    string Name;
    string Age;
 public:
    human(): Name("Sasha"), Age("18"){}
    void Show() 
    {
        cout << Name << " "<< Age << endl;
    }
};

class phone : public Interface
{
 private: 
    string Model;
    string Cost;
 public:
    phone(): Model("iPhone 12"), Cost("50000"){}
    void Show() 
    {
        cout << Model << " "<< Cost << endl;
    }
};

int main()
{
    human h = human();
    phone p= phone();
    h.Show();
    p.Show();

}