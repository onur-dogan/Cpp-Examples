#include <iostream>
#include "Date.cpp"
#include "Person.cpp"

int main()
{
    Date birthDate(1961, 4, 12);
    Date joinDate(1990, 6, 24);

    // Register first person
    Person firstPerson("Test", "Person", "Male", birthDate, joinDate);

    Date birthDate2(1970, 12, 3);
    Date joinDate2(1992, 1, 6);
    Person secondPerson;
    // Register second person
    secondPerson.setInformations("Test2", "Person2", 2, birthDate2, joinDate2);

    // Show the person list
    std::cout << "\n"
              << std::setw(40) << std::right << "*** PERSON LIST ***"
              << "\nPerson Count which is registered to the system: \t" << firstPerson.getPersonsCount()
              << std::endl;

    firstPerson.showInformations();
    secondPerson.showInformations();

    // Update first person's information by using a common function
    std::string newFirstName, newLastName;
    std::cout << "Enter first and last name to change the first person's full name" << std::endl;
    std::cin >> newFirstName >> newLastName;

    firstPerson.setFullName(newFirstName, newLastName);
    firstPerson.showInformations();

    // Update second person's information by using a friend function 
    std::string newName;
    std::cout << "Enter a name to change the second person's name" << std::endl;
    std::cin >> newName;

    setFirstNameByFriendFunc(secondPerson, newName);
    secondPerson.showInformations();
}