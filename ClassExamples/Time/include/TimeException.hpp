// TimeException.h

#ifndef TIME_EXCEPTION_H
#define TIME_EXCEPTION_H

#include <stdexcept>

/**
 * Custom exception to catch setting an invalid hour/minute/second
 */
class TimeException : public std::invalid_argument
{
public:
    TimeException(std::string);
    ~TimeException();
};

#endif