#include<iostream>
#include<conio.h>

using namespace std;
int main()
{
    int n = 0, sum = 0, Sum = 0, count = 0;
    cin >> n;
    for (int i = 1; i<=n; i++)
    {
        for (int j = 1; j <= i ; j++)
        {
            sum+=j;
        }
        // cout << sum << endl;
        Sum+=sum;
        if (Sum<=n)
        {
            sum=0;
            count++;
        } else break;
    }
    cout << count;
}