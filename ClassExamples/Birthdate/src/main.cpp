#include <iostream>
#include "Date.cpp"
#include "Person.cpp"

int main()
{
    Date birthDate(1961, 4, 12);
    Date joinDate(1990, 6, 24);

    Person firstPerson("Test", "Person", "Male", birthDate, joinDate);

    Date birthDate2(1970, 12, 3);
    Date joinDate2(1992, 1, 6);
    Person secondPerson;
    secondPerson.setInformations("Test2", "Person2", 2, birthDate2, joinDate2);

    firstPerson.showInformations();
    secondPerson.showInformations();

    std::string newName;
    std::cout << "Enter a name to change the second person's name" << std::endl;
    std::cin >> newName;

    setFirstNameByFriendFunc(secondPerson, newName);
    secondPerson.showInformations();
}