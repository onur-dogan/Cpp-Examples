#include <iostream>
#include "Course.cpp"

using namespace std;

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