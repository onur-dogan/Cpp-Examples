// PhoneNumber.h

#ifndef PHONENUMBER_H
#define PHONENUMBER_H

#include <string>
#include <ostream>

class PhoneNumber
{
    // Overload << operator that is customized to print phone numbers specifically.
    // Note that, `const` usage is necessary for the parameter object that references the class (const PhoneNumber &)
    // Because the friend function shouldn't update private fields manually and also the compiler throws an error without const keyword.
    // Therefore, it should allow the object as constant. Otherwise, it doesn't allow to access the private fields.
    friend std::ostream &operator<<(std::ostream &, const PhoneNumber &);

public:
    explicit PhoneNumber(const std::string, const std::string, const std::string);
    PhoneNumber();

    // Setters
    void setPhoneNumber(std::string, std::string, std::string);
    PhoneNumber &setCountryCode(std::string);
    PhoneNumber &setAreaCode(std::string);
    void setPhoneDigits(std::string);

    // Getters
    std::string getPhoneNumber() const;
    std::string getCountryCode() const;
    std::string getAreaCode() const;
    std::string getPhoneDigits() const;

    // Displayers
    void showPhoneNumber() const;

    // Destructor
    ~PhoneNumber();

private:
    std::string countryCode;
    std::string areaCode;
    std::string phoneDigits;

    // Helper function to check phone number format
    bool hasPhoneNumberCorrectFormat() const;
};

#endif