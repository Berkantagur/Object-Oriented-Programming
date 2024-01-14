#include <iostream>
using namespace std;
class B1
{
private:
    int a;

public:
    B1(int x)
    {
        a = x;
        cout << "Base B1 a =" << a << endl;
    }
    B1()
    {
        a = 100;
        cout << "Base B1(no param) a =" << a << endl;
    }
    ~B1() { cout << "Destructing B1 a = " << a << endl; }
    int geta() { return a; }
};
class B2
{
private:
    int b;

public:
    B2(int x)
    {
        b = x;
        cout << "Base B2 b =" << b << endl;
    }
    ~B2() { cout << "Destructing B2 b = " << b << endl; }
    int getb() { return b; }
};
class D : public B2, public B1
{
private:
    int c;

public:
    D(int x, int y) : B2(x), B1()
    {
        c = y;
        cout << "Constructing D(no parameter) c = " << c << endl;
    }
    D(int x, int y, int z) : B2(x), B1(y)
    {
        c = z;
        cout << "Constructing D c = " << c << endl;
    }
    ~D() { cout << "Destructing D c = " << c << endl; }
    void show()
    {
        cout << "a = " << geta() << ", b = " << getb() << ", c =" << c << endl;
    }
};
int main()
{
    int i;
    B2 bo2(15);
    cout << "b of bo2 = " << bo2.getb() << endl;
    D ob(3, 5, 8);
    ob.show();
    B1 bo1(20);
    cout << "a of bo1 = " << bo1.geta() << endl;
    return 0;
}