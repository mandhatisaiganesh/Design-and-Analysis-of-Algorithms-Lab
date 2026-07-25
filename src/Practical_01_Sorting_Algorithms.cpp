/**
 * ============================================================================
 * MARWADI UNIVERSITY - FACULTY OF ENGINEERING AND TECHNOLOGY
 * DEPARTMENT OF COMPUTER ENGINEERING (AI & ML)
 * DESIGN AND ANALYSIS OF ALGORITHMS (01AI0506)
 * 
 * PRACTICAL 01: Implementation and Time Analysis of Sorting Algorithms
 * Student Name: Sai Ganesh Mandhati
 * Roll Number  : 92460118370
 * 
 * Algorithms:
 *   1. Bubble Sort
 *   2. Selection Sort
 *   3. Insertion Sort
 *   4. Merge Sort
 *   5. Quick Sort
 * 
 * Language: C++17 | Compiler: g++ (-std=c++17 -Wall -Wextra -O2)
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>
#include <algorithm>

using namespace std;
using namespace std::chrono;

void printArray(const string& label, const vector<int>& arr) {
    cout << left << setw(20) << label << ": [ ";
    for (size_t i = 0; i < arr.size(); ++i) {
        cout << arr[i] << (i + 1 == arr.size() ? "" : ", ");
    }
    cout << " ]\n";
}

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

void selectionSort(vector<int>& arr, long long& comparisons, long long& swaps) {
    comparisons = 0; swaps = 0;
    size_t n = arr.size();
    for (size_t i = 0; i < n - 1; ++i) {
        size_t minIdx = i;
        for (size_t j = i + 1; j < n; ++j) {
            comparisons++;
            if (arr[j] < arr[minIdx]) minIdx = j;
        }
        if (minIdx != i) {
            swap(arr[i], arr[minIdx]);
            swaps++;
        }
    }
}

void insertionSort(vector<int>& arr, long long& comparisons, long long& shifts) {
    comparisons = 0; shifts = 0;
    size_t n = arr.size();
    for (size_t i = 1; i < n; ++i) {
        int key = arr[i];
        int j = static_cast<int>(i) - 1;
        while (j >= 0) {
            comparisons++;
            if (arr[j] > key) {
                arr[j + 1] = arr[j];
                shifts++;
                j--;
            } else break;
        }
        arr[j + 1] = key;
    }
}

void merge(vector<int>& arr, int left, int mid, int right, long long& comparisons) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; ++i) L[i] = arr[left + i];
    for (int j = 0; j < n2; ++j) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        comparisons++;
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSortHelper(vector<int>& arr, int left, int right, long long& comparisons) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSortHelper(arr, left, mid, comparisons);
        mergeSortHelper(arr, mid + 1, right, comparisons);
        merge(arr, left, mid, right, comparisons);
    }
}

void mergeSort(vector<int>& arr, long long& comparisons) {
    comparisons = 0;
    if (!arr.empty()) mergeSortHelper(arr, 0, static_cast<int>(arr.size()) - 1, comparisons);
}

int partition(vector<int>& arr, int low, int high, long long& comparisons, long long& swaps) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        comparisons++;
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
            swaps++;
        }
    }
    swap(arr[i + 1], arr[high]);
    swaps++;
    return i + 1;
}

void quickSortHelper(vector<int>& arr, int low, int high, long long& comparisons, long long& swaps) {
    if (low < high) {
        int pi = partition(arr, low, high, comparisons, swaps);
        quickSortHelper(arr, low, pi - 1, comparisons, swaps);
        quickSortHelper(arr, pi + 1, high, comparisons, swaps);
    }
}

void quickSort(vector<int>& arr, long long& comparisons, long long& swaps) {
    comparisons = 0; swaps = 0;
    if (!arr.empty()) quickSortHelper(arr, 0, static_cast<int>(arr.size()) - 1, comparisons, swaps);
}

int main() {
    cout << "======================================================================\n";
    cout << "         MARWADI UNIVERSITY - DEPARTMENT OF CE (AI & ML)\n";
    cout << "    DESIGN AND ANALYSIS OF ALGORITHMS LABORATORY (01AI0506)\n";
    cout << "    PRACTICAL 01: SORTING ALGORITHMS TIME ANALYSIS BENCHMARK\n";
    cout << "======================================================================\n";
    cout << "Student Name: Sai Ganesh Mandhati\n";
    cout << "Roll Number : 92460118370\n";
    cout << "======================================================================\n\n";

    int n;
    cout << "Enter the number of elements: ";
    if (!(cin >> n) || n <= 0) {
        cerr << "Error: Invalid array size.\n";
        return 1;
    }

    vector<int> original(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> original[i];
    }

    cout << "\n----------------------------------------------------------------------\n";
    printArray("Original Array", original);
    cout << "----------------------------------------------------------------------\n\n";

    cout << left << setw(18) << "Algorithm" 
         << setw(16) << "Time (us)" 
         << setw(18) << "Comparisons" 
         << setw(18) << "Swaps/Shifts" 
         << "Sorted Output\n";
    cout << string(85, '-') << "\n";

    // 1. Bubble Sort
    {
        vector<int> arr = original;
        long long comps = 0, swaps = 0;
        auto start = high_resolution_clock::now();
        bubbleSort(arr, comps, swaps);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start).count();
        cout << left << setw(18) << "Bubble Sort" << setw(16) << duration << setw(18) << comps << setw(18) << swaps;
        printArray("", arr);
    }

    // 2. Selection Sort
    {
        vector<int> arr = original;
        long long comps = 0, swaps = 0;
        auto start = high_resolution_clock::now();
        selectionSort(arr, comps, swaps);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start).count();
        cout << left << setw(18) << "Selection Sort" << setw(16) << duration << setw(18) << comps << setw(18) << swaps;
        printArray("", arr);
    }

    // 3. Insertion Sort
    {
        vector<int> arr = original;
        long long comps = 0, shifts = 0;
        auto start = high_resolution_clock::now();
        insertionSort(arr, comps, shifts);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start).count();
        cout << left << setw(18) << "Insertion Sort" << setw(16) << duration << setw(18) << comps << setw(18) << shifts;
        printArray("", arr);
    }

    // 4. Merge Sort
    {
        vector<int> arr = original;
        long long comps = 0;
        auto start = high_resolution_clock::now();
        mergeSort(arr, comps);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start).count();
        cout << left << setw(18) << "Merge Sort" << setw(16) << duration << setw(18) << comps << setw(18) << "N/A (Aux Memory)";
        printArray("", arr);
    }

    // 5. Quick Sort
    {
        vector<int> arr = original;
        long long comps = 0, swaps = 0;
        auto start = high_resolution_clock::now();
        quickSort(arr, comps, swaps);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start).count();
        cout << left << setw(18) << "Quick Sort" << setw(16) << duration << setw(18) << comps << setw(18) << swaps;
        printArray("", arr);
    }

    cout << string(85, '-') << "\n";
    cout << "\nStudent Name : Sai Ganesh Mandhati\n";
    cout << "Roll Number  : 92460118370\n";
    cout << "\n...Program finished with exit code 0\n";
    return 0;
}
