# Viva Questions - Practical 03

### Q1: What is a Max Heap?
**Answer**: A complete binary tree where every node's value is greater than or equal to the values of its children (\(A[\text{parent}(i)] \ge A[i]\)).

### Q2: What is the array index formula for left child, right child, and parent of index `i`?
**Answer**:
- Left Child: `2*i + 1`
- Right Child: `2*i + 2`
- Parent: `(i - 1) / 2`

### Q3: What is the time complexity of `buildMaxHeap()`?
**Answer**: \(\mathcal{O}(n)\).

### Q4: Why is Heap Sort not stable?
**Answer**: Swapping root elements with distant leaf nodes disrupts the original relative position of duplicate values.

### Q5: What is the height of a binary heap with \(n\) elements?
**Answer**: \(\lfloor \log_2 n \rfloor\).

### Q6: How does Heap Sort compare with Quick Sort?
**Answer**: Heap Sort guarantees \(\mathcal{O}(n \log n)\) worst-case time and \(\mathcal{O}(1)\) space, whereas Quick Sort is faster on average due to better CPU cache locality.

### Q7: What data structure is built on top of Heaps?
**Answer**: Priority Queues.

### Q8: What is a Min Heap?
**Answer**: A binary heap where every parent node is less than or equal to its children (\(A[\text{parent}(i)] \le A[i]\)).

### Q9: Where are leaves located in an array representation of a heap of size \(n\)?
**Answer**: From index \(\lfloor n/2 \rfloor\) to \(n - 1\).

### Q10: What is Introsort?
**Answer**: A hybrid sorting algorithm that starts with Quick Sort and switches to Heap Sort when the recursion depth exceeds \(\mathcal{O}(\log n)\).
