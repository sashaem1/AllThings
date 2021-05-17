#include <iostream>

using namespace std;
 
void last() // вызывается функцией three()
{
    std::cout << "Start last\n";
    std::cout << "last throwing int exception\n";
    throw -1;
    std::cout << "End last\n";
 
}
 
void three() // вызывается функцией two()
{
    std::cout << "Start three\n";
    last();
    std::cout << "End three\n";
}
 
void two() // вызывается функцией one()
{
    std::cout << "Start two\n";
    try
    {
        three();
    }
    catch(double)
    {
         std::cerr << "two caught double exception\n";
    }
    std::cout << "End two\n";
}
 
void one() // вызывается функцией main()
{
    std::cout << "Start one\n";
    try
    {
        two();
    }
    catch (int)
    {
         std::cerr << "one caught int exception\n";
    }
    catch (double)
    {
         std::cerr << "one caught double exception\n";
    }
    std::cout << "End one\n";
}
 
int main()
{
    std::cout << "Start main\n";
    try
    {
        one();
    }
    catch (int)
    {
         std::cerr << "main caught int exception\n";
    }
    std::cout << "End main\n";
 
    return 0;
}