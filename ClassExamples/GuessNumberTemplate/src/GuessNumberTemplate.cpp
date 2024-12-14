#include <iostream>
#include <random>
#include "GuessNumberTemplate.h"

#ifndef DISPLAY_HEADER
// The parameter is used with the "#" operator to embed it in the text
#define DISPLAY_HEADER(text) std::cout << "** " #text " **" << std::endl;
#endif

using namespace guessnumbertemplate;

int main()
{
    std::cout << "\n*** Welcome to review the Guess Number Template Class Examples ***\n"
              << std::endl;

    // Use same template to guess random number with comparing the integer numbers
    std::default_random_engine randomEngine(static_cast<unsigned int>(time(0)));
    std::uniform_int_distribution<int> intRandomNumberGenerator(1, 50);

    // Display header message by using a macro (declared with "define" preprocessor directive)
    DISPLAY_HEADER(Guess the number between 1 - 50);

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

    std::uniform_int_distribution<int> floatRandomNumberGenerator(1, 500);

    float floatRandomNumber = floatRandomNumberGenerator(randomEngine) / 3;
    std::cout << "The Random Number is: " << floatRandomNumber
              << "\nThe nearest number you did guess: " << GuessNumberTemplate(floatRandomNumber, float1, float2, float3)
              << std::endl;

    return 0;
}
