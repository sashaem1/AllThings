#include<iostream>
#include<conio.h>

using namespace std;

int main()
{
    float a;
    int b=a=0;
    char ch, char1;
    for( ; ; )
    {
        cout<< "Enter primer: ";
        cin>> a >> ch >> b;
        switch(ch)
        {
            case '+':
            {
                a+=b;
                cout<< "Result: "<< a<< endl;
                break;
            }
            case '-':
            {
                a-=b;
                cout<< "Result: "<< a<< endl;
                break;
            }
            case '/':
            {
                a/=b;
                cout<< "Result: "<< a<< endl;
                break;
            }
            case '*':
            {
                a*=b;
                cout<< "Result: "<< a<< endl;
                break;
            }
        }
        cout<<"Continue (y/n)? ";
        cin>>char1;
        if(char1 != 'y') break;
    }
}