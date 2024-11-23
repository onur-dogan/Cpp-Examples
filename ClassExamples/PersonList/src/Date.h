// Date.h

#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <array>

// This class can't(shouldn't) be a base class
class Date final
{
public:
    // When a variable is declared as static, space for it gets allocated for the lifetime of the program.
    // Even if the function is called multiple times, space for the static variable is allocated only once
    static unsigned int const monthsPerYear = 12;

    // Constructor
    explicit Date(int = 2024, int = 1, int = 1);

    // Setters
    void setDate(int, int, int);
    void setYear(int);
    void setMonth(int);
    void setDay(int);

    // Getters
    std::string getDate() const;
    unsigned int getYear() const;
    unsigned int getMonth() const;
    unsigned int getDay() const;

    // Printers
    void showDate() const;

    // Destructor
    ~Date();

private:
    unsigned int year;
    unsigned int month;
    unsigned int day;

    // Helpers
    // Check functions flow shouldn't be updated from any other location. It might cause to break check functionalities.
    // If they don't work properly, this class's functionalities don't work correctly.
    bool checkDayByMonth(int) const;
    bool checkMonth(int) const;
};

#endif