/**
 * This file includes the examples of sorting, searching algorithm methods in the lists
 */

#include <iostream>
#include <array>
#include <algorithm>
#include <ctime>
#include <random>

// Definitions
// Search functions
void searchingMethods();
void printSearchingResult(size_t &);
template <typename ARRAYTYPE, size_t arraySize>
void displayElements(std::array<ARRAYTYPE, arraySize> &, size_t, size_t, size_t);

// Searching methods
// Linear Search
template <typename ARRAYTYPE, size_t arraySize>
void linearSearch(std::array<ARRAYTYPE, arraySize> &, const ARRAYTYPE &);

// Binary Search
int calculateMiddlePoint(size_t, size_t);
template <typename ARRAYTYPE, size_t arraySize>
void binarySearch(std::array<ARRAYTYPE, arraySize> &, const ARRAYTYPE &);

// Sort functions
void sortingMethods();
template <typename ARRAYTYPE, size_t arraySize>
void printArrayElements(std::array<ARRAYTYPE, arraySize> &);

// Sorting methods
// Insertion sort
template <typename ARRAYTYPE, size_t arraySize>
void insertionSort(std::array<ARRAYTYPE, arraySize> &);

// Selection sort
template <typename ARRAYTYPE, size_t arraySize>
void selectionSort(std::array<ARRAYTYPE, arraySize> &);

template <typename ARRAYTYPE, size_t arraySize>
void mergeSort(std::array<ARRAYTYPE, arraySize> &, size_t, size_t);
template <typename ARRAYTYPE, size_t arraySize>
void merge(std::array<ARRAYTYPE, arraySize> &, size_t, size_t, size_t, size_t);

int main(int argc, char *argv[])
{
    // searchingMethods();

    sortingMethods();
}

void searchingMethods()
{
    std::default_random_engine randomNumberEngine(static_cast<unsigned int>(time(nullptr)));
    std::uniform_int_distribution<unsigned int> randomNumberGenerator(1, 10000);

    const size_t ARRAY_SIZE = 500;
    std::array<int, ARRAY_SIZE> intArray;

    for (int &element : intArray)
        element = randomNumberGenerator(randomNumberEngine);

    int searchKey;
    while (searchKey != -1)
    {
        std::cout << "\nEnter an integer number to search in the array(Type -1 to end the process): ";
        std::cin >> searchKey;

        // linearSearch(intArray, searchKey);
        binarySearch(intArray, searchKey);
    }
}

void printSearchingResult(size_t foundIndex)
{
    foundIndex >= 0 ? std::cout << "The value is found! It is in " << foundIndex << ". index.\n" : std::cout << "The value not found!\n";
}

template <typename ARRAYTYPE, size_t arraySize>
void linearSearch(std::array<ARRAYTYPE, arraySize> &array, const ARRAYTYPE &searchKey)
{
    int foundIndex = -1;
    for (size_t index = 0; index < array.size(); index++)
    {
        if (array[index] == searchKey)
        {
            std::cout << array[index];
            foundIndex = index;
            break;
        }
    }

    printSearchingResult(foundIndex);
}

template <typename ARRAYTYPE, size_t arraySize>
void displayElements(std::array<ARRAYTYPE, arraySize> &array, size_t lowIndex, size_t highIndex, size_t middleIndex)
{
    for (size_t i = lowIndex; i < array.size() && i <= highIndex; i++)
        // Show the middle element with an asterisk
        middleIndex == i ? std::cout << "**" << array[i] << "** " : std::cout << array[i] << " ";

    std::cout << std::endl;
}

inline int calculateMiddlePoint(size_t lowestIndex, size_t highestIndex)
{
    return (lowestIndex + highestIndex + 1) / 2;
}

