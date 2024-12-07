#include <iostream>
#include <iomanip>
#include <iterator>
#include "NodeList.hpp"

void showInstructions();

template <typename T>
void testNodeList(NodeList<T> &, const std::string &);

int main()
{
    NodeList<int> integerNodeList;
    testNodeList(integerNodeList, "integer");

    NodeList<double> doubleNodeList;
    testNodeList(doubleNodeList, "double");

    return 0;
}

void showInstructions()
{
    std::cout << "\nEnter one of the following:\n"
              << "1 to insert at the beginning of the list\n"
              << "2 to insert at end of the list\n"
              << "3 to delete from beginning of the list\n"
              << "4 to delete from end of the list\n"
              << "5 to end the list processing\n"
              << std::endl;
}

template <typename T>
void testNodeList(NodeList<T> &nodeList, const std::string &typeName)
{
    std::cout << "Test is started for " << typeName << " values\n";
    showInstructions();

    int selection;
    T enteredValue;

    do
    {
        std::cout << "\n\nSelection is: ";
        std::cin >> selection;

        switch (selection)
        {
        case 1:
            std::cout << "Enter a " << typeName << " value to insert at the beginning of the list: ";
            std::cin >> enteredValue;
            nodeList.insertAtFront(enteredValue);
            nodeList.printNodeList();
            break;
        case 2:
            std::cout << "Enter a " << typeName << " value to insert to the end of the list: ";
            std::cin >> enteredValue;
            nodeList.insertAtBack(enteredValue);
            nodeList.printNodeList();
            break;
        case 3:
            nodeList.removeFromFront(enteredValue);
            std::cout << enteredValue << " is removed from the node list...";
            nodeList.printNodeList();
            break;
        case 4:
            nodeList.removeFromBack(enteredValue);
            std::cout << enteredValue << " is removed from the node list...";
            nodeList.printNodeList();
            break;
        default:
            break;
        }
    } while (selection != 5);
}