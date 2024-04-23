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


#### Class Diagram
<!--change these later-->
```mermaid
classDiagram
class BinaryHeap {
  - heap: vector<EATNode*>
  - heapSize: int
  + BinaryHeap()
  + ~BinaryHeap()
  + insert(EATNode*)
  + find(int): EATNode*
  + extractMin(): EATNode*
  + printBinaryHeap(int)
  + printFilters()
  + filterBinaryHeap(int)
  + checkCol(int, int)
  + printAllTypes()
}
```

---
### Splay Tree

#### Class Diagram
```mermaid
classDiagram
class SplayTree {
  - root: EATNode*
  + SplayTree()
  + ~SplayTree()
  + insert(EATNode*)
  + remove(int)
  + search(int): EATNode*
  + printSplayTree()
  + add_bh_pointer(int, void*)
  + get_bh_pointer(int): void*
}
```
---
### AVL Tree


#### Class Diagram
```mermaid
classDiagram
class AVLTree {
  - root: EATNode*
  + AVLTree()
  + ~AVLTree()
  + search(int): EATNode*
  + insert(EATNode*)
  + printAVLTree(int)
  + isBalanced(): bool
  + printFilters()
  + printAllTypes()
}
```