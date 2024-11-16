// Person.h

#ifndef PERSON_H
#define PERSON_H

#include <array>
#include "Date.h"
#include "PhoneNumber.h"

class Person
{
    // Friend setter function
    // The friend functions in the class have permission to access any property(public/protected/private) of the class which it is defined
    // and can update the private fields directly. If the func wouldn't be declared as a friend, it can't even access the private properties
    friend void setFirstNameByFriendFunc(Person &, std::string);

public:
    explicit Person(const std::string, const std::string, const std::string, const PhoneNumber &, const Date &, const Date &);
    Person();

    // Setters
    void setInformations(std::string, std::string, int, PhoneNumber, Date, Date);
    Person &setFirstName(std::string);
    Person &setLastName(std::string);
    void setFullName(std::string, std::string);
    void setGender(int);
    void setPhoneNumber(PhoneNumber&);
    void setBirthDate(Date);
    void setJoinDate(Date);
    // Static variable setters
    void increaseCounter();

    // Getters
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getFullName() const;
    std::string getGender() const;
    std::string getPhoneNumber() const;
    Date getBirthDate() const;
    Date getJoinDate() const;
    // Static variable getters
    static unsigned int getPersonsCount();

    // Printers
    void showInformations() const;

    // Static variables which are available to reach independently of properties of this class
    static unsigned int count;

    // Destructor
    ~Person();

private:
    // Variables
    std::string firstName;
    std::string lastName;
    int age;
    std::string gender;
    PhoneNumber phoneNumber;
    // Using another class properties in other class.
    Date birthDate;
    Date joinDate;

    // Helpers
    // It checks the gender list and returns the gender so the genders can't be different value from the defined list
    std::string getGenderByIndex(int) const;
};

#endif