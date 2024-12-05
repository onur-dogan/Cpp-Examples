#include <iostream>
#include "GuessNumberTemplate.h"
#include <random>

int main()
{
    std::default_random_engine randomEngine(static_cast<unsigned int>(time(0)));
    std::uniform_int_distribution intRandomNumberGenerator(1, 200);

    // Use same template to guess random number with comparing the integer numbers
    std::cout << "** Guess the number between 1-50 **" << std::endl;

    int int1, int2, int3;
    std::cout << "Enter three integer value: ";
    std::cin >> int1 >> int2 >> int3;

    int intRandomNumber = intRandomNumberGenerator(randomEngine);
    std::cout << "The Random Number is: " << intRandomNumber
              << "\nThe nearest number you did guess: " << GuessNumberTemplate(intRandomNumber, int1, int2, int3)
              << std::endl;

    // Use same template to guess random number with comparing the float (decimal) numbers
    std::cout << "\n\n** Guess the number between 1-500 **" << std::endl;

    float float1, float2, float3;
    std::cout << "Enter three decimal value: ";
    std::cin >> float1 >> float2 >> float3;

    std::uniform_int_distribution floatRandomNumberGenerator(1, 500);

    float floatRandomNumber = floatRandomNumberGenerator(randomEngine) / 3;
    std::cout << "The Random Number is: " << floatRandomNumber
              << "\nThe nearest number you did guess: " << GuessNumberTemplate(floatRandomNumber, float1, float2, float3)
              << std::endl;

    return 0;
}
