# Algorithm - Practical 03

```text
Algorithm Heapify(A, N, i):
    largest <- i
    left <- 2 * i + 1
    right <- 2 * i + 2
    
    if left < N and A[left] > A[largest] then largest <- left
    if right < N and A[right] > A[largest] then largest <- right
    
    if largest != i then
        Swap(A[i], A[largest])
        Heapify(A, N, largest)
    end if

Algorithm HeapSort(A, N):
    // 1. Build Max Heap
    for i <- N / 2 - 1 down to 0 do
        Heapify(A, N, i)
    end for
    
    // 2. Extract Max Elements One by One
    for i <- N - 1 down to 1 do
        Swap(A[0], A[i])
        Heapify(A, i, 0)
    end for
```
