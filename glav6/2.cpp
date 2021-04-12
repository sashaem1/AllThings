#include <iostream> //для cout и т.д.
#include <conio.h>
using namespace std;

class tollBooth
{   
    private:
        unsigned int count;
        float Summ;
    public:
        tollBooth():count(0),Summ(0.0)
        {}
        void payingCar()
        { count++; Summ+=0.5; }
        void nopayCar()
        { count++; }
        void display()
            { cout << " count = " << count << " Summ = " <<Summ; }

        
};

int main()
{
    tollBooth toll;
    char ch;
    while (true)
    {
        cin >> ch;
        switch (ch)
        {
        case '+':
        {
            toll.payingCar();
            break;
        }
        case '-':
        {
            toll.nopayCar();
            break;
        }
        case 'e':
        {
            toll.display();
            exit(0);
        }
        } 
    }
    
    return 0;
}
