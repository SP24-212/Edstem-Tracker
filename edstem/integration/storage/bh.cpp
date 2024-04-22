#include "bh.h"
#include <iostream>
#include <vector>
#include <algorithm> // For std::swap

#define RESET   "\033[0m"
#define GREEN   "\033[32m"


BinaryHeap::BinaryHeap() : heapSize(0) {}

BinaryHeap::~BinaryHeap() {
    for (auto node : heap) {
        delete node;
    }
}

void BinaryHeap::resize(int newSize) {
    heap.resize(newSize);
}

void BinaryHeap::heapify(int index) {
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int smallest = index;

    if (left < heapSize && heap[left]->data.first < heap[smallest]->data.first) {
        smallest = left;
    }
    if (right < heapSize && heap[right]->data.first < heap[smallest]->data.first) {
        smallest = right;
    }

    if (smallest != index) {
        std::swap(heap[index], heap[smallest]);
        heapify(smallest);
    }
}

void BinaryHeap::insert(EATNode* node) {
    if (heapSize == heap.size()) {
        resize(heapSize + 1);
    }
    int i = heapSize++;
    heap[i] = node;

    while (i != 0 && heap[(i - 1) / 2]->data.first > heap[i]->data.first) {
        std::swap(heap[(i - 1) / 2], heap[i]);
        i = (i - 1) / 2;
    }
}

EATNode* BinaryHeap::extractMin() {
    if (heapSize <= 0)
        return nullptr;

    if (heapSize == 1) {
        heapSize--;
        return heap[0];
    }

    EATNode* root = heap[0];
    heap[0] = heap[heapSize - 1];
    heapSize--;
    heapify(0);

    return root;
}

void BinaryHeap::printBinaryHeap() {
    for (int i = 1; i < heapSize; i++) {
        std::cout << "Key: " << GREEN << heap[i]->data.first << RESET << " Contents: [";

        // Iterate over both column names and elements in the column
        for (size_t j = 1; j < heap[i]->data.second.first.size() - 1; j++) {
            
            // If j is 0: print Due Date: in RED
            if (j == 1) {
                std::cout << RED << "Due Date: " << RESET;
            }
            // If j is 1: print Lesson Type: in RED
            else if (j == 2) {
                std::cout << RED << "Lesson Type: " << RESET;
            }
            // If j is 2: print Openable: in RED
            else if (j == 3) {
                std::cout << RED << "Openable: " << RESET;
            }
            // If j is 3: print Title: in RED
            else if (j == 4) {
                std::cout << RED << "Title: " << RESET;
            }
            // If j is 4: print Status: in RED
            else if (j == 5) {
                std::cout << RED << "Status: " << RESET;
            } 
            // If j is 6: print User Score: in RED
            else if (j == 6) {
                std::cout << RED << "User Score: " << RESET;
            }
            // If j is 7: print Potential Score: in RED
            else if (j == 7) {
                std::cout << RED << "Potential Score: " << RESET;
            }

            // Print element in the column
            std::cout << heap[i]->data.second.first[j] << " ";
        }
        std::cout << "]\n\n";
    }
}


EATNode* BinaryHeap::find(int key) {
    for (auto node : heap) {
        if (node->data.first == key) {
            return node;
        }
    }
    return nullptr;
}

                                // // Helper function to get the height of a node
                                // int BinaryHeap::getHeight(EATNode* node){

                                // }

                                // // Helper function to get the balance factor of a node
                                // int BinaryHeap::getBalance(EATNode* node){

                                // }

                                // // Balance check function
                                // bool BinaryHeap::isBalanced(EATNode* node){

                                // }

                                // // Public function to check if the Binary Heap is balanced
                                // bool BinaryHeap::isBalanced(){

                                // }

// Helper function to check if a node has two children
bool BinaryHeap::hasTwoChildren(EATNode* node) {
    return (node->left != nullptr && node->right != nullptr);
    }

// Helper function to get the height of a node (same as existing getHeight)
int BinaryHeap::getHeight(EATNode* node) {
    if (node == nullptr) {
        return 0;
    }
    return 1 + std::max(getHeight(node->left), getHeight(node->right));
    }

// Function to check if the Binary Heap is "full" (every node has 2 children)
bool BinaryHeap::isBalanced(EATNode* node) {
    if (node == nullptr || (node->left == nullptr && node->right == nullptr)) {
        return true;
    }

    if (!hasTwoChildren(node)) {
        return false;
    }

    return isBalanced(node->left) && isBalanced(node->right);
    }

// Public function to check if the Binary Heap is "full" (every node has 2 children)
bool BinaryHeap::isBalanced() {
    return isBalanced(heap[0]);
}

// Function to visualize the binary heap
void BinaryHeap::visualize() {
std::string folderPath = "edstem/integration/edstem-data/";

std::ofstream file;
file.open(folderPath + "binary_heap.dot");
file << "digraph BinaryHeap {" << std::endl;
visualizeHelper(heap[0], file, 0);
file << "}" << std::endl;
file.close();
system(("dot -Tpng " + folderPath + "binary_heap.dot -o " + folderPath + "binary_heap.png").c_str());
system(("open " + folderPath + "binary_heap.png").c_str());
}

// Helper function to visualize the binary heap recursively
void BinaryHeap::visualizeHelper(EATNode* node, std::ofstream& file, int index) {
  // ... (rest of the code remains the same) ...

  if (node != nullptr) { // Only proceed if the node is not null
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    // Create edges for left and right children (even if null)
    file << "node_" << index << " -> ";
    if (left < heapSize) {
      file << "node_" << left;
    } else {
      file << "null";  // Indicate empty child
    }
    file << " [label=\"\\left\"];" << std::endl;  // Escape "left" with backslash

    file << "node_" << index << " -> ";
    if (right < heapSize) {
      file << "node_" << right;
    } else {
      file << "null";  // Indicate empty child
    }
    file << " [label=\"\\right\"];" << std::endl; // Escape "right" with backslash
  }

  // ... (rest of the code remains the same) ...
}