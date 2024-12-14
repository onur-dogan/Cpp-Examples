// Manager.h

#ifndef MANAGER_H
#define MANAGER_H

#include <iostream>
#include <array>
#include "Person.h"

namespace managerClass
{
    using namespace personClass;

    class Manager : public Person
    {
    public:
        // Constructor
        explicit Manager(const std::string, const std::string, const std::string, const PhoneNumber &, const Date &, const Date &, std::string, float);

        // Setters
        void setTitle(std::string);
        void setSharesPercentage(float);

        // Getters
        std::string getTitle() const;
        float getSharesPercentage() const;

        // Printers
        void showTitle() const noexcept;
        void showSharesPercentage() const noexcept;

        // Overrides
        void showInformations() const override;

        // Destructor
        ~Manager();

    private:
        std::string title;
        float sharesPercentage;
    };
}

#endif