template <typename ARRAYTYPE, size_t arraySize>
void binarySearch(std::array<ARRAYTYPE, arraySize> &array, const ARRAYTYPE &searchKey)
{
    int low = 0,
        high = array.size() - 1,
        middle = calculateMiddlePoint(low, high),
        foundIndex = -1,
        attemptCounter = 0;

    std::sort(array.begin(), array.end());
    std::cout << "** Elements as sorted for binary searching (The middle element indicates with asterisks(** **)) **\n";
    // Display elements at the beginning
    displayElements(array, 0, array.size() - 1, middle);

    do
    {
        std::cout << "\n***" << attemptCounter << ". Attempt***\n";
        displayElements(array, low, high, middle);

        // After setting the middle point in each check, the result will be the middle element in final.
        if (searchKey == array[middle])
        {
            foundIndex = middle;
            break;
        }

        // The array is sorted so if the searched numbers lower than the middle element, then it must be in the **low** side of the array
        // So, no need to check the high side. For this, the high side elements will be ignored
        // and new high value will be the element **behind** the middle one since the key isn't same with the middle value as checked above
        // Then, continue checking with the same flow
        if (searchKey < array[middle])
            high = middle - 1;
        // The array is sorted so if the searched numbers higher than the middle element, then it must be in the **high** side of the array
        // So, no need to check the low side. For this, the **low** side elements will be ignored
        // and new low value will be the element **in front of** the middle one since the key isn't same with the middle value as checked above
        // Then, continue checking with the same flow
        else
            low = middle + 1;

        // After setting the new low or high point, calculate the middle point
        middle = calculateMiddlePoint(low, high);
        attemptCounter++;
    } while (low <= high && foundIndex == -1);

    printSearchingResult(foundIndex);
}

template <typename ARRAYTYPE, size_t arraySize>
inline void printArrayElements(std::array<ARRAYTYPE, arraySize> &array)
{
    for (const int &element : array)
        std::cout << element << " ";
}

void sortingMethods()
{
    std::default_random_engine randomNumberEngine(static_cast<unsigned int>(time(nullptr)));
    std::uniform_int_distribution<unsigned int> randomNumberGenerator(1, 1000);

    const size_t ARRAY_SIZE = 20;
    std::array<int, ARRAY_SIZE> intArray;

    std::for_each(
        intArray.begin(),
        intArray.end(),
        [&randomNumberGenerator, &randomNumberEngine](int &value)
        { value = randomNumberGenerator(randomNumberEngine); });

    std::cout << "**The random elements of the **unsorted** array**\n";
    printArrayElements(intArray);

    insertionSort(intArray);
    std::cout << "\n\n**The elements of the array after insertion sorting process**\n";
    printArrayElements(intArray);

    // Shuffle array again to make sure the next function works properly
    std::random_shuffle(intArray.begin(), intArray.end());

    selectionSort(intArray);
    std::cout << "\n\n**The elements of the array after selection sorting process**\n";
    printArrayElements(intArray);

    // Shuffle array again to make sure the next function works properly
    std::random_shuffle(intArray.begin(), intArray.end());

    std::cout << "\n\nMerge sort process is started...\n";
    printArrayElements(intArray);
    mergeSort(intArray, 0, intArray.size() - 1);
    std::cout << "\n\n**The elements of the array after merging sorting process**\n";
    printArrayElements(intArray);
}

/**
 * Insertion sort is a simple and **inefficient** sorting algorithm.
 * It works by iteratively inserting each element of an unsorted list into its correct position in a sorted portion of the list
 */
template <typename ARRAYTYPE, size_t arraySize>
void insertionSort(std::array<ARRAYTYPE, arraySize> &array)
{
    // Sorts the array ascending(from smallest number to largest one)
    for (size_t nextIndex = 1; nextIndex < array.size(); nextIndex++)
    {
        ARRAYTYPE insertElement = array[nextIndex];
        size_t moveIndex = nextIndex;

        // Search the correct location where the insertion element will be placed
        while ((moveIndex > 0) && array[moveIndex - 1] > insertElement)
        {
            // Because of the array will be sorted ascending, the smalles value should be at first place
            // So, loop the numbers and if the previous value is higher than the current insert value,
            // then they should be displaced with the each other. For that, move the bigger element 1 row to the right
            array[moveIndex] = array[moveIndex - 1];
            --moveIndex;
        }

        array[moveIndex] = insertElement;
    }
}

