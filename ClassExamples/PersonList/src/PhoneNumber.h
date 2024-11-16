// PhoneNumber.h

#ifndef PHONENUMBER_H
#define PHONENUMBER_H

#include <string>

class PhoneNumber
{
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