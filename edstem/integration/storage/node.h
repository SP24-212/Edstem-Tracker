#include <iostream>
#include <vector>

#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define RED     "\033[31m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

#ifndef NODE_H
#define NODE_H



// Node class
class EATNode {
    // Private Members
    private:

    // Data stored in the node as a pair of key and vector of values
    std::pair<int, std::pair<std::vector<std::string>, void*> > data;

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

    // Friend classes
    friend class BinaryHeap;
    friend class SplayTree;
};

#endif // NODE_H
