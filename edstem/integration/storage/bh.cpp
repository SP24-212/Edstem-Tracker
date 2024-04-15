#include "bh.h"


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