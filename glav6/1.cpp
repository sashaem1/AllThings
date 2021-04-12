#include <iostream> //для cout и т.д.
using namespace std;

class Int 
{
    private:
        int nomber;
    public:
        void setZero()
        { nomber = 0; }
        void set(int a)
        { nomber = a; }
        void out()
        { cout << nomber << endl; }
        Int add(Int a)
        {
            Int b;
            b.nomber=a.nomber + nomber;
            return b;
        }
};
// Int Int :: add(Int a)
//         {
//             Int b;
//             b.nomber=a.nomber + nomber;
//             return b;
//         }

int main()
{
    Int a, b, c;
    a.set(9);
    b.set(7);
    c.setZero();
    // a.out();
    // b.out();
    c=a.add(b);
    // c=b;
    c.out();
    a.out();
    b.out();
    return 0;
}
