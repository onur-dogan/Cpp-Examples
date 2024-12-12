#include <iostream>
#include <math.h>
#include <unordered_map>
#include <chrono> // For Time Recording
#include <iomanip>
#include <map>
#include <cstdlib>
#include <random>
#include <vector>
#include <array>
#include <algorithm>
#include <cstring>
// For processing string based streams (e.g. ostringstream, istringstream, etc.)
#include <sstream>
/**
 * See: https://www.boost.org/doc/libs/1_72_0/libs/range/doc/html/range/reference/adaptors/reference/indexed.html
 * Used {
 *  boost::adaptors::indexed
 * }
 */
#include <boost/range/adaptor/indexed.hpp>

#include "colors.h"
#include "constants.hpp"

#define LETTER_LENGTH 26
#define FIRST_LETTER 'A'

const void calculateWithNumbers()
{
    int number1 = 0, number2 = 0, sum = 0;

    std::cout << "Enter the first integer: " << std::endl;
    std::cin >> number1;

    std::cout << "Enter the second integer: " << std::endl;
    std::cin >> number2;

    std::cout << "Number 1 + Number 2 ==>  " << number1 + number2
              << "\nNumber 1 - Number 2 ==> " << number1 - number2
              << "\nNumber 1 * Number 2 ==> " << number1 * number2
              << "\nNumber 1 / Number 2 ==> " << number1 / number2 << std::endl;
}

const void compareNumbers()
{
    int number1 = 0, number2 = 0;
    std::cout << "Enter the first number" << std::endl;
    std::cin >> number1;

    std::cout << "Enter the second number" << std::endl;
    std::cin >> number2;

    std::cout << ((number1 > number2) ? "1. number is higher than 2. number" : (number1 == number2) ? "The numbers are equal"
                                                                                                    : "2. number is higher than 1. number")
              << std::endl;
}

const void drawShapes()
{
    int selectedShape;
    size_t totalShapeLength = 10;

    std::cout << "Draw one of the shapes (Enter the number to draw it):" << "\n1 ==> Square" << "\n2 ==> Ellipse" << std::endl;
    std::cin >> selectedShape;

    switch (selectedShape)
    {
    case 1:
        for (int row = 0; row <= totalShapeLength; row++)
        {
            for (int col = 0; col <= totalShapeLength; col++)
            {
                // After putting the last *, go to the next line.
                // std::endl manipulator inserts a **newline** and flushes the stream.
                if (col == totalShapeLength)
                {
                    std::cout << "*" << std::endl;
                    continue;
                }

                // Draw the asteriks in a line at the first and the latest lines
                if ((row == 0) || (row == totalShapeLength))
                {
                    std::cout << "* ";
                    continue;
                }

                // Draw asteriks at the first column only if the row isn't first or the last
                if (col == 0)
                {
                    std::cout << "* ";
                    continue;
                }

                // Draw empty lines to equalize the spaces
                std::cout << "  ";
            }
        }
        break;
    case 2:
        for (int row = 0; row <= totalShapeLength; row++)
        {
            for (int col = 0; col <= totalShapeLength; col++)
            {
                if ((row == 0) || (row == totalShapeLength))
                {
                    if (col == totalShapeLength)
                    {
                        std::cout << " " << std::endl;
                        continue;
                    }

                    std::cout << (((col > 3) && (col < 7)) ? "*" : " ");
                    continue;
                }

                if ((row == 1) || (row == totalShapeLength - 1))
                {
                    if (col == totalShapeLength)
                    {
                        std::cout << "  " << std::endl;
                        continue;
                    }

                    std::cout << (((col == 2) || (col == 8)) ? "*" : " ");
                    continue;
                }

                if (((row == 2) || (row == totalShapeLength - 2)))
                {
                    if (col == totalShapeLength)
                    {
                        std::cout << "  " << std::endl;
                        continue;
                    }

                    std::cout << (((col == 1) || (col == 9)) ? "*" : " ");
                    continue;
                }

                if (col == 0)
                {
                    std::cout << "*";
                    continue;
                }

                if (col == totalShapeLength)
                {
                    std::cout << "*" << std::endl;
                    continue;
                }
                std::cout << " ";
            }
        }
        break;
    default:
        break;
    }
}

const void clearInputStream()
{
    // Ignore and clear the input stream to prevent the conflicts situations between this and the below input stream
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.clear();
}

const void showASCIIEquivalent()
{
    char character;
    std::cout << "Enter any character to see ASCII equivalent" << std::endl;
    std::cin >> character;
    clearInputStream();

    int asciiNumber = static_cast<int>(character);
    std::cout << "Character you entered: \n";
    // Put returns the ASCII equivalent of any number. It can be used multiple times as combined. \n was used to move one line down
    std::cout.put(asciiNumber).put('\n');
    std::cout << "ASCII Equivalent: \n"
              << asciiNumber << std::endl;

    int number;
    std::cout << "Enter any ASCII number to see it's equivalent character" << std::endl;
    std::cin >> number;

    std::cout << static_cast<char>(number) << std::endl;

    const char *const word = "Word";
    std::cout << "Value of static_cast<void *> is of the " << word << " is:\n"
              << static_cast<const void *>(word)
              << std::endl;
}

