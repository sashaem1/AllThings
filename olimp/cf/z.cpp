#include<iostream>
#include<string>

using namespace std;
int main()
{
    int A[4], i = 0, sum = 0;
    long int M; 
    for (i=0; i<4; i++)
    cin >> A[i];
    string str;
    cin >> str;
    // cout << (int)str[i];
    for (int i = 0; i < str.size(); i++)
    {
        // cin >> ch;
        M = str[i] - 49;
        // cout << M << " ";
        sum += A[M];
        // cout << M << " " << A[M] << " " << sum << " ";

    }
    // cout << sum;
    // char ch;
    // cin >> ch;
    // cout << "ch =" << (int)ch;
    // cin >> cd\
    
    // cout << "ch =" << (int)ch;
    
    cout << sum;
}