#include <iostream>
using namespace std;
class Base1
{
public:
    double x;
    Base1(double a)
    {
        x = a;
        cout << "Constructing Base1 " << x << endl;
    }
    ~Base1() { cout << "Destructing Base1 " << x << endl; }
};

class Derived1 : public Base1
{
public:
    double y;

public:
    Derived1(double a, double b) : Base1(a)
    {
        y = b;
        cout << "Constructing Derived1 " << y << endl;
    }
    ~Derived1() { cout << "Destructing Derived1 " << y << endl; }
};

class Derived2 : public Derived1
{
public:
    double z;
    Derived2(double a, double b, double c) : Derived1(a, b)
    {
        z = c;
        cout << "Constructing Derived2 " << z << endl;
    }
    ~Derived2() { cout << "Destructing Derived2 " << z << endl; }
};

int main()
{
    Derived1 object_1(5, 10);
    Derived2 object_2(20, 30, 50);
    Base1 object_3(150);
    return 0;
}