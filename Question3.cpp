//Create the missing classes dont change the int main() or the Employee class. OUTPUT of the code(if missing classes are completed) are below.

#include <iostream>
using namespace std;

// Base class Employee
class Employee {
public:
    static int totalpersonelnumber;
    // Pure virtual function
    virtual void displayInfo()
    {
        
    }
    // Virtual destructor
    Employee()
    {
        totalpersonelnumber++;
    }
};






int Employee::totalpersonelnumber = 0;
int Engineer::numberofEngineers = 0;
int Manager::numberofmanagers = 0;

int main()
{
    Engineer Engineer1("Hakan","Hardware"), Engineer2("Mahmut","Forensics");
    Manager Manager1("Niyazi","Hardware",3);

    Engineer1.displayInfo();
    Engineer2.displayInfo();
    Manager1.displayInfo();
    Manager1.displaymanagerInfo();
    Engineer::displayengineernumber();
    Manager::displaymanagernumber();

    /*
        OUTPUT:
        Engineer: Hakan, Specialty: Hardware
        Engineer: Mahmut, Specialty: Forensics
        Engineer: Niyazi, Specialty: Hardware also have managerial role
        Manager: Niyazi has a team with size of: 3
        There is 3 number of engineers of 3 total number personel
        There is 1 managers of 3 total number personel
    */

    return 0;
}
