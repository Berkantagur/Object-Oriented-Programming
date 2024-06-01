// With using class structure on the above write code for creating two course named Object Oriented Programing (with 4 credits) and Discrete Mathematics(with 3 credits) and enroll 40 students each and after that  try to enroll 20 student more.
// Display total course number before and after creating the courses, also display information about the courses after creating courses.

#include <iostream>
using namespace std;

// Course class
class Course {
// private block for variables
private:
    string name; // variable for course's name
    int credits; // variable for course's 
    
    const int MAX_ENROLLMENT = 50; // constant variable for enrollment limit
    int enrollment = 0; // variable for holding the number of enrolled students
    
public:
    static int totalCourses; // static public variable for holding the total course number
    
    // constructor function is used to assign values to Course.name and Course.credits variables
    Course(const string& name, int credits) : name(name), credits(credits)
    {
        // Increasing static variable Course.totalCourses every time there is new course created
        totalCourses++;
    }
    
    // static function for getting the total course number even if there is no courses
    static int getTotalCourses()
    {
        return totalCourses;
    }
    
    // function for enrolling students to Courses
    void enrollStudent(int enrolling_student_number)
    {
        // checking if course is full
        if (enrollment < MAX_ENROLLMENT && (enrollment+enrolling_student_number) < MAX_ENROLLMENT )
        {
            enrollment = enrollment + enrolling_student_number;
        }
        else
        {
            cout << "Cannot enroll more students. Course is full." << endl;
        }
    }
    
    // function for displaying all of the course info
    void displayCourseInfo()
    {
        cout << "Course: " << name << endl;
        cout << "Credits: " << credits << endl;
        cout << "Enrollment: " << enrollment << endl;
    }
};

// assigning zero to static totalCourses variable to avoid error
int Course::totalCourses = 0;

int main()
{
    // Creating two courses
    Course OOP("Object Oriented Programming", 4);
    Course DM("Discrete Mathematics", 3);
    
    // Enrolling 40 students to each course
    OOP.enrollStudent(40);
    DM.enrollStudent(40);
    
    // Enrolling 20 more students to each course
    OOP.enrollStudent(20);
    DM.enrollStudent(20);
    
    // Displaying total course number before and after creating the courses
    cout << "Total course number before creating the courses: " << Course::getTotalCourses() - 2 << endl;
    cout << "Total course number after creating the courses: " << Course::getTotalCourses() << endl;
    
    // Displaying information about the courses after creating courses
    OOP.displayCourseInfo();
    DM.displayCourseInfo();
    
    return 0;
}

// Output
// Cannot enroll more students. Course is full.
// Cannot enroll more students. Course is full.
// Total course number before creating the courses: 0
// Total course number after creating the courses: 2
// Course: Object Oriented Programming
// Credits: 4
// Enrollment: 40
// Course: Discrete Mathematics
// Credits: 3
// Enrollment: 40