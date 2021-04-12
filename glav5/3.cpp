#include <iostream> //для cout и т.д.
using namespace std;
void zeroSmaller(int &a, int &b)
{   
    if (a > b) b = 0;
    else a = 0;
}
int main()
{
int a = 10, b = 25; 
zeroSmaller(a,b); 
cout << "a =  " << a <<" b = "<< b << endl;
return 0;
}
