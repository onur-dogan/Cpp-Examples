#include <iostream>
#include <string>
#include <iomanip>
#include "PhoneNumber.h"

// Default Constructor
PhoneNumber::PhoneNumber() : PhoneNumber("", "", "") {};

// Main Constructur
PhoneNumber::PhoneNumber(std::string pCountryCode, std::string pAreaCode, std::string pPhoneDigits) : countryCode(pCountryCode), areaCode(pAreaCode), phoneDigits(pPhoneDigits) {};

void PhoneNumber::setPhoneNumber(std::string countryCode, std::string areaCode, std::string phoneDigits)
{
    this->setCountryCode(countryCode).setAreaCode(areaCode).setPhoneDigits(phoneDigits);
}

PhoneNumber &PhoneNumber::setCountryCode(std::string countryCode)
{
    this->countryCode = countryCode;

    return *this;
}

PhoneNumber &PhoneNumber::setAreaCode(std::string areaCode)
{
    this->areaCode = areaCode;

    return *this;
}

void PhoneNumber::setPhoneDigits(std::string phoneDigits)
{
    this->phoneDigits = phoneDigits;
}

std::string PhoneNumber::getPhoneNumber() const
{
    if (hasPhoneNumberCorrectFormat())
        return "+" + this->getCountryCode() + " " + this->getAreaCode() + " " + this->getPhoneDigits();

    return "-";
}

std::string PhoneNumber::getCountryCode() const
{
    return this->countryCode;
}

std::string PhoneNumber::getAreaCode() const
{
    return this->areaCode;
}

std::string PhoneNumber::getPhoneDigits() const
{
    return this->phoneDigits;
}

void PhoneNumber::showPhoneNumber() const
{
    if (hasPhoneNumberCorrectFormat())
        std::cout << std::setfill(' ')
                  << std::setw(4) << "+" + this->getCountryCode()
                  << std::setw(4) << this->getAreaCode()
                  << std::setw(8) << this->getPhoneDigits()
                  << std::endl;
    else
        std::cout << "\n(Phone number is not available. Please update it later)" << std::endl;
}

bool PhoneNumber::hasPhoneNumberCorrectFormat() const
{
    return !this->getAreaCode().empty() && !this->getCountryCode().empty() && !this->getPhoneDigits().empty();
}

// Overloaded << operator function to print phone number in a specific order
std::ostream &operator<<(std::ostream &output, const PhoneNumber &phoneNumber)
{
    return output << std::setfill(' ')
                  << std::setw(4) << "+" + phoneNumber.getCountryCode()
                  << std::setw(4) << phoneNumber.getAreaCode()
                  << std::setw(8) << phoneNumber.getPhoneDigits()
                  << std::endl;
}

PhoneNumber::~PhoneNumber()
{
    std::cout << "\nPhone Number class is destructing... for:\t";
    this->showPhoneNumber();
}