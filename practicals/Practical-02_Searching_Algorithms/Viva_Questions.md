# Viva Questions - Practical 02

### Q1: What is the main prerequisite for performing Binary Search?
**Answer**: The array or dataset must be sorted in a defined monotonic order (ascending or descending).

### Q2: Why do we use `low + (high - low) / 2` instead of `(low + high) / 2`?
**Answer**: `(low + high)` can cause integer overflow when `low` and `high` are large positive integers close to `INT_MAX`.

### Q3: How many comparisons does Binary Search take for an array of 1,000,000 elements in worst case?
**Answer**: \(\lceil \log_2(1,000,000) \rceil + 1 = 20\) comparisons.

### Q4: Can Binary Search be applied to a Singly Linked List effectively?
**Answer**: No, because accessing the middle element in a linked list requires traversing nodes sequentially in \(\mathcal{O}(n)\) time, nullifying the \(\mathcal{O}(\log n)\) benefit.

### Q5: What is the time complexity of Linear Search in best case?
**Answer**: \(\mathcal{O}(1)\) when the target element is present at the very first index (`A[0]`).

### Q6: Under what condition is Linear Search better than Binary Search?
**Answer**: When the input dataset is unsorted and small, or when searching a dataset once (since sorting takes \(\mathcal{O}(n \log n)\)).

### Q7: What standard C++ STL functions implement Binary Search?
**Answer**: `std::binary_search`, `std::lower_bound`, and `std::upper_bound` in `<algorithm>`.

### Q8: What algorithmic design paradigm does Binary Search belong to?
**Answer**: **Decrease and Conquer** (specifically by a constant factor of 2).

### Q9: What is ternary search and how does its time complexity compare to binary search?
**Answer**: Ternary search divides the search space into 3 equal parts. Its recurrence is \(T(n) = T(n/3) + \mathcal{O}(1)\), resulting in \(\mathcal{O}(\log_3 n)\). Although it does fewer recursive steps, it makes 2 comparisons per step, leading to more comparisons overall than binary search.

### Q10: What is Binary Search on Answer?
**Answer**: A technique where instead of searching an array, we binary search over a range of potential values to find the optimal solution to a monotonic decision problem.
