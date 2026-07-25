# Theory - Practical 02: Searching Algorithms

## 1. Linear Search
Linear search sequentially checks each element of the list until a match is found or the end of the list is reached.
- **Pre-requisite**: None (Works on unsorted arrays, linked lists, streams).
- **Time Complexity**: \(\mathcal{O}(n)\).

## 2. Binary Search
Binary search follows the **Decrease and Conquer** paradigm. It repeatedly divides the search interval in half.
- **Pre-requisite**: Array MUST be sorted.
- **Formula**: `mid = low + (high - low) / 2` (prevents integer overflow compared to `(low + high) / 2`).
- **Recurrence**: \(T(n) = T(n/2) + \Theta(1) \implies T(n) = \Theta(\log n)\).