const void calculateBMI()
{
    double height, weight, bmiValue;
    std::unordered_map<std::string, std::string> bmiValues{{"Obese", " > 30"}, {"Overweight", " 25 * 29.9"}, {"Normal", " 18.5 - 24.9"}, {"Underweight", " < 18.5"}};

    std::cout << "** BMI LIMITS **" << std::endl;

    for (auto value = bmiValues.begin(); value != bmiValues.end(); value++)
    {
        std::cout << value->first + ":" << value->second << std::endl;
    }
    std::cout << "\nEnter your height: " << std::endl;
    std::cin >> height;

    std::cout << "Enter your weight: " << std::endl;
    std::cin >> weight;

    bmiValue = weight / (pow(height / 100, 2));
    std::cout << "Your BMI index is: "
              << bmiValue
              << " (" + (next(bmiValues.begin(), (bmiValue < 18.5) ? 0 : (bmiValue < 25) ? 1
                                                                     : (bmiValue < 30)   ? 2
                                                                                         : 3)
                             ->first) +
                     ")"
              << std::endl;
}

const void calculateVehicleExpenses()
{
    float gasolinePerLiterPrice, averageDistanceWithPerLiter, parkingFees, vehicleTolls, traveledKM, totalExpenses = 0, totalUsedGasolineLiter = 0, totalGasolineExpenses = 0;

    std::cout << "-- Calculate Daily Vehicle Expenses (All input should be number!) --" << std::endl;

    std::cout << "Enter Gasoline liter price:" << std::endl;
    std::cin >> gasolinePerLiterPrice;

    std::cout << "Enter Parking fees:" << std::endl;
    std::cin >> parkingFees;

    std::cout << "Enter Vehicle tolls:" << std::endl;
    std::cin >> vehicleTolls;

    std::cout << "Enter Distance traveled by the vehicle with 1 liter of gasoline:" << std::endl;
    std::cin >> averageDistanceWithPerLiter;

    std::cout << "How many km will be traveled" << std::endl;
    std::cin >> traveledKM;

    totalUsedGasolineLiter = traveledKM / averageDistanceWithPerLiter;
    totalGasolineExpenses = totalUsedGasolineLiter * gasolinePerLiterPrice;
    totalExpenses = parkingFees + vehicleTolls + totalGasolineExpenses;

    std::cout << "Total traveled KM: " << traveledKM << " KM" << std::endl;
    std::cout << "Total Gasoline Expenses: " << totalGasolineExpenses << std::endl;
    std::cout << "Total Daily Expenses: " << totalExpenses << std::endl;
    std::cout << "Total Daily Expenses for 1 KM: " << totalExpenses / traveledKM << std::endl;
}

// Common type definition of the loop functions
typedef void (*loopFunctionPtr)(int);
const auto loopReader(int loopLength, loopFunctionPtr loopFunction)
{
    // Time recorder
    auto startTime = std::chrono::high_resolution_clock::now();
    loopFunction(loopLength);
    auto endTime = std::chrono::high_resolution_clock::now();

    // Calculate elapsed time the loop takes
    auto timeDifference = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);
    return timeDifference.count();
}

void forLoopFunction(int loopLength)
{
    int total = 0;
    // Single line for
    for (unsigned int i = 1; i <= loopLength; total += pow(i, 2), i++);

    std::cout << std::setw(25) << std::left << "Total With For ==> " << std::setw(5) << std::left << total << std::endl;
}

void whileLoopFunction(int loopLength)
{
    int total = 0, counter = 0;
    // Shorthand to increase counter in order instead of increasing it at last in func
    while (++counter <= loopLength)
    {
        total += pow(counter, 2);
    }

    std::cout << std::setw(25) << std::left << "Total With While ==> " << std::setw(5) << std::left << total << std::endl;
}

void doWhileLoopFunction(int loopLength)
{
    // Because of do works initially, the counter should start from 1
    int total = 0, counter = 1;
    do
    {
        total += pow(counter, 2);
    } while (++counter <= loopLength);

    std::cout << std::setw(25) << std::left << "Total With Do-While ==> " << std::setw(5) << std::left << total << std::endl;
}

const void loopComparator()
{
    int loopLength, total, forLoop;

    std::cout << "Enter number to find the sum of the squares of the numbers up to the entered number: " << std::endl;
    std::cin >> loopLength;

    double forLoopSpentTime = loopReader(loopLength, forLoopFunction);
    std::cout << forLoopSpentTime << " Milisecond spent - For Loop\n\n";

    double whileLoopSpentTime = loopReader(loopLength, whileLoopFunction);
    std::cout << whileLoopSpentTime << " Milisecond spent - While Loop\n\n";

    double doWhileLoopSpentTime = loopReader(loopLength, doWhileLoopFunction);
    std::cout << doWhileLoopSpentTime << " Milisecond spent - Do-While Loop\n\n"
              << std::endl;
}

const void printNumbersInOrder()
{
    int shouldPrintEvenNumbers;
    std::cout << "Enter 1 to print even numbers. Otherwise, it prints odd numbers" << std::endl;
    std::cin >> shouldPrintEvenNumbers;

    std::cout << " ** Numbers ** \n";
    for (unsigned i = shouldPrintEvenNumbers == 1 ? 2 : 1; i <= 100; i += 2)
    {
        std::cout << i << std::endl;
    }
}

// Letter constants
const std::unordered_map<char, int> lettersWithGradePoints = {{'A', 5}, {'B', 4}, {'C', 3}, {'D', 2}, {'F', 1}};
const int groupAndCalculateGradesByLetter(char letter, int letterCount)
{
    try
    {
        // Find related letter with grade point
        auto relatedLetter = lettersWithGradePoints.find(letter);

        // Display related grade letter information and how many students got that grade
        std::cout << letter << " (" << relatedLetter->second << ") \t" << std::setw(10) << letterCount << "\n";

        return relatedLetter->second * letterCount;
    }
    catch (std::exception error)
    {
        // If any issue occurs or the related letter doesn't exist, this shouldn't affect the total results
        return 0;
    }
}

