/**
 * MARWADI UNIVERSITY - DEPARTMENT OF CE (AI & ML)
 * DAA LAB (01AI0506) - PRACTICAL 04: FACTORIAL TIME ANALYSIS
 * Student Name: Sai Ganesh Mandhati | Roll Number: 92460118370
 */
#include <iostream>
#include <chrono>
#include <iomanip>

using namespace std;
using namespace std::chrono;

unsigned long long factorialIterative(int n, long long& ops) {
    ops = 0;
    unsigned long long fact = 1;
    for (int i = 1; i <= n; ++i) {
        ops++;
        fact *= i;
    }
    return fact;
}

unsigned long long factorialRecursive(int n, long long& ops) {
    ops++;
    if (n <= 1) return 1;
    return n * factorialRecursive(n - 1, ops);
}

int main() {
    cout << "======================================================================\n";
    cout << "         MARWADI UNIVERSITY - DEPARTMENT OF CE (AI & ML)\n";
    cout << "    DESIGN AND ANALYSIS OF ALGORITHMS LABORATORY (01AI0506)\n";
    cout << "    PRACTICAL 04: FACTORIAL TIME ANALYSIS (ITERATIVE VS RECURSIVE)\n";
    cout << "======================================================================\n";
    cout << "Student Name: Sai Ganesh Mandhati\n";
    cout << "Roll Number : 92460118370\n";
    cout << "======================================================================\n\n";

    int n;
    cout << "Enter a positive integer n: ";
    if (!(cin >> n) || n < 0 || n > 20) {
        cerr << "Error: Invalid input (0 <= n <= 20).\n";
        return 1;
    }

    long long iterOps = 0, recOps = 0;
    auto t1 = high_resolution_clock::now();
    unsigned long long iterResult = factorialIterative(n, iterOps);
    auto t2 = high_resolution_clock::now();
    auto iterTime = duration_cast<nanoseconds>(t2 - t1).count();

    auto t3 = high_resolution_clock::now();
    unsigned long long recResult = factorialRecursive(n, recOps);
    auto t4 = high_resolution_clock::now();
    auto recTime = duration_cast<nanoseconds>(t4 - t3).count();

    cout << "\n----------------------------------------------------------------------\n";
    cout << "FACTORIAL COMPUTATION RESULTS FOR N = " << n << "\n";
    cout << "----------------------------------------------------------------------\n";
    cout << left << setw(18) << "Method" << setw(22) << "Result" << setw(16) << "Time (ns)" << "Operations\n";
    cout << string(70, '-') << "\n";
    cout << left << setw(18) << "Iterative" << setw(22) << iterResult << setw(16) << iterTime << iterOps << "\n";
    cout << left << setw(18) << "Recursive" << setw(22) << recResult << setw(16) << recTime << recOps << "\n";
    cout << string(70, '-') << "\n";

    cout << "\nStudent Name : Sai Ganesh Mandhati\n";
    cout << "Roll Number  : 92460118370\n";
    cout << "\n...Program finished with exit code 0\n";
    return 0;
}
