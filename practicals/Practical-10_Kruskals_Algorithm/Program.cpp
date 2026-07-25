/**
 * MARWADI UNIVERSITY - DEPARTMENT OF CE (AI & ML)
 * DAA LAB (01AI0506) - PRACTICAL 10: KRUSKAL'S ALGORITHM
 * Student Name: Sai Ganesh Mandhati | Roll Number: 92460118370
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, weight;
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

struct DSU {
    vector<int> parent, rank;
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i) parent[i] = i;
    }
    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }
    bool unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            if (rank[root_i] < rank[root_j]) swap(root_i, root_j);
            parent[root_j] = root_i;
            if (rank[root_i] == rank[root_j]) rank[root_i]++;
            return true;
        }
        return false;
    }
};

int main() {
    cout << "======================================================================\n";
    cout << "         MARWADI UNIVERSITY - DEPARTMENT OF CE (AI & ML)\n";
    cout << "    DESIGN AND ANALYSIS OF ALGORITHMS LABORATORY (01AI0506)\n";
    cout << "    PRACTICAL 10: KRUSKAL'S MINIMUM SPANNING TREE ALGORITHM\n";
    cout << "======================================================================\n";
    cout << "Student Name: Sai Ganesh Mandhati\n";
    cout << "Roll Number : 92460118370\n";
    cout << "======================================================================\n\n";

    int V, E;
    cout << "Enter number of vertices V and edges E: ";
    if (!(cin >> V >> E) || V <= 0) return 1;

    vector<Edge> edges(E);
    cout << "Enter " << E << " weighted edges (u v weight):\n";
    for (int i = 0; i < E; ++i) cin >> edges[i].u >> edges[i].v >> edges[i].weight;

    sort(edges.begin(), edges.end());

    DSU dsu(V);
    int totalWeight = 0;

    cout << "\n----------------------------------------------------------------------\n";
    cout << "KRUSKAL'S MINIMUM SPANNING TREE (MST) EDGES\n";
    cout << "----------------------------------------------------------------------\n";
    for (const auto& edge : edges) {
        if (dsu.unite(edge.u, edge.v)) {
            cout << "Edge: " << edge.u << " - " << edge.v << " | Weight: " << edge.weight << "\n";
            totalWeight += edge.weight;
        }
    }
    cout << "----------------------------------------------------------------------\n";
    cout << "Total Minimum Spanning Tree Weight = " << totalWeight << "\n";
    cout << "----------------------------------------------------------------------\n";

    cout << "\nStudent Name : Sai Ganesh Mandhati\n";
    cout << "Roll Number  : 92460118370\n";
    cout << "\n...Program finished with exit code 0\n";
    return 0;
}
