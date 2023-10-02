import heapq


class Graph:
    def __init__(self, edges, n):
        self.adjList = [[] for _ in range(n)]
        self.indegree = [0] * n
        for (src, dest) in edges:
            self.adjList[src].append(dest)
            self.indegree[dest] = self.indegree[dest] + 1


def topological_sort(graph, n):
    L = []
    indegree = graph.indegree
    S = [i for i in range(n) if indegree[i] == 0]
    while S:
        n = heapq.heappop(S)
        L.append(n)
        for m in graph.adjList[n]:
            indegree[m] = indegree[m] - 1
            if indegree[m] == 0:
                heapq.heappush(S, m)
    for i in range(n):
        if indegree[i]:
            return None
    return L


if __name__ == "__main__":
    edges = [(0, 6), (1, 2), (1, 4), (1, 6), (3, 0), (3, 4), (5, 1), (7, 0), (7, 1)]
    n = 8
    graph = Graph(edges, n)
    print(topological_sort(graph, n))
