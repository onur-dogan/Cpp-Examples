#include <iostream>
#include <iomanip>
#include <ostream>
#include <array>
#include <ctime>
#include "DateComparator.h"

// Constant static variables
const std::array<unsigned int, DateComparator::monthsPerYear> DateComparator::daysPerMonth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// Overloaded output stream operator as a friend function
std::ostream &operator<<(std::ostream &output, DateComparator &dateComparator)
{
    output << std::setfill('0')
           << std::setw(2) << dateComparator.getDay() << "/"
           << std::setw(2) << dateComparator.getMonth() << "/"
           << std::setw(4) << dateComparator.getYear()
           << (dateComparator.getTimezone()[0] == '+' ? "(" : "(+") << dateComparator.getTimezone() << ")"
           << std::endl;

    return output;
}

// Overloaded input stream operator as a friend function
std::istream &operator>>(std::istream &input, DateComparator &dateComparator)
{
    input >> std::setw(2) >> dateComparator.day >> std::setw(2) >> dateComparator.month >> std::setw(4) >> dateComparator.year >> dateComparator.timezone;
    // Check inputs and update properties if any one of them is in correct format
    dateComparator.checkInputs();

    return input;
}

// Constructors
/**
 * @param setNowAsDefault ==> Send true to construct class with current date as default
 */
DateComparator::DateComparator(bool setNowAsDefault = true)
{
    if (!setNowAsDefault)
        return;

    // Get the current time and set it as deafult
    time_t timestamp = time(NULL);
    struct tm currentTime = *localtime(&timestamp);
    // Store current time
    this->currentTime = currentTime;

    // Set current date as default
    year = currentTime.tm_year + 1900;
    month = currentTime.tm_mon + 1;
    day = currentTime.tm_mday;
    timezone = currentTime.tm_zone;
}

DateComparator::DateComparator(int yearP, int monthP, int dayP, std::string timezoneP)
    : year(yearP), month(monthP), day(dayP), timezone(timezoneP) {}

// Overloaded operators
DateComparator &DateComparator::operator++()
{
    this->increaseDate(1);
    return *this;
}

void DateComparator::operator++(int increment)
{
    this->increaseDate(1);
}

DateComparator &DateComparator::operator--()
{
    this->decreaseDate(1);
    return *this;
}

void DateComparator::operator--(int decrement)
{
    this->decreaseDate(1);
}

// Getters
std::string DateComparator::getDate() const
{
    std::string dayStr = std::to_string(day);
    std::string monthStr = std::to_string(month);

    return (dayStr.length() == 1 ? ('0' + dayStr) : dayStr) + '/' +
           (monthStr.length() == 1 ? ('0' + monthStr) : monthStr) + '/' +
           std::to_string(year) + ' ' +
           timezone;
}

unsigned int DateComparator::getYear() const
{
    return this->year;
}

unsigned int DateComparator::getMonth() const
{
    return this->month;
}

unsigned int DateComparator::getDay() const
{
    return this->day;
}

std::string DateComparator::getTimezone() const
{
    return this->timezone;
}

// Private Setters
void DateComparator::increaseDate(int)
{
    // If there are days remaining in the current month, then increase it as normal
    if (this->day < daysPerMonth[this->month - 1])
    {
        this->day++;
        return;
    }

    // If the day was the last day of the month, then need to increase the month and set day to the first day of the new month
    if (this->month < monthsPerYear)
    {
        this->month++;
        this->day = 1;
        return;
    }

    // If the month was the last month of the year, then need to increase the year and set the first day and month of the year
    this->year++;
    this->month = 1;
    this->day = 1;
}

void DateComparator::decreaseDate(int)
{
    // If the day isn't 1, then decrease it as normal
    if (this->day > 1)
    {
        this->day--;
        return;
    }

    // If the day was 1, then need to decrease month and set day to the latest day of the new month
    if (this->month > 1)
    {
        this->month--;
        this->day = daysPerMonth[this->month - 1];
        return;
    }

    // If the month was 0, then need to decrease the year and set the latest day and month of the year
    this->year--;
    this->month = monthsPerYear;
    this->day = daysPerMonth[this->month - 1];
}

void DateComparator::checkInputs()
{
    // If the month field isn't in the correct format, set the defaults  
    if (this->month < 1)
        this->month = 1;
    if (this->month > monthsPerYear)
        this->month = monthsPerYear;

    // Year shouldn't be less than 0, if it isn't in the correct format, set the defaults  
    if (this->year < 0)
        this->year = 0001;

    // If the day field isn't in the correct format, set the defaults  
    if (this->day < 1)
        this->day = 1;

    int dayOfMonth = daysPerMonth[this->month - 1];
    if (this->day > dayOfMonth)
        this->day = dayOfMonth;
}

// Destructor
DateComparator::~DateComparator()
{
    std::cout << "Destructing the DateComparator object.. for date: "
              << this->getDate()
              << std::endl;
}
