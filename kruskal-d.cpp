#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
const int mod = 1000000007;
const int sze = 100010;
int dr[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dc[] = {0, 1, 1, 1, 0, -1, -1 , -1};
class Graph {
public:
	vvi g;	//graph g can contain maximum 100 vertices
	void addEdge(int u, int v, bool isBidirectonal = true) {
		//adds edge from ver u--v
		g[u].push_back(v);
		if (isBidirectonal) g[v].push_back(u);
	}

	void clear(){
		g.clear();
	}
} g;

typedef tuple<int, int, int> edge;		//wt, v1, v2
vector<edge> edges;
vector<bool> visited;

//try implementing using Union Find Disjoint Set

int kruskal(){
	//gives minimum spanning tree
	int ans = 0;
	sort(edges.begin(), edges.end());
	for(int i = 0; i < (int)edges.size(); ++i){
		int u = get<1>(edges[i]);
		int v = get<2>(edges[i]);
		if (visited[u] && visited[v]) continue;
		cout << u << " " << v << endl;
		visited[u] = true;
		visited[v] = true;
		ans += get<0>(edges[i]);
	}
	return ans;
}


int main() {
	freopen("in", "r", stdin);
	int n; cin >> n;
	int wt ,u, v;
	visited.assign(n, false);
	while(n-- && cin >> wt >> u >> v){
		edges.push_back(make_tuple(wt, u, v));
	}

	cout << kruskal() << endl;
}