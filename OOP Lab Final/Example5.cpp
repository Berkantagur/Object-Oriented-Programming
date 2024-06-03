#include<iostream>
using namespace std;

//Template functions that take two arguments from same type
template <typename X> void swapargs(X &a, X &b)
{
    X temp;
    temp = a;
    a = b;
    b = temp;
}
//overloadind of the previous template function
void swapargs(int a, int b)
{
    cout <<"Overloaded swap. Int a: " <<a << " Int b: " << b << endl;
}

int main()
{
    int i = 10, j = 20;
    float x = 10.1, y = 23.3;

    cout << "Original i, j:" << i << ' ' << j << endl;
    cout << "Original x, y:" << x << ' ' << y << endl;
    swapargs(i,j); //Calls the overloaded version of the function because two integers given as parameters
    swapargs(x,y); //Calls the original template function because two float variables given as arguments
    cout << "Swapped i, j:" << i << ' ' << j << endl;
    cout << "Swapped x, y:" << x << ' ' << y << endl;

    return 0;
}

// Output
// Original i, j:10 20
// Original x, y:10.1 23.3
// Overloaded swap. Int a: 10 Int b: 20
// Swapped i, j:10 20
// Swapped x, y:23.3 10.1
