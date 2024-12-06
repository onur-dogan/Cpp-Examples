#include <iostream>
#include <iomanip>
#include "Time.h"
#include "TimeException.cpp"

// *** Overloaded constructors ***
// They allow to get limited parameters and sets the missing ones automatically
// It is good to run the projects successfully for any situation(error)
// They all go to the main constructor(with 3 parameter) so it's important to define it correctly
Time::Time() : Time(0, 0, 0) {}
Time::Time(int hour) : Time(hour, 0, 0) {}
Time::Time(int hour, int minute) : Time(hour, minute, 0) {}

// Main constructor function to set the private values.
Time::Time(int hour, int minute, int second)
{
    setHour(hour);
    setMinute(minute);
    setSecond(second);
}

// Destructor function
Time::~Time()
{
    std::cout << "\nAll time class work flows are done. The destructor is running for...\n"
              << "Hour: " << hour
              << "\t Minute: " << minute
              << "\t Second: " << second
              << "\nTime class is destructed successfully! Thanks for using."
              << std::endl;
}

// Set private values in a function
void Time::setTime(int h, int m, int s)
{
    try
    {
        // Set private fields via set functions
        setHour(h);
        setSecond(s);
        setMinute(m);
    }
    catch (TimeException &timeException)
    {
        std::cout << "Exception occurred: " << timeException.what() << std::endl;
    }
}

void Time::setHour(int h)
{
    if (h < 0 || h > 24)
        throw TimeException("Entered hour was out of range");

    hour = h;
}

void Time::setMinute(int m)
{
    if (m < 0 || m > 60)
        throw TimeException("Entered minute was out of range");

    minute = m;
}

void Time::setSecond(int s)
{
    if (s < 0 || s > 60)
        throw TimeException("Entered second was out of range");

    second = s;
}

unsigned int Time::getHour() const
{
    return hour;
}

unsigned int Time::getMinute() const
{
    return minute;
}

unsigned int Time::getSecond() const
{
    return second;
}

void Time::showTime() const
{
    std::cout << "Time is: \t"
              << std::setfill('0')
              << std::setw(2) << getHour() << ":"
              << std::setw(2) << getMinute() << ":"
              << std::setw(2) << getSecond()
              << (hour >= 12 ? " PM" : " AM")
              << std::endl;
}