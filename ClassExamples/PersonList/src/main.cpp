#include <iostream>
#include <vector>
#include <queue>
#include <typeinfo>
#include <unistd.h>
#include <iomanip>

#include "Date.h"
#include "Person.h"
#include "PhoneNumber.h"
#include "Manager.h"

using namespace dateClass;
using namespace personClass;
using namespace phoneNumberClass;
using namespace managerClass;

int main()
{
    // Custom type definitions
    typedef std::vector<Person *> vPersonPtr;
    typedef std::vector<Manager *> vManagerPtr;
    typedef Manager *managerPtr;

    Date birthDate(1961, 4, 12);
    Date joinDate(1990, 6, 24);
    PhoneNumber personPhoneNumber;

    // Register first person
    Person firstPerson("Test", "Person", "Male", personPhoneNumber, birthDate, joinDate);

    Date birthDate2(1970, 12, 3);
    Date joinDate2(1992, 1, 6);
    PhoneNumber personPhoneNumber2;

    Person secondPerson;
    // Register second person
    secondPerson.setInformations("Test2", "Person2", 2, personPhoneNumber2, birthDate2, joinDate2);

    // Show the person list
    std::cout << "\n"
              << std::setw(40) << std::right << "*** PERSON LIST ***"
              << "\nPerson Count which is registered to the system: \t" << Person::getPersonsCount()
              << std::endl;

    vPersonPtr persons{&firstPerson, &secondPerson};
    for (const auto *person : persons)
    {
        // typeid expression allows us to reach the class information of the variable
        std::cout << "\nClass Type: (It writes like PK({Length of Class Name}){Class Name}. e.g. 'PK7Manager') "
                  << typeid(person).name()
                  << std::endl;

        person->showInformations();
    }

    // Update first person's information by using a common function
    std::string newFirstName, newLastName;
    std::cout << "Enter first and last name to change " << firstPerson.getFullName() << "'s full name" << std::endl;
    std::cin >> newFirstName >> newLastName;

    firstPerson.setFullName(newFirstName, newLastName);

    std::string countryCode, areaCode, phoneDigits;
    std::cout << "Enter phone country code, area code and phone digits (e.g. 902120001122) in order to change "
              << firstPerson.getFullName() << "'s phone number"
              << std::endl;
    std::cin >> std::setw(2) >> countryCode >> std::setw(3) >> areaCode >> std::setw(7) >> phoneDigits;

    personPhoneNumber.setPhoneNumber(countryCode, areaCode, phoneDigits);
    firstPerson.setPhoneNumber(personPhoneNumber);

    firstPerson.showInformations();

    // Second Person Processes
    // Update second person's information by using a friend function
    std::string newName;
    std::cout << "Enter a name to change the second person's name" << std::endl;
    std::cin >> newName;

    setFirstNameByFriendFunc(secondPerson, newName);

    std::string countryCode2, areaCode2, phoneDigits2;
    std::cout << "Enter phone country code, area code and phone digits (e.g. 902120001122) in order to change "
              << secondPerson.getFullName() << "'s phone number"
              << std::endl;
    std::cin >> std::setw(2) >> countryCode2 >> std::setw(3) >> areaCode2 >> std::setw(7) >> phoneDigits2;

    personPhoneNumber2.setPhoneNumber(countryCode2, areaCode2, phoneDigits2);
    secondPerson.setPhoneNumber(personPhoneNumber2);

    secondPerson.showInformations();

    // Manager Processes
    // Manager class is the derived class that is inherited of the Person(Base) Class.
    // It has inherited members of the base class. Also has additional fields like `title`
    PhoneNumber firstManagerPhoneNumber = PhoneNumber("90", "111", "2223344");
    Date firstManagerBirthDate = Date(1995, 4, 4);

    // Using the new keyword to manage memory allocation of this value manually
    managerPtr firstManager = new Manager("First", "Manager", "Female", firstManagerPhoneNumber, firstManagerBirthDate, Date(), "Co-Founder", 22.4);

    // Second Manager definitions
    PhoneNumber secondManagerPhoneNumber = PhoneNumber("90", "222", "1112233");
    Date secondManagerBirthDate = Date(1992, 6, 18);

    // Using the new keyword to manage memory allocation of this value manually
    managerPtr secondManager = new Manager("Second", "Manager", "Male", secondManagerPhoneNumber, secondManagerBirthDate, Date(), "Co-Founder", 77.6);

    vManagerPtr managers{firstManager, secondManager};
    for (const auto *manager : managers)
    {
        // typeid expression allows us to reach the class information of the variable
        std::cout << "\n"
                  << typeid(manager).name() << " Information"
                  << std::endl;
        // Shows informations by using the overridden showInformations function of the derived class instead of virtual function of the base class
        manager->showInformations();
    }

    // Wait a bit to show informations before destruction
    sleep(2);

    // Destruct the manually created class after it's responsibilities are done. It should be deallocated manually since it's created by `new` keyword.
    // If we don't deallocate it manually, it stays alive on the memory and these type memory management problems occur memory leak problems.
    // To test, just comment out the following line, run this part and check desctructing logs. Then uncomment it and check again.
    delete firstManager;
    delete secondManager;

    return 0;
}