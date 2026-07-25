/**
 * MARWADI UNIVERSITY - DEPARTMENT OF CE (AI & ML)
 * DAA LAB (01AI0506) - PRACTICAL 08: DFS AND BFS GRAPH TRAVERSAL
 * Student Name: Sai Ganesh Mandhati | Roll Number: 92460118370
 */
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void DFS(int u, const vector<vector<int>>& adj, vector<bool>& visited) {
    visited[u] = true;
    cout << u << " ";
    for (int v : adj[u]) {
        if (!visited[v]) DFS(v, adj, visited);
    }
}

void BFS(int start, const vector<vector<int>>& adj, int V) {
    vector<bool> visited(V, false);
    queue<int> q;
    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << " ";
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

int main() {
    cout << "======================================================================\n";
    cout << "         MARWADI UNIVERSITY - DEPARTMENT OF CE (AI & ML)\n";
    cout << "    DESIGN AND ANALYSIS OF ALGORITHMS LABORATORY (01AI0506)\n";
    cout << "    PRACTICAL 08: GRAPH TRAVERSAL (DFS AND BFS)\n";
    cout << "======================================================================\n";
    cout << "Student Name: Sai Ganesh Mandhati\n";
    cout << "Roll Number : 92460118370\n";
    cout << "======================================================================\n\n";

    int V, E;
    cout << "Enter number of vertices V and edges E: ";
    if (!(cin >> V >> E) || V <= 0) return 1;

    vector<vector<int>> adj(V);
    cout << "Enter " << E << " undirected edges (u v):\n";
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int startNode = 0;
    cout << "\n----------------------------------------------------------------------\n";
    cout << "DFS Traversal starting from node " << startNode << ": [ ";
    vector<bool> visited(V, false);
    DFS(startNode, adj, visited);
    cout << " ]\n";

    cout << "BFS Traversal starting from node " << startNode << ": [ ";
    BFS(startNode, adj, V);
    cout << " ]\n";
    cout << "----------------------------------------------------------------------\n";

    cout << "\nStudent Name : Sai Ganesh Mandhati\n";
    cout << "Roll Number  : 92460118370\n";
    cout << "\n...Program finished with exit code 0\n";
    return 0;
}
