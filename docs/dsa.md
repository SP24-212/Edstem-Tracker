# Data Structures and Algorithms in Use

For the Edstem-Lesson-Tracker project we use the following data structures and algorithms:



```mermaid
mindmap
  root((DSA))
    Splay Tree
    Binary Heap 
    AVL Tree
```
## Descriptions and Explanations 

### Binary Heap

**Description**
A Binary Heap is a self balancing data structure that acts very similarly to a priority queue with binary search tree qualities


<!--change these later-->
```mermaid
classDiagram
class BinaryHeap {
  -std::vector<EATNode*> heap
  -int heapSize
  -void resize(int newSize)
  -void heapify(int index)
  +BinaryHeap()
  +~BinaryHeap()
  +void insert(int key, std::vector<std::string> contents)
  +EATNode* find(int key)
  +EATNode* extractMin()
  +void printBinaryHeap()
}
```

---
### Splay Tree

```mermaid
classDiagram
class SplayTree {
  -EATNode* root
  -void splay(EATNode* node)
  -EATNode* findNode(int key)
  -void rotateRight(EATNode* node)
  -void rotateLeft(EATNode* node)
  -void deleteSplayTree(EATNode* node)
  -void inorderTraversal(EATNode* node)
  +SplayTree()
  +~SplayTree()
  +void insert(EATNode* node)
  +void remove(int key)
  +EATNode* search(int key)
  +void printSplayTree()
}
```
---
### AVL Tree