const void calculateGrades()
{
    char grade;
    std::map<char, int> gradeCounters;
    std::cout << "Enter grades incessantly (A, B, C, D, F) and type (Ctrl + D) to end it" << std::endl;

    while ((grade = std::cin.get()) != EOF)
    {
        // Allows only digits a-z, A-Z and 0-9, don't allow any empty character
        if (isxdigit(grade) && !iswdigit(grade))
        {
            gradeCounters[toupper(grade)]++;
        }
    }

    std::cout << "Letter" << "\t" << "Number Of Students\n";

    float totalGrade, attendersLength;
    for (auto const &gradesWithCount : gradeCounters)
    {
        unsigned int calculatedTotalGradeByLetter = groupAndCalculateGradesByLetter(gradesWithCount.first, gradesWithCount.second);
        // If the letter doesn't an available grade letter, then just ignore it
        if (calculatedTotalGradeByLetter == 0)
            continue;

        // Sum grades to find the total grade
        totalGrade += calculatedTotalGradeByLetter;
        // Increase attended student's length
        attendersLength += gradesWithCount.second;
    }

    // Display the final results
    std::cout << "\n *** Total Results *** \n"
              << std::setw(35) << std::left << "Number of Students Attended:" << attendersLength << "\n"
              << std::setw(35) << std::left << "Grage Point Average:" << std::setprecision(2) << totalGrade / attendersLength
              << std::endl;
}

const int generateRandomNumberByLimit(int limit)
{
    // Add 1 to each calculated number since it is available to generate 0 (between (0, limit-1)) randomly
    return 1 + rand() % limit;
}

const void generateRandomNumbers()
{
    int numberLimit;
    std::cout << "Enter a limit number that the random number can take biggest:" << std::endl;
    std::cin >> numberLimit;

    if (std::cin.fail())
        throw std::invalid_argument("The limit number must be a number!");

    // According to the CERT (MSC300CPP), the rand function doesn't have good statistical features so it provides predictable results,
    // Therefore, C++11 provides the "random" library which is much safer and generates random numbers that are hard to predict.

    // It uses default_random_engine to seed the engine, instead of srand func
    std::default_random_engine randomNumberEngine(static_cast<unsigned int>(time(0)));
    // Defines the limits of the generated numbers
    std::uniform_int_distribution<unsigned int> randomNumberGenerator(1, numberLimit);

    std::cout << "\nGenerated random numbers:\n";
    for (int i = 0; i < 5; i++)
        std::cout << randomNumberGenerator(randomNumberEngine) << std::endl;

    return;
    // THIS PART (Srand func usage) DISABLED BUT REVIEWABLE

    // Seed the number by calculating the difference between the current GMT (Greenwich Mean Time) time from 01.01.1970
    // After seeding a number via srand function, it always returns the same random number.
    // Because it changes the “seed” (starting point) of the algorithm.
    // Therefore, using the time difference ensures that a different random number is obtained each time
    srand(static_cast<unsigned int>(time(0)));
    std::cout << std::setw(60) << std::left << "\nGenerated random number when using time function:" << generateRandomNumberByLimit(numberLimit);

    srand(12);
    std::cout << std::setw(60) << std::left << "\nGenerated random number when seeding 12:" << generateRandomNumberByLimit(numberLimit);

    srand(23);
    std::cout << std::setw(60) << std::left << "\nGenerated random number when seeding 23:" << generateRandomNumberByLimit(numberLimit);

    srand(12);
    std::cout << std::setw(60) << std::left << "\nGenerated random number when seeding 12 again:" << generateRandomNumberByLimit(numberLimit);

    srand(36);
    std::cout << std::setw(60) << std::left << "\nGenerated random number when seeding 36:" << generateRandomNumberByLimit(numberLimit);

    srand(23);
    std::cout << std::setw(60) << std::left << "\nGenerated random number when seeding 23 again:" << generateRandomNumberByLimit(numberLimit);

    std::cout << "\nWhen seeding the same number via srand function, it generates the same random number\n"
              << std::endl;
}

int multiply(int num1, int num2)
{
    return num1 * num2;
}

double multiply(double num1, double num2)
{
    return num1 * num2;
}

const void overloadMultiplyCalculation()
{
    // Function overloading is a feature of object-oriented programming
    // where the multiple functions with the same name has different parameter data types
    int number1 = 5, number2 = 3;
    std::cout << "Multiply Integers (" << number1 << " with " << number2 << "):\t" << multiply(number1, number2) << std::endl;

    double number3 = 5.6, number4 = 3.7;
    std::cout << "Multiply Decimal Numbers via Same Overloaded Function ("
              << number3 << " with " << number4 << "):\t"
              << multiply(number3, number4)
              << std::endl;
}

