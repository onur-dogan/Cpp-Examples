// NodeList.hpp

#ifndef NODELIST_H
#define NODELIST_H

#include <iostream>
#include "ListNode.hpp"

namespace nodelist
{
    template <typename NODETYPE>
    class NodeList
    {
    public:
        NodeList() : firstPtr(nullptr), lastPtr(nullptr) {};

        void insertAtFront(const NODETYPE &value)
        {
            ListNode<NODETYPE> *newPtr = declareNewNode(value);

            if (isNodeEmpty())
                // The new list only includes one node
                setPointersSame(newPtr);
            else
            {
                // The new node should be connected/point to the next node.
                // The next node would be the first pointer since the new node is added at front
                newPtr->nextPtr = firstPtr;
                // The new pointer is the first pointer after now
                firstPtr = newPtr;
            }
        }

        void insertAtBack(const NODETYPE &value)
        {
            ListNode<NODETYPE> *newPtr = declareNewNode(value);

            if (isNodeEmpty())
                // The new list only includes one node
                setPointersSame(newPtr);
            else
            {
                // The new node will be added at back.
                // The previous last pointer should point this new node.
                lastPtr->nextPtr = newPtr;
                // The new node will be the last pointer.
                lastPtr = newPtr;
            }
        }

        bool removeFromFront(NODETYPE &value)
        {
            if (isNodeEmpty())
                return false;

            // Store the removed pointer as a temporary value to return by setting it to the parameter
            ListNode<NODETYPE> *removedTempPtr = firstPtr;

            // If there is only one pointer in the node list, the list(first and last nodes) should be empty after removing
            if (firstPtr == lastPtr)
                setPointersSame(nullptr);
            // Otherwise the first node will be removed and the connected node of the first node will be the new first node
            else
                firstPtr = firstPtr->nextPtr;

            value = removedTempPtr->getData();
            delete removedTempPtr;

            return true;
        }

        bool removeFromBack(NODETYPE &value)
        {
            if (isNodeEmpty())
                return false;

            // Store the removed pointer as a temporary value to return by setting it to the parameter
            ListNode<NODETYPE> *removedTempPtr = lastPtr;

            // If there is only one pointer in the node list, the list(first and last nodes) should be empty after removing
            if (firstPtr == lastPtr)
                setPointersSame(nullptr);
            // Otherwise the last node will be removed and the connected node of the first node will be the new first node
            else
            {
                // Need to find the new last pointer by checking the pointer's next connected nodes.
                ListNode<NODETYPE> *newLastPtr = firstPtr;

                // The pointer which will be the last pointer, has the last pointer as the next node.
                // So, check each next node by beginning from the first pointer to find the new last pointer
                while (newLastPtr->nextPtr != lastPtr)
                    newLastPtr = newLastPtr->nextPtr;

                lastPtr = newLastPtr;
                lastPtr->nextPtr = nullptr;
            }

            value = removedTempPtr->getData();
            delete removedTempPtr;

            return true;
        }

        bool isNodeEmpty() const
        {
            return firstPtr == nullptr;
        }

        void printNodeList()
        {
            if (isNodeEmpty())
            {
                std::cout << "\nThe list is empty!" << std::endl;
                return;
            }

            ListNode<NODETYPE> *currentPtr = firstPtr;

            std::cout << "\n***Node List***\n";
            while (currentPtr != nullptr)
            {
                std::cout << currentPtr->getData() << " ";
                currentPtr = currentPtr->nextPtr;
            }
        }

        ~NodeList()
        {
            if (!isNodeEmpty())
            {
                std::cout << "Nodes destructing...\n";

                ListNode<NODETYPE> *currentPtr = firstPtr;
                ListNode<NODETYPE> *tempPtr = nullptr;

                while (currentPtr != nullptr)
                {
                    tempPtr = currentPtr;
                    std::cout << "\nDestructing for " << currentPtr->getData();
                    currentPtr = currentPtr->nextPtr;

                    delete tempPtr;
                }
            }

            std::cout << "All nodes are destructed...";
        }

    private:
        ListNode<NODETYPE> *firstPtr;
        ListNode<NODETYPE> *lastPtr;

        inline void setPointersSame(ListNode<NODETYPE> *newPtr)
        {
            this->firstPtr = this->lastPtr = newPtr;
        }

        ListNode<NODETYPE> *declareNewNode(const NODETYPE &value)
        {
            return new ListNode<NODETYPE>(value);
        }
    };
}

#endif