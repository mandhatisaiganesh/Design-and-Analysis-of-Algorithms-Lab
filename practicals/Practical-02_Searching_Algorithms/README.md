# Practical 02: Implementation and Time Analysis of Searching Algorithms

## 📌 Aim
To implement and perform an empirical time complexity comparison between **Linear Search** and **Binary Search** in C++17.

## 🎯 Objectives
1. Understand search mechanics on unsorted vs. sorted datasets.
2. Implement Linear Search (\(\mathcal{O}(n)\)) and Binary Search (\(\mathcal{O}(\log n)\)).
3. Measure runtime performance and element comparison operations dynamically.

## 📊 Performance Comparison Matrix

| Algorithm | Paradigm | Unsorted Array Allowed? | Best Case Time | Average Case Time | Worst Case Time | Auxiliary Space |
| :--- | :--- | :---: | :---: | :---: | :---: | :---: |
| **Linear Search** | Sequential Scan | Yes | \(\mathcal{O}(1)\) | \(\mathcal{O}(n)\) | \(\mathcal{O}(n)\) | \(\mathcal{O}(1)\) |
| **Binary Search** | Decrease & Conquer | No (Must be Sorted) | \(\mathcal{O}(1)\) | \(\mathcal{O}(\log n)\) | \(\mathcal{O}(\log n)\) | \(\mathcal{O}(1)\) |

## 📁 Files Included
- `Program.cpp` – Production C++17 source code.
- `Sample_Input.txt` – Test dataset.
- `Sample_Output.txt` – Terminal output log.
- `Theory.md`, `Algorithm.md`, `Time_Complexity.md`, `Space_Complexity.md`, `Applications.md`, `Advantages.md`, `Limitations.md`, `Viva_Questions.md`, `Conclusion.md`, `References.md`.
