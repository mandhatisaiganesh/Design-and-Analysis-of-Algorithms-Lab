# Algorithm - Floyd-Warshall Algorithm (All-Pairs Shortest Path)

Pseudocode and line-by-line flow walk-through for Floyd-Warshall Algorithm (All-Pairs Shortest Path).


Step 1: Initialize the distance matrix.
- 0 for the distance from a vertex to itself.
- Edge weight if a direct edge exists.
- ∞ if there is no direct edge.
Step 2: Select each vertex k as an intermediate vertex.
Step 3: For every pair (i, j), calculate:
\[
D[i][k] + D[k][j]
\]
Step 4: If this value is smaller than the current D[i][j], update it.
Step 5: Repeat for all vertices.
Step 6: The final matrix contains the shortest distances between every pair of vertices.
