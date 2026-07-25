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

# BELLMAN-FORD

- The Bellman-Ford algorithm is a single-source shortest path algorithm that computes the shortest distance from a starting node to all other nodes in a weighted graph.
- It is uniquely versatile because it can handle negative edge weights and is used to detect negative weight cycles.

HOW IT WORKS:
- The algorithm uses dynamic programming to process and iteratively "relax" all the edges in the graph.
- Edge relaxation means checking if the path to a destination node can be shortened by going through the starting node.

1. Initialization: Set the distance to the source node to 0 and the distances to all other nodes to infinity (∞).
2. Relaxation Pass: Iterate through every edge in the graph and update the distance if \(dist[v] > dist[u] + weight(u, v)\).
3. Repeat: Repeat the entire relaxation process exactly |V| - 1 times, where |V| is the number of vertices in the graph.
   - This ensures the shortest paths are correctly propagated since no simple path can have more than |V| - 1 edges.
4. Negative Cycle Detection: After |V| - 1 iterations, perform one final pass through all the edges.
   - If any distance value is updated, it indicates the presence of a negative weight cycle.

# DIFFERENCE BETWEEN ALL 3

# LINKS
[DSA Shortest Paths](https://www.w3schools.com/dsa/dsa_theory_graphs_shortestpath.php)<br>
[Djikstra's Algorithm](https://www.w3schools.com/dsa/dsa_algo_graphs_dijkstra.php)<br>
[Floyd Warshall Algorithm](https://www.programiz.com/dsa/floyd-warshall-algorithm)<br>
[Bellman-Ford Algorithm](https://www.w3schools.com/dsa/dsa_algo_graphs_bellmanford.php)<br>
[Bellman-Ford Sample Problems](https://www.geeksforgeeks.org/dsa/bellman-ford-algorithm-dp-23/)
