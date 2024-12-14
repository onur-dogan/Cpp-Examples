#include <iomanip>
#include "Manager.h"
#include "Person.h"

namespace managerClass
{
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
        // Print the base information by calling the default (virtual) function of the base class
        // Calling the base function first is a good practice to avoid code duplication (DRY principle)
        Person::showInformations();

        // Then, print the additional specific fields of this derived class
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
}