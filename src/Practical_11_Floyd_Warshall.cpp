/**
 * ============================================================================
 * MARWADI UNIVERSITY - FACULTY OF ENGINEERING AND TECHNOLOGY
 * DEPARTMENT OF COMPUTER ENGINEERING (AI & ML)
 * DESIGN AND ANALYSIS OF ALGORITHMS LABORATORY (01AI0506)
 * 
 * PRACTICAL 11: Floyd-Warshall Algorithm (All-Pairs Shortest Path)
 * Student Name: Sai Ganesh Mandhati
 * Roll Number  : 92460118370
 * 
 * Algorithm: Floyd-Warshall All-Pairs Shortest Path (Dynamic Programming)
 * Language: C++17 | Compiler: g++ (-std=c++17 -Wall -Wextra -O2)
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <iomanip>
#include <chrono>

using namespace std;
using namespace std::chrono;

const int INF = 1e9; // Represents infinity

void floydWarshall(int V, vector<vector<int>>& dist) {
    for (int k = 0; k < V; ++k) {
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                if (dist[i][k] < INF && dist[k][j] < INF) {
                    if (dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
    }
}

int main() {
    cout << "======================================================================\n";
    cout << "         MARWADI UNIVERSITY - DEPARTMENT OF CE (AI & ML)\n";
    cout << "    DESIGN AND ANALYSIS OF ALGORITHMS LABORATORY (01AI0506)\n";
    cout << "    PRACTICAL 11: FLOYD-WARSHALL APSP BENCHMARK\n";
    cout << "======================================================================\n";
    cout << "Student Name: Sai Ganesh Mandhati\n";
    cout << "Roll Number : 92460118370\n";
    cout << "======================================================================\n\n";

    int V;
    cout << "Enter number of vertices: ";
    if (!(cin >> V) || V <= 0) {
        cerr << "Error: Invalid graph size.\n";
        return 1;
    }

    vector<vector<int>> dist(V, vector<int>(V));
    cout << "Enter adjacency matrix (" << V << "x" << V << ", use 99999 for INF):\n";
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            int val;
            cin >> val;
            dist[i][j] = (val >= 99999) ? INF : val;
        }
    }

    auto start = high_resolution_clock::now();
    floydWarshall(V, dist);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start).count();

    cout << "\n----------------------------------------------------------------------\n";
    cout << "ALL-PAIRS SHORTEST PATH MATRIX (FLOYD-WARSHALL)\n";
    cout << "----------------------------------------------------------------------\n";
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            if (dist[i][j] == INF) cout << setw(8) << "INF";
            else cout << setw(8) << dist[i][j];
        }
        cout << "\n";
    }
    cout << "----------------------------------------------------------------------\n";
    cout << "Execution Time: " << duration << " us\n";

    cout << "\nStudent Name : Sai Ganesh Mandhati\n";
    cout << "Roll Number  : 92460118370\n";
    cout << "\n...Program finished with exit code 0\n";
    return 0;
}
