/**
 * ============================================================================
 * MARWADI UNIVERSITY - FACULTY OF ENGINEERING AND TECHNOLOGY
 * DEPARTMENT OF COMPUTER ENGINEERING (AI & ML)
 * DESIGN AND ANALYSIS OF ALGORITHMS LABORATORY (01AI0506)
 * 
 * PRACTICAL 02: Implementation and Time Analysis of Searching Algorithms
 * Student Name: Sai Ganesh Mandhati
 * Roll Number  : 92460118370
 * 
 * Algorithms:
 *   1. Linear Search (Sequential Search)
 *   2. Binary Search (Divide & Conquer / Decrease & Conquer)
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

int linearSearch(const vector<int>& arr, int target, long long& comparisons) {
    comparisons = 0;
    for (size_t i = 0; i < arr.size(); ++i) {
        comparisons++;
        if (arr[i] == target) return static_cast<int>(i);
    }
    return -1;
}

int binarySearch(const vector<int>& arr, int target, long long& comparisons) {
    comparisons = 0;
    int low = 0, high = static_cast<int>(arr.size()) - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        comparisons++;
        if (arr[mid] == target) return mid;
        if (arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int main() {
    cout << "======================================================================\n";
    cout << "         MARWADI UNIVERSITY - DEPARTMENT OF CE (AI & ML)\n";
    cout << "    DESIGN AND ANALYSIS OF ALGORITHMS LABORATORY (01AI0506)\n";
    cout << "    PRACTICAL 02: SEARCHING ALGORITHMS BENCHMARK\n";
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

    int target;
    cout << "Enter target element to search: ";
    cin >> target;

    // Linear Search (works on unsorted array)
    long long linComps = 0;
    auto startLin = high_resolution_clock::now();
    int linIdx = linearSearch(arr, target, linComps);
    auto stopLin = high_resolution_clock::now();
    auto linDuration = duration_cast<microseconds>(stopLin - startLin).count();

    // Binary Search (requires sorted array)
    vector<int> sortedArr = arr;
    sort(sortedArr.begin(), sortedArr.end());
    long long binComps = 0;
    auto startBin = high_resolution_clock::now();
    int binIdx = binarySearch(sortedArr, target, binComps);
    auto stopBin = high_resolution_clock::now();
    auto binDuration = duration_cast<microseconds>(stopBin - startBin).count();

    cout << "\n----------------------------------------------------------------------\n";
    cout << "SEARCHING BENCHMARK RESULTS FOR TARGET = " << target << "\n";
    cout << "----------------------------------------------------------------------\n";
    cout << left << setw(18) << "Algorithm" << setw(15) << "Result Index" << setw(16) << "Time (us)" << "Comparisons\n";
    cout << string(65, '-') << "\n";
    cout << left << setw(18) << "Linear Search" << setw(15) << linIdx << setw(16) << linDuration << linComps << "\n";
    cout << left << setw(18) << "Binary Search" << setw(15) << binIdx << setw(16) << binDuration << binComps << "\n";
    cout << string(65, '-') << "\n";

    cout << "\nStudent Name : Sai Ganesh Mandhati\n";
    cout << "Roll Number  : 92460118370\n";
    cout << "\n...Program finished with exit code 0\n";
    return 0;
}
