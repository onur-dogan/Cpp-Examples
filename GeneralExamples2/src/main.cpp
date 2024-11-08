#include <iostream>
#include <math.h>

// Set default value to the parameter
int squareByValue(unsigned int value = 2);
void squareByValueReference(int &);
void squareValueAndReference();

int main()
{
    // Squares values in different functions to compare updating referenced values
    // squareValueAndReference();
}

// It doesn't update the value which is in parameter since it's reference isn't same with the x's reference
// Here, it creates a new value and makes the processes on it so it doesn't affect the x value in squareValueAndReference
int squareByValue(unsigned int value)
{
    return value *= value;
}

// The valueRef parameter has same value/reference with y cause of using ampersand(&)
// So when it's updated, y (with same reference) value also updates
void squareByValueReference(int &valueRef)
{
    valueRef *= valueRef;
}

void squareValueAndReference()
{
    int x = 2, y = 4;

    std::cout << "X value before triggering the squareByValue function: " << x
              << "\nReturn value by squareByValue function: " << squareByValue(x)
              << "\nX value after squareByValue function is completed (It is still same since the calculation didn't affect x): " << x;

    std::cout << "\nY value before triggering the squareByValue function: " << y;
    squareByValueReference(y);
    std::cout << "\nY value after squareByValue function is completed (It squares the value by taking its reference): " << y << std::endl;
}