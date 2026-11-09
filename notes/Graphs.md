Measuring costs

For any given input, the cost(time, space) of a randomized algorithm 

Don't get confused between adjacency matrix and list.
Both start with the same name but don't forget to read the second part.

Topological sort: Possible only in a DAG, don't exist if the graph contains cycles
Ordering of the nodes such that all the edges point forward.
i.e every edge(u,v) is arranged such that u occurs before v.

Exit time stamp or `X[u]` is a recorded time which indicates the exact moment when a node u's exploration is complete which means all of outgoing neighbours and sub-branches are completely explored.

Claim: Every DAG can always be topologically sorted using DFS's exit timestamps.

For any directed edge (u, v), `X[v]` < `X[u]`
I am completing this problem set.

Total time complexity of Dijkstra algorithm using a binary heap on V_reach vertices and E_reach edges, 
1. Initialization O(V): to fill each entry with O(\infty) which can be optimized to O(1), if done lazily, i.e. to fill it only when it is first encountered.
2. 

Summary: Total time complexity |E| * log|V|
Even if we don't use a single target, Dijkstra calculates the shortest distance to every u in the same time complexity.
Dijkstra has a greedy approximation that once a node is extracted, it contains the smallest path is violated.
