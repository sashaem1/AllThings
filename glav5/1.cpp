#include <iostream> //для cout и т.д.
using namespace std;
const float PI =3.14159F; 
float circarea(float r)
{
    return PI*r*r;
}
int main()
{
float rad; 
cout << "Введите радиус окружности: "; 
cin >> rad; 
cout << "Площадь круга равна " << circarea(rad) << endl;
return 0;
}
