#include<iostream>
#include<conio.h>

using namespace std;

struct phone
{
    int one;
    int two;
    int three;
};


int main()
{
    phone phone1, phone2={212, 555, 1212};
    cin >> phone1.one >> phone1.two >> phone1.three;
    cout << "Phone 1 : (" << phone1.one << ") "<<phone1.two << "-"<< phone1.three<< endl
    << "Phone 2 : (" << phone2.one << ") "<<phone2.two << "-"<< phone2.three<< endl; 
    return 0;
}