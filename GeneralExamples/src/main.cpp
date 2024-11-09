#include <iostream>
#include <math.h>
#include <unordered_map>
// For Time Recording
#include <chrono>
#include <iomanip>
#include <map>
#include <cstdlib>
#include <random>
#include <vector>
#include <array>
#include <algorithm>
/**
 * See: https://www.boost.org/doc/libs/1_72_0/libs/range/doc/html/range/reference/adaptors/reference/indexed.html
 * Used {
 *  boost::adaptors::indexed
 * }
 */
#include <boost/range/adaptor/indexed.hpp>

#include "colors.h"

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

const void showASCIIEquivalent()
{
    char character;
    std::cout << "Enter any character to see ASCII equivalent" << std::endl;
    std::cin >> character;

    std::cout << static_cast<int>(character) << std::endl;

    int number;
    std::cout << "Enter any ASCII number to see it's equivalent character" << std::endl;
    std::cin >> number;

    std::cout << static_cast<char>(number) << std::endl;
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

const auto loopReader(int loopLength, void (*loopFunction)(int))
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

void overloadMultiplyCalculation()
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

void sortAndSearchInArray()
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

void generalVectorFeatures()
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
    std::cout << "Is the integer vector list same with backup vector list?:\t" << (intList == backupIntList ? "Yes!" : "No!") << std::endl;

    // Try to achieve to an element index that doesn't exist and catch the error
    try
    {
        std::cout << "Let's see the 100. element of the vector: " << intList.at(100) << std::endl;
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
    for (float &floatItem : floatList)
        std::cout << floatItem << std::endl;

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
        std::cout << floatItem << std::endl;
}

size_t getSize(double *ptr)
{
    // Returns the pointer's size as byte
    return sizeof(ptr);
}

void findArrayLengthBySize()
{
    double numbers[20];

    std::cout << "The number of bytes in the array: (1 Double: 8 byte): " << sizeof(numbers)
              << "\nThe number of bytes of the array's pointer size: " << getSize(numbers)
              << "\nArray length (total_size/first_element_size): " << sizeof(numbers) / sizeof(numbers[0])
              << std::endl;
}

void displayBytesByDataType()
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
void stringCharArrayUsages()
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

    std::cout << language[7] << std::endl;
    std::cout << language[0] << "\t" << languageWithSingleQuotes[0] << std::endl;
    std::cout << "\n*** Char type array's sizes (Each char data type takes up 1 bit of space) ***"
              << "\nFirst array's byte size: " << sizeof(language)
              << "\nSecond array's byte size: " << sizeof(languageWithSingleQuotes)
              << FOREYEL << "\nSo, why the first array's byte size is 9 but the second one's is 8?"
              << FOREGRN << "\nBecause, when defining a char array as a string, it adds an epmty('\\n') element to the end of the array. See below lines ==>"
              << RESETTEXT
              << "\nThe last element of the first array: " << language[sizeof(language) / sizeof(language[0]) - 1]
              << "\nThe last element of the second array: " << languageWithSingleQuotes[sizeof(languageWithSingleQuotes) / sizeof(languageWithSingleQuotes[0]) - 1]
              << std::endl;

    std::string enteredString;
    std::cout << "\nEnter any long string\n";
    // Using setw when getting an input helps us to take only limited characters from the entered text
    std::cin >> std::setw(10) >> enteredString;
    std::cout << "Allowed string to store in the system:\t" << enteredString << std::endl;

    size_t characterLimit = 20; 
    char enteredCharacters[characterLimit];
    // Using getLine limitations when getting an input helps us to take only limited characters from the entered text
    // It gets the entered text's 20 character after the 10 character cause the above functionality takes and stores the first 10 character
    std::cin.getline(enteredCharacters, characterLimit);
    // Char arrays can be displayed as a string on the terminal without using any loop
    std::cout << "The list with the allowed characters in the system:\t" << enteredCharacters << std::endl;
}

int main()
{
    // Makes some calculations between two integers entered by the user
    // calculateWithNumbers();

    // Compares the numbers
    // compareNumbers();

    // Draws shapes
    // drawShapes();

    // Show ASCII equivalent of any character the user entered
    // showASCIIEquivalent();

    // Calculates BMI(Body Mass Index) and show the result
    // calculateBMI();

    // Calculates daily vehicle drive expenses
    // calculateVehicleExpenses();

    // Loop comparator by getting a length value from the user
    // loopComparator();

    // Print even or odd numbers
    // printNumbersInOrder();

    // According to the user enters, calculates average grades by using grade points and displays the class information
    // calculateGrades();

    // Generates random numbers according to the user entered limit
    // generateRandomNumbers();

    // Multiply the numbers for different parameter data types in the overloaded functions with same name
    // overloadMultiplyCalculation();

    // General basic sorting and searching in array (used with array library)
    // sortAndSearchInArray();

    // Create some vector variables, review and test some of the vector features
    // generalVectorFeatures();

    // Find array length by calculating the byte size of the variables
    // findArrayLengthBySize();

    // Displays bytes for each data type
    // displayBytesByDataType();

    // Gives some examples about using string/char array usages
    stringCharArrayUsages();
}
