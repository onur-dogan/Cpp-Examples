// ListNode.hpp

#ifndef LISTNODE_H
#define LISTNODE_H

template <typename NODETYPE>
class NodeList;

template <typename NODETYPE>
class ListNode
{
    // The NodeList class must be a friend of this class to can achieve the private variables of this class
    friend class NodeList<NODETYPE>;

public:
    // Constructor to store node type and set the next node in the list as null.
    // The pointers have to be declared as null ptr before using
    explicit ListNode(const NODETYPE &info) : data(info), nextPtr(nullptr) {};

    NODETYPE getData() const
    {
        return data;
    }

private:
    NODETYPE data;
    // The next node in the list
    ListNode<NODETYPE> *nextPtr;
};

#endif