#include <iostream>
#include <math.h>
#include <iomanip>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <boost/range/adaptor/indexed.hpp>
/**
 * See: https://www.boost.org/doc/libs/1_72_0/libs/range/doc/html/range/reference/adaptors/reference/indexed.html
 * Used {
 *  boost::adaptors::indexed
 * }
 */

#include "colors.h"

// Ref and Ptr Examples

// Definitions
void printMainArguments(int, char *[]);

// Set default value to the parameter
int squareByValue(unsigned int value = 2);
void squareByValueReference(int &);
void squareValueAndReference();

void setPointerAndMultiplyNumber();
void multiplyNumber(int *);
void updateConstantPointer();
void arrayPointerCalculations();

void deallocateVariables();

void customIntegerIterators();
void printNumbersReverse();

// Common print function
template <typename T>
inline void printElements(std::string title, T &list);

void listExamples();

void dequeueExamples();
void queueExamples();

void linkedSetExamples();

inline bool checkValue(std::string, int);
void insertElement(std::map<std::string, int> &, std::pair<std::string, int>);
inline void printPersons(std::map<std::string, int> &);
void mapExamples();

void bitsetExamples();

void algorithmExamples();
void mathematicalAlgorithmExamples();

void lambdaFunctions();

void memoryAllocationExample();

/**
 * @param argc (Argument Count) ==> A non-negative integer that contains the count of arguments that follow in `argv[]`
 * @param argv (Argument Vector) ==> An array of null-terminated strings representing command-line arguments entered by the user of the program.
 * By convention, argv[0] is the command with which the program is invoked. So, argv[0] displays the program filename.
 * argv[1] is the first command-line argument. The last argument from the command line is argv[argc - 1], and argv[argc] is always NULL
 *
 * @example Run the first function (printMainArguments) to see the outputs of the arguments
 */
int main(int argc, char *argv[])
{
    // Print the arguments of the main function
    // printMainArguments(argc, argv);

    // Squares values in different functions to compare updating referenced values
    // squareValueAndReference();

    // First setting initialization pointer and multiply calculation example
    // setPointerAndMultiplyNumber();

    // Test updating a constant pointer
    // updateConstantPointer();

    // Explanations and examples about array, pointer connection
    // arrayPointerCalculations();

    // Deallocate variables
    // deallocateVariables();

    // Created some custom integer iterators for output/input streams
    // customIntegerIterators();

    // Prints the numbers in reverse format
    // printNumbersReverse();

    // List usage and examples of the common methods
    // listExamples();

    // Dequeue usage and examples of the common methods
    // dequeueExamples();

    // Queue usage and examples of the common methods
    // queueExamples();

    // Linked Set, multiple set usage and examples of the common methods
    // linkedSetExamples();

    // Map usage and examples of the common methods
    // mapExamples();

    // Bitset usage and examples of the common methods
    // bitsetExamples();

    // Some array algorithm examples and explanations about some common methods
    // algorithmExamples();

    // Some mathematical array algorithm examples and explanations about some common methods
    // mathematicalAlgorithmExamples();

    // Lambda function usage and some examples
    // lambdaFunctions();

    // Example of triggering memory allocation issue manually
    // memoryAllocationExample();

    return 0;
}

void printMainArguments(int argc, char *argv[])
{
    std::cout << "argc: " << argc;
    // The size of the array pointed to by **argv** is at least **argc + 1**
    for (unsigned int i; i != argc; i++)
        std::cout << "\nargv[" << i << "]: " << std::quoted(argv[i]);

    // The last element `argv[argc]`, is guaranteed to be a **NULL** pointer
    std::cout << "\nargv[argc(" << argc << ")]: " << static_cast<void *>(argv[argc]) << "\n";
}

// It doesn't update the value which is in parameter since it's reference isn't same with the value's reference
// Here, it creates a new value and makes the processes on it. So, it doesn't affect the value in the squareValueAndReference
int squareByValue(unsigned int value)
{
    return value *= value;
}

// The valueRef parameter has the same value/reference as the value that was sent via caller function cause of using ampersand(&)
// So when it's updated in this function, the value parameter that is sent from the caller function (with the same reference) updates
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

// An example of a manipulator. It can be used instead of \t as seen in the following function
inline std::ostream &tab(std::ostream &output)
{
    return output << "\t";
}

