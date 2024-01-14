#include <iostream>
using namespace std;
class Base1
{
protected:
    double x, y;

public:
    Base1(double a, double b)
    {
        x = a;
        y = b;
    }
    virtual void f1()
    {
        cout << "Base1 function f1 \n";
        cout << "Value of f1(x,y): " << (x * y + 10) << endl;
    }
};

class Derived1 : public Base1
{
protected:
    double z;

public:
    Derived1(double a, double b, double c) : Base1(a, b)
    {
        z = c;
    }
};

class Derived2 : public Base1
{
protected:
    double t;

public:
    Derived2(double a, double b, double c) : Base1(a, b)
    {
        t = c;
    }
    void f1()
    {
        cout << "Derived2 function f1 : \n";
        cout << "Value of f1(x,y,t) : " << (x + y) * t << endl;
    }
};

int main()
{
    Base1 *p, object_b1(10, 20);
    Derived1 object_d1(5, 10, 2);
    Derived2 object_d2(40, 50, 3);
    p = &object_d2;
    p->f1();
    p = &object_b1;
    p->f1();
    p = &object_d1;
    p->f1();
    return 0;
}