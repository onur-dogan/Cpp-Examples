// DateComparator.h

#ifndef DATE_COMPARATOR_H
#define DATE_COMPARATOR_H

#include <istream>
#include <ostream>
#include <array>

namespace datecomparator
{
    // This class can't(shouldn't) be a base class
    class DateComparator final
    {
        // Overloaded stream operators
        // Output stream
        friend std::ostream &operator<<(std::ostream &, DateComparator &);
        // Input stream
        friend std::istream &operator>>(std::istream &, DateComparator &);

    public:
        // Constructor
        explicit DateComparator(int, int, int, std::string);
        DateComparator(bool);

        // Getters
        std::string getDate() const;
        unsigned int getYear() const;
        unsigned int getMonth() const;
        unsigned int getDay() const;
        std::string getTimezone() const;

        // Setters
        void setMonth();
        void setMonth(int);
        void setDay();
        void setDay(int);

        // Overloads
        // It overloads the prefix increment operator like ++i
        DateComparator &operator++();
        // It takes an integer paramter and overloads the postfix increment operator like i++
        void operator++(int);
        // It overloads the prefix decrement operator like --i
        DateComparator &operator--();
        // It takes an integer paramter and overloads the postfix decrement operator like i--
        void operator--(int);
        DateComparator &operator+=(int);
        DateComparator &operator-=(int);
        int operator>(DateComparator &) const noexcept;
        int operator<(DateComparator &) const noexcept;

        // Destructor
        ~DateComparator();

    private:
        // Variables
        unsigned int day;
        unsigned int month;
        unsigned int year;
        std::string timezone;

        // Setters
        void increaseDate(int);
        void decreaseDate(int);

        // Helpers
        // Check whether the date fields are in correct format
        void checkInputs();
        // Compare current date with another one
        int compareDates(DateComparator &) const;
        // Format timezone
        std::string formatTimezoneAsText() const;

        // Current time structure
        struct tm currentTime;

        // Constant static variables
        static const size_t monthsPerYear = 12;
        static const std::array<unsigned int, monthsPerYear> daysPerMonth;
    };
}

#endif