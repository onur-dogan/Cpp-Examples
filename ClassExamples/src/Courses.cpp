#include <iostream>
using namespace std;

class Course
{
private:
    // Define variables that will be private and be able to be used in the class functions only
    string courseName;

public:
    // Set course name as default in explicit(constructor)
    // It is mostly good to define a default variable in constructur instead of waiting to set a value to the variables
    explicit Course(string defaultCourseName) : courseName(defaultCourseName) {}

    void setCourseName(string newCourseName)
    {
        this->courseName = newCourseName;
    }

    string getCourseName() const
    {
        return this->courseName;
    }

    void displayCourseName() const
    {
        cout << this->courseName << endl;
    }
};

int main()
{
    // Define a new course variable that have Course class properties
    Course myCourse("Test Course");
    cout << "Display default defined course name manually ==> " << myCourse.getCourseName() << endl;

    myCourse.setCourseName("Changed Test Course");
    cout << "Display course name manually ==> " << myCourse.getCourseName() << endl;

    cout << "Display course name by using func in class ==> ";
    myCourse.displayCourseName();

    return 0;
}