const void sortAndSearchInArray()
{
    const size_t array_size = 6;
    std::array<std::string, array_size> programming_languages = {"C", "C++", "C#", "Java", "JavaScript", "Assembly"};

    std::string search;
    std::cout << "Enter a string to search an programming languages in the list:\n";
    std::cin >> search;

    std::cout << "Array Elements: \n";
    for (unsigned int i = 0; i < programming_languages.size(); i++)
        std::cout << i + 1 << ". \t" << programming_languages[i] << "\n";

    std::sort(programming_languages.begin(), programming_languages.end());
    std::cout << "\nSorted Array Elements: \n";
    for (unsigned int i = 0; i < programming_languages.size(); i++)
        std::cout << i + 1 << ". \t" << programming_languages[i] << "\n";

    bool isExist = std::binary_search(programming_languages.begin(), programming_languages.end(), search);
    std::cout << "\n"
              << (isExist ? "YES, it exists!!" : "Unfortunately, it doesn't exist..") << std::endl;
}

const void generalVectorFeatures()
{
    size_t intListLength = 3, floatListLength = 4;

    // For the array, it's not allowed to change array size. It has a constant length.
    // For vectors, it's free to push or remove elements from the vector list.
    std::vector<int> intList(intListLength);
    std::vector<float> floatList(floatListLength);

    std::cout << "Enter integer values to the list: ";
    for (int &intItem : intList)
        std::cin >> intItem;

    std::cout << "Enter float values to the list: ";
    for (float &floatItem : floatList)
        std::cin >> floatItem;

    // Copy vector to a new one
    std::vector<int> backupIntList(intList);

    // Compare them
    std::cout << "Is the integer vector list same with backup vector list?:\t"
              // std::boolalpha converts the boolean variable to text (1 ==> true, 0 ==> false)
              // std::noboolalpha resets the format to the default for the following texts so it returns 1 or 0
              << std::boolalpha << (intList == backupIntList)
              << std::noboolalpha << "!"
              << std::endl;

    // Try to achieve to an element index that doesn't exist and catch the error
    try
    {
        std::cout << "Let's try to see the 100. element of the vector: " << intList.at(100) << std::endl;
    }
    catch (std::out_of_range &err)
    {
        std::cout << FORERED
                  << "\nOops! An error occurred while attempting to see 100. element of the vector: \n"
                  << err.what() << "\n"
                  << RESETTEXT
                  << std::endl;
    }

    // Push a new value to the integer list
    std::cout << "Enter an integer value to insert into the integer list: ";
    int newValue;
    std::cin >> newValue;

    // Add new value to the end of the vector list
    intList.push_back(newValue);

    bool isSame = intList == backupIntList;
    // Compare it with the backup now
    std::cout << "Is the integer vector list same with backup vector list now?:\t" << std::endl;
    if (isSame)
        std::cout << "Yes!\n";
    else
        std::cout << "No! The integer list with the latest inserting includes " << intList.size() << " element.\n"
                  << "While the backup integer list includes " << backupIntList.size() << " element\n"
                  << "*** So, we must take a backup again! *** \n";

    std::cout << "\n\nLet's remove the latest pushed element from the vector (FIFO)" << std::endl;
    intList.pop_back();

    isSame = intList == backupIntList;
    // Compare it with the backup after removing the latest added element
    std::cout << "Is the integer vector list same with backup vector list after removing the latest inserted element?:\t" << std::endl;
    if (isSame)
        std::cout << "Yes!\n";
    else
        std::cout << "No! The integer list with the latest inserting includes " << intList.size() << " element.\n"
                  << "While the backup integer list includes " << backupIntList.size() << " element\n"
                  << "So, must take a backup again!\n";

    std::cout << "*** Integer List Exercises Are Done! *** \n\n"
              << "*** Remaining Exercises with Decimal elements: *** \n";
    for (const float &floatItem : floatList)
        // std::showpoint is used to show(fill) the 0s after the point(.) so each variable would be displayed in the same length
        // e.g. 2.300 is displayed as 2.3 without it, 2.300 with it. It displays five 0 after the point as default.
        // By setting precision, we can declare how many characters will be displayed totally(characters at point's left + characters at point's right)
        // std::noshowpoint resets the showpoint manipulator changes and it works as in normal
        std::cout << std::showpoint << floatItem << std::noshowpoint << std::endl;

    float replaceNum1, replaceNum2;
    std::cout << "Enter two decimal number to replace them with the first 2 element in the list";
    std::cin >> replaceNum1 >> replaceNum2;

    // Remove the first 2 element
    floatList.erase(floatList.begin(), floatList.begin() + 2);

    // *** Insert vs Emplace ***
    // Insert adds a copy of the object at the specified position
    floatList.insert(floatList.begin(), replaceNum2);
    // Emplace does in place insertion and constructs an object in-place at a specified position, potentially avoiding a copy operation
    floatList.emplace(floatList.begin(), replaceNum1);

    std::cout << "\nUpdated decimal elements: \n";
    for (float &floatItem : floatList)
        std::cout << std::setprecision(5) << std::showpoint << floatItem << std::noshowpoint << std::endl;
}

size_t getSize(double *ptr)
{
    // Returns the pointer's size as byte
    return sizeof(ptr);
}

const void findArrayLengthBySize()
{
    double numbers[20];

    std::cout << "The number of bytes in the array: (1 Double: 8 byte): " << sizeof(numbers)
              << "\nThe number of bytes of the array's pointer size: " << getSize(numbers)
              << "\nArray length (total_size/first_element_size): " << sizeof(numbers) / sizeof(numbers[0])
              << std::endl;
}

