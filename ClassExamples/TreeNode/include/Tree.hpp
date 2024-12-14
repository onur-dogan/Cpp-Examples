// Tree.hpp

#ifndef TREE_H
#define TREE_H

#include "TreeNode.hpp"

// (T = NODETYPE)
template <typename NODETYPE>
class Tree
{
public:
    Tree() : rootPtr(nullptr) {};

    // Add a new node to the tree
    void insertNode(const NODETYPE &newTreeValue)
    {
        insertNodeHelper(&rootPtr, newTreeValue);
    }

    void printTreeWithNodes()
    {
        printTreeWithNodesHelper(rootPtr);
    }

    // Sorting functions
    // It sorts by starting from the root of the tree and then goes to the left node first.
    // After the left nodes are sorted, then it continues with the right nodes on the left side.
    // After the left side is completed is continues with the right side of the root node with the same flow
    void preOrderTraversal() const
    {
        treePreOrderSorting(rootPtr);
    }

    // It sorts by starting from the left of the tree and going to the right step by step.
    // So, it sorts from left to right without comparing the priority, values or the stages.
    void inOrderTraversal() const
    {
        treeInOrderSorting(rootPtr);
    }

    // It sorts by starting from the left of the tree. But it goes to the right until the stages are completely sorted.
    // So, it starts from the bottom stage and sorts them from left to right. Then, continue with the upper stage and sorts with same flow
    void postOrderTraversal() const
    {
        treePostOrderSorting(rootPtr);
    }

private:
    // It represents the main(top) root tree node
    TreeNode<NODETYPE> *rootPtr;

    /**
     * It checks the next(below) tree nodes for each stage recursively until finding the node it should be located
     */
    void insertNodeHelper(TreeNode<NODETYPE> **treeNodePtr, const NODETYPE &newTreeValue)
    {
        // The below tree node is empty so insert it directly
        if (*treeNodePtr == nullptr)
        {
            *treeNodePtr = new TreeNode<NODETYPE>(newTreeValue);
            return;
        }

        // The tree node that has a value lower than the main tree's value, should be located at the **left** below tree node
        if (newTreeValue < (*treeNodePtr)->getData())
        {
            insertNodeHelper(&((*treeNodePtr)->leftPtr), newTreeValue);
            return;
        }

        // The tree node that has a value greater than the main tree's value, should be located at the **right** below tree node
        if (newTreeValue > (*treeNodePtr)->getData())
        {
            insertNodeHelper(&((*treeNodePtr)->rightPtr), newTreeValue);
            return;
        }

        std::cout << "The value is a duplicate so ignored. Enter the next one..\n";
    }

    void printTreeWithNodesHelper(TreeNode<NODETYPE> *treeNodePtr) const
    {
        std::cout << "\nNode: " << treeNodePtr->getData();
        if (treeNodePtr->leftPtr != nullptr)
        {
            std::cout << " Left Node: " << treeNodePtr->leftPtr->getData();
            printTreeWithNodesHelper(treeNodePtr->leftPtr);
        }

        if (treeNodePtr->rightPtr != nullptr)
        {
            std::cout << " Right Node: " << treeNodePtr->rightPtr->getData();
            printTreeWithNodesHelper(treeNodePtr->rightPtr);
        }
    }

    void treePreOrderSorting(TreeNode<NODETYPE> *treeNodePtr) const
    {
        // The below tree node is empty so insert it directly
        if (treeNodePtr != nullptr)
        {
            std::cout << treeNodePtr->getData() << ' ';
            treePreOrderSorting(treeNodePtr->leftPtr);
            treePreOrderSorting(treeNodePtr->rightPtr);
        }
    }

    void treeInOrderSorting(TreeNode<NODETYPE> *treeNodePtr) const
    {
        // The below tree node is empty so insert it directly
        if (treeNodePtr != nullptr)
        {
            treeInOrderSorting(treeNodePtr->leftPtr);
            std::cout << treeNodePtr->getData() << ' ';
            treeInOrderSorting(treeNodePtr->rightPtr);
        }
    }

    void treePostOrderSorting(TreeNode<NODETYPE> *treeNodePtr) const
    {
        // The below tree node is empty so insert it directly
        if (treeNodePtr != nullptr)
        {
            treePostOrderSorting(treeNodePtr->leftPtr);
            treePostOrderSorting(treeNodePtr->rightPtr);
            std::cout << treeNodePtr->getData() << ' ';
        }
    }
};

#endif