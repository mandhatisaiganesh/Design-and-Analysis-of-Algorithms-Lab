# Design and Analysis of Algorithms (DAA) Laboratory

![Course Code](https://img.shields.io/badge/Course%20Code-01AI0506-blue.svg?style=for-the-badge)
![University](https://img.shields.io/badge/University-Marwadi%20University-red.svg?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C%2B%2B17-00599C.svg?style=for-the-badge&logo=c%2B%2B)
![Compiler](https://img.shields.io/badge/Compiler-GCC%20g%2B%2B-green.svg?style=for-the-badge)
![License](https://img.shields.io/badge/License-MIT-yellow.svg?style=for-the-badge)
![Build Status](https://img.shields.io/badge/Build-Passing-brightgreen.svg?style=for-the-badge)

Welcome to the official open-source repository for the **Design and Analysis of Algorithms (DAA) Laboratory** (Course Code: **01AI0506**) at **Marwadi University**, Department of Computer Engineering (Artificial Intelligence & Machine Learning).

This repository contains production-ready C++17 implementations, rigorous asymptotic complexity proofs, benchmarking suites, detailed theoretical notes, flow explanations, sample outputs, and 120+ university viva preparation questions across 12 core algorithmic practicals.

---

## 🌟 Key Features

- ⚡ **Production C++17 Code**: Modular, clean, modern C++17 programs compiled with strict compiler flags (`-Wall -Wextra -O2`).
- ⏱️ **Sub-Microsecond Benchmarking**: Dynamic runtime tracking using standard C++ `<chrono>` high-resolution clocks (`std::chrono::high_resolution_clock`).
- 📊 **Exact Operational Counters**: Tracks element comparisons, swaps, shifts, and matrix state updates.
- 📘 **Unified University Lab Manual**: A single, complete, 3,800+ line print-ready lab manual (`Lab_Manual.md`) covering all 12 practicals with 19 standardized sections per practical.
- 🎓 **120+ Viva Voce Q&A**: 10 detailed interview/viva questions with solutions for every experiment.

---

## 🏫 University & Course Details

- **University**: Marwadi University, Rajkot, Gujarat, India (NAAC Grade A+)
- **Faculty**: Faculty of Engineering and Technology
- **Department**: Department of Computer Engineering (AI & ML)
- **Course Name**: Design and Analysis of Algorithms (DAA)
- **Course Code**: `01AI0506`
- **Semester**: 5th Semester B.Tech
- **Academic Year**: 2025 – 2026

---

## 📁 Repository Structure

```text
Design-and-Analysis-of-Algorithms-Lab/
├── README.md                           # Master Open-Source Documentation
├── LICENSE                             # MIT License
├── .gitignore                          # Git Exclusion Rules
├── Lab_Manual.md                       # Complete 12-Practical Master Lab Manual
├── src/                                # Modern C++17 Source Code Files
│   ├── Practical_01_Sorting_Algorithms.cpp
│   ├── Practical_02_Searching_Algorithms.cpp
│   ├── Practical_03_Heap_Sort.cpp
│   ├── Practical_04_Factorial.cpp
│   ├── Practical_05_01_Knapsack.cpp
│   ├── Practical_06_Matrix_Chain.cpp
│   ├── Practical_07_Coin_Change.cpp
│   ├── Practical_08_DFS_BFS.cpp
│   ├── Practical_09_Prims.cpp
│   ├── Practical_10_Kruskals.cpp
│   ├── Practical_11_Floyd_Warshall.cpp
│   └── Practical_12_TSP.cpp
├── outputs/                            # Terminal Execution Output Text Logs
│   ├── Output_01.txt
│   ├── Output_02.txt
│   ├── Output_03.txt
│   ├── Output_04.txt
│   ├── Output_05.txt
│   ├── Output_06.txt
│   ├── Output_07.txt
│   ├── Output_08.txt
│   ├── Output_09.txt
│   ├── Output_10.txt
│   ├── Output_11.txt
│   └── Output_12.txt
└── assets/                             # Visual Artifacts & Screenshots
```

---

## 🧪 List of Practicals

| Practical | Title / Topic | Design Paradigm | Key Algorithms Implemented | Code Link | Manual Link |
| :---: | :--- | :---: | :--- | :---: | :---: |
| **01** | Sorting Algorithms & Time Analysis | Brute Force / Divide & Conquer | Bubble, Selection, Insertion, Merge, Quick Sort | [Code](./src/Practical_01_Sorting_Algorithms.cpp) | [Manual](./Lab_Manual.md#practical-01-sorting-algorithms) |
| **02** | Searching Algorithms & Time Analysis | Decrease & Conquer | Linear Search, Binary Search | [Code](./src/Practical_02_Searching_Algorithms.cpp) | [Manual](./Lab_Manual.md#practical-02-searching-algorithms) |
| **03** | Max Heap Sort Implementation | Tree / Selection | Heapify, Build-Max-Heap, Heap Sort | [Code](./src/Practical_03_Heap_Sort.cpp) | [Manual](./Lab_Manual.md#practical-03-max-heap-sort) |
| **04** | Factorial Time Analysis | Iterative vs Recursive | Iterative Factorial, Recursion Tree Factorial | [Code](./src/Practical_04_Factorial.cpp) | [Manual](./Lab_Manual.md#practical-04-factorial-analysis) |
| **05** | 0/1 Knapsack Problem | Dynamic Programming | Bottom-up DP Tabulation | [Code](./src/Practical_05_01_Knapsack.cpp) | [Manual](./Lab_Manual.md#practical-05-01-knapsack-problem) |
| **06** | Matrix Chain Multiplication | Dynamic Programming | Optimal Parenthesization DP | [Code](./src/Practical_06_Matrix_Chain.cpp) | [Manual](./Lab_Manual.md#practical-06-matrix-chain-multiplication) |
| **07** | Coin Change Problem | Dynamic Programming | Minimum Coin Change DP | [Code](./src/Practical_07_Coin_Change.cpp) | [Manual](./Lab_Manual.md#practical-07-coin-change-problem) |
| **08** | Graph Traversals (DFS & BFS) | Graph Theory | Depth-First Search, Breadth-First Search | [Code](./src/Practical_08_DFS_BFS.cpp) | [Manual](./Lab_Manual.md#practical-08-graph-traversals-dfs--bfs) |
| **09** | Prim's Algorithm | Greedy Paradigm | Priority Queue Minimum Spanning Tree | [Code](./src/Practical_09_Prims.cpp) | [Manual](./Lab_Manual.md#practical-09-prims-algorithm) |
| **10** | Kruskal's Algorithm | Greedy Paradigm | Disjoint Set Union (DSU / Union-Find) MST | [Code](./src/Practical_10_Kruskals.cpp) | [Manual](./Lab_Manual.md#practical-10-kruskals-algorithm) |
| **11** | Floyd-Warshall Algorithm | Dynamic Programming | All-Pairs Shortest Path (APSP) | [Code](./src/Practical_11_Floyd_Warshall.cpp) | [Manual](./Lab_Manual.md#practical-11-floyd-warshall-algorithm) |
| **12** | Travelling Salesman Problem | DP with Bitmasking | Held-Karp Algorithm (\(\mathcal{O}(n^2 2^n)\)) | [Code](./src/Practical_12_TSP.cpp) | [Manual](./Lab_Manual.md#practical-12-travelling-salesman-problem) |

---

## ⚡ Algorithmic Complexity Comparison

| Algorithm | Design Paradigm | Best Case Time | Average Case Time | Worst Case Time | Auxiliary Space |
| :--- | :--- | :---: | :---: | :---: | :---: |
| **Bubble Sort** | Brute Force | \(\mathcal{O}(n)\) | \(\mathcal{O}(n^2)\) | \(\mathcal{O}(n^2)\) | \(\mathcal{O}(1)\) |
| **Selection Sort** | Brute Force | \(\mathcal{O}(n^2)\) | \(\mathcal{O}(n^2)\) | \(\mathcal{O}(n^2)\) | \(\mathcal{O}(1)\) |
| **Insertion Sort** | Incremental | \(\mathcal{O}(n)\) | \(\mathcal{O}(n^2)\) | \(\mathcal{O}(n^2)\) | \(\mathcal{O}(1)\) |
| **Merge Sort** | Divide & Conquer | \(\mathcal{O}(n \log n)\) | \(\mathcal{O}(n \log n)\) | \(\mathcal{O}(n \log n)\) | \(\mathcal{O}(n)\) |
| **Quick Sort** | Divide & Conquer | \(\mathcal{O}(n \log n)\) | \(\mathcal{O}(n \log n)\) | \(\mathcal{O}(n^2)\) | \(\mathcal{O}(\log n)\) |
| **Linear Search** | Sequential | \(\mathcal{O}(1)\) | \(\mathcal{O}(n)\) | \(\mathcal{O}(n)\) | \(\mathcal{O}(1)\) |
| **Binary Search** | Decrease & Conquer | \(\mathcal{O}(1)\) | \(\mathcal{O}(\log n)\) | \(\mathcal{O}(\log n)\) | \(\mathcal{O}(1)\) |
| **Max Heap Sort** | Tree / Selection | \(\mathcal{O}(n \log n)\) | \(\mathcal{O}(n \log n)\) | \(\mathcal{O}(n \log n)\) | \(\mathcal{O}(1)\) |
| **Iterative Factorial** | Linear Loop | \(\mathcal{O}(n)\) | \(\mathcal{O}(n)\) | \(\mathcal{O}(n)\) | \(\mathcal{O}(1)\) |
| **Recursive Factorial** | Recursion Tree | \(\mathcal{O}(n)\) | \(\mathcal{O}(n)\) | \(\mathcal{O}(n)\) | \(\mathcal{O}(n)\) |
| **0/1 Knapsack** | Dynamic Programming | \(\mathcal{O}(n W)\) | \(\mathcal{O}(n W)\) | \(\mathcal{O}(n W)\) | \(\mathcal{O}(n W)\) |
| **Matrix Chain Mult.** | Dynamic Programming | \(\mathcal{O}(n^3)\) | \(\mathcal{O}(n^3)\) | \(\mathcal{O}(n^3)\) | \(\mathcal{O}(n^2)\) |
| **Coin Change** | Dynamic Programming | \(\mathcal{O}(n \cdot V)\) | \(\mathcal{O}(n \cdot V)\) | \(\mathcal{O}(n \cdot V)\) | \(\mathcal{O}(V)\) |
| **DFS Traversal** | Graph Theory | \(\mathcal{O}(V + E)\) | \(\mathcal{O}(V + E)\) | \(\mathcal{O}(V + E)\) | \(\mathcal{O}(V)\) |
| **BFS Traversal** | Graph Theory | \(\mathcal{O}(V + E)\) | \(\mathcal{O}(V + E)\) | \(\mathcal{O}(V + E)\) | \(\mathcal{O}(V)\) |
| **Prim's Algorithm** | Greedy Paradigm | \(\mathcal{O}((V + E) \log V)\) | \(\mathcal{O}((V + E) \log V)\) | \(\mathcal{O}((V + E) \log V)\) | \(\mathcal{O}(V + E)\) |
| **Kruskal's Algorithm** | Greedy (DSU) | \(\mathcal{O}(E \log E)\) | \(\mathcal{O}(E \log E)\) | \(\mathcal{O}(E \log E)\) | \(\mathcal{O}(V + E)\) |
| **Floyd-Warshall** | Dynamic Programming | \(\mathcal{O}(V^3)\) | \(\mathcal{O}(V^3)\) | \(\mathcal{O}(V^3)\) | \(\mathcal{O}(V^2)\) |
| **TSP (Held-Karp)** | Bitmasking DP | \(\mathcal{O}(n^2 2^n)\) | \(\mathcal{O}(n^2 2^n)\) | \(\mathcal{O}(n^2 2^n)\) | \(\mathcal{O}(n 2^n)\) |

---

## 🛠️ Technologies & Environment

- **Language**: Standard C++17 (`<chrono>`, `<vector>`, `<queue>`, `<climits>`, `<iomanip>`, `<algorithm>`)
- **Compiler**: GCC / MinGW `g++` (v9.0 or higher recommended)
- **Compilation Flags**: `-std=c++17 -Wall -Wextra -O2`
- **Operating System**: Cross-platform compatible (Linux / macOS / Windows)

---

## ⚙️ Compilation & Execution Guide

### Compiling a Specific Practical

Navigate to the repository root directory and run `g++`:

```bash
# Example: Compile Practical 01 (Sorting Algorithms)
g++ -std=c++17 -Wall -Wextra -O2 src/Practical_01_Sorting_Algorithms.cpp -o Practical_01

# Example: Compile Practical 05 (0/1 Knapsack)
g++ -std=c++17 -Wall -Wextra -O2 src/Practical_05_01_Knapsack.cpp -o Practical_05
```

### Running an Executable

```bash
# Interactive Execution
./Practical_01

# Automated Execution using sample input
./Practical_01 < outputs/Output_01.txt
```

---

## 🎯 Learning Outcomes

By studying this repository, students and engineers will:
1. **Master Asymptotic Proofs**: Prove time and space bounds using Big-O, Big-Omega, and Big-Theta formalisms.
2. **Apply Algorithmic Paradigms**: Select between Divide & Conquer, Greedy Choice, and Dynamic Programming based on problem structure.
3. **Optimize Advanced Data Structures**: Utilize Binary Heaps, Priority Queues, Disjoint Set Union (DSU with Path Compression), and Adjacency Lists.
4. **Engineer Benchmarking Tools**: Instrument dynamic high-resolution time profiling and atomic comparison logging in C++.
5. **Excel in Technical Interviews**: Prepare for university lab viva voce examinations and competitive coding assessments with 120+ structured Q&A.

---

## 📸 Sample Terminal Outputs

Below is an excerpt of actual terminal execution from `src/Practical_01_Sorting_Algorithms.cpp`:

```text
======================================================================
         MARWADI UNIVERSITY - DEPARTMENT OF CE (AI & ML)
    DESIGN AND ANALYSIS OF ALGORITHMS LABORATORY (01AI0506)
    PRACTICAL 01: SORTING ALGORITHMS TIME ANALYSIS BENCHMARK
======================================================================
Student Name: Sai Ganesh Mandhati
Roll Number : 92460118370
======================================================================

Algorithm         Time (us)       Comparisons       Swaps/Shifts      Sorted Output
-------------------------------------------------------------------------------------
Bubble Sort       0               39                20                  : [ 11, 12, 22, 25, 34, 45, 50, 64, 78, 90 ]
Selection Sort    0               45                6                   : [ 11, 12, 22, 25, 34, 45, 50, 64, 78, 90 ]
Insertion Sort    0               25                20                  : [ 11, 12, 22, 25, 34, 45, 50, 64, 78, 90 ]
Merge Sort        7               21                N/A (Aux Memory)    : [ 11, 12, 22, 25, 34, 45, 50, 64, 78, 90 ]
Quick Sort        0               26                25                  : [ 11, 12, 22, 25, 34, 45, 50, 64, 78, 90 ]
-------------------------------------------------------------------------------------
```

---

## 👨‍💻 Author & Acknowledgements

- **Author**: Sai Ganesh Mandhati
- **Roll Number**: `92460118370`
- **Department**: Computer Engineering (AI & ML)
- **Institution**: Marwadi University, Rajkot, Gujarat, India

Special thanks to the faculty of the Department of Computer Engineering (AI & ML) at Marwadi University for providing guidance and academic infrastructure.

---

## 🔮 Future Improvements

- [ ] Add parallel multithreaded implementations of Quick Sort and Merge Sort using OpenMP / C++17 `std::execution::par`.
- [ ] Incorporate visualization scripts (Python / Matplotlib) plotting dynamic empirical runtime curves.
- [ ] Add string matching algorithms (KMP, Rabin-Karp, Boyer-Moore).

---

## 📜 License

Distributed under the MIT License. See [`LICENSE`](./LICENSE) for more details.

---
*Maintained by Sai Ganesh Mandhati | Marwadi University Department of Computer Engineering (AI & ML)*