const void displayBytesByDataType()
{
    char c;
    short s;
    int i;
    long l;
    long long ll;
    float f;
    double d;
    long double ld;
    int array[1];
    int *ptr = array;

    std::cout << "*** Byte Sizes For Each Data Type ***" << std::endl;
    std::cout << "\nsizeof c(char) ==> " << sizeof(c)
              << "\nsizeof s(short) ==> " << sizeof(s)
              << "\n\nsizeof i(int) ==> " << sizeof(i)
              << "\n\nsizeof f(float) ==> " << sizeof(f)
              << "\n\nsizeof d(double) ==> " << sizeof(d)
              << "\n\nsizeof l(long) ==> " << sizeof(l)
              << "\nsizeof ll(long long) ==> " << sizeof(ll)
              << "\nsizeof ld(long double) ==> " << sizeof(ld)
              << "\n\nsizeof array(int array (1 element)) ==> " << sizeof(array)
              << "\nsizeof pointer(ptr) ==> " << sizeof(ptr)
              << std::endl;
}

const void stringCharArrayUsages()
{
    // *** Character array constants have a static storage duration (they exist throughout the program) ***

    // Both are the same.
    char language[] = "Assembly";
    // When defining char array variables, single quote should be used ==>
    char languageWithSingleQuotes[] = {'A', 's', 's', 'e', 'm', 'b', 'l', 'y'};

    std::cout << "*** First Array Elements ***" << std::endl;
    for (auto const &character : language | boost::adaptors::indexed(1))
        std::cout << character.index() << ". " << character.value() << std::endl;

    std::cout << "*** Second Array Elements ***" << std::endl;
    for (auto const &character : languageWithSingleQuotes | boost::adaptors::indexed(1))
        std::cout << character.index() << ". " << character.value() << std::endl;

    std::cout << "\n*** Char type array's sizes (Each char data type takes up 1 bit of space) ***"
              << "\nFirst array's byte size: " << sizeof(language)
              << "\nSecond array's byte size: " << sizeof(languageWithSingleQuotes)
              << FOREYEL << "\nSo, why the first array's byte size is 9 but the second one's is 8?"
              << FOREGRN << "\nBecause, when defining a char array as a string, it adds an epmty('\\n') element to the end of the array. See below lines ==>"
              << RESETTEXT
              << "\nThe last element of the first array: " << language[sizeof(language) / sizeof(language[0]) - 1]
              << "\nThe last element of the second array: " << languageWithSingleQuotes[sizeof(languageWithSingleQuotes) / sizeof(languageWithSingleQuotes[0]) - 1]
              << std::endl;

    size_t textLength = 10;
    std::string enteredString;
    std::cout << "\nEnter any long string\n";
    // Using setw when getting an input helps us to take only limited characters from the entered text
    std::cin >> std::setw(textLength) >> enteredString;
    std::cout << "Allowed string to store in the system:\t" << enteredString << std::endl;

    size_t characterLimit = 20;
    char enteredCharacters[characterLimit];
    // Using getLine limitations when getting an input helps us to take only limited characters from the entered text
    // It gets the entered text's 20 character after the 10 character cause the above functionality takes and stores the first 10 character
    std::cin.getline(enteredCharacters, characterLimit);

    // Clear the input stream since we get limited characters. The remaining characters go as a value to the next input stream
    // This causes some conflicts between input streams. So, it is good to clear the input stream after the it is ended it's flow
    clearInputStream();

    // Char arrays can be displayed as a string on the terminal without using any loop
    // Same as ==> std::cout.write(enteredCharacters, std::cin.gcount());
    std::cout << "The entered text as a char array with the allowed characters in the system:\t" << enteredCharacters << std::endl;
}

const void showDecimalNumberEquivalents()
{
    int number;
    std::cout << "Enter a decimal number:" << std::endl;
    std::cin >> number;

    // If the entered value isn't an integer
    if (std::cin.fail())
    {
        std::cout << "Expected an integer but entered another type so the results can't be displayed! Try again!";
        clearInputStream();
        return;
    }

    // Displays the hexadecimal equivalent of the entered decimal number
    // **std::hex** is same as **std::setbase(16)**
    std::cout << number << " in hexadecimal is: " << std::hex << number << std::endl;
    // Displays the octal equivalent of the entered decimal number
    // std::hex is same as std::setbase(8)
    std::cout << std::dec << number << " in octal is: " << std::oct << number << std::endl;
    // Displays the entered decimal number again
    // std::setbase(10) is same as std::dec
    std::cout << std::setbase(10) << number << " in octal is: " << number << std::endl;

    double scientificNumber;
    std::cout << "Enter a double number to see its scientific equivalent:" << std::endl;
    std::cin >> scientificNumber;

    std::cout << "The number: " << scientificNumber
              << "\tIt's scientific format is: " << std::scientific << scientificNumber
              << std::endl;
}

static char letter = FIRST_LETTER;
inline char generateLetter()
{
    return letter++;
}

const void printLettersInAlphabet()
{
    std::array<char, LETTER_LENGTH> letters;
    std::fill(letters.begin(), letters.end(), 'C');

    std::ostream_iterator<char> lettersPrinter(std::cout, ",");

    std::cout << "\nThe letters array after filling with a single character:" << std::endl;
    std::copy(letters.cbegin(), letters.cend(), lettersPrinter);

    // Generate takes a _Generator function as 3. parameter and sets the values according to the return values of this func
    std::generate(letters.begin(), letters.end(), generateLetter);
    std::cout << "\nThe letters after generation:" << std::endl;
    std::copy(letters.cbegin(), letters.cend(), lettersPrinter);
}

/**
 * @param textLength Send text length to generate random text with that length
 */
