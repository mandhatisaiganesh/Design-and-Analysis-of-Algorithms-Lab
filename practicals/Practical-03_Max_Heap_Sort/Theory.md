# Theory - Practical 03: Max Heap Sort

## 1. Binary Heap Concept
A binary heap is a complete binary tree stored in an array representation:
- Root element is at index `0`.
- For element at index `i`:
  - Left child: `2i + 1`
  - Right child: `2i + 2`
  - Parent: `(i - 1) / 2`

## 2. Max Heap Property
In a Max Heap, for every node `i` other than root:
\[ A[\text{parent}(i)] \ge A[i] \]
Thus, the maximum key resides at the root index `0`.
