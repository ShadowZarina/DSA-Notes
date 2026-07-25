# SHORTEST PATH ALGORITHMS
- Djikstra's
- Floyd Warshall
- Belmans

# DJIKSTRAS

- Dijkstra's algorithm is a greedy graph search method used to find the shortest path from a starting node to all other nodes. 
- It uses a distance array and a priority queue to pick the closest unvisited node and update neighbor costs.

Process:
1. Set the start node distance to 0 and all other node distances to infinity (∞).
2. Put the start node into a priority queue (min-heap).
3. Pick the node with the smallest distance from the queue.
4. Look at each neighbor of this node.
5. Add the current path cost to the edge weight.
6. If this new cost is smaller than the old recorded cost, update the neighbor's distance.
7. Repeat the steps until the priority queue is empty.

# FLOYD WARSHALLS

# BELMANS

# DIFFERENCE BETWEEN ALL 3

# LINKS
[DSA Shortest Paths](https://www.w3schools.com/dsa/dsa_theory_graphs_shortestpath.php)<br>
[Djikstra's Algorithm](https://www.w3schools.com/dsa/dsa_algo_graphs_dijkstra.php)<br>
[Floyd Warshall Algorithm](https://www.programiz.com/dsa/floyd-warshall-algorithm)<br>
[Bellman-Ford Algorithm](https://www.w3schools.com/dsa/dsa_algo_graphs_bellmanford.php)
