#include <iostream>
#include <typeinfo>
using namespace std;
class Base
{
public:
    int x;
    virtual void f()
    {
        cout << x << "is a Base object\n";
    };
};
class Derived : public Base
{
public:
    int y;
    void derivedOnly()
    {
        cout << y << " " << x << "is a Derived object\n";
    }
};
int main()
{
    Base *bp, b_ob;
    Derived *dp, d_ob;
    b_ob.x = 3;
    d_ob.x = 5;
    d_ob.y = 8;
    bp = &b_ob;
    cout << typeid(*bp).name() << endl;
    bp = &d_ob;
    cout << typeid(*bp).name() << endl;
    dp = (Derived *)bp;
    dp->derivedOnly();
    bp = &d_ob;
    dp = dynamic_cast<Derived *>(bp);
    if (dp)
        dp->derivedOnly();
    else
        cout << "Cast from Base to Derived failed.\n";
    bp = &b_ob;
    dp = dynamic_cast<Derived *>(bp);
    if (dp)
        dp->derivedOnly();
    else
        cout << "Error, cast should work.\n";
    return 0;
}