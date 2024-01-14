// Write the program code for overloading the operator " = " (assignment operator) for class class1 which is declared below.
// dim_a is size the double type vector that the pointer " *A " points. You must take into account whether sizes of the vectors
// of the objects are same or not while overloading the operator " = "
class class1
{
public:
    int dim_a;
    double *A;
    class1(int a)
    {
        dim_a = a;
        A = new double[dim_a] // constructer
        ~class1()
        {
            delete[] A; // destructer
        }
        class1 &operator=(class1 &object_1); // " = " declaration of the operator " = "
    }