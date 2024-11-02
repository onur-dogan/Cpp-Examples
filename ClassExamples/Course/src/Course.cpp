#include <iostream>
#include "Course.h"
#include <iomanip>

Course::Course(std::string defaultCourseName, std::string defaultCourseInstructor, int defaultCourseNameLimit)
    : courseNameLimit(defaultCourseNameLimit), courseInstructor(defaultCourseInstructor)
{
    setCourseName(defaultCourseName);
}

void Course::setCourseName(std::string newCourseName)
{
    // Store limited character
    courseName = newCourseName.size() > courseNameLimit ? newCourseName.substr(0, courseNameLimit) : newCourseName;
}

void Course::setCourseInstructor(std::string newCourseInstructor)
{
    courseInstructor = newCourseInstructor;
}

void Course::setCourseGradeAverage(float totalGrade, int gradesLength)
{
    if (totalGrade <= 0 | gradesLength < 1)
        return;

    courseGradeLength = gradesLength;
    courseGradeAverage = static_cast<double>(totalGrade) / gradesLength;
}

std::string Course::getCourseName() const
{
    return courseName;
}

std::string Course::getCourseInstructor() const
{
    return courseInstructor;
}

float Course::getCourseGradeAverage() const
{
    return courseGradeAverage;
}

float Course::getCourseGradeLength() const
{
    return courseGradeLength;
}

void Course::displayCourseGradeAverageText() const
{
    std::cout << "Number of participants: " << getCourseGradeLength();
    /**
     * ** setprecision ** limitates the length of the numbers after comma
     * ** fixed ** writes floating-point values in fixed-point notation.
     * The value is represented with exactly as many digits in the decimal part as specified by the precision field (precision) and with no exponent part.
     * */
    std::cout << std::setprecision(2) << std::fixed;
    std::cout << "\nAverage Grade: " << getCourseGradeAverage() << std::endl;
}

int Course::getCourseNameLength() const
{
    return courseName.size();
}

void Course::displayCourseName() const
{
    std::cout << "Course Name: " << courseName
              << " (Course name character length: " << getCourseNameLength() << ")"
              << std::endl;
}

void Course::displayCourseInstructor() const
{
    std::cout << "Course Instructor: " << courseInstructor << std::endl;
}