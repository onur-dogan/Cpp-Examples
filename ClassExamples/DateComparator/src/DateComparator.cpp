#include <iostream>
#include <iomanip>
#include <ostream>
#include <array>
#include <ctime>
#include "DateComparator.h"

namespace datecomparator
{
    // Constant static variables
    const std::array<unsigned int, DateComparator::monthsPerYear> DateComparator::daysPerMonth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Overloaded output stream operator as a friend function
    std::ostream &operator<<(std::ostream &output, DateComparator &dateComparator)
    {
        output << std::setfill('0')
               << std::setw(2) << dateComparator.getDay() << "/"
               << std::setw(2) << dateComparator.getMonth() << "/"
               << std::setw(4) << dateComparator.getYear()
               << dateComparator.formatTimezoneAsText()
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
        // Store the current time
        this->currentTime = *localtime(&timestamp);

        // Set current date as default
        year = currentTime.tm_year + 1900;
        month = currentTime.tm_mon + 1;
        day = currentTime.tm_mday;
        timezone = currentTime.tm_zone;
    }

    DateComparator::DateComparator(int yearP, int monthP, int dayP, std::string timezoneP)
        : year(yearP), month(monthP), day(dayP), timezone(timezoneP) {}

    // Default date comparator class that generates default date
    DateComparator::DateComparator() : DateComparator(true) {}

    // Getters
    std::string DateComparator::getDate() const
    {
        std::string dayStr = std::to_string(day);
        std::string monthStr = std::to_string(month);

        return (dayStr.length() == 1 ? ('0' + dayStr) : dayStr) + '/' +
               (monthStr.length() == 1 ? ('0' + monthStr) : monthStr) + '/' +
               std::to_string(year) + ' ' +
               formatTimezoneAsText();
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

    // Setters
    // Set the last month of the year as default
    void DateComparator::setMonth()
    {
        setMonth(monthsPerYear);
    }

    void DateComparator::setMonth(int month)
    {
        this->month = month;
    }

    void DateComparator::setDay()
    {
        setDay(daysPerMonth[this->month - 1]);
    }

    void DateComparator::setDay(int day)
    {
        this->day = day;
    }

    // Overloaded operators
    DateComparator &DateComparator::operator++()
    {
        this->increaseDate(1);
        return *this;
    }

    void DateComparator::operator++(int)
    {
        this->increaseDate(1);
    }

    DateComparator &DateComparator::operator+=(int increment)
    {
        this->increaseDate(increment);
        return *this;
    }

    DateComparator &DateComparator::operator--()
    {
        this->decreaseDate(1);
        return *this;
    }

    void DateComparator::operator--(int)
    {
        this->decreaseDate(1);
    }

    DateComparator &DateComparator::operator-=(int decrement)
    {
        this->decreaseDate(decrement);
        return *this;
    }

    int DateComparator::operator>(DateComparator &dateToCompare) const noexcept
    {
        int compareResult = this->compareDates(dateToCompare);
        return compareResult;
    }

    int DateComparator::operator<(DateComparator &dateToCompare) const noexcept
    {
        int compareResult = this->compareDates(dateToCompare);
        return -compareResult;
    }

    // Private Setters
    void DateComparator::increaseDate(int increment)
    {
        // If there are days remaining in the current month, then increase it as normal
        if (this->day + increment <= daysPerMonth[this->month - 1])
        {
            this->day += increment;
            return;
        }

        // If the incremented day isn't available in current month, map months to find new date
        increment -= (daysPerMonth[this->month - 1] - this->day);
        while (increment > 0)
        {
            this->month++;
            // If the month is the latest month of the year, then increase year and set month to the first month
            if (this->month > this->monthsPerYear)
            {
                this->year++;
                this->month = 1;
            }

            // If the increment value is less than the days of the month, then add it to the day
            if (increment <= daysPerMonth[this->month - 1])
            {
                this->day = increment;
                break;
            }

            // Otherwise, decrease increment value and check the next month
            increment -= daysPerMonth[this->month - 1];
        }
    }

    void DateComparator::decreaseDate(int decrement)
    {
        int difference = this->day - decrement;
        if (difference > 0)
        {
            this->day -= decrement;
            return;
        }

        // If the incremented day isn't available in current month, map months to find new date
        decrement -= this->day;
        while (decrement > 0)
        {
            this->month--;
            // If the month is the latest month of the year, then increase year and set month to the first month
            if (this->month < 1)
            {
                this->year--;
                this->month = this->monthsPerYear;
            }

            // If the increment value is less than the days of the month, then add it to the day
            if (decrement < daysPerMonth[this->month - 1])
            {
                this->day = daysPerMonth[this->month - 1] - decrement;
                break;
            }

            // Otherwise, decrease increment value and check the next month
            decrement -= daysPerMonth[this->month - 1];
        }
    }

    int DateComparator::compareDates(DateComparator &dateToCompare) const
    {
        if (this->getYear() != dateToCompare.getYear())
            return this->getYear() > dateToCompare.getYear() ? 1 : -1;

        if (this->getMonth() != dateToCompare.getMonth())
            return this->getMonth() > dateToCompare.getMonth() ? 1 : -1;

        if (this->getDay() == dateToCompare.getDay())
            return 0;

        return this->getDay() > dateToCompare.getDay() ? 1 : -1;
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

    std::string DateComparator::formatTimezoneAsText() const
    {
        return (this->timezone[0] == '+' ? "(" : "(+") + this->timezone + ")";
    }

    // Destructor
    DateComparator::~DateComparator()
    {
        std::cout << "Destructing the DateComparator object.. for date: "
                  << this->getDate()
                  << std::endl;
    }
}