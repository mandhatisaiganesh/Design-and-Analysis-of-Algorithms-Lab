# Algorithmic Limitations - Practical 01

## 1. Bubble Sort Limitations
- **Poor Scalability**: Inefficient for large datasets (\(\mathcal{O}(n^2)\)).
- **Excessive Swapping**: Performs up to \(\mathcal{O}(n^2)\) swap operations in worst-case scenarios.

## 2. Selection Sort Limitations
- **Non-Adaptive**: Computes \(\Theta(n^2)\) comparisons even on a completely sorted array.
- **Unstable**: Swapping distant elements can alter the relative order of duplicate elements.

## 3. Insertion Sort Limitations
- **Quadratic Scaling**: Inefficient for large unsorted arrays (\(\mathcal{O}(n^2)\)).

## 4. Merge Sort Limitations
- **Space Overhead**: Requires \(\mathcal{O}(n)\) auxiliary memory space, making it unsuitable for memory-constrained embedded systems.

## 5. Quick Sort Limitations
- **Worst-Case Degradation**: Degenerates to \(\mathcal{O}(n^2)\) when pivot selection is poor (e.g., sorted input with first/last element pivot).
- **Unstable**: Does not guarantee preserving the original order of duplicate keys.
