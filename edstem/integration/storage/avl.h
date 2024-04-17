#include "node.h"

#ifndef AVL_H
#define AVL_H

// AVL Tree Class
class AVLTree{
    // Private Members
    private:
    
    // root: A pointer to the root of the AVL tree
    EATNode* root;
    // search: A function that searches for a node with a given key in the AVL tree
    EATNode* search(EATNode* node, int key);
    // insert: A function that inserts a node with a given key and contents into the AVL tree
    EATNode* insert(EATNode* node, EATNode* newNode);
    // rotateRight: A function that performs a right rotation on a node
    EATNode* rotateRight(EATNode* node);
    // rotateLeft: A function that performs a left rotation on a node
    EATNode* rotateLeft(EATNode* node);
    // getHeight: A function that returns the height of a node
    int getHeight(EATNode* node);
    // getBalance: A function that returns the balance factor of a node
    int getBalance(EATNode* node);
    // inorderTraversal: A function that performs an inorder traversal of the AVL tree
    void inorderTraversal(EATNode* node);
    // deleteAllNodes: A function that deletes all nodes in the AVL tree
    void deleteAllNodes(EATNode* node);
    // isBalanced: A function that checks if the AVL tree is balanced
    bool isBalanced(EATNode* node);
    // visualize helper function
    void visualizeHelper(EATNode* node, std::ofstream& file);
    

    // Public Members
    public:

    // Constructor: Initializes the root of the AVL tree to nullptr
    AVLTree();
    // Destructor: Deletes all nodes in the AVL tree
    ~AVLTree();
    // search: Searches for a node with a given key in the AVL tree
    EATNode* search(int key);
    // insert: A function that inserts a node with a given key and contents into the AVL tree
    void insert(EATNode* node);
    // printAVLTree: Prints the contents of the AVL tree in order
    void printAVLTree();
    // do remove later

    // isBalanced: A function that checks if the AVL tree is balanced
    bool isBalanced();

    // visualize: A function that visualizes the AVL tree
    void visualize();
    

};

#endif // AVL_H

