#include <iostream>
#include <queue>
#include <sstream>
#include <utility>
#include <vector>

/*
Problem:
Suppose you are given a directed graph with n vertices represented as an edge list, where each vertex is labeled from 0 to n - 1
(inclusive). Each edge in the graph is represented as a vector of pairs named edges, where edges[i] = [u_i, v_i] denotes a
uni-directional edgebetween vertex u_i and vertex v_i.

Every vertex pair is connected by at most one edge (no parallel edges), and there are no self-loops.

Determine if there is a valid path that exists from the given vertex source to the given vertex destination. Return true if a valid
path exists, and false otherwise.
*/

// Use Breadth First Search Algorithm
bool validPath(int n, std::vector<std::pair<int, int> > edges, int source, int destination)
{
  // Array to check if vertex has been visited, initialize all values to false
  bool visited[n];
  for (auto& val : visited) {
    val = false;
  }
  // Queue to store neighbor verticies by level
  std::queue<int> bfs_queue;
  // Set source as visited
  visited[source] = true;
  // Add source to the queue
  bfs_queue.push(source);
  // Begin breadth first search
  while (!bfs_queue.empty()) {
    // Make front of queue the new source vertex and pop from the queue
    source = bfs_queue.front();
    bfs_queue.pop();
    // Search through all edges in graph
    for (auto& pair : edges) {
      // Find edges coming from source vertex and check if the verticies they point to are visited
      if (pair.first == source && !visited[pair.second]) {
        // If they aren't, set them to visited and push them to queue for future computation
        visited[pair.second] = true;
        bfs_queue.push(pair.second);
      }
    }
  }
  // Return if destination was visited
  return visited[destination];
}
