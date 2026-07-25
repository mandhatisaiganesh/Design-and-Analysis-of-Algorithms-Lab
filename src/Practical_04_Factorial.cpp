/**
 * ============================================================================
 * MARWADI UNIVERSITY - FACULTY OF ENGINEERING AND TECHNOLOGY
 * DEPARTMENT OF COMPUTER ENGINEERING (AI & ML)
 * DESIGN AND ANALYSIS OF ALGORITHMS LABORATORY (01AI0506)
 * 
 * PRACTICAL 04: Time Analysis of Factorial (Iterative vs Recursive)
 * Student Name: Sai Ganesh Mandhati
 * Roll Number  : 92460118370
 * 
 * Algorithms:
 *   1. Iterative Factorial (Linear Loop)
 *   2. Recursive Factorial (Recursion Stack)
 * 
 * Language: C++17 | Compiler: g++ (-std=c++17 -Wall -Wextra -O2)
 * ============================================================================
 */

#include <iostream>
#include <chrono>
#include <iomanip>

using namespace std;
using namespace std::chrono;

unsigned long long factorialIterative(int n, long long& operations) {
    operations = 0;
    unsigned long long result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
        operations++;
    }
    return result;
}

unsigned long long factorialRecursive(int n, long long& operations) {
    operations++;
    if (n <= 1) return 1;
    return n * factorialRecursive(n - 1, operations);
}

int main() {
    cout << "======================================================================\n";
    cout << "         MARWADI UNIVERSITY - DEPARTMENT OF CE (AI & ML)\n";
    cout << "    DESIGN AND ANALYSIS OF ALGORITHMS LABORATORY (01AI0506)\n";
    cout << "    PRACTICAL 04: FACTORIAL TIME ANALYSIS BENCHMARK\n";
    cout << "======================================================================\n";
    cout << "Student Name: Sai Ganesh Mandhati\n";
    cout << "Roll Number : 92460118370\n";
    cout << "======================================================================\n\n";

    int n;
    cout << "Enter a non-negative integer (N <= 20): ";
    if (!(cin >> n) || n < 0 || n > 20) {
        cerr << "Error: Invalid input. N must be between 0 and 20 to prevent overflow.\n";
        return 1;
    }

    // Iterative
    long long iterOps = 0;
    auto startIter = high_resolution_clock::now();
    unsigned long long iterRes = factorialIterative(n, iterOps);
    auto stopIter = high_resolution_clock::now();
    auto iterDuration = duration_cast<nanoseconds>(stopIter - startIter).count();

    // Recursive
    long long recOps = 0;
    auto startRec = high_resolution_clock::now();
    unsigned long long recRes = factorialRecursive(n, recOps);
    auto stopRec = high_resolution_clock::now();
    auto recDuration = duration_cast<nanoseconds>(stopRec - startRec).count();

    cout << "\n----------------------------------------------------------------------\n";
    cout << "FACTORIAL COMPUTATION RESULTS FOR N = " << n << "\n";
    cout << "----------------------------------------------------------------------\n";
    cout << left << setw(18) << "Method" 
         << setw(22) << "Result" 
         << setw(16) << "Time (ns)" 
         << "Operations\n";
    cout << string(68, '-') << "\n";
    cout << left << setw(18) << "Iterative" << setw(22) << iterRes << setw(16) << iterDuration << iterOps << "\n";
    cout << left << setw(18) << "Recursive" << setw(22) << recRes << setw(16) << recDuration << recOps << "\n";
    cout << string(68, '-') << "\n";

    cout << "\nStudent Name : Sai Ganesh Mandhati\n";
    cout << "Roll Number  : 92460118370\n";
    cout << "\n...Program finished with exit code 0\n";
    return 0;
}
