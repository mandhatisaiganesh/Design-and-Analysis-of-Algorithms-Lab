/**
 * ============================================================================
 * MARWADI UNIVERSITY - FACULTY OF ENGINEERING AND TECHNOLOGY
 * DEPARTMENT OF COMPUTER ENGINEERING (AI & ML)
 * DESIGN AND ANALYSIS OF ALGORITHMS LABORATORY (01AI0506)
 * 
 * PRACTICAL 05: 0/1 Knapsack Problem using Dynamic Programming
 * Student Name: Sai Ganesh Mandhati
 * Roll Number  : 92460118370
 * 
 * Algorithm: 0/1 Knapsack (DP Bottom-up Tabulation)
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

int knapsackDP(int W, const vector<int>& wt, const vector<int>& val, int n, vector<vector<int>>& dp) {
    for (int i = 0; i <= n; ++i) {
        for (int w = 0; w <= W; ++w) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            } else if (wt[i - 1] <= w) {
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    return dp[n][W];
}

int main() {
    cout << "======================================================================\n";
    cout << "         MARWADI UNIVERSITY - DEPARTMENT OF CE (AI & ML)\n";
    cout << "    DESIGN AND ANALYSIS OF ALGORITHMS LABORATORY (01AI0506)\n";
    cout << "    PRACTICAL 05: 0/1 KNAPSACK DYNAMIC PROGRAMMING BENCHMARK\n";
    cout << "======================================================================\n";
    cout << "Student Name: Sai Ganesh Mandhati\n";
    cout << "Roll Number : 92460118370\n";
    cout << "======================================================================\n\n";

    int n, W;
    cout << "Enter the number of items: ";
    if (!(cin >> n) || n <= 0) {
        cerr << "Error: Invalid number of items.\n";
        return 1;
    }

    vector<int> val(n), wt(n);
    cout << "Enter values of " << n << " items: ";
    for (int i = 0; i < n; ++i) cin >> val[i];

    cout << "Enter weights of " << n << " items: ";
    for (int i = 0; i < n; ++i) cin >> wt[i];

    cout << "Enter maximum knapsack capacity W: ";
    cin >> W;

    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    auto start = high_resolution_clock::now();
    int maxProfit = knapsackDP(W, wt, val, n, dp);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start).count();

    cout << "\n----------------------------------------------------------------------\n";
    cout << "DP TABLE TABULATION (0/1 KNAPSACK)\n";
    cout << "----------------------------------------------------------------------\n";
    cout << setw(8) << "Item \\ W";
    for (int w = 0; w <= W; ++w) cout << setw(6) << w;
    cout << "\n" << string(10 + 6 * (W + 1), '-') << "\n";

    for (int i = 0; i <= n; ++i) {
        cout << setw(8) << ("Item " + to_string(i));
        for (int w = 0; w <= W; ++w) {
            cout << setw(6) << dp[i][w];
        }
        cout << "\n";
    }

    cout << "\nMaximum Profit Value in Knapsack = " << maxProfit << "\n";
    cout << "Execution Time                  = " << duration << " us\n";

    // Selected Items Backtracking
    cout << "\nSelected Items: ";
    int res = maxProfit;
    int w = W;
    vector<int> selectedItems;
    for (int i = n; i > 0 && res > 0; --i) {
        if (res == dp[i - 1][w]) continue;
        else {
            selectedItems.push_back(i);
            res -= val[i - 1];
            w -= wt[i - 1];
        }
    }
    reverse(selectedItems.begin(), selectedItems.end());
    cout << "[ ";
    for (size_t i = 0; i < selectedItems.size(); ++i) {
        cout << "Item " << selectedItems[i] << (i + 1 == selectedItems.size() ? "" : ", ");
    }
    cout << " ]\n";

    cout << "\nStudent Name : Sai Ganesh Mandhati\n";
    cout << "Roll Number  : 92460118370\n";
    cout << "\n...Program finished with exit code 0\n";
    return 0;
}
