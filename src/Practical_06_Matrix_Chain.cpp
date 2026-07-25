/**
 * ============================================================================
 * MARWADI UNIVERSITY - FACULTY OF ENGINEERING AND TECHNOLOGY
 * DEPARTMENT OF COMPUTER ENGINEERING (AI & ML)
 * DESIGN AND ANALYSIS OF ALGORITHMS LABORATORY (01AI0506)
 * 
 * PRACTICAL 06: Matrix Chain Multiplication using Dynamic Programming
 * Student Name: Sai Ganesh Mandhati
 * Roll Number  : 92460118370
 * 
 * Algorithm: Matrix Chain Multiplication (Optimal Parenthesization DP)
 * Language: C++17 | Compiler: g++ (-std=c++17 -Wall -Wextra -O2)
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <climits>
#include <chrono>
#include <iomanip>

using namespace std;
using namespace std::chrono;

void printParenthesis(int i, int j, const vector<vector<int>>& s, char& name) {
    if (i == j) {
        cout << name++;
        return;
    }
    cout << "(";
    printParenthesis(i, s[i][j], s, name);
    printParenthesis(s[i][j] + 1, j, s, name);
    cout << ")";
}

int matrixChainOrder(const vector<int>& p, vector<vector<int>>& m, vector<vector<int>>& s) {
    int n = static_cast<int>(p.size()) - 1; // Number of matrices

    for (int i = 1; i <= n; ++i) m[i][i] = 0;

    for (int L = 2; L <= n; ++L) {
        for (int i = 1; i <= n - L + 1; ++i) {
            int j = i + L - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; ++k) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
    return m[1][n];
}

int main() {
    cout << "======================================================================\n";
    cout << "         MARWADI UNIVERSITY - DEPARTMENT OF CE (AI & ML)\n";
    cout << "    DESIGN AND ANALYSIS OF ALGORITHMS LABORATORY (01AI0506)\n";
    cout << "    PRACTICAL 06: MATRIX CHAIN MULTIPLICATION BENCHMARK\n";
    cout << "======================================================================\n";
    cout << "Student Name: Sai Ganesh Mandhati\n";
    cout << "Roll Number : 92460118370\n";
    cout << "======================================================================\n\n";

    int numMatrices;
    cout << "Enter number of matrices: ";
    if (!(cin >> numMatrices) || numMatrices <= 0) {
        cerr << "Error: Invalid number of matrices.\n";
        return 1;
    }

    vector<int> p(numMatrices + 1);
    cout << "Enter dimension array p of size " << (numMatrices + 1) << ": ";
    for (int i = 0; i <= numMatrices; ++i) cin >> p[i];

    int n = numMatrices;
    vector<vector<int>> m(n + 1, vector<int>(n + 1, 0));
    vector<vector<int>> s(n + 1, vector<int>(n + 1, 0));

    auto start = high_resolution_clock::now();
    int minCost = matrixChainOrder(p, m, s);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start).count();

    cout << "\n----------------------------------------------------------------------\n";
    cout << "OPTIMAL MATRIX CHAIN MULTIPLICATION COST\n";
    cout << "----------------------------------------------------------------------\n";
    cout << "Minimum Scalar Multiplications Required: " << minCost << "\n";
    cout << "Optimal Parenthesization Structure  : ";
    char name = 'A';
    printParenthesis(1, n, s, name);
    cout << "\nExecution Time                      : " << duration << " us\n";

    cout << "\nStudent Name : Sai Ganesh Mandhati\n";
    cout << "Roll Number  : 92460118370\n";
    cout << "\n...Program finished with exit code 0\n";
    return 0;
}
