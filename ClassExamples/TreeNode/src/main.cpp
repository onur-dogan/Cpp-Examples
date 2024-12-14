#include <iostream>
#include "Tree.hpp"

int main()
{
    std::cout << "\n*** Welcome to review the Tree Node Class Examples ***\n"
              << std::endl;

    Tree<int> testIntTree;
    std::cout << "Enter values of the tree. (Type -1 to end the process)\n";

    int value;

    while (std::cin >> value && value != -1)
    {
        testIntTree.insertNode(value);
    }

    std::cout << "\nTree Summary\n";
    testIntTree.printTreeWithNodes();

    std::cout << "\n\nPreorder Traversal Tree\n";
    testIntTree.preOrderTraversal();

    std::cout << "\nInorder Traversal Tree\n";
    testIntTree.inOrderTraversal();

    std::cout << "\nPostorder Traversal Tree\n";
    testIntTree.postOrderTraversal();

    std::cout << std::endl;

    return 0;
}