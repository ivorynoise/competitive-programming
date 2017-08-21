//the question asks the candidate to check if the whole graph is strongly connected

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
const int mod = 1000000007;
const int sze = 100010;
int dr[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dc[] = {0, 1, 1, 1, 0, -1, -1 , -1};

vvi g;	//graph g can contain maximum 100 vertices
void addEdge(int u, int v, bool isBidirectonal) {
	//adds edge from ver u--v
	g[u].push_back(v);
	if (isBidirectonal) g[v].push_back(u);
}

//a graph is said to be strongly connected if there exists a PATH from u->v and v->u
//check for strongly connectedess
int nSCC;	//no of strongly connected component
int dfsCnt;
vi discTime;	//discTime[x] : discovery time of x
vi low;			//low[x] : lowest vertex that can be discovered from x
enum state{UNVISITED = -1};
vector<bool> visited;
stack<int> stk;

bool tarjanSCC(int src) {
	visited[src] = true;
	discTime[src] = low[src] = dfsCnt++;
	stk.push(src);

	for (auto ngbr : g[src]) {
		//if there exists more than 1 SCC from ngbr then no way to reach src to ngbr in both
		//direction
		if (visited[ngbr] == false && !tarjanSCC(ngbr)) return false;
		low[src] = min(low[src], low[ngbr]);
	}

	if (low[src] == discTime[src]) {
		//this is root of sub-SCC
		++nSCC;
		// cout << nSCC << ": ";
		while (1) {
			int v = stk.top();
			stk.pop();
			visited[v] = false;
			// cout << v << " ";
			if (src == v) break;
		}
		// cout << endl;
	}

	if (nSCC > 1) return false;
	return true;
}



int main() {
	// freopen("in", "r", stdin);
	int n, e, u, v, dir;

	while (cin >> n >> e) {
		if (n == 0 && e == 0) break;
		g.clear();
		g.resize(n);
		nSCC = 0;	//no of strongly connected component
		dfsCnt = 0;
		discTime.assign(n, UNVISITED);	//discTime[x] : discovery time of x
		low.assign(n, 0);			//low[x] : lowest vertex that can be discovered from x
		visited.assign(n, false);
		while (e--) {
			cin >> u >> v >> dir; 
			--dir;
			addEdge(--u, --v, dir);
		}

		for (int i = 0; i < n; ++i) {
			if (discTime[i] == UNVISITED) tarjanSCC(0);
		}
		cout << (nSCC == 1) << endl;
		// for (auto& x : g) x.clear();
	}
}