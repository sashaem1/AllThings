#include <iostream> //для cout и т.д.
#include <conio.h>
using namespace std;

class Time
{   
    private:
        int hours;
        int minutes; 
        int seconds;
    public:
        Time():hours(0), minutes(0), seconds(0)
        {}
        Time(int h, int m, int s):hours(h), minutes(m), seconds(s)
        {}
        void display()
        {
            cout << hours << ':' << minutes << ':' << seconds;
        }
        Time add(Time a)
        {
            Time b;
            if(seconds + a.seconds >=60) 
            {
                b.seconds += seconds + a.seconds - 60;
                b.minutes++;
            } else
            {
                b.seconds += seconds + a.seconds;
            } 
            if(minutes + a.minutes >=60) 
            {
                b.minutes += minutes + a.minutes - 60;
                b.hours++;
            } else
            {
                b.minutes += minutes + a.minutes;
            }
            b.hours += hours + a.hours;
            return b; 
        }
        
};

int main()
{   
    Time time1(10,29,29), time2(10,31,31), time3;
    time3=time1.add(time2);
    time3.display();
    return 0;
}
