/**
 * ============================================================================
 * MARWADI UNIVERSITY - FACULTY OF ENGINEERING AND TECHNOLOGY
 * DEPARTMENT OF COMPUTER ENGINEERING (AI & ML)
 * DESIGN AND ANALYSIS OF ALGORITHMS LABORATORY (01AI0506)
 * 
 * PRACTICAL 12: Travelling Salesman Problem (Held-Karp Bitmask DP)
 * Student Name: Sai Ganesh Mandhati
 * Roll Number  : 92460118370
 * 
 * Algorithm: Travelling Salesman Problem (Held-Karp Dynamic Programming with Bitmasking)
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

const int INF = 1e9;

int tspBitmask(int mask, int pos, int N, const vector<vector<int>>& dist, vector<vector<int>>& dp, vector<vector<int>>& parent) {
    if (mask == (1 << N) - 1) {
        return dist[pos][0]; // Return to starting city 0
    }

    if (dp[mask][pos] != -1) return dp[mask][pos];

    int ans = INF;
    int bestNext = -1;

    for (int city = 0; city < N; ++city) {
        if ((mask & (1 << city)) == 0) {
            int newCost = dist[pos][city] + tspBitmask(mask | (1 << city), city, N, dist, dp, parent);
            if (newCost < ans) {
                ans = newCost;
                bestNext = city;
            }
        }
    }

    parent[mask][pos] = bestNext;
    return dp[mask][pos] = ans;
}

int main() {
    cout << "======================================================================\n";
    cout << "         MARWADI UNIVERSITY - DEPARTMENT OF CE (AI & ML)\n";
    cout << "    DESIGN AND ANALYSIS OF ALGORITHMS LABORATORY (01AI0506)\n";
    cout << "    PRACTICAL 12: TRAVELLING SALESMAN PROBLEM (BITMASK DP) BENCHMARK\n";
    cout << "======================================================================\n";
    cout << "Student Name: Sai Ganesh Mandhati\n";
    cout << "Roll Number : 92460118370\n";
    cout << "======================================================================\n\n";

    int N;
    cout << "Enter number of cities (N <= 16): ";
    if (!(cin >> N) || N <= 0 || N > 16) {
        cerr << "Error: Invalid number of cities. N must be between 1 and 16.\n";
        return 1;
    }

    vector<vector<int>> dist(N, vector<int>(N));
    cout << "Enter " << N << "x" << N << " distance matrix:\n";
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> dist[i][j];
        }
    }

    vector<vector<int>> dp(1 << N, vector<int>(N, -1));
    vector<vector<int>> parent(1 << N, vector<int>(N, -1));

    auto start = high_resolution_clock::now();
    int minCost = tspBitmask(1, 0, N, dist, dp, parent);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start).count();

    cout << "\n----------------------------------------------------------------------\n";
    cout << "TRAVELLING SALESMAN PROBLEM OPTIMAL TOUR COST\n";
    cout << "----------------------------------------------------------------------\n";
    cout << "Minimum Cost to Visit All Cities and Return to Start = " << minCost << "\n";
    cout << "Execution Time                                       = " << duration << " us\n";

    // Reconstruct tour path
    cout << "\nOptimal Tour Path: 0";
    int mask = 1;
    int curr = 0;
    while (curr != -1) {
        int nextCity = parent[mask][curr];
        if (nextCity != -1) {
            cout << " -> " << nextCity;
            mask |= (1 << nextCity);
        }
        curr = nextCity;
    }
    cout << " -> 0\n";

    cout << "\nStudent Name : Sai Ganesh Mandhati\n";
    cout << "Roll Number  : 92460118370\n";
    cout << "\n...Program finished with exit code 0\n";
    return 0;
}
