// GuessNumberTemplate.h

#ifndef GUESS_NUMBER_TEMPLATE_H
#define GUESS_NUMBER_TEMPLATE_H

/**
 * Template definition uses to define parameters with temporary data types. Due to this, it allows any parameter type.
 * When the compiler sees that this function is triggered, it sets the parameter's type instead of the temporary (T) type
 * and C++ runs the function by using the related data and their types
 * So, it provides diversity in development
 *  */

#include <math.h>

template <typename T>
T GuessNumberTemplate(T randomNumber, T value1, T value2, T value3)
{
    // As default, set the first value as nearest to the random value
    T nearestNumber = value1;

    T value1Difference = abs(randomNumber - value1);
    T value2Difference = abs(randomNumber - value2);
    T value3Difference = abs(randomNumber - value3);

    if (value2Difference < value1Difference && value2Difference < value3Difference)
        nearestNumber = value2;

    if (value3Difference < value1Difference && value3Difference < value2Difference)
        nearestNumber = value3;

    return nearestNumber;
}

#endif