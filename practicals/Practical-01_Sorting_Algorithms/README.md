# Practical 01: Implementation and Time Analysis of Sorting Algorithms

## 📌 Aim
To implement and perform an empirical time complexity analysis of five fundamental sorting algorithms: **Bubble Sort**, **Selection Sort**, **Insertion Sort**, **Merge Sort**, and **Quick Sort** in C++17.

## 🎯 Objectives
1. Implement standard comparison-based sorting algorithms using modular C++ functions.
2. Measure dynamic execution runtime in microseconds (\(\mu s\)) using high-resolution timers (`std::chrono`).
3. Count exact element comparison and swap/shift operations for each algorithm.
4. Compare performance metrics across best, average, and worst-case input distributions.

## 🛠️ Quick Start & Execution

### Compilation
```bash
g++ -std=c++17 -Wall -Wextra -O2 Program.cpp -o Program
```

### Execution
```bash
# Interactive mode
./Program

# Automated execution with test input
./Program < Sample_Input.txt
```

## 📊 Summary of Experimental Results

| Algorithm | Paradigm | Input Size (\(N\)) | Measured Time (\(\mu s\)) | Comparisons | Swaps / Shifts |
| :--- | :--- | :---: | :---: | :---: | :---: |
| **Bubble Sort** | Brute Force | 10 | 0 | 39 | 20 |
| **Selection Sort** | Brute Force | 10 | 0 | 45 | 6 |
| **Insertion Sort** | Incremental | 10 | 0 | 25 | 20 |
| **Merge Sort** | Divide & Conquer | 10 | 3 | 21 | N/A (Aux Array) |
| **Quick Sort** | Divide & Conquer | 10 | 0 | 26 | 25 |

## 📁 File Structure
- `Program.cpp`: Production C++17 benchmark source code.
- `Theory.md`: In-depth theoretical concepts & mathematical foundations.
- `Algorithm.md`: Step-by-step pseudocode and flow diagrams.
- `Sample_Input.txt`: Test input dataset.
- `Sample_Output.txt`: Verified execution console log.
- `Time_Complexity.md`: Asymptotic notation derivations.
- `Space_Complexity.md`: Memory bounds and stack frame analysis.
- `Applications.md`: Real-world engineering applications.
- `Advantages.md`: Strengths of each sorting method.
- `Limitations.md`: Bottlenecks and edge cases.
- `Viva_Questions.md`: 10 Viva Voce questions with detailed answers.
- `Conclusion.md`: Summary of findings.
- `References.md`: Academic textbook citations.
