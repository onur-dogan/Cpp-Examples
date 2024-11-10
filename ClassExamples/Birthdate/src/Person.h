// Person.h

#ifndef PERSON_H
#define PERSON_H

#include <array>
#include "Date.h"

class Person
{
public:
    explicit Person(const std::string, const std::string, const std::string, const Date &, const Date &);
    Person();

    // Setters
    void setInformations(std::string, std::string, int, Date, Date);
    void setFirstName(std::string);
    void setLastName(std::string);
    void setGender(int);
    void setBirthDate(Date);
    void setJoinDate(Date);

    // Getters
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getGender() const;
    Date getBirthDate() const;
    Date getJoinDate() const;

    // Printers
    void showInformations() const;

    // Destructor
    ~Person();

private:
    std::string firstName;
    std::string lastName;
    int age;
    std::string gender;
    // Using another class properties in other class.
    Date birthDate;
    Date joinDate;

    // It checks the gender list and returns the gender so the genders can't be different value from the defined list
    std::string getGenderByIndex(int) const;
};

#endif