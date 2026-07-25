# Pseudocode & Flow Explanation - Practical 01

## 1. Bubble Sort

### Pseudocode
```text
Algorithm BubbleSort(A, N):
    Input: Array A of N elements
    Output: Sorted Array A in ascending order

    for i <- 0 to N - 2 do
        swapped <- false
        for j <- 0 to N - i - 2 do
            if A[j] > A[j + 1] then
                Swap(A[j], A[j + 1])
                swapped <- true
            end if
        end for
        if swapped = false then
            break // Array is already sorted
        end if
    end for
```

---

## 2. Selection Sort

### Pseudocode
```text
Algorithm SelectionSort(A, N):
    Input: Array A of N elements
    Output: Sorted Array A in ascending order

    for i <- 0 to N - 2 do
        min_index <- i
        for j <- i + 1 to N - 1 do
            if A[j] < A[min_index] then
                min_index <- j
            end if
        end for
        if min_index != i then
            Swap(A[i], A[min_index])
        end if
    end for
```

---

## 3. Insertion Sort

### Pseudocode
```text
Algorithm InsertionSort(A, N):
    Input: Array A of N elements
    Output: Sorted Array A in ascending order

    for i <- 1 to N - 1 do
        key <- A[i]
        j <- i - 1
        while j >= 0 and A[j] > key do
            A[j + 1] <- A[j]
            j <- j - 1
        end while
        A[j + 1] <- key
    end for
```

---

## 4. Merge Sort

### Pseudocode
```text
Algorithm MergeSort(A, low, high):
    if low < high then
        mid <- low + (high - low) / 2
        MergeSort(A, low, mid)
        MergeSort(A, mid + 1, high)
        Merge(A, low, mid, high)
    end if

Algorithm Merge(A, low, mid, high):
    n1 <- mid - low + 1
    n2 <- high - mid
    Create sub-arrays L[0..n1-1] and R[0..n2-1]
    
    Copy A[low..mid] to L and A[mid+1..high] to R
    
    i <- 0, j <- 0, k <- low
    while i < n1 and j < n2 do
        if L[i] <= R[j] then
            A[k] <- L[i]; i <- i + 1
        else
            A[k] <- R[j]; j <- j + 1
        end if
        k <- k + 1
    end while

    Copy remaining elements of L and R if any.
```

---

## 5. Quick Sort (Lomuto Partition)

### Pseudocode
```text
Algorithm QuickSort(A, low, high):
    if low < high then
        pi <- Partition(A, low, high)
        QuickSort(A, low, pi - 1)
        QuickSort(A, pi + 1, high)
    end if

Algorithm Partition(A, low, high):
    pivot <- A[high]
    i <- low - 1
    for j <- low to high - 1 do
        if A[j] < pivot then
            i <- i + 1
            Swap(A[i], A[j])
        end if
    end for
    Swap(A[i + 1], A[high])
    return i + 1
```
