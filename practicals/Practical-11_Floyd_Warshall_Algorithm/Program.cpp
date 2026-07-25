/**
 * MARWADI UNIVERSITY - DEPARTMENT OF CE (AI & ML)
 * DAA LAB (01AI0506) - PRACTICAL 11: FLOYD-WARSHALL ALGORITHM
 * Student Name: Sai Ganesh Mandhati | Roll Number: 92460118370
 */
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

const int INF = 1e9;

void floydWarshall(vector<vector<int>>& dist, int V) {
    for (int k = 0; k < V; ++k) {
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                if (dist[i][k] < INF && dist[k][j] < INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
}

int main() {
    cout << "======================================================================\n";
    cout << "         MARWADI UNIVERSITY - DEPARTMENT OF CE (AI & ML)\n";
    cout << "    DESIGN AND ANALYSIS OF ALGORITHMS LABORATORY (01AI0506)\n";
    cout << "    PRACTICAL 11: FLOYD-WARSHALL ALL-PAIRS SHORTEST PATH\n";
    cout << "======================================================================\n";
    cout << "Student Name: Sai Ganesh Mandhati\n";
    cout << "Roll Number : 92460118370\n";
    cout << "======================================================================\n\n";

    int V = 4;
    vector<vector<int>> dist = {
        {0, 5, INF, 10},
        {INF, 0, 3, INF},
        {INF, INF, 0, 1},
        {INF, INF, INF, 0}
    };

    floydWarshall(dist, V);

    cout << "----------------------------------------------------------------------\n";
    cout << "ALL-PAIRS SHORTEST PATH MATRIX (FLOYD-WARSHALL)\n";
    cout << "----------------------------------------------------------------------\n";
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            if (dist[i][j] == INF) cout << setw(7) << "INF";
            else cout << setw(7) << dist[i][j];
        }
        cout << "\n";
    }
    cout << "----------------------------------------------------------------------\n";

    cout << "\nStudent Name : Sai Ganesh Mandhati\n";
    cout << "Roll Number  : 92460118370\n";
    cout << "\n...Program finished with exit code 0\n";
    return 0;
}
