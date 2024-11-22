#include <iostream>
#include <unistd.h>
#include "Date.cpp"
#include "Person.cpp"
#include "PhoneNumber.cpp"
#include "Manager.cpp"

int main()
{
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

    firstPerson.showInformations();
    secondPerson.showInformations();

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
    Manager *firstManager = new Manager("First", "Manager", "Female", firstManagerPhoneNumber, firstManagerBirthDate, Date(), "Co-Founder", 22.4);
    firstManager->showInformations();
    // Show the additional fields
    firstManager->showTitle();
    firstManager->showSharesPercentage();

    // Wait a bit to show informations before destruction
    sleep(2);

    // Destruct the manually created class after it's responsibilities are done. It should be deallocated manually since it's created by `new` keyword.
    // If we don't deallocate it manually, it stays alive on the memory and these type memory management problems occur memory leak problems.
    // To test, just comment out the following line, run this part and check desctructing logs. Then uncomment it and check again.
    delete firstManager;
}