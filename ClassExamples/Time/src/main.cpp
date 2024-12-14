#include <iostream>
#include "Time.h"

using namespace timeClass;

int main()
{
    std::cout << "\n*** Welcome to review the Time Class Examples ***\n"
              << std::endl;

    Time time;
    // A reference value that stores the reference address of the time variable
    Time &timeRef = time;
    // A pointer value that stores the reference adress of the time variable
    Time *timePtr = &time;

    int hour, minute, second;
    std::cout << "Enter hour, minute and second in order:" << std::endl;
    std::cin >> hour >> minute >> second;

    timePtr->setTime(hour, minute, second);
    timePtr->showTime();

    std::cout << "Time Ref's memory address(&timeRef): " << &timeRef
              << "\nTime variable's memory address(&time (Same with the above one)): " << &time
              << "\nTime Pointer's value(timePtr (Same with the above one)): " << timePtr
              << "\nTime Pointer's memory address(&timePtr (It's own memory address)): " << timePtr
              << std::endl;

    /**
     * Let's test the destructor functions. Create another time referenced class and set another time
     * Then, just display the time for the new one and see which order the destructor logs will appear in
     */
    Time time2;
    Time *time2Ptr = &time2;

    int hour2, minute2, second2;
    std::cout << "\nEnter hour, minute and second in order for the second time variable" << std::endl;
    std::cin >> hour2 >> minute2 >> second2;

    time2Ptr->setTime(hour2, minute2, second2);

    // The newly created class is destructed first and then the first one.
    // Also, the destructor functions wait until all of the main scope lines are run.
    // After the workflows are completed for the related defined classes, the destructor functions trigger.
    time2Ptr->showTime();

    return 0;
}