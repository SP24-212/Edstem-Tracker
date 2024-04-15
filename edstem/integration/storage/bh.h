#include <iostream>
#include <vector>
#include "node.h"

#ifndef BH_H
#define BH_H

// Binary Heap class
class BinaryHeap {

    private:
    /*
    Private Members:
    Heap: Array to store the nodes
    heapSize: The size of the heap
    resize: Helper function to resize the heap
    heapify: Helper function to maintain the heap property
    */
    
    std::vector<EATNode*> heap;
    int heapSize;
    void resize(int newSize);
    void heapify(int index);

    public:
    /*
    Public Members:
    BinaryHeap: Constructor
    ~BinaryHeap: Destructor
    -------------------
    insert: Used to insert a new node into the heap
    find: Used to find a node with a given key
    extractMin: Used to extract the node with the minimum key
    printBinaryHeap: Used to print the contents of the heap
    */

    BinaryHeap();
    ~BinaryHeap();
    void insert(EATNode* node);
    EATNode* find(int key);
    EATNode* extractMin();
    void printBinaryHeap();
    // Other 



    
};



#endif // BH_H