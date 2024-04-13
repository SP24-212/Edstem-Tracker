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
---
title: Binary Heap
---
classDiagram
class BinaryHeap {
    - heap_list: List
    - current_size: int
    + insert(value: int): void
    + percolate_up(i: int): void
    + delete_min(): int
    + percolate_down(i: int): void
    + min_child(i: int): int
    + peek_min(): int
    + is_empty(): bool
    + size(): int
}
```

---
### Splay Tree


---
### AVL Tree


