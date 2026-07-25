/**
 * MARWADI UNIVERSITY - DEPARTMENT OF CE (AI & ML)
 * DAA LAB (01AI0506) - PRACTICAL 09: PRIM'S ALGORITHM
 * Student Name: Sai Ganesh Mandhati | Roll Number: 92460118370
 */
#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> pii; // {weight, vertex}

void primMST(int V, const vector<vector<pii>>& adj) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<int> key(V, INT_MAX);
    vector<int> parent(V, -1);
    vector<bool> inMST(V, false);

    key[0] = 0;
    pq.push({0, 0});

    int totalWeight = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (inMST[u]) continue;
        inMST[u] = true;
        totalWeight += key[u];

        for (auto& edge : adj[u]) {
            int v = edge.second;
            int weight = edge.first;
            if (!inMST[v] && weight < key[v]) {
                key[v] = weight;
                pq.push({key[v], v});
                parent[v] = u;
            }
        }
    }

    cout << "\n----------------------------------------------------------------------\n";
    cout << "PRIM'S MINIMUM SPANNING TREE (MST) EDGES\n";
    cout << "----------------------------------------------------------------------\n";
    for (int i = 1; i < V; ++i) {
        cout << "Edge: " << parent[i] << " - " << i << " | Weight: " << key[i] << "\n";
    }
    cout << "----------------------------------------------------------------------\n";
    cout << "Total Minimum Spanning Tree Weight = " << totalWeight << "\n";
    cout << "----------------------------------------------------------------------\n";
}

int main() {
    cout << "======================================================================\n";
    cout << "         MARWADI UNIVERSITY - DEPARTMENT OF CE (AI & ML)\n";
    cout << "    DESIGN AND ANALYSIS OF ALGORITHMS LABORATORY (01AI0506)\n";
    cout << "    PRACTICAL 09: PRIM'S MINIMUM SPANNING TREE ALGORITHM\n";
    cout << "======================================================================\n";
    cout << "Student Name: Sai Ganesh Mandhati\n";
    cout << "Roll Number : 92460118370\n";
    cout << "======================================================================\n\n";

    int V, E;
    cout << "Enter number of vertices V and edges E: ";
    if (!(cin >> V >> E) || V <= 0) return 1;

    vector<vector<pii>> adj(V);
    cout << "Enter " << E << " weighted edges (u v weight):\n";
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }

    primMST(V, adj);

    cout << "\nStudent Name : Sai Ganesh Mandhati\n";
    cout << "Roll Number  : 92460118370\n";
    cout << "\n...Program finished with exit code 0\n";
    return 0;
}
