# Algorithmic Advantages - Practical 01

## 1. Bubble Sort
- **Simplicity**: Extremely simple to conceptualize and code.
- **Adaptive**: Detects pre-sorted lists in \(\mathcal{O}(n)\) time via early termination flag.
- **In-Place & Stable**: Preserves relative order without additional memory overhead.

## 2. Selection Sort
- **Minimal Swaps**: Performs at most \(n-1\) element swaps, minimizing expensive memory write operations.
- **Predictable Performance**: Operates in \(\mathcal{O}(n^2)\) regardless of input ordering.

## 3. Insertion Sort
- **High Efficiency on Small Datasets**: Outperforms \(\mathcal{O}(n \log n)\) algorithms for small array sizes (\(n < 30\)).
- **Online Sorting**: Can sort a stream of numbers as they arrive in real-time.

## 4. Merge Sort
- **Guaranteed \(\mathcal{O}(n \log n)\)**: Maintains identical logarithmic performance even in worst-case scenarios.
- **Stable & Parallelizable**: Ideal for sorting linked lists and parallel distributed sorting architectures.

## 5. Quick Sort
- **Cache-Friendly**: Excellent spatial locality of reference leading to superior CPU cache hit ratios.
- **In-Place Operation**: Requires minimal memory (\(\mathcal{O}(\log n)\) stack space) compared to Merge Sort.
