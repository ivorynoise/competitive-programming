#include <bits/stdc++.h>
using namespace std;

void dijkstra(int C, vector<pair<int, int>> adj[], vector<int>& dist, vector<int>& visited) {
    dist[C] = 0;
    visited[C] = 1;
    pq.push({0, C});
    while (pq.size()) {
        int node = pq.top().second;
        visited[node] = 1;
        pq.pop();
        for (int i = 0; i < adj[node].size(); i++) {
            pair<int, int> p = adj[node][i];
            int x = p.first;
            int y = p.second;
            if (visited[x] == 0) {
                if (dist[x] > (dist[node] + y)) {
                    dist[x] = dist[node] + y;
                    pq.push({dist[x], x});
                }
            }
        }
    }
    return;
}