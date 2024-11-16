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
    return "+" + this->getCountryCode() + " " + this->getAreaCode() + " " + this->getPhoneDigits();
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
    std::cout << std::setfill(' ')
              << std::setw(4) << "+" + this->getCountryCode()
              << std::setw(4) << this->getAreaCode()
              << std::setw(8) << this->getPhoneDigits()
              << std::endl;
}

PhoneNumber::~PhoneNumber()
{
    std::cout << "\nPhone Number class is destructing... for:\t";
    this->showPhoneNumber();
}