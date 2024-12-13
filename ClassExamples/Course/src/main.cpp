#include <iostream>
#include "Course.cpp"

using namespace course;

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

    // Get notes for each participans
    float grade = 0, totalGrade = 0;

    // **unsigned** keyword allows the variable to be only a positive. The integer can never be a negative value
    unsigned gradeCounter = -1;

    std::cout << "Enter grades in order.. (Enter -1 to quit): \n";
    while (grade != -1)
    {
        gradeCounter++;
        totalGrade += grade;

        std::cout << (gradeCounter + 1) << ". Note: ";
        std::cin >> grade;
    }

    testCourse.setCourseGradeAverage(totalGrade, gradeCounter);
    testCourse.displayCourseGradeAverageText();

    return 0;
}