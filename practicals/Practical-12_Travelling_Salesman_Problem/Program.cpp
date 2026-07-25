/**
 * MARWADI UNIVERSITY - DEPARTMENT OF CE (AI & ML)
 * DAA LAB (01AI0506) - PRACTICAL 12: TRAVELLING SALESMAN PROBLEM (TSP)
 * Student Name: Sai Ganesh Mandhati | Roll Number: 92460118370
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

const int INF = 1e9;

int tspDP(int mask, int pos, int n, const vector<vector<int>>& dist, vector<vector<int>>& memo) {
    if (mask == (1 << n) - 1) return dist[pos][0];
    if (memo[mask][pos] != -1) return memo[mask][pos];

    int ans = INF;
    for (int city = 0; city < n; ++city) {
        if ((mask & (1 << city)) == 0) {
            int newCost = dist[pos][city] + tspDP(mask | (1 << city), city, n, dist, memo);
            ans = min(ans, newCost);
        }
    }
    return memo[mask][pos] = ans;
}

int main() {
    cout << "======================================================================\n";
    cout << "         MARWADI UNIVERSITY - DEPARTMENT OF CE (AI & ML)\n";
    cout << "    DESIGN AND ANALYSIS OF ALGORITHMS LABORATORY (01AI0506)\n";
    cout << "    PRACTICAL 12: TRAVELLING SALESMAN PROBLEM (TSP DP & BITMASKING)\n";
    cout << "======================================================================\n";
    cout << "Student Name: Sai Ganesh Mandhati\n";
    cout << "Roll Number : 92460118370\n";
    cout << "======================================================================\n\n";

    int n = 4;
    vector<vector<int>> dist = {
        {0, 20, 42, 25},
        {20, 0, 30, 34},
        {42, 30, 0, 10},
        {25, 34, 10, 0}
    };

    vector<vector<int>> memo(1 << n, vector<int>(n, -1));
    int minCost = tspDP(1, 0, n, dist, memo);

    cout << "----------------------------------------------------------------------\n";
    cout << "TRAVELLING SALESMAN PROBLEM OPTIMAL TOUR COST\n";
    cout << "----------------------------------------------------------------------\n";
    cout << "Minimum Cost to Visit All Cities and Return to Start = " << minCost << "\n";
    cout << "----------------------------------------------------------------------\n";

    cout << "\nStudent Name : Sai Ganesh Mandhati\n";
    cout << "Roll Number  : 92460118370\n";
    cout << "\n...Program finished with exit code 0\n";
    return 0;
}