void setPointerAndMultiplyNumber()
{
    int value = 5;
    std::cout << "Value: " << value << tab << "It's address in memory: (& gives address of a value) " << &value << std::endl;

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

// An example of a manipulator. It can be used instead of \n as seen in the following function
inline std::ostream &endLine(std::ostream &output)
{
    return output << "\n"
                  << std::flush;
}

void deallocateVariables()
{
    size_t arrayLength = 10;
    char *newArray = new char[arrayLength]{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'k', 'p'};

    std::cout << "*** BEFORE ***" << std::endl;
    for (unsigned int i = 0; i < arrayLength; i++)
        std::cout << newArray[i] << endLine;

    delete[] newArray;

    std::cout << "*** AFTER ***" << std::endl;
    for (unsigned int i = 0; i < arrayLength; i++)
        std::cout << newArray[i] << endLine;
}

void customIntegerIterators()
{
    std::cout << "Enter two integers";

    // New istream iterator to read the inputs
    std::istream_iterator<int> inputInt(std::cin);

    int number1 = *inputInt;
    std::cout << "First integer's address: " << &inputInt << " and value: " << *inputInt << std::endl;

    // Get the next value
    ++inputInt;
    int number2 = *inputInt;
    std::cout << "Second integer's address: " << &inputInt << " and value: " << *inputInt << std::endl;

    // New ostream_iterator to print the inputs
    std::ostream_iterator<int> outputInt(std::cout);
    // Streams the result automatically
    *outputInt = number1 + number2;
}

void printNumbersReverse()
{
    const size_t ARRAY_SIZE = 6;
    std::array<int, ARRAY_SIZE> newArray{10, 20, 30, 40, 50, 60};
    // Create a new vector by using the variables in the array
    std::vector<int> numbers{newArray.begin(), newArray.end()};
    // Stream iterator to print the integer variables. \n is used to print each one in a line
    std::ostream_iterator<int> printer(std::cout, "\n");

    std::cout << "The variables in the vector: " << std::endl;
    // It copies the vector elements to print via printer func
    std::copy(numbers.begin(), numbers.end(), printer);

    // Lets change the first element automatically
    numbers[0] = 999;

    int newFirstNumber, newSecondNumber;
    std::cout << "Enter two number to add as the first and the second elements: " << std::endl;
    std::cin >> newFirstNumber >> newSecondNumber;
    numbers.insert(numbers.begin(), newFirstNumber);
    numbers.insert(numbers.begin()++, newSecondNumber);

    std::cout << "The variables in the vector after the changes: " << std::endl;
    std::copy(numbers.begin(), numbers.end(), printer);

    std::cout << "The variables as reversed: " << std::endl;
    for (auto reverseIterator = numbers.crbegin(); reverseIterator != numbers.crend(); reverseIterator++)
        std::cout << *reverseIterator;

    // Print max and min numbers
    int minNumber = std::min({5123, 1231, 43298, 9594, 1111});
    int maxNumber = std::max({5123, 1231, 43298, 9594, 1111});
    std::cout << "Additional test to find the max and min numbers quickly." << " Min: " << minNumber << ", Max:" << maxNumber;
}

// Common print function to print the elements in the list/dequeue
template <typename T>
inline void printElements(std::string title, T &list)
{
    // Print the title first
    std::cout << "\n"
              << title
              << ":\n";
    // Then, print the elements in the list
    for (auto num = list.cbegin(); num != list.cend(); num++)
        std::cout << *num << "\t";

    // Or use iterator
    // std::ostream_iterator<int> outputIterator(std::cout, "\t");
    // Overloads for streambuf iterators.
    // std::copy(list.cbegin(), list.cend(), outputIterator);
}

void listExamples()
{
    const size_t SIZE = 4;
    std::array<int, SIZE> numbers{5, 10, 15, 20};
    std::list<int> intList;
    std::list<int> otherIntList;

    std::cout << "Enter 4 numbers to add in the list: " << std::endl;

    std::istream_iterator<int> intListListener(std::cin);
    // Set the first entered data
    intList.push_back(*intListListener);
    // Then loop the enters until the list is fully filled
    while (intList.size() != 4)
        intList.push_back(*(++intListListener));

    // Print the list
    printElements("The list", intList);

    // Sort and print the list again
    intList.sort();
    printElements("The list after sorting process", intList);

    // Copy the elemets of the created list to the other one
    otherIntList.insert(otherIntList.cbegin(), intList.cbegin(), intList.cend());
    printElements("\nYour list is copied to the other list. The other list after copying process", otherIntList);

    // splice function copies the elements of the list to the other one and purges the elements from the main list
    intList.splice(intList.cend(), otherIntList);
    printElements("\nThe other list is spliced to the main list. The list after splice process", intList);
    printElements("The other list after splice process", otherIntList);

    // Sort and print the spliced list
    intList.sort();
    printElements("\nThe merged list after sorting process", intList);

    // Set list with the custom data
    otherIntList.insert(otherIntList.cend(), numbers.cbegin(), numbers.cend());
    otherIntList.sort();
    printElements("\nThe other list is like that now", otherIntList);

    // merge function copies the elements of the list **as sorted** to the other one and purges the elements from the main list
    intList.merge(otherIntList);
    printElements("\nThe main list is merged with the other list. The list after merging process", intList);
    printElements("The other after merging process", otherIntList);

    // unique function removes the duplicated values
    intList.unique();
    printElements("\nThe main list after removing the duplicated values", intList);

    std::cout << "\nEnter a value you would like to remove from the list" << std::endl;
    // Removes every element in the list equal to value
    intList.remove(*(++intListListener));

    printElements("\nThe main list after removing the value you entered", intList);

    std::cout << "\n End of the list functions.." << std::endl;
}

void dequeueExamples()
{
    size_t DEQUEUE_SIZE = 5;
    std::deque<std::string> personDequeue;

    std::cout << "Enter the names of the 5 persons in the first place of the queue to the last\n"
              << std::endl;

    std::istream_iterator<std::string> dequeueListener(std::cin);
    personDequeue.push_back(*dequeueListener);
    while (personDequeue.size() != DEQUEUE_SIZE)
        personDequeue.push_back(*(++dequeueListener));

    // Print the queue
    printElements("The persons in the queue", personDequeue);

    // Remove the first person from the queue
    personDequeue.pop_front();
    printElements("The first person is removed from the queue. The new queue is", personDequeue);

    /**
     * The first person accepted to give its place to the second person. Change their positions in the queue
     *
     * Quick Note and Example:
     *  If we would take the address of the queue's 0 element here like this:
     * std::string *firstPerson = &personDequeue[0];
     * personDequeue[0] = personDequeue[1];
     * personDequeue[1] = *firstPerson;
     * Then it would change person 1's name with the changed person 0's name so the first and the second persons would have the same name
     * Because, it would get the value in the related address. The value in the address was already changed with the person[1] value, in the 2. line
     *
     * std::string firstPerson = personDequeue[0];
     * personDequeue[0] = personDequeue[1];
     * personDequeue[1] = firstPerson;
     *
     * Used swap function as shorthand.
     *  */
    std::swap(personDequeue[0], personDequeue[1]);

    printElements("The first person changed the queue place with the second person. The new queue is", personDequeue);
}

void queueExamples()
{
    size_t QUEUE_SIZE = 5;
    // Normal queue
    std::queue<std::string> personQueue;

    std::cout << "Enter the names of the 5 persons in the first place of the queue to the last\n"
              << std::endl;

    std::istream_iterator<std::string> queueListener(std::cin);
    // In queue, it always pushes to the back ()
    personQueue.push(*queueListener);
    while (personQueue.size() != QUEUE_SIZE)
        personQueue.push(*(++queueListener));

    std::cout << "The person who is at the first place of the queue: \t" << personQueue.front() << std::endl;
    personQueue.pop();

    std::cout << "The person who was in the first place entered the room. So, the new person in the first place of the queue: \t"
              << personQueue.front()
              << std::endl;

    // PRIORTY QUEUE
    // Priority queue that sorts the values automatically and sets the variable with the biggest value to the top
    std::priority_queue<int> personAgePriortyQueue;
    std::cout << "Enter the age of the 5 persons to make a queue\n"
              << std::endl;

    std::istream_iterator<int> priorityQueueListener(std::cin);

    personAgePriortyQueue.push(*priorityQueueListener);
    while (personAgePriortyQueue.size() != QUEUE_SIZE)
        personAgePriortyQueue.push(*(++priorityQueueListener));

    // So, the priority queue sorts the elements automatically and locates the biggest value to the top(front) of the queue
    std::cout << "The person who should be at the first place of the priority queue with age of: \t" << personAgePriortyQueue.top() << std::endl;
    personAgePriortyQueue.pop();

    std::cout << "The person who was in the first place entered the room. So, the new person in the first place of the queue with age of: \t"
              << personAgePriortyQueue.top()
              << std::endl;
}

void linkedSetExamples()
{
    // It sorts the variables automatically. If the sorting doesn't important, then use **unordered_set**
    // The default sorting is less. It can be configured by setting the 2. parameter below:
    // For example, I set it to sort by greater or equal
    std::set<double, std::greater<double>> doubleLinkedSet({44.44, 3.3, 1.1, 88.88, 5.5});
    printElements("Elements in the list", doubleLinkedSet);

    // The sets don't allow to storage of the same variables. That's one of the best features of it. So, it doesn't allow to insert a value that exists
    // However, we can configure it to allow that by setting `greater_equal` or `less_equal` when defining the set.
    // It allows variables that exist because of the _equal setting. See the example below:
    std::cout << "\nLet's try to insert some elements to the list" << std::endl;

    auto insertedValue = doubleLinkedSet.insert(*doubleLinkedSet.begin());
    std::cout << "\n"
              << *insertedValue.first << (insertedValue.second ? " is" : " is not")
              << " inserted!";
    printElements("Elements in the list after trying to insert the element", doubleLinkedSet);

    insertedValue = doubleLinkedSet.insert(120.99);
    std::cout << "\n"
              << *insertedValue.first << (insertedValue.second ? " is" : " is not")
              << " inserted!";
    printElements("Elements in the list after trying to insert the element", doubleLinkedSet);

    // ----------------------------------------------------------------------------------------
    // The other linked set that allows to insert the equal values
    std::set<double, std::greater_equal<double>> otherDoubleLinkedSet({200, 300, 400, 500, 100});
    printElements("\nThe elements in the other list", otherDoubleLinkedSet);

    std::cout << "\nLet's try to insert some elements to the list" << std::endl;

    insertedValue = otherDoubleLinkedSet.insert(*otherDoubleLinkedSet.begin());
    std::cout << "\n"
              << *insertedValue.first << (insertedValue.second ? " is" : " is not")
              << " inserted!";
    printElements("Elements in the list after trying to insert the element", otherDoubleLinkedSet);

    insertedValue = otherDoubleLinkedSet.insert(11.22);
    std::cout << "\n"
              << *insertedValue.first << (insertedValue.second ? " is" : " is not")
              << " inserted!";
    printElements("Elements in the list after trying to insert the element", otherDoubleLinkedSet);

    // -----------------------------------------------------------------------------------------
    // Multiset variable example with the less as Compare parameter, to run find function
    std::multiset<double, std::less<double>> doubleMultipleSet(otherDoubleLinkedSet.begin(), otherDoubleLinkedSet.end());
    printElements("The elements in the multiset list", doubleMultipleSet);

    double search, nearestNum;
    std::cout << "\nEnter a number to check whether it is in this list: ";
    std::istream_iterator<double> searchListener(std::cin);
    search = *searchListener;

    auto result = doubleMultipleSet.find(search);
    // Note that, looks like the find method doesn't work as expected if the multiset is created without less compare parameter
    std::cout << search << ((result == doubleMultipleSet.end()) ? " doesn't exist" : " exists") << " in the list\n";

    std::cout << "\nEnter a number to see the nearest elements to it in the list: ";
    nearestNum = *(++searchListener);

    auto p = doubleMultipleSet.equal_range(nearestNum);
    std::cout << "Lower bound: " << *(p.first)
              << "\nUpper bound: " << *(p.second);
    // If would like to get the bounds separately, the function below prints the same response:
    // std::cout << "Lower bound: " << *(doubleMultipleSet.lower_bound(nearestNum))
    //           << "\nUpper bound: " << *(doubleMultipleSet.upper_bound(nearestNum));
}

inline bool checkValue(std::string name, int age)
{
    if (!name.length())
    {
        std::cerr << "The person must have a name information! Make sure you entered the correct information" << std::endl;
        return false;
    }

    if (age <= 0)
    {
        std::cerr << "The person can't have age lower than 0! Make sure you entered the correct information" << std::endl;
        return false;
    }

    return true;
}

void insertElement(std::map<std::string, int> &map, std::pair<std::string, int> pair)
{
    bool isValueOk = checkValue(pair.first, pair.second);
    if (isValueOk)
    {
        // To check by using the find method, need to compare it with the end() function's result
        if (map.find(pair.first) != map.end())
        {
            std::cerr << "There is a person with the same name(" << pair.first << ") already in the list, so it didn't inserted to the list.." << std::endl;
            return;
        }

        map.insert(pair);
    }
}

inline void printPersons(std::map<std::string, int> &map)
{
    for (const auto &person : map | boost::adaptors::indexed(1))
        std::cout << person.index() << ". Person's Name(Key): " << person.value().first << ", Age(Value): " << person.value().second << "\n";
}

void mapExamples()
{
    const size_t MAP_SIZE = 5;
    // A new map list with `{key = PersonName, value: age}` prototype that sorted by key. The first variable has set manually as an example
    std::map<std::string, int, std::less<std::string>> personWithAges{{"Software Developer", 26}};

    std::cout << "Enter the name and the age of each person to insert in the map list. (There will be 5 person in the list)" << std::endl;

    int count = 1;
    std::cout << count << ". Person's Name: ";
    std::istream_iterator<std::string> nameListener(std::cin);

    std::cout << *nameListener << "'s Age: ";
    std::istream_iterator<int> ageListener(std::cin);
    insertElement(personWithAges, std::make_pair(*nameListener, *ageListener));

    while (count != MAP_SIZE)
    {
        ++count;
        std::cout << count << ". Person's Name: ";
        ++nameListener;

        std::cout << *nameListener << "'s Age: ";
        ++ageListener;

        insertElement(personWithAges, std::make_pair(*nameListener, *ageListener));
    }

    std::cout << "*** The Person List ***\n";
    printPersons(personWithAges);
}

void bitsetExamples()
{
    // It sets bit size by this value. For example;
    // It would be 00000 as default if the size would be 5. So in short, it adds a'0' byte as many as the size as default
    const size_t MAX_BITSET_SIZE = 16;
    std::bitset<MAX_BITSET_SIZE> bit;

    // It changes the related bit as "on"(1). It doesn't allow to set bit size more than the MAX_BITSET_SIZE
    std::vector<int> bitSetIndexes{1, 5, 8, 13};
    for (auto bitSetIndex = bitSetIndexes.cbegin(); bitSetIndex != bitSetIndexes.cend(); ++bitSetIndex)
        bit.set(*bitSetIndex);

    // Display bool values as string
    std::cout << std::boolalpha
              << "\nBits: " << bit
              // Returns the number of all bits.
              << "\nBits size (.size()): " << bit.size()
              // Returns the number of bits which are set.
              << "\nBits count which are set as true(1) (.count()): " << bit.count()
              // Tests whether any of the bits are on and returns true if at least one bit is set(1)
              << "\nCheck whether any bit has set as true(1) (.any()): " << bit.any()
              // Tests whether all the bits are on and returns true if all the bits are set(1)
              << "\nCheck whether all of the bits has set as true(1) (.all()): " << bit.all()
              // Tests whether any of the bits are on and returns true if none of the bits are set(1)
              << "\nCheck whether all of the bits has set as false(0) (.any()): " << bit.none()
              // Tests the value of a bit and returns 1 if the value is 1. If it is 0, then returns 0
              // If the value isn't available in the bit variable, returns out_of_range error
              << "\nCheck whether the first(far right) bit is true?: " << bit.test(0)
              << std::endl;

    std::bitset<MAX_BITSET_SIZE> bit2;
    std::vector<int> bit2SetIndexes{0, 1, 4, 9, 10, 11};

    for (auto bit2SetIndex = bit2SetIndexes.cbegin(); bit2SetIndex != bit2SetIndexes.cend(); ++bit2SetIndex)
        bit2.set(*bit2SetIndex);

    std::cout << "\nThe other bits: " << bit2
              // Returns the number of all bits.
              << "\nBits size (.size()): " << bit2.size()
              // Returns the number of bits which are set.
              << "\nBits count which are set as true(1) (.count()): " << bit2.count()
              // Tests whether any of the bits are on and returns true if at least one bit is set
              << "\nCheck whether any bit has set as true(1) (.any()): " << bit2.any()
              // Tests whether all the bits are on and returns true if all the bits are set
              << "\nCheck whether all of the bits has set as true(1) (.all()): " << bit2.all()
              // Tests whether any of the bits are on and returns true if none of the bits are set
              << "\nCheck whether all of the bits has set as false(0) (.any()): " << bit2.none()
              // Tests the value of a bit and returns 1 if the value is 1. If it is 0, then returns 0
              // If the value isn't available in the bit variable, returns out_of_range error
              << "\nCheck whether the first(far right) bit is true?: " << bit2.test(0)
              << std::endl;

    std::bitset<MAX_BITSET_SIZE> bitAfterANDOperator, bitAfterOROperator, bitAfterXOROperator;
    /**
     * & operator is used for logical AND operators. &= equals the result to the value automatically.
     * Logical &(AND) operator works like:
     *  - 1 & 1 ==> 1
     *  - 1 & 0 ==> 0
     *  - 0 & 1 ==> 0
     *  - 0 & 0 ==> 0
     * So, `bit &= bit2` would make the process and set the result to the bit variable
     */
    bitAfterANDOperator = bit & bit2;
    std::cout << "\nThe new bits after applying the logical AND operator: " << bitAfterANDOperator;

    /**
     * | operator is used for logical OR operators. |= equals the result to the value automatically.
     * Logical |(OR) operator works like:
     * - 1 | 1 ==> 1
     * - 1 | 0 ==> 1
     * - 0 | 1 ==> 1
     * - 0 | 0 ==> 0
     * So, `bit |= bit2` would make the process and set the result to the bit variable
     */
    bitAfterOROperator = bit | bit2;
    std::cout << "\nThe new bits after applying the logical OR operator: " << bitAfterOROperator;

    /**
     * ^ operator is used for logical XOR operators. ^= equals the result to the value automatically.
     * Logical ^(XOR) operator works like:
     * - 1 | 1 ==> 0
     * - 1 & 0 ==> 1
     * - 0 & 1 ==> 1
     * - 0 & 0 ==> 0
     * So, `bit ^= bit2` would make the process and set the result to the bit variable
     *
     */
    bitAfterXOROperator = bit ^ bit2;
    std::cout << "\nThe new bits after applying the logical XOR operator: " << bitAfterXOROperator;

    std::cout << "\nThe bits are like this currently: " << bit;

    // Logical ~(NOT) operator converts the bits to the opposite, like converting 1 to 0 and 0 to 1.
    std::cout << "\nThe bits after applying the logical NOT operator: " << ~bit;

    bit >>= 1;
    std::cout << "\nThe bits, after shifting 1 step right: " << bit;

    bit <<= 1;
    std::cout << "\nThe bits, after shifting 1 step left: " << bit;

    // Converts bits to a string
    std::string bitAsString = bit.to_string();
    std::cout << "\nThe bits after converting to a string: " << bitAsString;

    // Converts bits to a long(decimal) variable and returns a numerical interpretation of the %bitset.
    long bitAsLong = bit.to_ulong();
    std::cout << "\nThe bits after converting to a long(decimal): " << bitAsLong;

    // Toggles every bit to its opposite value(1 to 0, 0 to 1)
    bit.flip();
    std::cout << "\nThe bits, after flipping process: " << bit;

    // Sets every bit to false(0)
    bit.reset();
    std::cout << "\nThe bits, after reset: " << bit;
}

static int greaterThanInt = 6;
inline bool greaterThan(int number)
{
    return number > greaterThanInt;
}

static int lowerThanInt = 5;
inline bool lowerThan(int number)
{
    return number < lowerThanInt;
}

void algorithmExamples()
{
    const size_t ARRAY_LENGTH = 5;
    std::array<int, ARRAY_LENGTH> array1{2, 4, 6, 10, 10};
    std::array<int, ARRAY_LENGTH> array2(array1);
    std::array<int, ARRAY_LENGTH> array3{2, 10, 14, 16, 18};

    std::ostream_iterator<int> printArray(std::cout, ",");

    std::cout << "***Arrays***" << std::endl;
    std::cout << "\nFirst Array: ";
    std::copy(array1.cbegin(), array1.cend(), printArray);
    std::cout << "\nSecond Array: ";
    std::copy(array2.cbegin(), array2.cend(), printArray);
    std::cout << "\nThird Array: ";
    std::copy(array3.cbegin(), array3.cend(), printArray);

    // MATCH FUNCTIONS
    std::cout << "\nAre the first and second arrays equal? " << std::boolalpha << std::equal(array1.cbegin(), array1.cend(), array2.cbegin());
    std::cout << "\nAre the first and third arrays equal? " << std::boolalpha << std::equal(array1.cbegin(), array1.cend(), array3.cbegin());

    auto mismatched = std::mismatch(array1.cbegin(), array1.cend(), array3.cbegin());
    // mismatched.first gives the address of the value
    std::cout << "\nThe one of the unmatched first array's elements between array1 and array3: " << *mismatched.first
              << " (Index: " << mismatched.first - array1.begin() << ")"
              << "\nThe one of the unmatched second array's elements between array1 and array3: " << *mismatched.second
              << " (Index: " << mismatched.second - array3.begin() << ")";

    char text1[] = "Test3 Text";
    char text2[] = "Test2 Text";
    std::cout << "\nText comparision between " << text1 << " and " << text2 << "."
              << "Is " << text1 << " greater than the " << text2 << "?\t"
              // lexicographical_compare function compares the texts and returns boolean.
              // If the first sent text is greater, then returns true. Otherwise, returns false
              << std::boolalpha << std::lexicographical_compare(std::begin(text1), std::end(text1), std::begin(text2), std::end(text2))
              << std::endl;

    // REMOVE FUNCTIONS
    // Removes all 10 values from the array and returns the last element of the new array
    auto newLastElement = std::remove(array1.begin(), array1.end(), greaterThanInt);

    std::cout << "The first and second arrays after removing all " << greaterThanInt << "s from the first array";
    std::cout << "\nFirst Array:\n";
    std::copy(array1.begin(), newLastElement, printArray);
    std::cout << "\nSecond Array:\n";
    std::copy(array2.cbegin(), array2.cend(), printArray);

    // Removes the related value from the main array and then copies the sequence to the other array(3. parameter)
    std::remove_copy(array1.cbegin(), array1.cend(), array3.begin(), greaterThanInt);
    std::cout << "\n\nThe first and third arrays after removing all " << greaterThanInt << "s from the first array and copy to the third";
    std::cout << "\nFirst Array:\n";
    std::copy(array1.cbegin(), array1.cend(), printArray);
    std::cout << "\nThird Array:\n";
    std::copy(array3.cbegin(), array3.cend(), printArray);

    // Removes all values which are greater than 10 and returns the last element of the new array
    newLastElement = std::remove_if(array1.begin(), array1.end(), greaterThan);
    std::cout << "\n\nThe first and second arrays after removing all values which are greater than " << greaterThanInt << " from the first array";
    std::cout << "\nFirst Array:\n";
    std::copy(array1.begin(), newLastElement, printArray);
    std::cout << "\nSecond Array:\n";
    std::copy(array2.cbegin(), array2.cend(), printArray);

    // Removes the related value from the main array and then copies the sequence to the other array(3. parameter)
    std::remove_copy_if(array1.cbegin(), array1.cend(), array3.begin(), greaterThan);
    std::cout << "\n\nThe first and third arrays after removing all values which are greater than " << greaterThanInt << " from the first array and copy to the third";
    std::cout << "\nFirst Array:\n";
    std::copy(array1.cbegin(), array1.cend(), printArray);
    std::cout << "\nThird Array:\n";
    std::copy(array3.cbegin(), array3.cend(), printArray);

    // REPLACE FUNCTIONS
    std::cout << "\n\nThe Array: " << std::endl;
    std::copy(array1.cbegin(), array1.cend(), printArray);

    // replace function replaces the related values with the new value(4. parameter)
    int firstElement = array1[0], newValue = 200;
    std::replace(array1.begin(), array1.end(), firstElement, newValue);

    std::cout << "\nThe array after replacing " << firstElement << " with the " << newValue << ": ";
    std::copy(array1.cbegin(), array1.cend(), printArray);

    std::cout << "\n\nThe third array: " << std::endl;
    std::copy(array3.cbegin(), array3.cend(), printArray);

    // replace_copy replaces the related values with the new value(4. parameter) and copies this replaced array with the other one(3. parameter)
    firstElement = array1[0], newValue = 500;
    std::replace_copy(array1.begin(), array1.end(), array3.begin(), firstElement, newValue);

    std::cout << "\nThe array after replaced " << firstElement << " with the " << newValue << " and then copied to the other array.";
    std::cout << "\nThe other array after copying: ";
    std::copy(array3.cbegin(), array3.cend(), printArray);

    std::cout << "\n\nThe array: " << std::endl;
    std::copy(array3.cbegin(), array3.cend(), printArray);

    // replace_if replaces the values if the predicate function returns true for it
    newValue = 350;
    std::replace_if(array1.begin(), array1.end(), lowerThan, newValue);

    std::cout << "\nThe array after replacing the values which are lower than " << lowerThanInt << " with the " << newValue << ":\n";
    std::copy(array1.cbegin(), array1.cend(), printArray);

    // replace_copy_if copies a sequence, replacing each value for which a predicate returns true with another value.
    newValue = 7;
    std::replace_copy_if(array1.cbegin(), array1.cend(), array3.begin(), greaterThan, newValue);
    std::cout << "\n\nThe first and third arrays after replacing all values which are greaterThan than " << greaterThanInt << " from the first array and copy to the third";
    std::cout << "\nFirst Array:\n";
    std::copy(array1.cbegin(), array1.cend(), printArray);
    std::cout << "\nThird Array:\n";
    std::copy(array3.cbegin(), array3.cend(), printArray);
}

void mathematicalAlgorithmExamples()
{
    const size_t ARRAY_SIZE = 10, DEFAULT_ARRAY_SIZE = 3, CONSTANT_VALUE = 10;
    std::array<int, ARRAY_SIZE> numbers{5, 6, 3};
    std::fill_n(numbers.begin() + DEFAULT_ARRAY_SIZE, numbers.size() - DEFAULT_ARRAY_SIZE, CONSTANT_VALUE);

    printElements("The array elements", numbers);

    // Randomly shuffle the elements of a sequence
    std::random_shuffle(numbers.begin(), numbers.end());
    printElements("The array elements", numbers);

    // Count function returns the count of a value in the array
    int constantValueCount = std::count(numbers.cbegin(), numbers.cend(), CONSTANT_VALUE);
    std::cout << "\nThe count of " << CONSTANT_VALUE << "s in the array: " << constantValueCount;

    int valuesCountByCondition = std::count_if(numbers.cbegin(), numbers.cend(), greaterThan);
    std::cout << "\nThe count of the values which are greater than " << greaterThanInt << " in the array: " << valuesCountByCondition;

    // Return a pair of iterators pointing to the minimum and maximum elements in a range. First ==> min value, Second ==> max value
    auto minMaxNumbers = std::minmax_element(numbers.cbegin(), numbers.cend());
    // Singly, `std::min_element(numbers.cbegin(), numbers.cend());` returns the min element. If only min value is needed, use this
    std::cout << "\nThe minimum value in the array: " << *minMaxNumbers.first;

    // Singly, `std::max_element(numbers.cbegin(), numbers.cend());` returns the max element. If only max value is needed, use this
    std::cout << "\nThe maximum value in the array: " << *minMaxNumbers.second;

    // Accumulate values in a range.
    std::cout << "\nThe total of the elements: " << std::accumulate(numbers.cbegin(), numbers.cend(), 0);

    std::cout << "\nThe square of the each element: ";
    std::for_each(
        numbers.begin(),
        numbers.end(),
        // Lambda function declared to make a basic process quickly
        [](int number)
        { std::cout << squareByValue(number) << "\t"; });

    std::array<int, ARRAY_SIZE> transformedNumbers;
    // Transform function performs an operation according to the function(4. parameter) to all elements in the array
    // Then, sets this new array to the other array(3. parameter)
    std::transform(numbers.cbegin(), numbers.cend(), transformedNumbers.begin(), [](int number)
                   { return std::sqrt(number); });

    printElements("\nThe main array", numbers);
    printElements("\nThe transformed array includes the root values of each element", transformedNumbers);

    // Find_if function finds the first element in a sequence for which a predicate(3. parameter) is true
    auto foundElement = std::find_if(numbers.cbegin(), numbers.cend(), greaterThan);
    std::cout << "\nThe first found element which is greater than " << greaterThanInt;
    if (foundElement != numbers.cend())
        std::cout << " is: " << *foundElement << " (Index: " << (foundElement - numbers.cbegin()) << ")";
    else
        std::cout << " is not available";

    foundElement = std::find_if_not(numbers.cbegin(), numbers.cend(), greaterThan);
    std::cout << "\nThe first found element which is not greater than " << greaterThanInt;
    if (foundElement != numbers.cend())
        std::cout << " is: " << *foundElement << " (Index: " << (foundElement - numbers.cbegin()) << ")";
    else
        std::cout << " is not available";

    int searchInt;
    std::cout << "\nEnter a number to search it in the array by using binary_search: ";
    std::cin >> searchInt;
    // binary_search function searches the value in the array and returns bool whether the value is in the array
    std::cout << "Is " << searchInt << " in the array? " << std::boolalpha << std::binary_search(numbers.cbegin(), numbers.cend(), searchInt) << std::endl;

    std::cout << "\nAre all the values higher than << " << greaterThanInt << "? " << std::all_of(numbers.cbegin(), numbers.cend(), greaterThan);
    std::cout << "\nIs any value higher than << " << greaterThanInt << "? " << std::any_of(numbers.cbegin(), numbers.cend(), greaterThan);
    std::cout << "\nIs none of the values higher than << " << greaterThanInt << "? " << std::none_of(numbers.cbegin(), numbers.cend(), greaterThan);

    // Swaps the elements with the each other
    std::swap(numbers[1], numbers[4]);
    printElements("\nAfter swapping the 2. element with the 5. element, the array looks like", numbers);

    // Uses iterator to swap the elements with the each other by the indexes
    std::iter_swap(numbers.begin() + 2, numbers.end() - 3);
    printElements("\nAfter swapping the 3. element with the 8. element, the array looks like", numbers);

    // Swaps each element in the range with the corresponding element in the range. The ranges must not overlap
    std::swap_ranges(numbers.begin(), numbers.begin() + 3, numbers.end() - 3);
    printElements("\nAfter swapping the first 3 elements with the last 3 elements", numbers);

    // unique_copy function removes the **consecutive** duplicate values and copies result to a sequence
    std::vector<int> uniqueNumbers;
    std::unique_copy(numbers.cbegin(), numbers.cend(), std::back_inserter(uniqueNumbers));
    printElements("The new unique array", uniqueNumbers);

    /**
     * `unique` function removes the **consecutive** duplicate values. For example;
     * If the array is like 10, 10, 20, 20, 10, 10, 5, the result of the unique function would be 10, 20, 10, 5
     * It removes the duplicates but only the consecutive ones
     */
    auto endLocation = std::unique(numbers.begin(), numbers.end());
    std::cout << "\nAfter removing the consecutive duplicate values, the array looks like:\n";
    std::ostream_iterator<int> numberPrinter(std::cout, "\t");
    std::copy(numbers.begin(), endLocation, numberPrinter);

    // Copies the elements to the the back of the other array
    // It has the same effect as copy, but starts at the end of the range and works its way to the start, returning the start of the result
    printElements("\nThe other array looks like", transformedNumbers);
    std::copy_backward(numbers.cbegin() + 5, numbers.cend(), transformedNumbers.end());
    printElements("After copying the unique array's first 5 elements to the end of the other array, the other array looks like", transformedNumbers);

    // Merges two sorted ranges in one
    std::array<int, ARRAY_SIZE * 2> mergedNumbers;
    std::merge(numbers.cbegin(), numbers.cend(), transformedNumbers.cbegin(), transformedNumbers.cend(), mergedNumbers.begin());
    printElements("The main array", numbers);
    printElements("The other array", transformedNumbers);
    printElements("These arrays are merged in one array. The merged array", mergedNumbers);

    // Reverses the array
    std::reverse(mergedNumbers.begin(), mergedNumbers.end());
    printElements("These array is reversed. The reversed array", mergedNumbers);

    std::sort(numbers.begin(), numbers.end());
    std::sort(mergedNumbers.begin(), mergedNumbers.end());
    printElements("\nThe main array(sorted)", numbers);
    printElements("The merged array(sorted)", mergedNumbers);
    std::cout << "\nIs the merged array includes the main array? "
              << std::boolalpha << std::includes(mergedNumbers.cbegin(), mergedNumbers.cend(), numbers.cbegin(), numbers.cend());

    // Return the difference of two sorted ranges.
    std::array<int, ARRAY_SIZE> differentNumbers, intersectedNumbers, symmetricDifferentNumbers;
    auto differenceResultEnd = std::set_difference(mergedNumbers.cbegin(), mergedNumbers.cend(), numbers.cbegin(), numbers.cend(), differentNumbers.begin());
    std::cout << "\nThe different values of the main array with the merged array: \n";
    std::copy(differentNumbers.begin(), differenceResultEnd, numberPrinter);

    auto intersectionReqsultEnd = std::set_intersection(numbers.cbegin(), numbers.cend(), mergedNumbers.cbegin(), mergedNumbers.cend(), intersectedNumbers.begin());
    std::cout << "\nThe intersected values between the main array and the merged array: \n";
    std::copy(intersectedNumbers.begin(), intersectionReqsultEnd, numberPrinter);

    auto diffResultEnd = std::set_symmetric_difference(numbers.cbegin(), numbers.cend(), mergedNumbers.cbegin(), mergedNumbers.cend(), symmetricDifferentNumbers.begin());
    std::cout << "\nThe values which exist in main array and not in merged array and exists in merged array and not in main array: \n";
    std::copy(symmetricDifferentNumbers.begin(), diffResultEnd, numberPrinter);

    std::array<int, ARRAY_SIZE * 2> unionNumbers;
    auto unionResultEnd = std::set_union(numbers.cbegin(), numbers.cend(), mergedNumbers.cbegin(), mergedNumbers.cend(), unionNumbers.begin());
    std::cout << "\nThe values which exist in one or both of the main array and merged array: \n";
    std::copy(unionNumbers.begin(), unionResultEnd, numberPrinter);

    const size_t BOUND_LIMIT = 5;
    auto numberBounds = std::equal_range(numbers.cbegin(), numbers.cend(), BOUND_LIMIT);
    std::cout
        // It finds the lower bound in the array by the given value. If need to get only lower bound, use the below function
        // auto lower = std::lower_bound(numbers.cbegin(), numbers.cend(), BOUND_LIMIT);
        << "\nLower bound of " << BOUND_LIMIT << " in main array is " << *numberBounds.first
        << " (Index: " << numberBounds.first - numbers.cbegin() << ")"
        // It finds the upper bound in the array by the given value. If need to get only upper bound, use the below function
        // auto upper = std::upper_bound(numbers.cbegin(), numbers.cend(), BOUND_LIMIT);
        << "\nUpper bound of " << BOUND_LIMIT << " in main array is " << *numberBounds.second
        << " (Index: " << numberBounds.second - numbers.cbegin() << ")";

    // Heap functions
    printElements("The main array looks like", numbers);

    // is_heap function checks whether the any elements in the range is a heap
    std::cout << "\n\nDoes the main array include heap elements: " << std::boolalpha << std::is_heap(numbers.cbegin(), numbers.cend());
    // Constructs a heap in the range of the array
    std::make_heap(numbers.begin(), numbers.end());
    printElements("The array after running make_heap function", numbers);
    std::cout << "\nDoes the main array includes heap elements: " << std::boolalpha << std::is_heap(numbers.cbegin(), numbers.cend());
    // Search the end of a heap
    std::cout << "\nThe end of the heap: " << *std::is_heap_until(numbers.cbegin(), numbers.cend());

    // Sort the elements in the heap
    std::sort_heap(numbers.begin(), numbers.end());
    printElements("The arrat after running sort_heap function", numbers);
}

auto sumLambda = [](int &total, int number)
{ total += number; };

void lambdaFunctions()
{
    const size_t ARRAY_SIZE = 5;
    std::array<int, ARRAY_SIZE> numbers{7, 12, 15, 20, 30};
    int total = 0;

    std::ostream_iterator<int> printer(std::cout, "\t");
    std::cout << "***Numbers***\n";
    copy(numbers.cbegin(), numbers.cend(), printer);

    for (unsigned int counter = 1; counter <= 5; ++counter)
    {
        std::cout << "\nResults of the " << counter << ". power of the numbers:\n";
        std::for_each(
            numbers.begin(),
            numbers.end(),
            [&counter, &total](int num)
            {
                int result = std::pow(num, counter);
                std::cout << result << ", ";

                sumLambda(total, result);
            });
    }

    std::cout << "\nTotal of the all values that are calculated: " << total << std::endl;
}

/**
 * Custom error handler function which is used instead instead of a try-catch block in the below function
 */
void customErrorHandler()
{
    std::cerr << "Memory allocation issue is occurred";
    abort();
}

void memoryAllocationExample()
{
    const size_t PTR_SIZE = 50000;
    double *ptr[PTR_SIZE];

    // Set a new handler to catch the memory allocation errors for the following loop
    std::set_new_handler(customErrorHandler);

    const size_t ARR_SIZE = pow(PTR_SIZE, 2);
    for (size_t i = 0; i < PTR_SIZE; i++)
    {
        std::cout << "ptr[" << i << "] points to " << ARR_SIZE << " new doubles\n";
        ptr[i] = new double[ARR_SIZE];
    }
}