std::string generateRandomText(int textLength)
{
    int firstLetterASCIIEquivalent = static_cast<int>(FIRST_LETTER);
    std::default_random_engine randomTextEngine(static_cast<int>(time(nullptr)));
    std::uniform_int_distribution<int> randomNumberGenerator(firstLetterASCIIEquivalent, firstLetterASCIIEquivalent + LETTER_LENGTH - 1);

    // Generate random characters and combine them into a string
    std::string randomText;
    for (size_t i = 0; i < textLength; i++)
        randomText += randomNumberGenerator(randomTextEngine);

    return randomText;
}

const void generateRandomTextByUserEnter()
{
    int textLength;
    std::cout << "\nEnter the text length you would like to generate: ";
    std::cin >> textLength;

    // Generate random characters and combine them into a string
    std::string randomText = generateRandomText(textLength);
    std::cout << "\nCongratulations! Generated Text: " << randomText;
}

const void charStringOperations()
{
    size_t RANDOM_STR_LENGTH = 15;
    std::string randomStr1 = generateRandomText(RANDOM_STR_LENGTH);
    std::string randomStr2 = generateRandomText(RANDOM_STR_LENGTH * 2).substr(RANDOM_STR_LENGTH, RANDOM_STR_LENGTH * 2);

    std::cout << "\n1. Text Informations:"
              << "\nText: " << randomStr1
              << "\nCapacity: " << randomStr1.capacity()
              << "\nMax Size: " << randomStr1.max_size()
              << "\nSize: " << randomStr1.size()
              << "\nLength: " << randomStr1.size();
    std::cout << "\n2. Text Informations: "
              << "\nText: " << randomStr2
              << "\nCapacity: " << randomStr2.capacity()
              << "\nMax Size: " << randomStr2.max_size()
              << "\nSize: " << randomStr2.size()
              << "\nLength: " << randomStr2.size();

    std::cout << "\n**Comparing Results**\n";
    // Compare function compares the strings/substrings with each other and returns integer according to the result
    int compareResult = randomStr1.compare(randomStr2);
    std::cout << (compareResult > 0   ? "1. Text > 2. Text"
                  : compareResult < 0 ? "2. Text > 1. Text"
                                      : "Texts are the same!");

    std::string insertionText = "TEST";
    // Inserts a string after the position index in string
    randomStr1.insert(RANDOM_STR_LENGTH / 2, insertionText);
    std::cout << "\n1. Text after inserting a random text into the middle of the string: " << randomStr1;

    randomStr1.replace(RANDOM_STR_LENGTH / 2, insertionText.size(), "");
    std::cout << "\n1. Text after removing the inserted string: " << randomStr1;

    size_t randomStr1Length = randomStr1.size();
    // It stores each character of the string as a pointer
    char *randomStr1Ptr = new char[randomStr1Length - 1];

    randomStr1.copy(randomStr1Ptr, randomStr1Length, 0);
    // Set the latest pointer to nullptr
    randomStr1Ptr[randomStr1Length] = '\0';

    // c_str returns const pointer to null-terminated contents.
    std::cout << "\n1. Text is converted to a pointer-based string: " << randomStr1.c_str()
              << "\nIt's pointer equivalent is: " << randomStr1Ptr;

    // data function returns non-const pointer to contents so it stores each character of the string
    const char *randomStr1CharactersPtr = randomStr1.data();
    std::cout << "\nA new char pointer list to display each character of 1. Text: ";
    for (size_t i = 0; i < randomStr1Length; i++)
        // Print each character
        std::cout << *(randomStr1CharactersPtr + i) << " ";

    std::string::const_iterator stringIterator = randomStr1.begin();
    std::cout << "\nEach character of the 1. Text by using a string iterator: ";
    while (stringIterator != randomStr1.end())
        // Print the character and then get the next pointer
        std::cout << *(stringIterator++) << " ";

    std::string inputExample("Test 123 66.55 P");
    // istringstream is a class for char input memory streams.
    // The inputExample mentions the input whether the buffer can read, or write, or both
    std::istringstream stringInput(inputExample);
    std::string str;
    int num;
    double decNum;
    char character;

    // It allows taking the inputs with their types from a string text(The types must be in correct order)
    stringInput >> str >> num >> decNum >> character;
    std::cout << "\n\n**istringstream Example**"
              << "\nText is: " << inputExample
              << "\nstring: " << str
              << "\ninteger: " << num
              << "\ndouble: " << decNum
              << "\nchar: " << character;

    long longVal;
    stringInput >> longVal;
    // If the related type doesn't correct, then we can check that with input functions
    stringInput.good() ? std::cout << "\nThe long value is: " << longVal : std::cout << "\nInput doesn't start with a long type value";

    std::ostringstream outputString;
    std::cout << "\n\n**ostringstream Example**";
    std::string text1("\n**Output of several data types**");
    std::string text2("\n            VALUES");
    std::string text3("\n            double: ");
    std::string text4("\n           integer: ");
    std::string text5("\naddress of integer: ");

    double doubleVal = 121.12;
    int intVal = 99;

    // Set related values as a output to the ostringstream
    outputString << text1 << text2
                 << text3 << doubleVal
                 << text4 << intVal
                 << text5 << &intVal;

    // str function is used for displaying the character contents in the ostringstream
    std::cout << "\nThe result text: " << outputString.str();
    outputString << "\nExtra text is adde to the end!!";

    std::cout << "\nThe result text after adding extra text: " << outputString.str();

    /**
     * Functions to convert string to a numerical value
     * stoi ==> int
     * stol ==> long
     * stoul ==> unsigned long
     * stoll ==> long long
     * stoull ==> unsigned long long
     * stof ==> float
     * stod ==> double
     * stold ==> long double
     */
    std::string intString = "5555Test",
                longString = "-22.33Test",
                unsignedLongString = "33.22Test",
                longLongString = "-333.445Test",
                unsignedLongLongString = "5555,999Test",
                floatString = "123.55Test",
                doubleString = "99.44Test",
                longDoubleString = "-555.99Test";

    std::cout << "\n\n**Testing converting string to a numerical value with functions**\n"
              << "\nString: " << intString << "\tIt's integer equivalent with stoi: " << std::stoi(intString)
              << "\nString: " << longString << "\tIt's long equivalent with stol: " << std::stol(longString)
              << "\nString: " << unsignedLongString << "\tIt's unsigned long equivalent with stoul: " << std::stoul(longString)
              << "\nString: " << longLongString << "\tIt's long long equivalent with stoll: " << std::stoll(longLongString)
              << "\nString: " << unsignedLongLongString << "\tIt's unsigned long long equivalent with stoull: " << std::stoull(unsignedLongLongString)
              << "\nString: " << floatString << "\tIt's float equivalent with stof: " << std::stof(floatString)
              << "\nString: " << doubleString << "\tIt's double equivalent with stod: " << std::stod(doubleString)
              << "\nString: " << longDoubleString << "\tIt's long double equivalent with stold: " << std::stold(longDoubleString)
              << std::endl;

    std::string mixedText = "Hello123Test";
    try
    {
        int number = std::stoi(mixedText);
    }
    catch (std::invalid_argument err)
    {
        std::cout << "An error occurred while converting " << mixedText << " to an integer! Error: " << err.what();
    }

    size_t copyText1Length = 30, copyText2Length = 7;
    char text[] = "C++ is love!";
    char copyText1[copyText1Length];
    char copyText2[copyText2Length];

    strcpy(copyText1, text);
    strncpy(copyText2, copyText1, copyText2Length);
    copyText2[copyText2Length] = '\0';

    std::cout << "\n\nText: " << text
              << "\n1. Copied Text(Whole text is copied): " << copyText1
              << "\n2. Copied Text(Only 10 characters are copied): " << copyText2;

    strcat(copyText1, text);
    strncat(copyText2, text, 5);
    std::cout << "\n\nText is combined with 1. Copied Text: " << copyText1
              << "\n2. Copied text is combined with text's first 5 characters: " << copyText2;

    char *wordsPtr = strtok(copyText1, " ");
    std::cout << "\n\nWords in 1. Copied Text: \n";
    while (wordsPtr != nullptr)
    {
        // strlen function gets char as parameter and returns the length of it
        std::cout << wordsPtr << " (" << strlen(wordsPtr) << " Character)" << "\n";
        // Sending 1. argument as NULL, orders strtok function to continue from the latest call point.
        // strtok function stores the latest saved point information in the background.
        // So, it returns the next divided string each time from the string.
        // When it is called, if there's no unit stored in strtok function, then it returns NULL
        wordsPtr = strtok(NULL, " ");
    }

    std::cout << "After strtok function process is completed, the 1. Copied Text is: " << copyText1;

    std::cout << "\n\n***Converting C(Char) pointer strings to numerical values processes***\n"
              << "Some type explanations: (P: Pointer, K: Constant, c: Char, d: Double, i: Int, l: Long, etc.)\n";

    const char *doubleChar = "95.596% double process running",
               *intChar = "999 employees are working in this department",
               *longChar = "12345678 KM distance between the cities",
               *negativeLongChar = "-12345678 is an even negative number";
    /**
     * Type of char that returns by typeid is PKc. So, what 'P', 'K', 'c' means?
     * 'P' means **Pointer**
     * 'K' means **Constant**
     * 'c' means **char**
     * Running `c++filt -t` command returns the equivalent of this type name.
     * For example: `c++filt -t PKc` command returns `char const*`
     *
     * For **classes**, the type name returns a string that includes the `length of class name letters + class name`
     * For example, if the class name is 'Student';
     * typeid().name() function returns `7Student`
     *
     * Converter Functions:
     * atof ==> Converts a string to a floating-point number
     * atoi ==> Converts a string to an integer
     * atol ==> Convert a string to a long integer
     */
    std::cout << "\nChar double string: " << doubleChar << " (Type: " << typeid(doubleChar).name() << ')'
              << "\nDouble Equivalent(atof): " << atof(doubleChar) << " (Type: " << typeid(atof(doubleChar)).name() << ')'
              << "\n\nChar integer string: " << intChar << " (Type: " << typeid(intChar).name() << ')'
              << "\nInteger Equivalent(atoi): " << atoi(intChar) << " (Type: " << typeid(atoi(intChar)).name() << ')'
              << "\n\nChar long string: " << longChar << " (Type: " << typeid(longChar).name() << ')'
              << "\nLong Equivalent(atoi): " << atol(longChar) << " (Type: " << typeid(atol(longChar)).name() << ')';

    char *stringPtrOfDoubleChar, *stringPtrOfLongChar, *stringPtrOfUnsignedLongChar;
    stringPtrOfDoubleChar = stringPtrOfLongChar = stringPtrOfUnsignedLongChar = nullptr;

    /**
     * strtod ==> Converts a string to a floating-point number.
     * Returns the converted floating-point value and sets the string to a char pointer(2. parameter).
     *
     * strtol ==> Convert a string to a long integer.
     * Returns the converted long integer and sets the string values from the converted value to a char pointer(2. parameter).
     *
     * strtol ==> Convert a string to a unsigned long integer.
     * Returns the converted unsigned long integer and sets the string values from the converted value to a char pointer(2. parameter).
     */
    double doubleValueInString = strtod(doubleChar, &stringPtrOfDoubleChar);
    long longValueInString = strtol(negativeLongChar, &stringPtrOfLongChar, 0);
    unsigned long unsignedLongValueInString = strtoul(longChar, &stringPtrOfUnsignedLongChar, 0);

    std::cout << "\n\nThe double type text: " << doubleChar
              << "\t(The double value: " << doubleValueInString
              << "\tThe string value: '" << stringPtrOfDoubleChar << "'"
              << "\n\nThe negative long type text: " << negativeLongChar
              << "\t(The long value: " << longValueInString
              << "\tThe string value: '" << stringPtrOfUnsignedLongChar << "'"
              << "\n\nThe long type text: " << longChar
              << "\t(The unsigned long value: " << unsignedLongValueInString
              << "\tThe string value: '" << stringPtrOfLongChar << "'";
}

