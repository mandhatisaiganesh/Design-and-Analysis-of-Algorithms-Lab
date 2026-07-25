/**
 * ============================================================================
 * MARWADI UNIVERSITY - FACULTY OF ENGINEERING AND TECHNOLOGY
 * DEPARTMENT OF COMPUTER ENGINEERING (AI & ML)
 * DESIGN AND ANALYSIS OF ALGORITHMS LABORATORY (01AI0506)
 * 
 * PRACTICAL 03: Implementation of Max Heap Sort
 * Student Name: Sai Ganesh Mandhati
 * Roll Number  : 92460118370
 * 
 * Language: C++17 | Compiler: g++ (-std=c++17 -Wall -Wextra -O2)
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>

using namespace std;
using namespace std::chrono;

void heapify(vector<int>& arr, int n, int i, long long& comparisons, long long& swaps) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n) {
        comparisons++;
        if (arr[left] > arr[largest]) largest = left;
    }

    if (right < n) {
        comparisons++;
        if (arr[right] > arr[largest]) largest = right;
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);
        swaps++;
        heapify(arr, n, largest, comparisons, swaps);
    }
}

void heapSort(vector<int>& arr, long long& comparisons, long long& swaps) {
    comparisons = 0; swaps = 0;
    int n = static_cast<int>(arr.size());

    // Build Max-Heap
    for (int i = n / 2 - 1; i >= 0; --i) {
        heapify(arr, n, i, comparisons, swaps);
    }

    // Extract elements from heap one by one
    for (int i = n - 1; i > 0; --i) {
        swap(arr[0], arr[i]);
        swaps++;
        heapify(arr, i, 0, comparisons, swaps);
    }
}

void printArray(const vector<int>& arr) {
    cout << "[ ";
    for (size_t i = 0; i < arr.size(); ++i) {
        cout << arr[i] << (i + 1 == arr.size() ? "" : ", ");
    }
    cout << " ]\n";
}

int main() {
    cout << "======================================================================\n";
    cout << "         MARWADI UNIVERSITY - DEPARTMENT OF CE (AI & ML)\n";
    cout << "    DESIGN AND ANALYSIS OF ALGORITHMS LABORATORY (01AI0506)\n";
    cout << "    PRACTICAL 03: MAX HEAP SORT IMPLEMENTATION\n";
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

    vector<int> arr(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; ++i) cin >> arr[i];

    cout << "\nOriginal Array: ";
    printArray(arr);

    long long comparisons = 0, swaps = 0;
    auto start = high_resolution_clock::now();
    heapSort(arr, comparisons, swaps);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start).count();

    cout << "\nSorted Array (Max Heap Sort): ";
    printArray(arr);

    cout << "\n----------------------------------------------------------------------\n";
    cout << "HEAP SORT PERFORMANCE METRICS\n";
    cout << "----------------------------------------------------------------------\n";
    cout << "Execution Time : " << duration << " us\n";
    cout << "Comparisons    : " << comparisons << "\n";
    cout << "Swaps          : " << swaps << "\n";
    cout << "----------------------------------------------------------------------\n";

    cout << "\nStudent Name : Sai Ganesh Mandhati\n";
    cout << "Roll Number  : 92460118370\n";
    cout << "\n...Program finished with exit code 0\n";
    return 0;
}
