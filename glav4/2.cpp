#include<iostream>
#include<conio.h>

using namespace std;

struct point
{
    int x;
    int y;
};


int main()
{
    point point1, point2, point3;
    cout << "Enter point 1 : ";
    cin >> point1.x >> point1.y;
    cout << "Enter point 2 : ";
    cin >> point2.x >> point2.y;
    point3.x = point1.x + point2.x;
    point3.y = point1.y + point2.y;
    cout << "Point 3 is " << point3.x << "." << point3.y;
}