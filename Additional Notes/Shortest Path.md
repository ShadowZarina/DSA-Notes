# SHORTEST PATH ALGORITHMS
- Djikstra's
- Floyd Warshall
- Belmans

# DJIKSTRAS

- Dijkstra's algorithm is a greedy graph search method used to find the shortest path from a starting node to all other nodes. 
- It uses a distance array and a priority queue to pick the closest unvisited node and update neighbor costs.

PROCESS:
1. Set the start node distance to 0 and all other node distances to infinity (∞).
2. Put the start node into a priority queue (min-heap).
3. Pick the node with the smallest distance from the queue.
4. Look at each neighbor of this node.
5. Add the current path cost to the edge weight.
6. If this new cost is smaller than the old recorded cost, update the neighbor's distance.
7. Repeat the steps until the priority queue is empty.

# FLOYD WARSHALLS

- The Floyd–Warshall algorithm works by maintaining a two-dimensional array that represents the distances between nodes.
- Initially, this array is filled using only the direct edges between nodes.
- Then, the algorithm gradually updates these distances by checking if shorter paths exist through intermediate nodes.
- This algorithm works for both the directed and undirected weighted graphs and can handle graphs with both positive and negative weight edges.
- Note: It does not work for the graphs with negative cycles (where the sum of the edges in a cycle is negative).\

HOW IT WORKS:
- It tests every vertex as an intermediate step between all other pairs of vertices.
- It uses three nested loops: the outer loop picks an intermediate node (k), and the two inner loops pick the start (i) and end (j) nodes.
- Formula: dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])

PROCESS:
1. Start by updating the distance matrix by treating each vertex as a possible intermediate node between all pairs of vertices.
2. Iterate through each vertex, one at a time.
3. For each selected vertex k, attempt to improve the shortest paths that pass through it.
4. When we pick vertex number k as an intermediate vertex, we already have considered vertices {0, 1, 2, .. k-1} as intermediate vertices.
5. For every pair (i, j) of the source and destination vertices respectively, there are two possible cases. 
  - k is not an intermediate vertex in shortest path from i to j. We keep the value of dist[i][j] as it is. 
  - k is an intermediate vertex in shortest path from i to j.
  - We update the value of dist[i][j] as dist[i][k] + dist[k][j], if dist[i][j] > dist[i][k] + dist[k][j]
6. Repeat this process for each vertex k until all intermediate possibilities have been considered.

# BELMANS

# DIFFERENCE BETWEEN ALL 3

# LINKS
[DSA Shortest Paths](https://www.w3schools.com/dsa/dsa_theory_graphs_shortestpath.php)<br>
[Djikstra's Algorithm](https://www.w3schools.com/dsa/dsa_algo_graphs_dijkstra.php)<br>
[Floyd Warshall Algorithm](https://www.programiz.com/dsa/floyd-warshall-algorithm)<br>
[Bellman-Ford Algorithm](https://www.w3schools.com/dsa/dsa_algo_graphs_bellmanford.php)
