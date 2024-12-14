// TreeNode.hpp

#ifndef TREENODE_H
#define TREENODE_H

// Tree class predeclaration (It will use this class as a type for some variables)
template <typename NODETYPE>
class Tree;

// (T = NODETYPE)
template <typename NODETYPE>
class TreeNode
{
    friend class Tree<NODETYPE>;

public:
    explicit TreeNode(const NODETYPE &data) : leftPtr(nullptr), treeData(data), rightPtr(nullptr) {};

    NODETYPE getData() const
    {
        return this->treeData;
    }

private:
    /**
     * @example
     *                   (leftPtr(30)) ----- rootPtr(50) ----- (rightPtr(40))
     *                       |                                       |
     *                       |                                       |
     *     leftPtr(20) ----- 30                                      40 ----- rightPtr(44)
     *         |                                                                    |
     *         |                                                                    |
     *         20                                                                   44
     */

    // left pointer points to the tree node at left below of the main one
    TreeNode<NODETYPE> *leftPtr;
    // current tree node
    NODETYPE treeData;
    // right pointer points to the tree node at right below of the main one
    TreeNode<NODETYPE> *rightPtr;
};

#endif