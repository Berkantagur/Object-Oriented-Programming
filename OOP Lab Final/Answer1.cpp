//Example 1 Answer

//main library
#include <iostream>
//name space
using namespace std;


//main course class
class Course {

//private block for variables
private:
    //variable for course's name
    string name;
    //Variable for course's credits
    int credits;
    //Costant variable for enrollment limit
    const int MAX_ENROLLMENT = 50;
    //variable for holding the number of enrolled students
    int enrollment = 0;

public:
    //static public variable for holding the total course number
    static int totalCourses;
    //constructor function is used to assing values to Course.name and Course.credits variables
    Course(const string& name, int credits) : name(name), credits(credits)
    {
        //Increasing static variable Course.totalCourses every time there is new course created
        totalCourses++;
    }
    //static function for getting the total course number even if there is no courses
    static int getTotalCourses()
    {
        return totalCourses;
    }
    //function for enrolling students to Courses
    void enrollStudent(int enrolling_student_number)
    {
        //checking if course is full
        if (enrollment < MAX_ENROLLMENT && (enrollment+enrolling_student_number) < MAX_ENROLLMENT )
        {
            enrollment = enrollment + enrolling_student_number;
        }
        else
        {

            cout << "Cannot enroll more students. Course is full." << endl;

        }
    }
    //function for displaying all of the course info
    void displayCourseInfo()
    {
        cout << "Course: " << name << endl;
        cout << "Credits: " << credits << endl;
        cout << "Enrollment: " << enrollment << endl;
    }
};

//assigning zero to static totalCourses variable to avoid error
int Course::totalCourses = 0;

int main()
{

    cout << "There is total of " << Course::totalCourses << " Courses as of now" << endl;

    Course OOP_Course("Object Oriented Programing", 4);
    Course DM_Course("Discrete Mathematics", 3);

    OOP_Course.displayCourseInfo();
    DM_Course.displayCourseInfo();

    cout << "There is total of " << Course::totalCourses << " Courses as of now" << endl;

    OOP_Course.enrollStudent(40);
    OOP_Course.enrollStudent(20);
    DM_Course.enrollStudent(40);
    DM_Course.enrollStudent(20);

    OOP_Course.displayCourseInfo();
    DM_Course.displayCourseInfo();


}