/**
 * MARWADI UNIVERSITY - DEPARTMENT OF CE (AI & ML)
 * DAA LAB (01AI0506) - PRACTICAL 06: MATRIX CHAIN MULTIPLICATION
 * Student Name: Sai Ganesh Mandhati | Roll Number: 92460118370
 */
#include <iostream>
#include <vector>
#include <climits>
#include <iomanip>

using namespace std;

void printParenthesis(int i, int j, int n, const vector<vector<int>>& bracket, char& name) {
    if (i == j) {
        cout << name++;
        return;
    }
    cout << "(";
    printParenthesis(i, bracket[i][j], n, bracket, name);
    printParenthesis(bracket[i][j] + 1, j, n, bracket, name);
    cout << ")";
}

void matrixChainOrder(const vector<int>& p, int n) {
    vector<vector<int>> m(n, vector<int>(n, 0));
    vector<vector<int>> bracket(n, vector<int>(n, 0));

    for (int L = 2; L < n; L++) {
        for (int i = 1; i < n - L + 1; i++) {
            int j = i + L - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    bracket[i][j] = k;
                }
            }
        }
    }

    cout << "\n----------------------------------------------------------------------\n";
    cout << "OPTIMAL MATRIX CHAIN MULTIPLICATION COST\n";
    cout << "----------------------------------------------------------------------\n";
    cout << "Minimum Scalar Multiplications Required: " << m[1][n - 1] << "\n";
    cout << "Optimal Parenthesization Structure  : ";
    char name = 'A';
    printParenthesis(1, n - 1, n, bracket, name);
    cout << "\n----------------------------------------------------------------------\n";
}

int main() {
    cout << "======================================================================\n";
    cout << "         MARWADI UNIVERSITY - DEPARTMENT OF CE (AI & ML)\n";
    cout << "    DESIGN AND ANALYSIS OF ALGORITHMS LABORATORY (01AI0506)\n";
    cout << "    PRACTICAL 06: MATRIX CHAIN MULTIPLICATION (DP)\n";
    cout << "======================================================================\n";
    cout << "Student Name: Sai Ganesh Mandhati\n";
    cout << "Roll Number : 92460118370\n";
    cout << "======================================================================\n\n";

    int n;
    cout << "Enter number of matrices: ";
    if (!(cin >> n) || n <= 0) return 1;

    vector<int> p(n + 1);
    cout << "Enter matrix dimension array p of size " << n + 1 << ": ";
    for (int i = 0; i <= n; ++i) cin >> p[i];

    matrixChainOrder(p, n + 1);

    cout << "\nStudent Name : Sai Ganesh Mandhati\n";
    cout << "Roll Number  : 92460118370\n";
    cout << "\n...Program finished with exit code 0\n";
    return 0;
}
