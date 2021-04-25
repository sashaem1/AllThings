#include<iostream>
#include <iomanip>

using namespace std;
int main()
{
    int n = 0, m = 0, k = 0, COUNT = 0, count = 0;
    int i = 0, j = 0, l = 0; 
    cin >> n >> m >> k;
    // cout << "333";
    int *X = new int[m+1];
    for (i = 0; i<m+1; i++)
    {
        cin >> X[i];
    }
    // cout << "333";
    j = m;
        // cout <<"i = " << i << endl;
        for (i = 0; i<m; i++)
        {
            // cout <<"i = " << i << endl;
            int a = X[i];
            int b = X[j];
            for (l = 0; l < n; l++)
            {
                // cout <<"l = " << l << endl;
                if (l == 0) 
                {
                    if (a%2 != b%2) count++;
                }
                else
                {
                    a = a/(2);
                    b = b/(2);
                    // cout <<"l = " << l << " a = " << a << " b = " << b << endl ;
                    if (a%2 != b%2) count++;
                } 
                // if ((a/(2*l))%2 != (b/(2*l))%2) count++;
            }
            if (count<=k)
            {
                COUNT++;
                // cout << " '+' k = " << count << endl;
            }
            // else cout << " '-' k = " << count << endl;
            count = 0;
        }
    cout << COUNT;
    delete [] X;
    return 0;
}