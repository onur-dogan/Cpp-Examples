/**
 * This file includes the examples of sorting, searching algorithm methods in the lists
 */

#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#include <ctime>
#include <random>
/**
 * See: https://www.boost.org/doc/libs/1_72_0/libs/range/doc/html/range/reference/adaptors/reference/indexed.html
 * Used {
 *  boost::adaptors::indexed
 * }
 */
#include <boost/range/adaptor/indexed.hpp>

// Definitions
template <typename ARRAYTYPE, size_t arraySize>
inline void shuffleElements(std::array<ARRAYTYPE, arraySize> &);

// Search functions
void searchingMethods();
void printSearchingResult(int);
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

// Merge sort
template <typename ARRAYTYPE, size_t arraySize>
void mergeSort(std::array<ARRAYTYPE, arraySize> &, size_t, size_t);
template <typename ARRAYTYPE, size_t arraySize>
void merge(std::array<ARRAYTYPE, arraySize> &, size_t, size_t, size_t, size_t);

// Block sort
template <typename ARRAYTYPE, size_t arraySize>
void blockSort(std::array<ARRAYTYPE, arraySize> &);

// Quick sort
template <typename ARRAYTYPE, size_t arraySize>
void quickSort(std::array<ARRAYTYPE, arraySize> &, size_t, size_t);
template <typename ARRAYTYPE, size_t arraySize>
size_t partition(std::array<ARRAYTYPE, arraySize> &, size_t, size_t);

// Heap sort
template <typename ARRAYTYPE, size_t arraySize>
void heapSort(std::array<ARRAYTYPE, arraySize> &);
template <typename ARRAYTYPE, size_t arraySize>
void heapify(std::array<ARRAYTYPE, arraySize> &, size_t, size_t);

typedef void (*MethodFunction)();
struct methodFunctionStr
{
    MethodFunction f;
    std::string desc;
};

int main(int argc, char *argv[])
{
    std::vector<methodFunctionStr> definitions{
        // Examples and explanations of some searching algorithm methods
        {f : searchingMethods, desc : "Searching Algorithm Examples"},
        // Examples and explanations of some sorting algorithm methods
        {f : sortingMethods, desc : "Sorting Algorithm Examples"}};

    std::cout << "**Welcome to the 4th General Algorithm Examples**";
    std::cout << "**\nType number to see the example outputs.. (Type -1 to end the process!)**";

    int selection;
    while (selection != -1)
    {
        for (const auto definition : definitions | boost::adaptors::indexed(1))
            std::cout << "\n"
                      << definition.index() << ". Run the "
                      << definition.value().desc << " function";

        std::cout << std::endl;
        std::cin >> selection;
        try
        {
            std::cout << definitions.at(selection - 1).desc << " running...";
            definitions.at(selection - 1).f();
        }
        catch (std::out_of_range err)
        {
            std::cout << "\nThe related function couldn't run since you typed a number that isn't available in the list..."
                      << "\nPlease make sure typed an available number!";
        }
    }
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
    while (true)
    {
        std::cout << "\nEnter an integer number to search in the array(Type -1 to end the process): ";
        std::cin >> searchKey;
        if (searchKey == -1)
            break;

        std::cout << "\n**The related element is searched by using **linear search** algorithm. The results:**\n";
        linearSearch(intArray, searchKey);

        std::cout << "\n\n**The related element is searched by using **binary search** algorithm. The results:**\n";
        binarySearch(intArray, searchKey);
    }
}

void printSearchingResult(int foundIndex)
{
    foundIndex >= 0 ? (std::cout << "The value is found! It is in " << foundIndex << ". index.\n") : (std::cout << "The value not found!\n");
}

/**
 * Time Complexity: O(n)
 *
 * Linear search is a simple searching algorithm.
 * It traverses the list to find the search element.
 */
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

/**
 * Time Complexity: O(logn)
 *
 * Binary search is an efficient searching algorithm.
 * In a **sorted** array, it finds the search value by repeatedly comparing the search element with the middle element
 * It divides the array and determines a new middle element until the search element is found or all elements are compared.
 */
