#include<iostream>
#include<conio.h>

using namespace std;
const int N[30] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
int main()
{
    int n=0;
    cin >> n;
    int *M = new int[n];
    for (int i = 0; i<n; i++)
    cin >> M[i];
    if (n == 1)
    {
        if (M[0] == 0) cout << "UP";
        else if (M[0] == 15) cout << "DOWN";
        else cout << "-1";
        delete [] M;
        exit(0);
    }
    else
    {
        for (int i = 0; i<30; i++)
        {
            if (M[0]==N[i]&&( (M[1]==N[i+1])|| (M[0]==N[i]&&M[1]==N[0]&&i==29) ))
            {
                float c = (i+n)%30;
                cout << i << " "<< n <<" "<< c << endl;
                if (c>=16) cout << "DOWN";
                else cout << "UP";
                delete [] M;
                exit(0);
            }
        }
    } 
}