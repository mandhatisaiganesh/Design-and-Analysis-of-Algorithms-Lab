/**
 * ============================================================================
 * MARWADI UNIVERSITY - FACULTY OF ENGINEERING AND TECHNOLOGY
 * DEPARTMENT OF COMPUTER ENGINEERING (AI & ML)
 * DESIGN AND ANALYSIS OF ALGORITHMS LABORATORY (01AI0506)
 * 
 * PRACTICAL 09: Prim's Algorithm for Minimum Spanning Tree (MST)
 * Student Name: Sai Ganesh Mandhati
 * Roll Number  : 92460118370
 * 
 * Algorithm: Prim's MST (Greedy Paradigm using Priority Queue / Min-Heap)
 * Language: C++17 | Compiler: g++ (-std=c++17 -Wall -Wextra -O2)
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <chrono>
#include <iomanip>

using namespace std;
using namespace std::chrono;

typedef pair<int, int> pii; // {weight, vertex}

struct Edge {
    int u, v, weight;
};

void primsMST(int V, const vector<vector<pii>>& adj, vector<Edge>& mstEdges, int& totalWeight) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<int> key(V, INT_MAX);
    vector<int> parent(V, -1);
    vector<bool> inMST(V, false);

    int startNode = 0;
    pq.push({0, startNode});
    key[startNode] = 0;

    totalWeight = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (inMST[u]) continue;
        inMST[u] = true;

        if (parent[u] != -1) {
            mstEdges.push_back({parent[u], u, key[u]});
            totalWeight += key[u];
        }

        for (auto& edge : adj[u]) {
            int v = edge.second;
            int weight = edge.first;

            if (!inMST[v] && key[v] > weight) {
                key[v] = weight;
                pq.push({key[v], v});
                parent[v] = u;
            }
        }
    }
}

int main() {
    cout << "======================================================================\n";
    cout << "         MARWADI UNIVERSITY - DEPARTMENT OF CE (AI & ML)\n";
    cout << "    DESIGN AND ANALYSIS OF ALGORITHMS LABORATORY (01AI0506)\n";
    cout << "    PRACTICAL 09: PRIM'S MINIMUM SPANNING TREE BENCHMARK\n";
    cout << "======================================================================\n";
    cout << "Student Name: Sai Ganesh Mandhati\n";
    cout << "Roll Number : 92460118370\n";
    cout << "======================================================================\n\n";

    int V, E;
    cout << "Enter number of vertices and edges: ";
    if (!(cin >> V >> E) || V <= 0) {
        cerr << "Error: Invalid graph size.\n";
        return 1;
    }

    vector<vector<pii>> adj(V);
    cout << "Enter " << E << " edges (u v weight):\n";
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }

    vector<Edge> mstEdges;
    int totalWeight = 0;

    auto start = high_resolution_clock::now();
    primsMST(V, adj, mstEdges, totalWeight);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start).count();

    cout << "\n----------------------------------------------------------------------\n";
    cout << "PRIM'S MINIMUM SPANNING TREE (MST) EDGES\n";
    cout << "----------------------------------------------------------------------\n";
    for (const auto& edge : mstEdges) {
        cout << "Edge: " << edge.u << " - " << edge.v << " | Weight: " << edge.weight << "\n";
    }
    cout << "----------------------------------------------------------------------\n";
    cout << "Total Minimum Spanning Tree Weight = " << totalWeight << "\n";
    cout << "Execution Time                     = " << duration << " us\n";

    cout << "\nStudent Name : Sai Ganesh Mandhati\n";
    cout << "Roll Number  : 92460118370\n";
    cout << "\n...Program finished with exit code 0\n";
    return 0;
}
