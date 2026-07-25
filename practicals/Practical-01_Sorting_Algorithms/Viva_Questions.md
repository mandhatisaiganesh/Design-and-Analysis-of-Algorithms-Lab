# Viva Voce Questions & Answers - Practical 01

### Q1: What is a stable sorting algorithm? Name stable and unstable algorithms from this practical.
**Answer**: A sorting algorithm is stable if it preserves the relative order of elements with equal key values from the input array.
- **Stable Algorithms**: Bubble Sort, Insertion Sort, Merge Sort.
- **Unstable Algorithms**: Selection Sort, Quick Sort.

---

### Q2: What is the main advantage of Selection Sort over Bubble Sort?
**Answer**: Selection Sort performs at most \(n - 1\) swaps (O(n) memory writes), whereas Bubble Sort can perform up to \(\mathcal{O}(n^2)\) swaps. Selection Sort is preferred when writing to memory is expensive (e.g., EEPROM flash).

---

### Q3: Why is Merge Sort preferred for sorting linked lists over Quick Sort?
**Answer**: In linked lists, inserting elements at a specific node takes \(\mathcal{O}(1)\) extra space, enabling Merge Sort to operate without \(\mathcal{O}(n)\) auxiliary array allocation. Furthermore, random access in linked lists is \(\mathcal{O}(n)\), which degrades Quick Sort partitioning performance.

---

### Q4: When does Quick Sort exhibit its worst-case time complexity of \(\mathcal{O}(n^2)\)?
**Answer**: Quick Sort exhibits \(\mathcal{O}(n^2)\) worst-case time when the selected pivot is consistently the smallest or largest element (e.g., Lomuto partition on an already sorted or reverse-sorted array without randomized pivot selection).

---

### Q5: How can Quick Sort's worst-case complexity be mitigated?
**Answer**: By using **Randomized Pivoting** (selecting a random index as pivot) or the **Median-of-Three Strategy** (choosing the median of first, middle, and last elements). Alternatively, Introsort switches to Heap Sort when recursion depth exceeds \(\mathcal{O}(\log n)\).

---

### Q6: What is an adaptive sorting algorithm?
**Answer**: An algorithm is adaptive if it takes advantage of existing order in the input sequence, achieving faster runtimes on partially sorted arrays. Examples include Insertion Sort and optimized Bubble Sort (\(\mathcal{O}(n)\) best case).

---

### Q7: State the Master Theorem recurrence for Merge Sort and solve it.
**Answer**:
\[ T(n) = 2T(n/2) + \Theta(n) \]
Here \(a = 2, b = 2, f(n) = \Theta(n)\). Since \(n^{\log_b a} = n^{\log_2 2} = n^1 = n = f(n)\), Master Theorem Case 2 applies:
\[ T(n) = \Theta(n \log n) \]

---

### Q8: What is the difference between In-place and Out-of-place sorting?
**Answer**: An in-place algorithm requires \(\mathcal{O}(1)\) auxiliary memory space beyond the stack space required for execution (e.g., Quick Sort, Bubble Sort). Out-of-place algorithms require additional auxiliary arrays proportional to input size (e.g., Merge Sort \(\mathcal{O}(n)\)).

---

### Q9: Why is Insertion Sort used inside production algorithms like Timsort?
**Answer**: Insertion Sort has very small constant factors and overhead. For small arrays (\(n \le 32\)), Insertion Sort outperforms \(\mathcal{O}(n \log n)\) algorithms like Quick Sort or Merge Sort.

---

### Q10: What is internal vs external sorting?
**Answer**: Internal sorting takes place entirely in main memory (RAM) when dataset size fits within RAM capacity. External sorting is used for massive datasets that exceed RAM capacity and reside on disk/secondary storage (e.g., External Merge Sort).
