#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n, k, s = 0;
    cin >> k >> n;
    int i = 0;
    int ki = 1;
    while(s<n)
    {
        // if(i%k == 0)
        // {
        //     s+=ki;
        //     ki++;
        // } else s+=1;
        // s=k*i+1;
        s+=ki+(k-1);
        ki++;
    }
    ki-=1;
    // cout << ki  << endl;
    if (s!=n) s-=(ki+(k-1));
    // cout << s << endl;
    if (k!=1)
    while(1)
    {
        s+=i;
        if(s<n)i++;
        else break;
    }
    // cout << ki << " " << i << endl;
    if(k == 2) cout << ki*2 + i;
    else if (k==1) cout << ki;
    else cout << ki*(k-1) + i;
}