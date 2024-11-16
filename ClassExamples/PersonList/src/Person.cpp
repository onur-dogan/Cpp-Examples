#include <iostream>
#include <iomanip>
#include <string>
#include "Person.h"
#include "Date.h"
#include "PhoneNumber.h"

// First, set the default value of the static variables
unsigned int Person::count = 0;

// Default constructor
Person::Person() : Person("", "", "", PhoneNumber(), Date(2000, 1, 1), Date(2000, 1, 1)) {}

// Main constructor
Person::Person(std::string fName, std::string lName, std::string pGender, const PhoneNumber &pNumber, const Date &pBirthDate, const Date &pJoinDate)
    : firstName(fName), lastName(lName), gender(pGender), phoneNumber(pNumber), joinDate(pJoinDate)
{
    setBirthDate(pBirthDate);
    increaseCounter();
}

// Setter Functions
void Person::setInformations(std::string fName, std::string lName, int genderIndex, PhoneNumber phoneNumber, Date pBirthDate, Date pJoinDate)
{
    setFirstName(fName);
    setLastName(lName);
    setGender(genderIndex);
    setPhoneNumber(phoneNumber);
    setBirthDate(pBirthDate);
    setJoinDate(pJoinDate);
}

Person &Person::setFirstName(std::string firstName)
{
    if (!firstName.empty())
        // Use this keyword to access the properties of class.
        // e.g. the parameter has the same name as a private member so this keyword is used to specify the related class's field
        this->firstName = firstName;

    // Return class properties reference to support repeatedly updates
    return *this;
}

Person &Person::setLastName(std::string lastName)
{
    if (!lastName.empty())
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

void Person::setPhoneNumber(PhoneNumber &phoneNumber)
{
    this->phoneNumber = phoneNumber;
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

void Person::increaseCounter()
{
    count++;
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

std::string Person::getFullName() const
{
    return this->firstName + " " + this->lastName;
}

std::string Person::getPhoneNumber() const
{
    return this->phoneNumber.getPhoneNumber();
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

unsigned int Person::getPersonsCount()
{
    // Static functions work independently of the class so, this keyword is meaningless in the static functions
    return count;
}

// Helper function to get gender by index
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

    // Show phone number only if all of the requred fields are filled
    std::cout << "\n*** Phone Number ***\n";
    if (!phoneNumber.getAreaCode().empty() && !phoneNumber.getCountryCode().empty() && !phoneNumber.getPhoneDigits().empty())
        phoneNumber.showPhoneNumber();
    else
        std::cout << "\n(Phone number is not available. Please update it later)";

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