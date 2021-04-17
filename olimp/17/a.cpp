#include <iostream>
#include <string>
using namespace std;

int main()
{
    int v1, v2, s1=0, s2=0;
    cin >>  v1 >> v2;
    long long i = 1;
    if(v1>0&&v2>0)
    while(((s1+v1*i)%360)!=((s2+v2*i)%360)) 
    i++;
    else 
    do
    {
        if(v1>0) 
        {
            s1+=v1;
            s1%=360;
        }
        else
        {
            s1+=v1;
            s1%=360;
        }
        if(v2>0) 
        {
            s2+=v2;
            s2%=360;
        }
        else
        {
            s2+=v2;
            s2%=360;
        }     
        i++;
    }while(s1!=s2); 
    //i++;
    // cout << i;
}