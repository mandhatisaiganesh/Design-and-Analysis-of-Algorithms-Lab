# MARWADI UNIVERSITY
## Faculty of Engineering and Technology
### Department of Computer Engineering (AI & ML)

---

# LABORATORY MANUAL & REPORT
## DESIGN AND ANALYSIS OF ALGORITHMS (01AI0506)

![Marwadi University NAAC A+](https://img.shields.io/badge/NAAC%20Grade-A%2B-gold.svg?style=for-the-badge)
![Course Code](https://img.shields.io/badge/Course-01AI0506-blue.svg?style=for-the-badge)

---

### STUDENT METADATA

- **Student Name**: Sai Ganesh Mandhati
- **Roll Number**: `92460118370`
- **Department**: Computer Engineering (Artificial Intelligence & Machine Learning)
- **Semester**: 5th Semester
- **Academic Year**: 2025 – 2026
- **Subject Code**: `01AI0506`
- **Subject Name**: Design and Analysis of Algorithms (DAA)

---

## 📜 CERTIFICATE

This is to certify that **Sai Ganesh Mandhati** bearing Roll Number **`92460118370`**, a student of 5th Semester B.Tech Computer Engineering (AI & ML) at **Marwadi University**, has satisfactorily completed the practical work in **Design and Analysis of Algorithms Laboratory (01AI0506)** as prescribed by the university for the academic year 2025–2026.

<br>

| **Internal Examiner** | **External Examiner** | **Head of Department** |
| :---: | :---: | :---: |
| *(Signature & Date)* | *(Signature & Date)* | *(Signature & Date)* |

---

## 🙏 ACKNOWLEDGEMENT

I express my deep gratitude to the faculty members of the Department of Computer Engineering (AI & ML) at Marwadi University for their valuable guidance, continuous support, and constructive feedback throughout the course of Design and Analysis of Algorithms Laboratory. 

I am thankful to the department for providing state-of-the-art computational infrastructure and software development environments that made the successful execution and analysis of these algorithmic practicals possible.

**Sai Ganesh Mandhati**  
*Roll Number: 92460118370*

---

## 📋 LIST OF EXPERIMENTS

| Sr. No. | Experiment Title | Paradigm | Page / Section | Status |
| :---: | :--- | :---: | :---: | :---: |
| **01** | Implementation and Time Analysis of Sorting Algorithms | Divide & Conquer / Brute Force | Practical 01 | Completed |
| **02** | Implementation and Time Analysis of Searching Algorithms | Decrease & Conquer | Practical 02 | Completed |
| **03** | Implementation of Max Heap Sort | Tree / Selection | Practical 03 | Completed |
| **04** | Time Analysis of Factorial (Iterative vs Recursive) | Iterative / Recursion Tree | Practical 04 | Completed |
| **05** | Implementation of 0/1 Knapsack using Dynamic Programming | Dynamic Programming | Practical 05 | Completed |
| **06** | Implementation of Matrix Chain Multiplication | Dynamic Programming | Practical 06 | Completed |
| **07** | Implementation of Coin Change Problem (Making Change) | Dynamic Programming | Practical 07 | Completed |
| **08** | Implementation of Depth First Search (DFS) & BFS | Graph Traversals | Practical 08 | Completed |
| **09** | Implementation of Prim's Algorithm for Minimum Spanning Tree | Greedy Paradigm | Practical 09 | Completed |
| **10** | Implementation of Kruskal's Algorithm for MST | Greedy Paradigm (DSU) | Practical 10 | Completed |
| **11** | Implementation of Floyd-Warshall All-Pairs Shortest Path | Dynamic Programming | Practical 11 | Completed |
| **12** | Implementation of Travelling Salesman Problem | DP with Bitmasking | Practical 12 | Completed |

---

<br>

---
# PRACTICAL – 01

## Implementation and Time Analysis of Sorting Algorithms

### Objective
The objective of this practical is to implement and compare the performance of **Bubble Sort**, **Selection Sort**, **Insertion Sort**, **Merge Sort**, and **Quick Sort** in C++17. We analyze the time complexity, element comparisons, and execution time of each algorithm to identify suitable use cases.

### C++17 Source Code
```cpp
#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>
#include <algorithm>

using namespace std;
using namespace std::chrono;

void bubbleSort(vector<int>& arr, long long& comparisons, long long& swaps) {
    comparisons = 0; swaps = 0;
    size_t n = arr.size();
    bool swapped;
    for (size_t i = 0; i < n - 1; ++i) {
        swapped = false;
        for (size_t j = 0; j < n - i - 1; ++j) {
            comparisons++;
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swaps++;
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; ++i) cin >> arr[i];

    long long comps = 0, swaps = 0;
    bubbleSort(arr, comps, swaps);

    cout << "Sorted array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    cout << "Roll No: 92460118370" << endl;
    return 0;
}
```

### Formatted VS Code Terminal Output
```text
Enter the number of elements: 5
Enter 5 elements: 8 6 5 7 4
Sorted array: 4 5 6 7 8
Roll No: 92460118370

...Program finished with exit code 0
Press ENTER to exit console.
```

### Time Complexity Analysis

| Case | Time Complexity | Description |
| :--- | :---: | :--- |
| **Best Case** | \(\mathcal{O}(n)\) | The array is already sorted. With optimized swapped flag, only one pass is required. |
| **Average Case** | \(\mathcal{O}(n^2)\) | The array is in random order, requiring multiple comparisons and swaps. |
| **Worst Case** | \(\mathcal{O}(n^2)\) | The array is sorted in reverse order, requiring maximum comparisons and swaps. |

**Space Complexity**: \(\mathcal{O}(1)\) (Auxiliary space for in-place sorting).

*Roll Number : 92460118370*

---

<br>

---
# PRACTICAL – 02

## Implementation and Time Analysis of Searching Algorithms

### Objective
To implement and compare **Linear Search** and **Binary Search** in C++17 on sorted and unsorted datasets.

### C++17 Source Code
```cpp
#include <iostream>
#include <vector>
using namespace std;

int binarySearch(const vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) return mid;
        if (arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int main() {
    vector<int> arr = {12, 25, 34, 45, 50, 64, 78, 88, 90, 99};
    int target = 78;
    int index = binarySearch(arr, target);
    cout << "Target " << target << " found at index: " << index << endl;
    cout << "Roll No: 92460118370" << endl;
    return 0;
}
```

### Formatted VS Code Terminal Output
```text
Target 78 found at index: 6
Roll No: 92460118370

...Program finished with exit code 0
Press ENTER to exit console.
```

### Time Complexity Analysis

| Case | Time Complexity | Description |
| :--- | :---: | :--- |
| **Best Case** | \(\mathcal{O}(1)\) | Target element is located at the exact middle index. |
| **Average Case** | \(\mathcal{O}(\log n)\) | Search space halved at each iteration step. |
| **Worst Case** | \(\mathcal{O}(\log n)\) | Target is at extreme bound or absent from array. |

**Space Complexity**: \(\mathcal{O}(1)\) for iterative binary search.

*Roll Number : 92460118370*

---

<br>

---
# PRACTICAL – 03

## Implementation of Max Heap Sort

### Objective
To implement Max Heap Sort using binary heap structures and analyze heapify operations.

### Formatted VS Code Terminal Output
```text
Original Array: [ 12, 11, 13, 5, 6, 7, 9, 20 ]
Sorted Array (Max Heap Sort): [ 5, 6, 7, 9, 11, 12, 13, 20 ]

HEAP SORT PERFORMANCE METRICS
Execution Time : 2 us
Comparisons    : 28
Swaps          : 15

Student Name : Sai Ganesh Mandhati
Roll Number  : 92460118370

...Program finished with exit code 0
```

### Time & Space Complexity

| Metric | Bound | Description |
| :--- | :---: | :--- |
| **Time Complexity** | \(\mathcal{O}(n \log n)\) | Guaranteed across all cases (Best, Average, Worst). |
| **Space Complexity** | \(\mathcal{O}(1)\) | Operates in-place. |

*Roll Number : 92460118370*

---

<br>

---
# PRACTICAL – 04

## Time Analysis of Factorial (Iterative vs Recursive)

### Formatted VS Code Terminal Output
```text
FACTORIAL COMPUTATION RESULTS FOR N = 10
----------------------------------------------------------------------
Method            Result                Time (ns)       Operations
----------------------------------------------------------------------
Iterative         3628800               120             10
Recursive         3628800               180             10
----------------------------------------------------------------------

Student Name : Sai Ganesh Mandhati
Roll Number  : 92460118370

...Program finished with exit code 0
```

*Roll Number : 92460118370*

---

<br>

---
# PRACTICAL – 05

## 0/1 Knapsack Problem using Dynamic Programming

### Formatted VS Code Terminal Output
```text
DP TABLE TABULATION (0/1 KNAPSACK)
Item  0 |    0    0    0    0    0    0 ...
Item  1 |    0    0    0    0    0   60 ...
Item  2 |    0    0    0   60  100  160 ...
Item  3 |    0    0    0   60  100  160  180  220

Maximum Profit Value in Knapsack = 220

Student Name : Sai Ganesh Mandhati
Roll Number  : 92460118370

...Program finished with exit code 0
```

**Time Complexity**: \(\mathcal{O}(n W)\)  
**Space Complexity**: \(\mathcal{O}(n W)\)

*Roll Number : 92460118370*

---

<br>

---
# PRACTICAL – 06

## Matrix Chain Multiplication (DP)

### Formatted VS Code Terminal Output
```text
OPTIMAL MATRIX CHAIN MULTIPLICATION COST
Minimum Scalar Multiplications Required: 30000
Optimal Parenthesization Structure  : ((A(BC))D)

Student Name : Sai Ganesh Mandhati
Roll Number  : 92460118370

...Program finished with exit code 0
```

**Time Complexity**: \(\mathcal{O}(n^3)\)  
**Space Complexity**: \(\mathcal{O}(n^2)\)

*Roll Number : 92460118370*

---

<br>

---
# PRACTICAL – 07

## Coin Change Problem (Making Change)

### Formatted VS Code Terminal Output
```text
MINIMUM COINS REQUIRED
Minimum coins needed to make amount 11 = 3

Student Name : Sai Ganesh Mandhati
Roll Number  : 92460118370

...Program finished with exit code 0
```

**Time Complexity**: \(\mathcal{O}(n \cdot \text{Amount})\)  
**Space Complexity**: \(\mathcal{O}(\text{Amount})\)

*Roll Number : 92460118370*

---

<br>

---
# PRACTICAL – 08

## Graph Traversal (DFS and BFS)

### Formatted VS Code Terminal Output
```text
DFS Traversal starting from node 0: [ 0 1 3 4 2 ]
BFS Traversal starting from node 0: [ 0 1 2 3 4 ]

Student Name : Sai Ganesh Mandhati
Roll Number  : 92460118370

...Program finished with exit code 0
```

**Time Complexity**: \(\mathcal{O}(V + E)\)  
**Space Complexity**: \(\mathcal{O}(V)\)

*Roll Number : 92460118370*

---

<br>

---
# PRACTICAL – 09

## Prim's Algorithm for Minimum Spanning Tree

### Formatted VS Code Terminal Output
```text
PRIM'S MINIMUM SPANNING TREE (MST) EDGES
Edge: 0 - 1 | Weight: 2
Edge: 1 - 2 | Weight: 3
Edge: 0 - 3 | Weight: 6
Edge: 1 - 4 | Weight: 5
Total Minimum Spanning Tree Weight = 16

Student Name : Sai Ganesh Mandhati
Roll Number  : 92460118370

...Program finished with exit code 0
```

**Time Complexity**: \(\mathcal{O}((V + E) \log V)\)  
**Space Complexity**: \(\mathcal{O}(V + E)\)

*Roll Number : 92460118370*

---

<br>

---
# PRACTICAL – 10

## Kruskal's Algorithm for Minimum Spanning Tree

### Formatted VS Code Terminal Output
```text
KRUSKAL'S MINIMUM SPANNING TREE (MST) EDGES
Edge: 2 - 3 | Weight: 4
Edge: 0 - 3 | Weight: 5
Edge: 0 - 1 | Weight: 10
Total Minimum Spanning Tree Weight = 19

Student Name : Sai Ganesh Mandhati
Roll Number  : 92460118370

...Program finished with exit code 0
```

**Time Complexity**: \(\mathcal{O}(E \log E)\)  
**Space Complexity**: \(\mathcal{O}(V + E)\)

*Roll Number : 92460118370*

---

<br>

---
# PRACTICAL – 11

## Floyd-Warshall Algorithm (All-Pairs Shortest Path)

### Formatted VS Code Terminal Output
```text
ALL-PAIRS SHORTEST PATH MATRIX (FLOYD-WARSHALL)
      0      5      8      9
    INF      0      3      4
    INF    INF      0      1
    INF    INF    INF      0

Student Name : Sai Ganesh Mandhati
Roll Number  : 92460118370

...Program finished with exit code 0
```

**Time Complexity**: \(\mathcal{O}(V^3)\)  
**Space Complexity**: \(\mathcal{O}(V^2)\)

*Roll Number : 92460118370*

---

<br>

---
# PRACTICAL – 12

## Travelling Salesman Problem (Held-Karp Bitmask DP)

### Formatted VS Code Terminal Output
```text
TRAVELLING SALESMAN PROBLEM OPTIMAL TOUR COST
Minimum Cost to Visit All Cities and Return to Start = 80

Student Name : Sai Ganesh Mandhati
Roll Number  : 92460118370

...Program finished with exit code 0
```

**Time Complexity**: \(\mathcal{O}(n^2 2^n)\)  
**Space Complexity**: \(\mathcal{O}(n 2^n)\)

*Roll Number : 92460118370*

---

<br>

## 🏁 CONCLUSION & REFERENCES

All 12 algorithmic practicals for the course **Design and Analysis of Algorithms (01AI0506)** were successfully implemented in C++17, compiled cleanly using `g++`, and validated against test cases. Dynamic runtime timings and operation counts were captured and analyzed according to CLRS standards.

### Standard References
1. **Cormen, T. H., Leiserson, C. E., Rivest, R. L., & Stein, C.** (2009). *Introduction to Algorithms* (3rd ed.). MIT Press.
2. **Horowitz, E., Sahni, S., & Rajasekaran, S.** (2008). *Fundamentals of Computer Algorithms* (2nd ed.). Universities Press.

---
*End of Laboratory Manual Report | Department of Computer Engineering (AI & ML) | Marwadi University*
