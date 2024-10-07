#include <iostream>
#include <math.h>
#include <unordered_map>

using namespace std;

const void calculateWithNumbers()
{
    int number1 = 0, number2 = 0, sum = 0;

    cout << "Enter the first integer: " << endl;
    cin >> number1;

    cout << "Enter the second integer: " << endl;
    cin >> number2;

    cout << "Number 1 + Number 2 ==>  " << number1 + number2
         << "\nNumber 1 - Number 2 ==> " << number1 - number2
         << "\nNumber 1 * Number 2 ==> " << number1 * number2
         << "\nNumber 1 / Number 2 ==> " << number1 / number2 << endl;
}

const void compareNumbers()
{
    int number1 = 0, number2 = 0;
    cout << "Enter the first number" << endl;
    cin >> number1;

    cout << "Enter the second number" << endl;
    cin >> number2;

    cout << ((number1 > number2) ? "1. number is higher than 2. number" : (number1 == number2) ? "The numbers are equal"
                                                                                               : "2. number is higher than 1. number")
         << endl;
}

const void drawShapes()
{
    int selectedShape;
    size_t totalShapeLength = 10;

    cout << "Draw one of the shapes (Enter the number to draw it):" << "\n1 ==> Square" << "\n2 ==> Ellipse" << endl;
    cin >> selectedShape;

    switch (selectedShape)
    {
    case 1:
        for (int row = 0; row <= totalShapeLength; row++)
        {
            for (int col = 0; col <= totalShapeLength; col++)
            {
                // After putting the last *, go to the next line.
                // endl manipulator inserts a **newline** and flushes the stream.
                if (col == totalShapeLength)
                {
                    cout << "*" << endl;
                    continue;
                }

                // Draw the asteriks in a line at the first and the latest lines
                if ((row == 0) || (row == totalShapeLength))
                {
                    cout << "* ";
                    continue;
                }

                // Draw asteriks at the first column only if the row isn't first or the last
                if (col == 0)
                {
                    cout << "* ";
                    continue;
                }

                // Draw empty lines to equalize the spaces
                cout << "  ";
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
                        cout << " " << endl;
                        continue;
                    }

                    cout << (((col > 3) && (col < 7)) ? "*" : " ");
                    continue;
                }

                if ((row == 1) || (row == totalShapeLength - 1))
                {
                    if (col == totalShapeLength)
                    {
                        cout << "  " << endl;
                        continue;
                    }

                    cout << (((col == 2) || (col == 8)) ? "*" : " ");
                    continue;
                }

                if (((row == 2) || (row == totalShapeLength - 2)))
                {
                    if (col == totalShapeLength)
                    {
                        cout << "  " << endl;
                        continue;
                    }

                    cout << (((col == 1) || (col == 9)) ? "*" : " ");
                    continue;
                }

                if (col == 0)
                {
                    cout << "*";
                    continue;
                }

                if (col == totalShapeLength)
                {
                    cout << "*" << endl;
                    continue;
                }
                cout << " ";
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
    cout << "Enter any character to see ASCII equivalent" << endl;
    cin >> character;

    cout << static_cast<int>(character) << endl;

    int number;
    cout << "Enter any ASCII number to see it's equivalent character" << endl;
    cin >> number;

    cout << static_cast<char>(number) << endl;
}

const void calculateBMI()
{
    double height, weight, bmiValue;
    unordered_map<string, string> bmiValues{{"Obese", " > 30"}, {"Overweight", " 25 * 29.9"}, {"Normal", " 18.5 - 24.9"}, {"Underweight", " < 18.5"}};

    cout << "** BMI LIMITS **" << endl;

    for (auto value = bmiValues.begin(); value != bmiValues.end(); value++)
    {
        cout << value->first + ":" << value->second << endl;
    }
    cout << "\nEnter your height: " << endl;
    cin >> height;

    cout << "Enter your weight: " << endl;
    cin >> weight;

    bmiValue = weight / (pow(height / 100, 2));
    cout << "Your BMI index is: "
         << bmiValue
         << " (" + (next(bmiValues.begin(), (bmiValue < 18.5) ? 0 : (bmiValue < 25) ? 1
                                                                : (bmiValue < 30)   ? 2
                                                                                    : 3)
                        ->first) +
                ")"
         << endl;
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
}
