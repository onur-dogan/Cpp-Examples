#include <stdexcept>
#include "TimeException.hpp"

TimeException::TimeException(std::string errorMessage) : std::invalid_argument(errorMessage) {};

TimeException::~TimeException() {};