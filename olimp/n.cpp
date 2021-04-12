#include<iostream>
#include<conio.h>

using namespace std;
int main()
{
    int d1, d2, d3, sum = 0;
    cin >> d1 >> d2 >> d3;
    if (d1+d2<d3)
    {
        sum = 2*d1 + 2*d2;
        // sum = d1 + d2 + d3;
        // cout << "1.";
    }
    else if(2*d3<=d2 || 2*d3<=d1)
    {
        if (2*d3<=d2) sum = 2*d3 + 2*d1;
        else sum = 2*d3 + 2*d2;
        // cout << "2.";
    } 
    else
    {
        // sum = 2*d1 + 2*d2;
        sum = d1 + d2 + d3;
        // cout << "3.";
    }
    cout << sum;
}