const void displayBits()
{
    int number;
    std::cout << "Enter an unsigned int to see its equivalent as bits: ";
    std::cin >> number;

    unsigned int eachBitLimit = sizeof(double);

    const int shift = eachBitLimit * sizeof(int) - 1;
    const unsigned int mask = 1 << shift;

    std::cout << number << " ==> ";
    for (size_t i = 1; i <= shift + 1; i++)
    {
        std::cout << (number & mask ? '1' : '0');
        number <<= 1;

        if (i % eachBitLimit == 0)
            std::cout << ' ';
    }

    std::cout << std::endl;
}

struct OptionStructure
{
    std::string desc;
    const void (*function)();
};

OptionStructure getOptionModel(const void (*function)()) noexcept
{
    return OptionStructure{
        function : function
    };
}

typedef std::vector<OptionStructure> vOption;
vOption getOptions() noexcept
{
    std::vector<OptionStructure> options{
        // Makes some calculations between two integers entered by the user
        getOptionModel(calculateWithNumbers),
        // Compares the numbers
        getOptionModel(compareNumbers),
        // Draws shapes
        getOptionModel(drawShapes),
        // Show ASCII equivalent of any character the user entered
        getOptionModel(showASCIIEquivalent),
        // Calculates BMI(Body Mass Index) and show the result
        getOptionModel(calculateBMI),
        // Calculates daily vehicle drive expenses
        getOptionModel(calculateVehicleExpenses),
        // Loop comparator by getting a length value from the user
        getOptionModel(loopComparator),
        // Print even or odd numbers
        getOptionModel(printNumbersInOrder),
        // According to the user entries, calculates average grades by using grade points and displays the class information
        getOptionModel(calculateGrades),
        // Generates random numbers according to the user entered limit
        getOptionModel(generateRandomNumbers),
        // Multiply the numbers for different parameter data types in the overloaded functions with same name
        getOptionModel(overloadMultiplyCalculation),
        // General basic sorting and searching in array (used with array library)
        getOptionModel(sortAndSearchInArray),
        // Create some vector variables, review and test some of the vector features
        getOptionModel(generalVectorFeatures),
        // Find array length by calculating the byte size of the variables
        getOptionModel(findArrayLengthBySize),
        // Displays bytes for each data type
        getOptionModel(displayBytesByDataType),
        // Gives some examples about using string/char array usages
        getOptionModel(stringCharArrayUsages),
        // Show hexadecimal, octal and scientific equivalents of a decimal number
        getOptionModel(showDecimalNumberEquivalents),
        // Print letters in the alphabet
        getOptionModel(printLettersInAlphabet),
        // Generate random text
        getOptionModel(generateRandomTextByUserEnter),
        // Some string operation example and explanations
        getOptionModel(charStringOperations),
        // Display bit equivalent of an unsigned integer
        getOptionModel(displayBits),
    };

    return options;
}

