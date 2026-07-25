# Time Complexity Analysis - Practical 02

| Algorithm | Best Case | Average Case | Worst Case | Recurrence |
| :--- | :---: | :---: | :---: | :--- |
| **Linear Search** | \(\mathcal{O}(1)\) | \(\mathcal{O}(n)\) | \(\mathcal{O}(n)\) | \(T(n) = T(n-1) + \mathcal{O}(1)\) |
| **Binary Search** | \(\mathcal{O}(1)\) | \(\mathcal{O}(\log n)\) | \(\mathcal{O}(\log n)\) | \(T(n) = T(n/2) + \Theta(1)\) |

### Binary Search Derivation (Master Theorem Case 2)
\[ T(n) = T(n/2) + \Theta(1) \]
Here \(a=1, b=2, f(n) = \Theta(1)\).
\(n^{\log_b a} = n^{\log_2 1} = n^0 = 1\).
Since \(f(n) = \Theta(1) = \Theta(n^{\log_b a})\), Master Theorem Case 2 gives:
\[ T(n) = \Theta(\log n) \]
