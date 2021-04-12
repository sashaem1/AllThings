#include<iostream>
#include<iomanip>

using namespace std;

int main()
{ 
    int n=0;
    for(int i =0; i<20; i++)
    {
        cout<<setw(40-n);
        for (int j = 0; j <= n; j++)
        {
            cout<<'X';
        }
        n+=2;
        cout<< endl;
    }
}