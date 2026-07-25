/**
 * MARWADI UNIVERSITY - DEPARTMENT OF CE (AI & ML)
 * DAA LAB (01AI0506) - PRACTICAL 05: 0/1 KNAPSACK USING DP
 * Student Name: Sai Ganesh Mandhati | Roll Number: 92460118370
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int knapsackDP(int W, const vector<int>& wt, const vector<int>& val, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int w = 0; w <= W; ++w) {
            if (wt[i - 1] <= w)
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    cout << "\n----------------------------------------------------------------------\n";
    cout << "DP TABLE TABULATION (0/1 KNAPSACK)\n";
    cout << "----------------------------------------------------------------------\n";
    for (int i = 0; i <= n; ++i) {
        cout << "Item " << setw(2) << i << " | ";
        for (int w = 0; w <= W; ++w) {
            cout << setw(4) << dp[i][w] << " ";
        }
        cout << "\n";
    }
    return dp[n][W];
}

int main() {
    cout << "======================================================================\n";
    cout << "         MARWADI UNIVERSITY - DEPARTMENT OF CE (AI & ML)\n";
    cout << "    DESIGN AND ANALYSIS OF ALGORITHMS LABORATORY (01AI0506)\n";
    cout << "    PRACTICAL 05: 0/1 KNAPSACK DYNAMIC PROGRAMMING\n";
    cout << "======================================================================\n";
    cout << "Student Name: Sai Ganesh Mandhati\n";
    cout << "Roll Number : 92460118370\n";
    cout << "======================================================================\n\n";

    int n, W;
    cout << "Enter number of items: ";
    if (!(cin >> n) || n <= 0) return 1;
    cout << "Enter Knapsack Capacity W: ";
    cin >> W;

    vector<int> val(n), wt(n);
    cout << "Enter values of " << n << " items: ";
    for (int i = 0; i < n; ++i) cin >> val[i];
    cout << "Enter weights of " << n << " items: ";
    for (int i = 0; i < n; ++i) cin >> wt[i];

    int maxVal = knapsackDP(W, wt, val, n);

    cout << "\n----------------------------------------------------------------------\n";
    cout << "Maximum Profit Value in Knapsack = " << maxVal << "\n";
    cout << "----------------------------------------------------------------------\n";

    cout << "\nStudent Name : Sai Ganesh Mandhati\n";
    cout << "Roll Number  : 92460118370\n";
    cout << "\n...Program finished with exit code 0\n";
    return 0;
}
