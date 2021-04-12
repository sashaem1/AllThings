#include<iostream>
#include<conio.h>

using namespace std;

int main()
{
    long int a=0;
    cout<<" Enter:";
    char b;
    while((b =getche()) != '\r')
    {
        // b-='0';
        // a*=10;
        // a+=static_cast<long>(b);
        // cout<<"("<< a << ")";
        a=a*10+static_cast<long>(b-48);
    } 
    cout<<" You enter "<< a;   
}