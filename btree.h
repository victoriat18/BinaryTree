//HEADER!!
//***************************************************************************
//
// Name: Victoria Torres
// ZId:  Z2043396 
// CSCI 340 PE1
// Binary Tree: stores data in nodes and can add values, count nodes,
// find the tree's height, and visit each node in order.
// 10/13/2026
//I certify that this is my own work and, where appropriate, an extension
// Of the starter code provided for the assignment.
//
//***************************************************************************


#ifndef H_BTREE
#define H_BTREE

//added
#include "node.h"
#include <cstdlib>

typedef enum{left_side, right_side} SIDE; // random selection

inline SIDE rnd()
{

    return rand()%2 ? right_side : left_side; 
}// End of rnd()



template <typename T> class BinaryTree{

public:
    BinaryTree();                                         // default constructor
    unsigned     getSize() const;                        // returns size of tree
    unsigned     getHeight() const;                     // returns height of tree
    virtual void Insert(const T&);                     // inserts node in tree
    void         Inorder(void (*)(const T&));         // inorder traversal of tree

protected:
    Node<T> *root;                                      // root of tree

private:
    unsigned _getSize(Node<T> *) const;                 // private version of getSize()
    unsigned _getHeight(Node<T> *) const;               // private version of getHeight()
    void     _Insert(Node<T> *&, const T&);             // private version of Insert()
    void     _Inorder(Node<T> *, void (*)(const T&));   // private version of Inorder()
};

// Default constructor
template <typename T>
BinaryTree<T>::BinaryTree() : root(nullptr)
{
}

// Return the number of nodes
template <typename T>
unsigned BinaryTree<T>::getSize() const
{
    return _getSize(root);
}

// Count nodes recursively
template <typename T>
unsigned BinaryTree<T>::_getSize(Node<T> *node) const
{
    if (node == nullptr)
        return 0;

    return 1 + _getSize(node->left) + _getSize(node->right);
}

//Return the height of the tree
template <typename T>
unsigned BinaryTree<T>::getHeight() const
{
    return _getHeight(root);
}

// Calculate height recursively, an empty tree has height 0
template <typename T>
unsigned BinaryTree<T>::_getHeight(Node<T> *node) const
{
    if (node == nullptr)
        return 0;
    
    unsigned left_height = _getHeight(node->left);
    unsigned right_height = _getHeight(node->right);
//Add 1 for the current node to the greater subtree height
    return 1 + (left_height > right_height ? left_height : right_height);
}
// Insert a value into the tree
template <typename T>
void BinaryTree<T>::Insert(const T& value)
{
    _Insert(root, value);
}

//Insert recursively into a randomly selected subtree
template <typename T>
void BinaryTree<T>::_Insert(Node<T> *&node, const T& value)
{
    if (node == nullptr)
    {
    // create a new node when an empty position is found
        node = new Node<T>(value);
        return;
    }
    if (rnd() == left_side)

    _Insert(node->left, value);

    else
    _Insert(node->right, value);
}
// Start inorder traversal
template <typename T>
void BinaryTree<T>::Inorder(void (*visit)(const T&))
{
    _Inorder(root, visit);
}
// Visit left subtree, node, then right subtree
template <typename T>
void BinaryTree<T>::_Inorder(Node<T> *node, void (*visit)(const T&))
{
    if(node == nullptr)
        return;

    _Inorder(node->left, visit);

    visit(node->data);

    _Inorder(node->right, visit);
}

#endif // End of H_BTREE
