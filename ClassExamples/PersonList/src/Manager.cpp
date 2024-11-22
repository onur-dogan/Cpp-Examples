#include <iomanip>
#include "Manager.h"
#include "Person.h"

// Constructor
Manager::Manager(std::string fName, std::string lName, std::string mGender, const PhoneNumber &mNumber, const Date &mBirthDate, const Date &mJoinDate, std::string mTitle, float mSharesPercentage)
    : Person(fName, lName, mGender, mNumber, mBirthDate, mJoinDate), title(mTitle), sharesPercentage(mSharesPercentage) {}

// Setters
void Manager::setTitle(std::string title)
{
    this->title = title;
}

void Manager::setSharesPercentage(float sharesPercentage)
{
    this->sharesPercentage = sharesPercentage;
}

// Getters
std::string Manager::getTitle() const
{
    return this->title;
}

float Manager::getSharesPercentage() const
{
    return this->sharesPercentage;
}

// Printers
void Manager::showTitle() const noexcept
{
    std::cout << "\n*** Title ***\n"
              << this->getTitle()
              << std::endl;
}

void Manager::showSharesPercentage() const noexcept
{
    std::cout << "\n*** Shares (%) ***\n"
              << this->getSharesPercentage()
              << "%"
              << std::endl;
}

// Overridden functions
void Manager::showInformations() const
{
    std::cout << "\n*** Welcome, " << getFirstName() << " " << getLastName() << " ***" << std::endl;
    std::cout << "\n*** Manager Information ***"
              << "\nFirst Name: \t" << getFirstName()
              << "\nLast Name: \t" << getLastName()
              << "\nAge: \t" << getAge()
              << "\nGender: \t" << getGender()
              << std::endl;

    // Show phone number only if all of the requred fields are filled
    std::cout << "\n*** Phone Number ***\n";
    // Print phone number by using the overloaded << operator that is customized to display phone numbers
    std::cout << this->getPhoneNumber() << std::endl;
    // It is also possible to print via another function
    // phoneNumber.showPhoneNumber();

    std::cout << "\n*** Birth Date ***";
    this->getBirthDate().showDate();

    std::cout << "\n*** Join Date ***";
    this->getJoinDate().showDate();

    // Show the additional fields for manager class
    this->showTitle();
    this->showSharesPercentage();
}

// Destructor
Manager::~Manager()
{
    std::cout << "Manager class is destructing.. for: \n"
              << this->getFullName()
              << " - "
              << this->getTitle()
              << " ("
              << this->getSharesPercentage()
              << "% Shares)"
              << std::endl;
}