/**
 * Selection sort is another a simple and **inefficient** sorting algorithm.
 * It finds the smallest/largest value for each position of the unsorted array and swaps them with each other to sort the array.
 */
template <typename ARRAYTYPE, size_t arraySize>
void selectionSort(std::array<ARRAYTYPE, arraySize> &array)
{
    // Sorts the array ascending(from smallest number to largest one)
    for (size_t i = 0; i < array.size(); i++)
    {
        // Set the smallest value as default
        size_t indexOfSmallestValue = i;

        // Check all other values in the array to check and find the smallest value
        for (size_t j = i + 1; j < array.size(); j++)
            if (array[j] < array[indexOfSmallestValue])
                indexOfSmallestValue = j;

        // If the smallest value is in the correct location, then no need to anything
        if (indexOfSmallestValue == i)
            continue;

        // If there is another value which is smaller than the current value, swap indexes with each other
        ARRAYTYPE tempCurrentValue = array[i];
        // Set the smallest value to the current index since the smallest number should be at first
        array[i] = array[indexOfSmallestValue];
        // Set the number in the current index to the index of the new smallest number
        array[indexOfSmallestValue] = tempCurrentValue;
    }
}

/**
 * Merge sort is efficient, general-purpose, and comparison-based sorting algorithm. It is also conceptually more complex.
 * It divides the array elements into smaller subarrays to sort them recursively.
 * After sorting the sub arrays, merges them into one combined array
 */
template <typename ARRAYTYPE, size_t arraySize>
void mergeSort(std::array<ARRAYTYPE, arraySize> &array, size_t low, size_t high)
{
    // If the array has 1 element
    if ((high - low) < 1)
        return;

    size_t middle1 = (low + high) / 2, middle2 = middle1 + 1;
    // More detailed logs ==>
    // std::cout << "***The elements are splitting***\n"
    //           << "The elements of the array: ";
    // displayElements(array, low, high, -1);

    // std::cout << "\nThe first part of the splitted array: ";
    // displayElements(array, low, middle1, -1);

    // std::cout << "\nThe second part of the splitted array: ";
    // displayElements(array, middle2, high, -1);

    // It sends first half of the array into this function to sort them recursively
    mergeSort(array, low, middle1);
    // It sends second half of the array into this function to sort them recursively
    mergeSort(array, middle2, high);

    // After split processes are done, merge the splitted arrays
    merge(array, low, middle1, middle2, high);
}

template <typename ARRAYTYPE, size_t arraySize>
void merge(std::array<ARRAYTYPE, arraySize> &array, size_t left, size_t leftLastIndex, size_t right, size_t rightLastIndex)
{
    size_t leftFirstIndex = left,
           rightFirstIndex = right,
           combinedIndex = leftFirstIndex;
    std::array<ARRAYTYPE, arraySize> combinedArray;

    // This loop should be run until one of the left or the right side elements are fully processed.
    // It locates the smallest value for each index and then gets the next value by incrementing the index and checking it as well.
    // In the end, this loop will configure the combined array in ascending format
    while (leftFirstIndex <= leftLastIndex && rightFirstIndex <= rightLastIndex)
        combinedArray[combinedIndex++] = array[array[leftFirstIndex] <= array[rightFirstIndex] ? leftFirstIndex++ : rightFirstIndex++];

    // After the above loop is done, the right first index and left first index will be increased.
    // Check whether the remaining elements are on the left or right side.
    // If all of the left side elements are copied to the combined array, then only the right side elements exist now.
    // Therefore, the only choice is to copying them into the combined array
    if (leftFirstIndex == right)
        while (rightFirstIndex <= rightLastIndex)
            combinedArray[combinedIndex++] = array[rightFirstIndex++];
    // If there are values that are stayed on the left side, then the right side elements must be fully copied
    // Therefore, no need to check anything more. Just copy them after the values since they must be the biggest values
    else
        while (leftFirstIndex <= leftLastIndex)
            combinedArray[combinedIndex++] = array[leftFirstIndex++];

    for (size_t i = left; i <= rightLastIndex; ++i)
        array[i] = combinedArray[i];
}