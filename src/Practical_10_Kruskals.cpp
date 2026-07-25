/**
 * ============================================================================
 * MARWADI UNIVERSITY - FACULTY OF ENGINEERING AND TECHNOLOGY
 * DEPARTMENT OF COMPUTER ENGINEERING (AI & ML)
 * DESIGN AND ANALYSIS OF ALGORITHMS LABORATORY (01AI0506)
 * 
 * PRACTICAL 10: Kruskal's Algorithm for Minimum Spanning Tree (MST)
 * Student Name: Sai Ganesh Mandhati
 * Roll Number  : 92460118370
 * 
 * Algorithm: Kruskal's MST (Greedy Paradigm using Disjoint Set Union / DSU)
 * Language: C++17 | Compiler: g++ (-std=c++17 -Wall -Wextra -O2)
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <iomanip>

using namespace std;
using namespace std::chrono;

struct Edge {
    int u, v, weight;
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

class DSU {
    vector<int> parent;
    vector<int> rank;

public:
    DSU(int n) : parent(n), rank(n, 0) {
        for (int i = 0; i < n; ++i) parent[i] = i;
    }

    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]); // Path compression
    }

    bool unite(int i, int j) {
        int rootI = find(i);
        int rootJ = find(j);
        if (rootI != rootJ) {
            if (rank[rootI] < rank[rootJ]) swap(rootI, rootJ);
            parent[rootJ] = rootI;
            if (rank[rootI] == rank[rootJ]) rank[rootI]++;
            return true;
        }
        return false;
    }
};

void kruskalsMST(int V, vector<Edge>& edges, vector<Edge>& mstEdges, int& totalWeight) {
    sort(edges.begin(), edges.end());
    DSU dsu(V);
    totalWeight = 0;

    for (const auto& edge : edges) {
        if (dsu.unite(edge.u, edge.v)) {
            mstEdges.push_back(edge);
            totalWeight += edge.weight;
            if (static_cast<int>(mstEdges.size()) == V - 1) break;
        }
    }
}

int main() {
    cout << "======================================================================\n";
    cout << "         MARWADI UNIVERSITY - DEPARTMENT OF CE (AI & ML)\n";
    cout << "    DESIGN AND ANALYSIS OF ALGORITHMS LABORATORY (01AI0506)\n";
    cout << "    PRACTICAL 10: KRUSKAL'S MINIMUM SPANNING TREE BENCHMARK\n";
    cout << "======================================================================\n";
    cout << "Student Name: Sai Ganesh Mandhati\n";
    cout << "Roll Number : 92460118370\n";
    cout << "======================================================================\n\n";

    int V, E;
    cout << "Enter number of vertices and edges: ";
    if (!(cin >> V >> E) || V <= 0) {
        cerr << "Error: Invalid graph parameters.\n";
        return 1;
    }

    vector<Edge> edges(E);
    cout << "Enter " << E << " edges (u v weight):\n";
    for (int i = 0; i < E; ++i) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }

    vector<Edge> mstEdges;
    int totalWeight = 0;

    auto start = high_resolution_clock::now();
    kruskalsMST(V, edges, mstEdges, totalWeight);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start).count();

    cout << "\n----------------------------------------------------------------------\n";
    cout << "KRUSKAL'S MINIMUM SPANNING TREE (MST) EDGES\n";
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
