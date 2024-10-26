#include <iostream>
#include "Course.h"

using namespace std;

Course::Course(string defaultCourseName) : courseName(defaultCourseName) {};

void Course::setCourseName(string newCourseName)
{
    courseName = newCourseName;
}

string Course::getCourseName() const
{
    return courseName;
}

void Course::displayCourseName() const
{
    cout << "Course Name: " << courseName << endl;
}