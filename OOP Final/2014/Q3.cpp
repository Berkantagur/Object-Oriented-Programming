#include <iostream>
using namespace std;
struct A
{
    double x, y, z;
    A(double a, double b, double c)
    {
        x = a;
        y = b;
        z = c;
    };
};

void error_function(int error)
{
    try
    {
        double x = 5;
        int y = 8;
        double z = 15;
        long int t = 250;
        A u(10, 20, 30);

        if (error == 0)
        {
            throw x;
        }
        else if (error == 1)
        {
            throw t;
        }
        else if (error == 2)
        {
            throw "string error 1";
        }
        else if (error == 3)
        {
            throw u;
        }
        else if (error == 4)
        {
            throw y;
        }
        else if (error == 5)
        {
            throw "string error 2";
        }
        else if (error == 6)
        {
            throw u;
        }
        else
            cout << "No error" << endl;
    }
    catch (double x)
    {
        cout << "Caught double error. Error: " << x << endl;
    }
    catch (int x)
    {
        cout << "Caught integer error. Error: " << x << endl;
    }
    catch (char *x)
    {
        cout << "Caught string error. Error: " << x << endl;
    }
    catch (A x)
    {
        cout << "Caught A error. Error: " << x.x << " " << x.y << " " << x.z << endl;
    }
    catch (...)
    {
        cout << "Unknown error" << endl;
    }
}

int main()
{
    error_function(5);
    error_function(6);
    error_function(4);
    error_function(2);
    error_function(3);
    error_function(1);
    error_function(0);
    return 0;
}