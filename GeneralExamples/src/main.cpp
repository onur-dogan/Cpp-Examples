#include <iostream>
#include <math.h>
#include <unordered_map>
#include <chrono>
#include <math.h>
#include <iomanip>

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

    std::cout << "Total With For ==> " << std::setw(10) << total << std::endl;
}

void whileLoopFunction(int loopLength)
{
    int total = 0, counter = 0;
    // Shorthand to increase counter in order instead of increasing it at last in func
    while (++counter <= loopLength)
    {
        total += pow(counter, 2);
    }

    std::cout << "Total With While ==> " << std::setw(10) << total << std::endl;
}

void doWhileLoopFunction(int loopLength)
{
    // Because of do works initially, the counter should start from 1
    int total = 0, counter = 1;
    do
    {
        total += pow(counter, 2);
    } while (++counter <= loopLength);

    std::cout << "Total With Do-While ==> " << std::setw(10) << total << std::endl;
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
    printNumbersInOrder();
}
