#include<iostream>
#include<conio.h>

using namespace std;
int main()
{
    int n = 0, h = 0, toll = 0;
    cin >> n >> h;
    int *A = new int [n];
    for (int i = 0; i < n; i++)
    cin >> A[i];
    for (int i = 0; i < n; i++)
    {
        if (A[i]> h) toll++;
    }
    cout << (toll*2 + (n-toll));
}