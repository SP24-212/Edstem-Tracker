#include <iostream>
#include <vector>

#ifndef NODE_H
#define NODE_H



// Node class
class EATNode {
    // Private Members
    private:

    // Data stored in the node as a pair of key and vector of values
    std::pair<int, std::vector<std::string> > data;

    // Since we will know the position of everything in the vector we know whether we need to use stoi or if the value is a string we can just return a bool
    
    // Pointers to the left and right children of the node
    EATNode* left;
    EATNode* right;

    // Parent pointer - to be used in the splay operation
    EATNode* parent;

   

    // Public Members
    public:

    // Constructor

    EATNode(int key, std::vector<std::string> contents);

    // Destructor
    ~EATNode();


    friend class SplayTree;
};

#endif // NODE_H
