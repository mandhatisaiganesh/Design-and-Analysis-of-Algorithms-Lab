# Theory - Sorting Algorithms

## 1. Introduction to Sorting
Sorting is the process of arranging a collection of data items into a specific order (ascending or descending). It is a foundational problem in Computer Science because optimized sorting significantly improves the efficiency of other algorithms such as searching, data deduplication, and database indexing.

---

## 2. Classification of Sorting Algorithms

### 2.1 By Algorithmic Paradigm
- **Brute Force / Comparison-based**: Bubble Sort, Selection Sort.
- **Incremental Construction**: Insertion Sort.
- **Divide and Conquer**: Merge Sort, Quick Sort.

### 2.2 By Stability
A sorting algorithm is **stable** if two elements with equal keys appear in the same order in sorted output as they appeared in the input array.
- **Stable Algorithms**: Bubble Sort, Insertion Sort, Merge Sort.
- **Unstable Algorithms**: Selection Sort, Quick Sort, Heap Sort.

### 2.3 By Space Memory Usage
- **In-place Sorting**: Requires \(\mathcal{O}(1)\) additional memory space beyond input storage (e.g., Bubble, Selection, Insertion, Quick Sort stack space \(\mathcal{O}(\log n)\)).
- **Out-of-place Sorting**: Requires auxiliary array storage proportional to input size \(n\) (e.g., Merge Sort \(\mathcal{O}(n)\)).

---

## 3. Detailed Algorithmic Mechanics

### 3.1 Bubble Sort
Repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order. Passes continue until no swaps are needed.
- **Optimization**: An early-exit flag `swapped` terminates execution early if an entire pass executes without any element swaps (achieving \(\mathcal{O}(n)\) best-case complexity for pre-sorted arrays).

### 3.2 Selection Sort
Divides the input list into two parts: a sorted sublist built up from left to right and an unsorted sublist. In each pass, it finds the minimum element in the unsorted sublist and swaps it with the leftmost unsorted element.
- **Key Property**: Minimizes element swaps to at most \(n-1\), making it useful when write operations are extremely costly (e.g., EEPROM/Flash memory).

### 3.3 Insertion Sort
Builds the final sorted array one item at a time. It iterates through input elements, removing one element and placing it into its correct location within the growing sorted sub-array.
- **Key Property**: Extremely efficient for small datasets (\(n < 50\)) and substantially pre-sorted arrays (Adaptive behavior).

### 3.4 Merge Sort
A divide-and-conquer algorithm that recursively divides the array into two halves until single-element sub-arrays are reached, and then merges the sorted sub-arrays back together.
- **Recurrence Relation**:
  \[ T(n) = 2T(n/2) + \Theta(n) \]
  By Master Theorem Case 2, \(T(n) = \Theta(n \log n)\) across all cases.

### 3.5 Quick Sort
Selects a 'pivot' element and partitions the array such that all elements less than the pivot come before it, and all elements greater come after it. It then recursively applies the same logic to the sub-arrays.
- **Recurrence Relation (Average Case)**:
  \[ T(n) = 2T(n/2) + \Theta(n) \implies T(n) = \Theta(n \log n) \]
- **Worst Case**: Occurs when the pivot choice consistently yields highly unbalanced partitions (\(0\) and \(n-1\)), leading to:
  \[ T(n) = T(n-1) + \Theta(n) = \Theta(n^2) \]
