/**
 * MARWADI UNIVERSITY - DEPARTMENT OF CE (AI & ML)
 * DAA LAB (01AI0506) - PRACTICAL 07: COIN CHANGE PROBLEM
 * Student Name: Sai Ganesh Mandhati | Roll Number: 92460118370
 */
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int minCoinsDP(const vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= amount; ++i) {
        for (int coin : coins) {
            if (i - coin >= 0 && dp[i - coin] != INT_MAX) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }
    return dp[amount] == INT_MAX ? -1 : dp[amount];
}

int main() {
    cout << "======================================================================\n";
    cout << "         MARWADI UNIVERSITY - DEPARTMENT OF CE (AI & ML)\n";
    cout << "    DESIGN AND ANALYSIS OF ALGORITHMS LABORATORY (01AI0506)\n";
    cout << "    PRACTICAL 07: COIN CHANGE PROBLEM (MAKING CHANGE)\n";
    cout << "======================================================================\n";
    cout << "Student Name: Sai Ganesh Mandhati\n";
    cout << "Roll Number : 92460118370\n";
    cout << "======================================================================\n\n";

    int n, amount;
    cout << "Enter number of coin denominations: ";
    if (!(cin >> n) || n <= 0) return 1;

    vector<int> coins(n);
    cout << "Enter coin denominations: ";
    for (int i = 0; i < n; ++i) cin >> coins[i];

    cout << "Enter target amount to change: ";
    cin >> amount;

    int ans = minCoinsDP(coins, amount);

    cout << "\n----------------------------------------------------------------------\n";
    cout << "MINIMUM COINS REQUIRED\n";
    cout << "----------------------------------------------------------------------\n";
    if (ans != -1) cout << "Minimum coins needed to make amount " << amount << " = " << ans << "\n";
    else cout << "Target amount " << amount << " cannot be formed using given denominations.\n";
    cout << "----------------------------------------------------------------------\n";

    cout << "\nStudent Name : Sai Ganesh Mandhati\n";
    cout << "Roll Number  : 92460118370\n";
    cout << "\n...Program finished with exit code 0\n";
    return 0;
}
