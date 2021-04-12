#include<iostream>
#include <iomanip>

using namespace std;
int main()
{
    int n = 0, sum = 0;
    long double P=0.0;
    cin >> n;
    int *p = new int[n];
    for (int i = 0; i<n; i++)
    {
        cin >> p[i];
        sum+=p[i];
    }
    P = (long double)sum/n;
    cout << setprecision(14) <<  P;
}