#include <iostream>
#include <math.h>
using namespace std;
int Sqrt(int a)
{
    if (a < 0) throw -1;
    a = sqrt(a);
    return a;
}

int main()
{
    int a = 4, b = -4;
    try
    {
        cout << Sqrt(a) << endl;
    }
    catch (int)
    {
        cerr << "nomber < 0\n";
    }
    
    try
    {
        cout << Sqrt(b) << endl;
    }
    catch (int)
    {
        cerr << "nomber < 0\n";
    }

    return 0;
}