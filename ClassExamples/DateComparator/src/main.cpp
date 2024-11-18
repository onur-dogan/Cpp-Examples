#include <iostream>
#include "DateComparator.cpp"

int main()
{
    // Current date
    DateComparator currentDate;
    // Print current date
    std::cout << "Current Date: \t" << currentDate;
    // Show the tomorrow's date after using overloaded *postfix* increment operator
    currentDate++;
    std::cout << "Tomorrow: \t" << currentDate;
    // Show the yesterday's date after using overloaded *postfix* and *prefix* decrement operators
    currentDate--;
    --currentDate;
    std::cout << "Yesterday was: \t" << currentDate;
    // Set current date again by using the overloaded *prefix* increment order
    ++currentDate;

    // Another date entered by the user
    DateComparator enteredDate(false);
    std::cout << "Enter the date you would like to compare with today. Day, Month, Year in order" << std::endl;
    std::cin >> enteredDate;
    // Print entered date
    std::cout << "Entered Date: \t" << enteredDate;
    // Show the one day later after using overloaded *postfix* increment operator
    enteredDate++;
    std::cout << "Tomorrow: \t" << enteredDate;
    // Show the one day ago after using overloaded *postfix* and *prefix* decrement operators
    enteredDate--;
    --enteredDate;
    std::cout << "Yesterday was: \t" << enteredDate;
    // Set current date again by using the overloaded *prefix* increment order
    ++enteredDate;

}