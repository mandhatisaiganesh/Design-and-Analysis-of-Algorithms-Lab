# Time Complexity Analysis - Practical 01

## 1. Summary Comparison Table

| Algorithm | Best Case Time | Average Case Time | Worst Case Time | Recurrence Relation (Worst/Average) |
| :--- | :---: | :---: | :---: | :--- |
| **Bubble Sort** | \(\mathcal{O}(n)\) | \(\mathcal{O}(n^2)\) | \(\mathcal{O}(n^2)\) | \(T(n) = T(n-1) + \mathcal{O}(n)\) |
| **Selection Sort** | \(\mathcal{O}(n^2)\) | \(\mathcal{O}(n^2)\) | \(\mathcal{O}(n^2)\) | \(T(n) = T(n-1) + \mathcal{O}(n)\) |
| **Insertion Sort** | \(\mathcal{O}(n)\) | \(\mathcal{O}(n^2)\) | \(\mathcal{O}(n^2)\) | \(T(n) = T(n-1) + \mathcal{O}(n)\) |
| **Merge Sort** | \(\mathcal{O}(n \log n)\) | \(\mathcal{O}(n \log n)\) | \(\mathcal{O}(n \log n)\) | \(T(n) = 2T(n/2) + \Theta(n)\) |
| **Quick Sort** | \(\mathcal{O}(n \log n)\) | \(\mathcal{O}(n \log n)\) | \(\mathcal{O}(n^2)\) | Worst: \(T(n) = T(n-1) + \Theta(n)\) |

---

## 2. Mathematical Proofs

### 2.1 Bubble Sort Worst Case Proof
In worst case (reverse sorted array), the total number of comparisons \(C(n)\) is:
\[ C(n) = (n - 1) + (n - 2) + \dots + 1 = \sum_{i=1}^{n-1} i = \frac{n(n - 1)}{2} = \frac{n^2 - n}{2} \in \mathcal{O}(n^2) \]

### 2.2 Merge Sort Proof (Master Theorem Case 2)
Merge Sort divide step takes \(\mathcal{O}(1)\), solving two subproblems of size \(n/2\) takes \(2T(n/2)\), and merging takes \(\Theta(n)\):
\[ T(n) = 2T(n/2) + f(n), \quad \text{where } f(n) = \Theta(n) \]
Here \(a = 2, b = 2\).
\[ n^{\log_b a} = n^{\log_2 2} = n^1 = n \]
Since \(f(n) = \Theta(n^{\log_b a})\), by Master Theorem Case 2:
\[ T(n) = \Theta(n^{\log_b a} \log n) = \Theta(n \log n) \]

### 2.3 Quick Sort Worst Case Derivation
When the pivot choice always selects the extreme element (minimum or maximum):
\[ T(n) = T(n-1) + T(0) + \Theta(n) = T(n-1) + c \cdot n \]
Expanding recursively:
\[ T(n) = c \cdot n + c \cdot (n-1) + c \cdot (n-2) + \dots + c \cdot 1 = c \sum_{i=1}^{n} i = c \frac{n(n+1)}{2} \in \Theta(n^2) \]