template <typename ARRAYTYPE, size_t arraySize>
void binarySearch(std::array<ARRAYTYPE, arraySize> &array, const ARRAYTYPE &searchKey)
{
    int low = 0,
        high = array.size() - 1,
        middle = calculateMiddlePoint(low, high),
        foundIndex = -1,
        attemptCounter = 1;

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

    std::cout << "\n**The random elements of the **unsorted** array**\n";
    printArrayElements(intArray);

    insertionSort(intArray);
    std::cout << "\n\n**The elements of the array after **insertion** sorting process**\n";
    printArrayElements(intArray);

    // Shuffle array again to make sure the next function works properly
    shuffleElements(intArray);

    selectionSort(intArray);
    std::cout << "\n\n**The elements of the array after **selection** sorting process**\n";
    printArrayElements(intArray);

    // Shuffle array again to make sure the next function works properly
    shuffleElements(intArray);

    std::cout << "\n\nMerge sort process is started...\n";
    printArrayElements(intArray);

    mergeSort(intArray, 0, intArray.size() - 1);
    std::cout << "\n\n**The elements of the array after **merge** sorting process**\n";
    printArrayElements(intArray);

    // Shuffle array again to make sure the next function works properly
    shuffleElements(intArray);

    blockSort(intArray);

    // Shuffle array again to make sure the next function works properly
    shuffleElements(intArray);

    quickSort(intArray, 0, intArray.size() - 1);
    std::cout << "\n\n**The elements of the array after **quick** sorting process**\n";
    printArrayElements(intArray);

    // Shuffle array again to make sure the next function works properly
    shuffleElements(intArray);
    heapSort(intArray);
    std::cout << "\n\n**The elements of the array after **heap** sorting process**\n";
    printArrayElements(intArray);
}

/**
 * Time Complexity: O(n²), Best Case: O(n)
 *
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
 * Time Complexity: O(n²)
 *
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

/**
 * Time Complexity: O(n*logn) in both the average and worst cases.
 *
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

/**
 * Time Complexity: O(n*logn)
 *
 * Block sort is a sorting algorithm that sorts an array by dividing it into blocks of fixed size, and sorting each block individually
 * After the elements in each block are sorted individually, merge the sorted blocks back into a single sorted array
 */
template <typename ARRAYTYPE, size_t arraySize>
void blockSort(std::array<ARRAYTYPE, arraySize> &array)
{
    size_t blockSize = 3;
    std::vector<std::vector<ARRAYTYPE>> blocks;

    // Divide the array elements into blocks of fixed size(blockSize)
    for (size_t i = 0; i < array.size(); i += blockSize)
    {
        std::vector<ARRAYTYPE> block;

        for (size_t blockIndex = i; blockIndex < i + blockSize && blockIndex < array.size(); blockIndex++)
            block.push_back(array[blockIndex]);

        // Sort each block individually and then append it to the blocks list
        std::sort(block.begin(), block.end());
        blocks.push_back(block);
    }

    // Merge the sorted blocks into a single sorted list
    std::vector<ARRAYTYPE> result;
    while (!blocks.empty())
    {
        // Find the block which has the smallest element
        size_t blockIndexWithSmallestValue = 0;
        for (size_t i = 1; i < blocks.size(); i++)
        {
            if (blocks[i][0] < blocks[blockIndexWithSmallestValue][0])
                blockIndexWithSmallestValue = i;
        }

        // Remove the smallest element from the related block and append it to the result list
        result.push_back(blocks[blockIndexWithSmallestValue][0]);
        blocks[blockIndexWithSmallestValue].erase(blocks[blockIndexWithSmallestValue].begin());

        // If the block is empty, after removing the smallest element from it, then no need to check it more.
        // Just remove it from the blocks list
        if (blocks[blockIndexWithSmallestValue].empty())
        {
            blocks.erase(blocks.begin() + blockIndexWithSmallestValue);
        }
    }

    std::cout << "\n\n**The elements of the array after block sorting process**\n";
    for (const int &element : result)
        std::cout << element << " ";
}

