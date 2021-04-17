#include <iostream>
#include <string>
using namespace std;

int main()
{
    long long n, a, b;
    int t, s1 = 0, s2 = 0;
    cin>>t;
    int *mas = new int[t];
    // int mas[2];
    for(int i = 0; i<t; i++)
    {
        cin >> n >> a >> b;
        int j = 1;
        while(1)
        {
            // int j = 1;
            if(j%2 == 1)
            {
                n-=a;
                if(n<=0)
                { 
                s1 = 2;
                break;
                }
            }
            else 
            // if(j%2 == 0)
            {
                n-=b;
                if(n<=0)
                {
                s1 = 1;
                break;
                }
            }
            j++;
        }
        // while(1)
        // {
        //     int j = 0;
        //     if(j%2 == 1)
        //     {
        //         n-=a;
        //         if(n<=0)
        //         {
        //         s2 = 2;
        //         break;
        //         }
        //     }
        //     else 
        //     if(j%2 == 0)
        //     {
        //         n-=b;
        //         if(n<=0)
        //         { 
        //         s2 = 1;
        //         break;
        //         }
        //     }
        // }
        mas[i] = s1;
    }
    for(int i = 0; i<t; i++) cout << mas[i] << endl;
}