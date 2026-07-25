/**
 * ============================================================================
 * MARWADI UNIVERSITY - FACULTY OF ENGINEERING AND TECHNOLOGY
 * DEPARTMENT OF COMPUTER ENGINEERING (AI & ML)
 * DESIGN AND ANALYSIS OF ALGORITHMS LABORATORY (01AI0506)
 * 
 * PRACTICAL 07: Implementation of Coin Change Problem
 * Student Name: Sai Ganesh Mandhati
 * Roll Number  : 92460118370
 * 
 * Algorithm: Minimum Coin Change (Dynamic Programming Tabulation)
 * Language: C++17 | Compiler: g++ (-std=c++17 -Wall -Wextra -O2)
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <climits>
#include <chrono>
#include <iomanip>
#include <algorithm>

using namespace std;
using namespace std::chrono;

int coinChangeMin(const vector<int>& coins, int amount, vector<int>& dp, vector<int>& coinUsed) {
    dp.assign(amount + 1, INT_MAX);
    coinUsed.assign(amount + 1, -1);
    dp[0] = 0;

    for (int i = 1; i <= amount; ++i) {
        for (int coin : coins) {
            if (i >= coin && dp[i - coin] != INT_MAX) {
                if (dp[i - coin] + 1 < dp[i]) {
                    dp[i] = dp[i - coin] + 1;
                    coinUsed[i] = coin;
                }
            }
        }
    }

    return dp[amount] == INT_MAX ? -1 : dp[amount];
}

int main() {
    cout << "======================================================================\n";
    cout << "         MARWADI UNIVERSITY - DEPARTMENT OF CE (AI & ML)\n";
    cout << "    DESIGN AND ANALYSIS OF ALGORITHMS LABORATORY (01AI0506)\n";
    cout << "    PRACTICAL 07: COIN CHANGE PROBLEM BENCHMARK\n";
    cout << "======================================================================\n";
    cout << "Student Name: Sai Ganesh Mandhati\n";
    cout << "Roll Number : 92460118370\n";
    cout << "======================================================================\n\n";

    int n;
    cout << "Enter number of coin denominations: ";
    if (!(cin >> n) || n <= 0) {
        cerr << "Error: Invalid number of coins.\n";
        return 1;
    }

    vector<int> coins(n);
    cout << "Enter " << n << " coin denominations: ";
    for (int i = 0; i < n; ++i) cin >> coins[i];

    int amount;
    cout << "Enter target change amount: ";
    cin >> amount;

    vector<int> dp, coinUsed;
    auto start = high_resolution_clock::now();
    int minCoins = coinChangeMin(coins, amount, dp, coinUsed);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start).count();

    cout << "\n----------------------------------------------------------------------\n";
    cout << "MINIMUM COINS REQUIRED\n";
    cout << "----------------------------------------------------------------------\n";
    if (minCoins == -1) {
        cout << "Amount " << amount << " cannot be formed with given coin denominations.\n";
    } else {
        cout << "Minimum coins needed to make amount " << amount << " = " << minCoins << "\n";
        cout << "Execution Time                             = " << duration << " us\n";

        cout << "\nCoins Selected: [ ";
        int curr = amount;
        while (curr > 0) {
            cout << coinUsed[curr] << (curr - coinUsed[curr] > 0 ? ", " : "");
            curr -= coinUsed[curr];
        }
        cout << " ]\n";
    }

    cout << "\nStudent Name : Sai Ganesh Mandhati\n";
    cout << "Roll Number  : 92460118370\n";
    cout << "\n...Program finished with exit code 0\n";
    return 0;
}
