// bellman-ford
vector<int> bellmanFord(WeightedGraph g, int src, bool& negCycle) {
	/*\
	 * Finds the single src shortest path (SSSP) even for negative weights
	 * If negative cycle occurs, it detects that
	 * (N3)
	\*/

	vector<int> dist(g.size(), inf);
	dist[src] = 0;

	for (int edge = 1; edge <= g.size(); ++edge) {	// also detects -ve cycle
		auto& adjList = g.v;

		for (int vtx = 0; vtx < g.size(); ++vtx) {

			auto& nbrList = adjList[vtx];
			for (auto& p : nbrList) {
				auto id = p.first;
				auto wt = p.second;

				if (wt + dist[vtx] < dist[id]) {
					dist[id] = wt + dist[vtx];
					if (edge == g.size())negCycle = true;
				}
			}
		}
	}
	return dist;
}

// floyd-warshall
vector<vector<int> > floydWarshall(WeightedGraph ug) {
	/*\
	 *	Computes the All Pair Shortest Path
	 *	(N)
	\*/
	int n = ug.size();
	vector<vector<int> > ans(n, vector<int>(n, inf));

	auto& adjList = ug.v;

	// preprocessing
	for (int src = 0; src < n; ++src) {
		auto& nbrList = adjList[src];
		ans[src][src] = 0;

		for (int i = 0; i < nbrList.size(); ++i) {
			auto ngbr = nbrList[i].first;
			auto wt = nbrList[i].second;

			ans[src][ngbr] = wt;
		}
	}


	for (int via = 0; via < n; ++via) {
		for (int src = 0; src < n; ++src) {
			auto& nbrList = adjList[src];
			for (int i = 0; i < n; ++i) {
				// auto ngbr = nbrList[i].first;
				// auto wt = nbrList[i].second;

				{
					ans[src][i] = min(ans[src][i], ans[src][via] + ans[via][i]);
				}
			}
		}
	}

	return ans;
}


// prim
class ComparePair{
	typedef pair<int, int> Pair;
public:
	bool operator()(const Pair& a, const Pair& b){
		return a.second >= b.second;
	}
};

int prim(WeightedGraph g) {
	/*\
	 * Calculates the Minimum Spanning Tree
	 * More like Dijkstra
	\*/

	int n = g.size();
	int dist = 0;
	vector<bool> visited(n, false);

	typedef pair<int, int> ii;
	priority_queue<ii, vector<ii>, ComparePair > q;

	q.push(make_pair(0, 0));
	// visited[0] = true;

	while (!q.empty()) {
		auto p = q.top(); 	// DO NOT use ref variable
		q.pop();
		auto i = p.first;
		auto w = p.second;
		cout << i << w << endl;
		if (visited[i]) continue;
		visited[i] = true;
		dist += w;

		auto& nbrList = g.v[i];

		for (int j = 0; j < nbrList.size(); ++j) {
			if (visited[nbrList[j].first] == false) {
				q.push(nbrList[j]);
			}

		}
	}
	return dist;
}

// kruskal
class UnionSet{
	vector<int> v, sze;
public:

	UnionSet(int N){
		v.resize(N, 0);
		sze.resize(N, 1);

		for(int i = 0; i < N; ++i){
			v[i] = i;
		}
	}

	int root(int x){
		while(x != v[x]){
			v[x] = v[v[x]];	// flattening the tree log*N
			x = v[x];
		}
		return x;
	}

	bool sameSet(int x, int y){
		return root(x) == root(y);
	}

	void setUnion(int x, int y){
		int root_x = root(x);
		int root_y = root(y);

		if (sze[root_x] > sze[root_y]){
			sze[root_x] += sze[root_y];
			v[root_y] = root_x;
		}
		else {
			sze[root_y] += sze[root_x];
			v[root_x] = root_y;
		}
	}
};
int kruskal(WeightedGraph g){
	/*\
	 * Computes MST
	 * Uses UnionSet
	\*/

	auto& adjList = g.v;
	int n = g.size();

	typedef pair<int, int> ii;
	typedef tuple<int, int, int> iii;
	UnionSet u(n);

	// Edge List sorting
	vector<iii> v;

	for(int src = 0; src < n; ++src){
		for(int i = 0; i < adjList[src].size(); ++i){
			auto& nbr = adjList[src][i].first;
			auto& wt  = adjList[src][i].second;
			v.push_back(make_tuple(wt, src, nbr));
		}
	}

	sort(v.begin(), v.end());

	int dist = 0;
	for(int i = 0; i < v.size(); ++i){
		auto curEdge = v[i];
		if (!u.sameSet(get<1>(curEdge), get<2>(curEdge))){
			dist += get<0>(curEdge);
			u.setUnion(get<1>(curEdge), get<2>(curEdge));
		}
	}
	return dist;
}