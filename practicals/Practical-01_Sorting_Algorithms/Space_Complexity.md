# Space Complexity Analysis - Practical 01

## 1. Summary Comparison Table

| Algorithm | Auxiliary Memory Space | Call Stack Memory Space | Overall Space Complexity | In-Place Sorting? |
| :--- | :---: | :---: | :---: | :---: |
| **Bubble Sort** | \(\mathcal{O}(1)\) | \(\mathcal{O}(1)\) | \(\mathcal{O}(1)\) | Yes |
| **Selection Sort** | \(\mathcal{O}(1)\) | \(\mathcal{O}(1)\) | \(\mathcal{O}(1)\) | Yes |
| **Insertion Sort** | \(\mathcal{O}(1)\) | \(\mathcal{O}(1)\) | \(\mathcal{O}(1)\) | Yes |
| **Merge Sort** | \(\mathcal{O}(n)\) | \(\mathcal{O}(\log n)\) | \(\mathcal{O}(n)\) | No |
| **Quick Sort** | \(\mathcal{O}(1)\) | Worst: \(\mathcal{O}(n)\), Avg: \(\mathcal{O}(\log n)\) | \(\mathcal{O}(\log n)\) | Yes |

---

## 2. Memory Breakdown Details

### 2.1 Merge Sort Space Complexity
Merge Sort requires an auxiliary array during the merge operation to store temporary sub-arrays.
- Maximum size of auxiliary buffers: \(n1 + n2 = n\).
- Recursion call tree depth: \(\lceil \log_2 n \rceil\).
- Total Space: \(\mathcal{O}(n + \log n) = \mathcal{O}(n)\).

### 2.2 Quick Sort Call Stack Frames
While Quick Sort swaps elements in-place without allocating auxiliary arrays, recursive function calls consume call stack memory:
- **Best / Average Call Stack Depth**: \(\mathcal{O}(\log n)\) when partitioning divides input evenly.
- **Worst Call Stack Depth**: \(\mathcal{O}(n)\) when array is already sorted or reverse-sorted without randomized pivoting.
