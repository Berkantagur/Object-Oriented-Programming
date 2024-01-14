#include <iostream>
using namespace std;
class myclass
{
public:
    double x, y;
    myclass(double a, double b)
    {
        x = a;
        y = b;
        cout << "Constructing, x =" << x << " y =" << y << endl;
    };
    myclass(const myclass &ob1)
    {
        x = ob1.x;
        y = ob1.y;
        cout << "Copy Constructor, x =" << x << " y =" << y << endl;
    };
    ~myclass() { cout << "Destroying, x =" << x << " y =" << y << endl; };
    void show() { cout << "x =" << x << " y =" << y << endl; }
};
void fun1(myclass ob1)
{
    myclass ob(5, 20);
    ob.x = ob.x + ob1.x;
    ob.y = ob.y + ob1.y;
    cout << "x = " << ob.x << " y =" << ob.y << endl;
}
int main()
{
    myclass ob1(50, 100);
    myclass ob2 = ob1;
    fun1(ob1);
    ob1.show();
    fun1(ob2);
    ob2.show();
    return 0;
}