inline void displayOptions(vOption &options)
{
    for (const auto &option : options | boost::adaptors::indexed(1))
        std::cout << option.index() << ". " << option.value().desc << std::endl;
}

int main()
{
    std::cout << "Enter the number of the function which you would like to run: "
              << "(Type '" << std::cin.eof() << "' to end the process)"
              << std::endl;

    vOption options = getOptions();

    for (unsigned int i = 0; i < options.size(); i++)
    {
        // Assign the descriptions from the constant texts
        options[i].desc = Constants[i];

        // Display the options
        std::cout << (i + 1) << ". " << options[i].desc << std::endl;
    }

    int selection;
    while (std::cin >> selection && selection != EOF)
    {
        // Don't allow to enter an integer that causes any error
        if (selection < 0 || selection > options.size())
        {
            std::cout << "Unavailable number to run any function. Please make sure you entered an available number:" << std::endl;
            continue;
        }

        // If the user types 0, print the menu again
        if (selection == 0)
        {
            displayOptions(options);
            continue;
        }

        // Show selected option information
        std::cout << "\nSelected option is: "
                  << selection << ". " << options[selection - 1].desc
                  << "\nThe function is running...\n"
                  << std::endl;

        // Run the related function
        options[selection - 1].function();
        // Clear stream
        clearInputStream();

        // After the related function is completed, show the final explanations
        std::cout << "\nRun another function by entering its number. Type '0' to see the menu again. Type '"
                  << EOF
                  << "' to end the process.\n"
                  << std::endl;
    }

    return 0;
}