template <typename ARRAYTYPE, size_t arraySize>
size_t partition(std::array<ARRAYTYPE, arraySize> &array, size_t low, size_t high)
{
    // The default pivot is the last element
    ARRAYTYPE pivot = array[high];

    // Index of smaller element and indicates the right position of pivot found so far
    size_t index = low - 1;

    // Loop each element and sort the values by comparing them with the pivot value
    // At the end, the index value will have the count (-1) of the values which are lower than the pivot value
    // Therefore, the pivot value's correct index will be (index + 1) as a result
    // and all of the smaller values will be placed at the left side of the pivot in list
    for (size_t j = low; j <= high - 1; j++)
    {
        if (array[j] < pivot)
        {
            index++;

            ARRAYTYPE tempVal = array[index];
            array[index] = array[j];
            array[j] = tempVal;
        }
    }

    // The pivot(last) element's correct location is calculated in the above loop
    // So, swap it with the value which is in its correct position. Then, the last element will be another value
    // and the function will sort the elements by the new pivot value recursively. At the end, all of the elements will be sorted
    ARRAYTYPE tempVal = array[index + 1];
    array[index + 1] = array[high];
    array[high] = tempVal;

    return index + 1;
}

/**
 * Time Complexity: O(n*logn)
 *
 * Heap sort is an efficient general-purpose sorting algorithm.
 * It chooses one of the elements as a pivot element.
 * Then, it sorts the other elements around the pivot element by placing the pivot in its correct position.
 * At the end, the smaller values will be located on the left of the pivot, and the greater values will be on its right.
 */
template <typename ARRAYTYPE, size_t arraySize>
void quickSort(std::array<ARRAYTYPE, arraySize> &array, size_t low, size_t high)
{
    // If there's only one value in the list
    if (low >= high)
        return;

    size_t pivotIndex = partition(array, low, high);

    // Recursion calls for smaller elements and greater or equals elements
    quickSort(array, low, pivotIndex - 1);
    quickSort(array, pivotIndex + 1, high);
}

template <typename ARRAYTYPE, size_t arraySize>
void heapify(std::array<ARRAYTYPE, arraySize> &array, size_t arrayLength, size_t index)
{
    // Initialize largest value as root
    int largest = index,
        // The value at the left node is placed after the root node 2n+1
        leftIndex = 2 * index + 1,
        // the value at the right node is placed after the root's left node 2n+2
        rightIndex = 2 * index + 2;

    // If left child is larger than the largest value, then it should be largest
    if (leftIndex < arrayLength && array[leftIndex] > array[largest])
        largest = leftIndex;

    // If right child is larger than largest value, then it should be the largest
    if (rightIndex < arrayLength && array[rightIndex] > array[largest])
        largest = rightIndex;

    // If the largest value is not root, then swap them with each other since the largest value should be the root
    if (largest != index)
    {
        ARRAYTYPE tempVal = array[index];
        array[index] = array[largest];
        array[largest] = tempVal;

        // Recursively heapify the affected sub-tree
        heapify(array, arrayLength, largest);
    }
}

/**
 * Time Complexity: O(n*logn)
 *
 * Heap sort is an efficient comparison-based sorting algorithm.
 * It works by visualizing the elements of the array as a special kind of complete **binary tree** called a **heap**
 * The algorithm finds the max/min element and swap it with the last/first element.
 * Then, it repeats the same process for the remaining elements
 */
template <typename ARRAYTYPE, size_t arraySize>
void heapSort(std::array<ARRAYTYPE, arraySize> &array)
{
    size_t arrayLength = array.size();

    // Checks left and right trees at the same time so the loop should be run for tree value length / 2 - 1(-1 for the root)
    for (int i = arrayLength / 2 - 1; i >= 0; i--)
        heapify(array, arrayLength, i);

    for (size_t i = arrayLength - 1; i > 0; i--)
    {
        // Move current root to end
        ARRAYTYPE tempVal = array[0];
        array[0] = array[i];
        array[i] = tempVal;

        // Call max heapify on the reduced heap
        heapify(array, i, 0);
    }
}

template <typename ARRAYTYPE, size_t arraySize>
void shuffleElements(std::array<ARRAYTYPE, arraySize> &array)
{
    std::random_shuffle(array.begin(), array.end());
}