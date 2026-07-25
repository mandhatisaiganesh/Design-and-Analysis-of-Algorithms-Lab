/**
 * ============================================================================
 * MARWADI UNIVERSITY - FACULTY OF ENGINEERING AND TECHNOLOGY
 * DEPARTMENT OF COMPUTER ENGINEERING (AI & ML)
 * DESIGN AND ANALYSIS OF ALGORITHMS LABORATORY (01AI0506)
 * 
 * PRACTICAL 08: Implementation of Graph Traversals (DFS & BFS)
 * Student Name: Sai Ganesh Mandhati
 * Roll Number  : 92460118370
 * 
 * Algorithms:
 *   1. Depth-First Search (DFS)
 *   2. Breadth-First Search (BFS)
 * 
 * Language: C++17 | Compiler: g++ (-std=c++17 -Wall -Wextra -O2)
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <queue>
#include <chrono>
#include <iomanip>

using namespace std;
using namespace std::chrono;

class Graph {
    int V;
    vector<vector<int>> adj;

public:
    Graph(int v) : V(v), adj(v) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); // Undirected graph
    }

    void dfsUtil(int node, vector<bool>& visited, vector<int>& dfsOrder) {
        visited[node] = true;
        dfsOrder.push_back(node);
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfsUtil(neighbor, visited, dfsOrder);
            }
        }
    }

    vector<int> getDFS(int startNode) {
        vector<bool> visited(V, false);
        vector<int> dfsOrder;
        dfsUtil(startNode, visited, dfsOrder);
        return dfsOrder;
    }

    vector<int> getBFS(int startNode) {
        vector<bool> visited(V, false);
        vector<int> bfsOrder;
        queue<int> q;

        visited[startNode] = true;
        q.push(startNode);

        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            bfsOrder.push_back(curr);

            for (int neighbor : adj[curr]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        return bfsOrder;
    }
};

void printVector(const string& label, const vector<int>& vec) {
    cout << left << setw(35) << label << ": [ ";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << vec[i] << (i + 1 == vec.size() ? "" : ", ");
    }
    cout << " ]\n";
}

int main() {
    cout << "======================================================================\n";
    cout << "         MARWADI UNIVERSITY - DEPARTMENT OF CE (AI & ML)\n";
    cout << "    DESIGN AND ANALYSIS OF ALGORITHMS LABORATORY (01AI0506)\n";
    cout << "    PRACTICAL 08: GRAPH TRAVERSALS (DFS & BFS) BENCHMARK\n";
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

    Graph g(V);
    cout << "Enter " << E << " edges (u v):\n";
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    int startNode;
    cout << "Enter starting node for traversals (0 to " << (V - 1) << "): ";
    cin >> startNode;

    auto startDfs = high_resolution_clock::now();
    vector<int> dfsResult = g.getDFS(startNode);
    auto stopDfs = high_resolution_clock::now();
    auto dfsTime = duration_cast<microseconds>(stopDfs - startDfs).count();

    auto startBfs = high_resolution_clock::now();
    vector<int> bfsResult = g.getBFS(startNode);
    auto stopBfs = high_resolution_clock::now();
    auto bfsTime = duration_cast<microseconds>(stopBfs - startBfs).count();

    cout << "\n----------------------------------------------------------------------\n";
    cout << "GRAPH TRAVERSAL RESULTS\n";
    cout << "----------------------------------------------------------------------\n";
    printVector("DFS Traversal starting from node " + to_string(startNode), dfsResult);
    cout << "DFS Execution Time: " << dfsTime << " us\n\n";

    printVector("BFS Traversal starting from node " + to_string(startNode), bfsResult);
    cout << "BFS Execution Time: " << bfsTime << " us\n";

    cout << "\nStudent Name : Sai Ganesh Mandhati\n";
    cout << "Roll Number  : 92460118370\n";
    cout << "\n...Program finished with exit code 0\n";
    return 0;
}
