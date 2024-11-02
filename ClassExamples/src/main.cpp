#include <iostream>
#include "Course.cpp"

int main()
{
    // Define a new course variable that have Course class properties
    Course testCourse("Test Course", "Random Author", 20);
    std::cout << "Display default defined course name and instructor manually ==> "
              << testCourse.getCourseName() + " - "
              << testCourse.getCourseInstructor()
              << std::endl;

    // Set a new course informations
    testCourse.setCourseName("Changed Test Course Long Name");
    testCourse.setCourseInstructor("Changed Test Instructor Name");
    std::cout << "Display new course's name manually ==> " << testCourse.getCourseName()
              << "- " + testCourse.getCourseInstructor()
              << " (Course name character length: " << testCourse.getCourseNameLength() << ")"
              << std::endl;

    std::cout << "Display course name and instructor by using func in class ==> \n";
    testCourse.displayCourseName();
    testCourse.displayCourseInstructor();

    return 0;
}