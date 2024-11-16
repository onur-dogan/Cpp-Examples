#include <iostream>
#include "Date.cpp"
#include "Person.cpp"
#include "PhoneNumber.cpp"

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

    // Update second person's information by using a friend function
    std::string newName;
    std::cout << "Enter a name to change the second person's name" << std::endl;
    std::cin >> newName;

    setFirstNameByFriendFunc(secondPerson, newName);
    secondPerson.showInformations();
}