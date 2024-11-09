#include <iostream>
#include <math.h>
#include <iomanip>
/**
 * See: https://www.boost.org/doc/libs/1_72_0/libs/range/doc/html/range/reference/adaptors/reference/indexed.html
 * Used {
 *  boost::adaptors::indexed
 * }
 */
#include <boost/range/adaptor/indexed.hpp>

#include "colors.h"

// Ref and Ptr Examples

// Set default value to the parameter
int squareByValue(unsigned int value = 2);
void squareByValueReference(int &);
void squareValueAndReference();

void setPointerAndMultiplyNumber();
void multiplyNumber(int *);
void updateConstantPointer();
void arrayPointerCalculations();

int main()
{
    // Squares values in different functions to compare updating referenced values
    // squareValueAndReference();

    // First setting initialization pointer and multiply calculation example
    // setPointerAndMultiplyNumber();

    // Test updating a constant pointer
    // updateConstantPointer();

    // Explanations and examples about array, pointer connection
    arrayPointerCalculations();
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

void multiplyNumber(int *numberPtr)
{
    // numberPtr returns the address of the value
    // *numberPtr returns value of the addressed variable
    // &numberPtr returns the address of the pointer
    *numberPtr = pow(*numberPtr, 3);
}

void setPointerAndMultiplyNumber()
{
    int value = 5;
    std::cout << "Value: " << value << "\tIt's address in memory: (& gives address of a value) " << &value << std::endl;

    /**
     * Set value's address to a pointer. So, valuePtr stores the memory address of the value variable.
     * However, as a quick note, valuePtr has another memory address. It stores the address of other value.
     *
     * value ==> (Value: 5, Address: 60000 (e.g.))
     *   |             |__________________________________________________________________
     *   |_____________________                                                           |
     *                         |                                                          |
     * valuePtr ==> (Value: value's Address(60000), Address: 500000 (e.g.), Pointer(*valuePtr): 5 (value variable's value))
     */
    int *valuePtr = &value;

    // Example to explain with more detail:
    std::cout << "\n*** Pointer stores the value's memory address as a value. Note that, it has another memory address ***"
              << std::setw(40) << std::left << "\nValue_pointer's value: " << valuePtr
              << std::setw(40) << std::left << "\nValue variable's memory address: " << &value
              << std::setw(40) << std::left << "\nValue_pointer's memory address: " << &valuePtr << std::endl;

    std::cout << "*** Calculation Example by using the pointers ***" << std::endl;
    // Let's update value by making calculations with valuePtr. It has the address of value so *valuePtr mentions the value of number.
    // Therefore, making any process on *valuePtr affects the value in the related address.
    // So, when calculating the *valuePtr, it makes the calculation on the value. See the example:
    std::cout << "Value before calculation: " << value << std::endl;

    multiplyNumber(valuePtr);
    std::cout << "Value after getting 3rd power of the pointer(has address of value): " << value
              << "\nValue changes but its address (pointer value) stays the same: " << valuePtr << std::endl;
}

void updateConstantPointer()
{
    int number = 12, updateNumber = 20;
    int *const ptr = &number;

    std::cout << "*** Test changing the const pointer's value and address **"
              << "\n- It allows to change the value of the const pointers but doesn't allow to change the address of it"
              << std::endl;

    std::cout << "Number: " << number
              << "\nPointer's value (number's address) (ptr): " << ptr
              << "\nThe number's value in the address of the pointer (*ptr): " << *ptr
              << "\nPointer's default address (&ptr): " << &ptr << std::endl;
    // Update pointer's value (number's value as well). It allows
    *ptr = updateNumber;
    std::cout << "\nUpdated Number (Updated to " << updateNumber << "): " << number
              << "\nPointer's value after update(Should be same): " << ptr
              << "\nThe number's value in the address of the pointer(Should be updated): " << *ptr
              << "\nPointer's address after update(Should be same): " << &ptr << std::endl;

    // However, updating the address of the pointer doesn't allow since the pointer is defined as a constant.
    // If a pointer is defined as a constant, changing its address isn't allowed. Changing the value is allowed.
    // Just comment out the following line to test
    // ptr = &value;

    // If we would define the ptr as;
    const int *const ptr2 = &number;
    // Then it doesn't allow to change both of the value and address. Just comment out the following line to test
    // It says `expression must be a modifiable lvalue`. lvalue means the variables that has an identifiable location in memory
    // Because of it is a constant variable here, it isn't a modifiable **lvalue**. Without const tag, it would be a modifiable **lvalue**
    // *ptr2 = updateNumber;
}

void arrayPointerCalculations()
{
    // Array elements addresses are designed as ==>
    // Values:  15    20    30    40   50   60
    // Adress: 6000  6004  6008  6012 6014 6018
    int number[6]{15, 20, 30, 40, 50, 60};
    // When setting the number to a pointer, it sets the first element (15)
    int *numberPtr = number; // Same with the int *numberPtr = &number[0];

    std::cout << "*** Array Elements ***" << std::endl;
    std::cout << "Each array element has " << sizeof(number[0]) << " byte" << std::endl;
    for (auto const &element : number | boost::adaptors::indexed(1))
    {
        std::cout << element.index() << ". Element: " << element.value() << std::endl;
    }

    std::cout << "\nPointer's addressed value(Should be the first element of number array): " << *numberPtr
              << "\nPointer's address(Should be the first number array's element's address): " << numberPtr
              << std::endl;

    std::cout << "\n*** Let's reach the two up level pointer. It should be equal to the array's 3. element ***" << std::endl;
    // It updates the address. It adds 4 byte (byte size of array element) to the address. Let's see the process steps ==>
    // The numberPtr was storing the number[0]'s address (6000).
    // For each increment, it's address is updated to 6004 and then 6008. So, it has 6008 address value now.
    // In the 6008 address, number[2] (30) exists. Therefore, *numberPtr displays the 30 and numberPtr displays 6008.
    numberPtr += 2;
    std::cout << "\nPointer's addressed value(Should be the third element of number array): " << *numberPtr
              << FOREGRN
              << "\nPointer's address(Should be the third number array's element's address (First address + (2(Increment) * 4(1 array element's byte value)))): "
              << RESETTEXT
              << numberPtr
              << std::endl;

    std::cout << "\n*** Let's react the 1 down level pointer. It should be equal to the array's 2. element ***" << std::endl;
    // The numberPtr was storing the number[2]'s address (6008).
    // It's address is updated to 6004 (and then 6000 for 2 decrement). So, it has 6004 address value now.
    // In the 6004 address, number[1] (20) exists. Therefore, *numberPtr displays the 20 and numberPtr displays 6004.
    numberPtr--;

    std::cout << "\nPointer's addressed value(Should be the second element of number array): " << *numberPtr
              << FOREGRN
              << "\nPointer's address(Should be the second number array's element's address (First address + (1(Increment) * 4(1 array element's byte value)))): "
              << RESETTEXT
              << numberPtr
              << std::endl;

    // Let's subtract pointers from each other. Note that, for these type calculations, both of the pointers must be addressed to the same array
    // Create a new pointer. It stores the first element of the array as default
    int *numberPtr2 = number; // Same with the int *numberPtr2 = &number[0];

    // Subtracting the pointers addresses from each other gives us the element index difference between them
    // Examples ==>
    std::cout << "\nAfter the latest pointer calculations, the old pointer has the address of the **second** element: " << numberPtr
              << "\nThe new pointer is addressed to the **first** element of the array: " << numberPtr2
              << "\nAfter subtracting their addresses, the response provides the index length between the elements: "
              << numberPtr - numberPtr2
              << FOREGRN << "\n(It calculates it by dividing the result to the byte size of an element (4 == 1))" << RESETTEXT
              << "\n\nAfter the latest pointer calculations, the old pointer has the value of the **second** element: " << *numberPtr
              << "\nThe new pointer has the value of the **first** element of the array: " << *numberPtr2
              << "\nAfter subtracting their values: " << *numberPtr - *numberPtr2
              << std::endl;

    numberPtr += 4;
    std::cout << "\n\n*** Let's make the same calculation by increasing both of the pointers ***"
              << "\nAfter increasing the old pointer's address for 4 level up, it is addressed to the **sixth** element: " << numberPtr
              << "\nThe new pointer is still addressed to the **first** element of the array: " << numberPtr2
              << "\nAfter subtracting their addresses, the response provides the index length between the elements: "
              << numberPtr - numberPtr2
              << FOREGRN << "\n(It calculates it by dividing the result to the byte size of an element ((4 == 1) * 5))" << RESETTEXT
              << "\nAfter increasing the old pointer's address for 4 level up, it has the **sixth** element's value: " << *numberPtr
              << "\nThe new pointer is still has the **first** element's value: " << *numberPtr2
              << "\nAfter subtracting their values: " << *numberPtr - *numberPtr2
              << std::endl;
}