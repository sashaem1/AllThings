#include <iostream> 
using namespace std;
long power(int hour, int min, int sec)
{
    return (360*hour + 60*min + sec);
}
int main()
{
int hour, min, sec;
char ch;
while (ch != 'n')
{
    cout << "Enter hours, minuts and seconds : "; 
    cin >> hour >> min >> sec; 
    cout << "Total seconds : " << power(hour, min, sec) << endl
    << " Continue (y/n)";
    cin >> ch;
}
return 0;
}