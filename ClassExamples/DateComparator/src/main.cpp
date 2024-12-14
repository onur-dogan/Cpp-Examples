#include <iostream>
#include "DateComparator.h"

using namespace datecomparator;

int main()
{
    std::cout << "\n*** Welcome to review the Date Comparator Class Examples ***\n"
              << std::endl;

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

    unsigned int increment;
    std::cout << "Enter a positive number to see the dates based on the number you entered" << std::endl;
    std::cin >> increment;

    currentDate += increment;
    std::cout << "Current Date after insertion: " << currentDate;
    currentDate -= increment;
    std::cout << "Current Date was: " << currentDate << std::endl;

    enteredDate += increment;
    std::cout << "Entered Date after insertion: " << enteredDate;
    enteredDate -= increment;
    std::cout << "Entered Date was: " << enteredDate << std::endl;

    std::cout << "*** FINAL RESULTS ***" << std::endl;
    int compareEnteredDateToCurrent = enteredDate > currentDate;
    std::cout << "Entered date is "
              << ((compareEnteredDateToCurrent == 1) ? "later than" : compareEnteredDateToCurrent == -1 ? "earlier than"
                                                                                                        : "equal to")
              << " the current date\n"
              << std::endl;

    DateComparator lastDateOfTheYear;
    lastDateOfTheYear.setMonth();
    lastDateOfTheYear.setDay();
    int enteredDateEarlierThanLastDay = enteredDate < lastDateOfTheYear;
    std::cout << "Question: Is entered date earlier than last day of this year ("
              << enteredDate.getDate() << ") < (" << lastDateOfTheYear.getDate() << ") ?\n"
              << "Answer: " << (enteredDateEarlierThanLastDay == 1 ? "Yes" : "No")
              << std::endl;

    return 0;
}