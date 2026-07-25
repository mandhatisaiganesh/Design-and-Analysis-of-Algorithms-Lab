# Algorithm - Practical 02

## 1. Linear Search Pseudocode
```text
Algorithm LinearSearch(A, N, target):
    for i <- 0 to N - 1 do
        if A[i] = target then
            return i
        end if
    end for
    return -1
```

## 2. Binary Search Pseudocode
```text
Algorithm BinarySearch(A, N, target):
    low <- 0
    high <- N - 1
    while low <= high do
        mid <- low + (high - low) / 2
        if A[mid] = target then
            return mid
        else if A[mid] < target then
            low <- mid + 1
        else
            high <- mid - 1
        end if
    end while
    return -1
```
