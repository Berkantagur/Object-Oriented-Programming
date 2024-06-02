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

// Derived class Engineer
class Engineer : public Employee {
protected:
    string name;
    string specialty;

public:
    static int numberofEngineers;
    Engineer(const string& n, const string& s) : name(n), specialty(s), Employee()
    {
        numberofEngineers++;
    }

    void displayInfo() override
    {
        cout << "Engineer: " << name << ", Specialty: " << specialty << endl;
    }
    static void displayengineernumber()
    {
        cout << "There is " << numberofEngineers <<" number of engineers of "<< totalpersonelnumber << " total number personel" << endl;
    }
};

// Derived class Manager
class Manager : public Engineer {
private:
    //variable for holding the manager's team size
    int teamSize;

public:
    static int numberofmanagers;

    Manager(const string& n, const string& s, int t) : teamSize(t),Engineer(n,s)
    {
        numberofmanagers++;
    }
     void displayInfo() override
    {
        cout << "Engineer: " << name << ", Specialty: " << specialty << " also have managerial role" << endl;
    }
    void displaymanagerInfo()
    {
        cout << "Manager: " << name << " has a team with size of: " << teamSize << endl;
    }
    static void displaymanagernumber()
    {
        cout << "There is " << numberofmanagers << "managers of " << totalpersonelnumber << "total number personel" << endl;
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

    return 0;
}

    /*
        OUTPUT:
        Engineer: Hakan, Specialty: Hardware
        Engineer: Mahmut, Specialty: Forensics
        Engineer: Niyazi, Specialty: Hardware also have managerial role
        Manager: Niyazi has a team with size of: 3
        There is 3 number of engineers of 3 total number personel
        There is 1managers of 3total number personel
    */