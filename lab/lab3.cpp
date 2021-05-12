#include <iostream>
#include <string>

using namespace std;

class human
{
 protected:
    string Fio;
    int age;
 public:
    human(): Fio("Ivanov I.I."), age(21) {}
    virtual void Show()
    {
        cout << Fio << " " << age;
    }
};

class worker
{
 protected:
    string specialty;
    string salary;
 public:
    worker(): specialty("Surgeon"), salary("50000") {}
    virtual void Show()
    {
        cout << specialty << " " << salary;
    }
};

class doctor : public human, public worker
{
 public: 
    doctor():human(), worker() {}
    void Show()
    {
        cout << Fio << " " << age << specialty << " " << salary;
    }
};

int main()
{
    doctor doc;
    doc.Show();
}