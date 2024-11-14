#include <iostream>
#include <iomanip>
#include "Person.h"
#include "Date.h"

// Default constructor
Person::Person() : Person("", "", "", Date(2000, 1, 1), Date(2000, 1, 1)) {}

Person::Person(std::string fName, std::string lName, std::string pGender, const Date &pBirthDate, const Date &pJoinDate)
    : firstName(fName), lastName(lName), gender(pGender), joinDate(pJoinDate)
{
    setBirthDate(pBirthDate);
}

// Setter Functions
void Person::setInformations(std::string fName, std::string lName, int genderIndex, Date pBirthDate, Date pJoinDate)
{
    setFirstName(fName);
    setLastName(lName);
    setGender(genderIndex);
    setBirthDate(pBirthDate);
    setJoinDate(pJoinDate);
}

Person &Person::setFirstName(std::string firstName)
{
    if (firstName.length() > 0)
        // Use this keyword to access the properties of class.
        // e.g. the parameter has the same name as a private member so this keyword is used to specify the related class's field
        this->firstName = firstName;

    // Return class properties reference to support repeatedly updates
    return *this;
}

Person &Person::setLastName(std::string lastName)
{
    if (lastName.length() > 0)
        // Use this keyword to access the properties of class.
        // e.g. the parameter has the same name as a private member so this keyword is used to specify the related class's field
        this->lastName = lastName;

    // Return class properties reference to support repeatedly updates
    return *this;
}

// Function to update fields repeatedly
void Person::setFullName(std::string firstName, std::string lastName)
{
    // this-> is same with (*this). So, why used parentheses here? Wouldn't it work without parentheses?
    // Because the dot(.) operator is prioritized higher than the asterisk(*) operator.
    // The compiler would show an error if try to use it without parentheses
    // this->setFirstName(firstName).setLastName(lastName);
    (*this).setFirstName(firstName).setLastName(lastName);
}

void Person::setGender(int genderIndex)
{
    gender = getGenderByIndex(genderIndex);
}

void Person::setBirthDate(Date pBirthDate)
{
    birthDate = pBirthDate;
    age = 2024 - pBirthDate.getYear();
}

void Person::setJoinDate(Date pJoinDate)
{
    joinDate = pJoinDate;
}

// Getter Functions
std::string Person::getFirstName() const
{
    return firstName;
}

std::string Person::getLastName() const
{
    return lastName;
}

std::string Person::getGender() const
{
    return gender;
}

Date Person::getBirthDate() const
{
    return birthDate;
}

Date Person::getJoinDate() const
{
    return joinDate;
}

std::string Person::getGenderByIndex(int genderIndex) const
{
    const size_t genderLength = 3;
    // When a variable is declared as static, space for it gets allocated for the lifetime of the program.
    // Even if the function is called multiple times, space for the static variable is allocated only once
    static const std::array<std::string, genderLength> genders = {"Male", "Female", "Unknown"};

    if (genderIndex != 0 && genderIndex != 1)
        // Returns the latest one as default
        return genders[genderLength - 1];

    return genders[genderIndex];
}

// Printer Functions
void Person::showInformations() const
{
    std::cout << "\n*** Welcome, " << firstName << " " << lastName << " ***" << std::endl;
    std::cout << "\n*** Personal Information ***"
              << "\nFirst Name: \t" << firstName
              << "\nLast Name: \t" << lastName
              << "\nAge: \t" << age
              << "\nGender: \t" << gender;

    std::cout << "\n*** Birth Date ***";
    birthDate.showDate();

    std::cout << "*** Join Date ***";
    joinDate.showDate();
}

// Friend Setter Functions
void setFirstNameByFriendFunc(Person &person, std::string newFirstName)
{
    person.firstName = newFirstName;
}

// Destructor
Person::~Person()
{
    std::cout << "\nPerson Class is destructing with fields:..."
              << "\nFirst Name: \t" << firstName
              << "\nLast Name: \t" << lastName
              << "\nAge: \t" << age
              << "\nGender: \t" << gender
              << "\nBirth Date: \t" << birthDate.getDate()
              << "\nJoin Date: \t" << joinDate.getDate()
              << std::endl;
}