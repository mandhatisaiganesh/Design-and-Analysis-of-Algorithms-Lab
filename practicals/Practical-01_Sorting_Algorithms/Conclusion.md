# Conclusion - Practical 01

## Experimental Findings & Summary

In this practical, five core sorting algorithms were implemented in C++17 and empirically benchmarked on test datasets.

1. **Quadratic Algorithms (Bubble, Selection, Insertion)**:
   - Suitable for small array sizes (\(N < 50\)).
   - Insertion Sort performed best on partially sorted arrays due to adaptive loop behavior.
   - Selection Sort minimized write swaps to \(\mathcal{O}(n)\).

2. **Logarithmic Divide & Conquer Algorithms (Merge, Quick Sort)**:
   - Demonstrated superior performance for scaling datasets.
   - Quick Sort achieved the fastest execution times in-memory due to minimal overhead and high cache efficiency.
   - Merge Sort offered guaranteed \(\mathcal{O}(n \log n)\) stability at the expense of \(\mathcal{O}(n)\) auxiliary memory allocation.
