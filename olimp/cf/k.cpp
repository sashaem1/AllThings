#include<iostream>
#include<conio.h>
#include<string>

using namespace std;
const char N[30] = {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', 'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/'};
int main()
{
    char ch;
    string S;
    cin >> ch;
    int i = 0;
    // getline(cin, S);
    cin >> S;
    // cout<<ch<<endl;
    if (ch == 'L')
    {
        for(i = 0; i<size(S); i++)
        {
            for (int j = 0; j<30; j++)
            {
                if (S[i]==N[j])
                if (j != 29)
                cout<<N[j+1];
                else cout << N[0];
            }
        }
    }
    else if (ch == 'R')
    {
        for(i = 0; i<size(S); i++)
        {
            for (int j = 0; j<30; j++)
            {
                if (S[i]==N[j])
                if (j != 0)
                cout<<N[j-1];
                else cout << N[29];
            }
        }
    }
    return 0;
}