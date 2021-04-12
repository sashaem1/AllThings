#include <iostream> //для cout и т.д.
using namespace std;
double power(double n, int p)
{
    double M=1;
    for(int i=0; i<p; i++)
    M*=n;
    return M;
}
int main()
{
double n;
int p; 
cout << "Enter number  and power: "; 
cin >> n>> p; 
cout << "Power : " << power(n,p) << endl;
return 0;
}
