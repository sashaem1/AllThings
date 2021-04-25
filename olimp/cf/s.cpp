#include<iostream>

using namespace std;
int main()
{
    long long n = 0, m = 0, sum = 0, poz = 1;
    cin >> n >> m;
    int *p = new int[m];
    for (int i = 0; i<m; i++)
    {
        cin >> p[i];
    }
    for (int i = 0; i<m; i++)
    {
        if (p[i]== poz) continue;
        else if (p[i] > poz)
        {
            sum += p[i] - poz;
            poz = p[i];
            // cout << "1  " << sum << endl;
        }else{
            sum += n - (poz - p[i]);
            poz = p[i];
            // cout << "2  " << sum << endl;
        }
    }
    cout << sum;
}