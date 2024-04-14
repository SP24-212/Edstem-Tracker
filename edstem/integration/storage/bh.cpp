#include "bh.h"
#include <iostream>
#include <vector>
#include <algorithm> // For std::swap

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
    for (int i = 0; i < heapSize; i++) {
        std::cout << "Contents: [";
        for (const auto& s : heap[i]->data.second) {
            std::cout << s << " ";
        }
        std::cout << "]\n";
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