#include <iostream>
//library for advanced math operation
#include <cmath>
using namespace std;


template <class T1, class T2>
class BasicMathOperations
{
    protected:

        T1 operand1;
        T2 operand2;

    public:
        //constructor function
        BasicMathOperations(T1 operand1, T2 operand2):operand1(operand1),operand2(operand2) {}

        static T1 addition(T1 op1, T2 op2)
        {
            return (op1+op2);
        }

        static T1 subtraction(T1 op1, T2 op2)
        {
            return (op1-op2);
        }
        static T1 multiplication(T1 op1, T2 op2)
        {
            return (op1*op2);
        }
        static T1 division(T1 op1, T2 op2)
        {
            return (op1/op2);
        }
};

int main()
{
    int op1 = 12;
    double op2 = 4.0 , op3 = 0;

    try
    {
        cout << BasicMathOperations<int, double>::addition(op1, op2)<< endl;
        cout << BasicMathOperations<int, double>::subtraction(op1, op2)<< endl;
        cout << BasicMathOperations<int, double>::multiplication(op1, op2)<< endl;
        cout << BasicMathOperations<int, double>::division(op1, op2)<< endl;

    }
    catch(const exception& e)
    {
        cout << "ERROR!!" << endl;
    }
}
