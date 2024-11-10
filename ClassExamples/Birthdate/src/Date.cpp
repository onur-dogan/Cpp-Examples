#include <iostream>
#include <iomanip>
#include "Date.h"

Date::Date(int year, int month, int day)
{
    setDate(year, month, day);
}

void Date::setDate(int year, int month, int day)
{
    setYear(year);
    setMonth(month);
    setDay(day);
}

void Date::setYear(int newYear)
{
    year = newYear;
}

void Date::setMonth(int newMonth)
{
    if (checkMonth(newMonth))
        month = newMonth;
}

void Date::setDay(int newDay)
{
    if (checkDayByMonth(newDay))
        day = newDay;
}

std::string Date::getDate() const
{
    std::string dayStr = std::to_string(day);
    std::string monthStr = std::to_string(month);

    return (dayStr.length() == 1 ? ('0' + dayStr) : dayStr) + '/' + (monthStr.length() == 1 ? ('0' + monthStr) : monthStr) + '/' + std::to_string(year);
}

unsigned int Date::getYear() const
{
    return year;
}

unsigned int Date::getMonth() const
{
    return month;
}

unsigned int Date::getDay() const
{
    return day;
}

void Date::showDate() const
{
    std::cout << "\n Date: \t"
              << std::setfill('0')
              << std::setw(2) << day
              << std::setw(2) << month
              << std::setw(4) << year
              << std::endl;
}

bool Date::checkDayByMonth(int birthDay) const
{
    static const std::array<int, monthsPerYear + 1> daysPerMonth = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int dayByMonth = daysPerMonth[month];
    if (birthDay < 0 || birthDay > dayByMonth)
        return false;

    return true;
}

bool Date::checkMonth(int monthP) const
{
    if (monthP < 0 || monthP > monthsPerYear)
        return false;

    return true;
}

Date::~Date()
{
    std::cout << "\nDate Class is destructing with fields:..."
              << "Year: " << year
              << "Month: " << month
              << "Day: " << day
              << std::endl;
}