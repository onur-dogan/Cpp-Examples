#include <iostream>
#include "Course.h"

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

std::string Course::getCourseName() const
{
    return courseName;
}

std::string Course::getCourseInstructor() const
{
    return courseInstructor;
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