#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
const int mod = 1000000007;
const int sze = 100010;
int dr[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dc[] = {0, 1, 1, 1, 0, -1, -1 , -1};

enum color {RED, BLACK, UNCOLORED};
vi parent;
vector<color> c;

vi g[205];	//graph g can contain maximum 100 vertices
void addEdge(int u, int v) {
	//adds edge from ver u--v
	g[u].push_back(v);
	g[v].push_back(u);
}


bool isBipartitie(int src) {
	queue<int> q;
	q.push(src);
	c[src] = RED;	//let us mark it RED

	color curColor = RED;

	while (!q.empty()) {
		int cur = q.front();
		curColor = c[cur];
		q.pop();

		for (auto ngbr : g[cur]) {
			color next = curColor == RED ? BLACK : RED;
			if (c[ngbr] == UNCOLORED) {
				//lets color the ngbr
				c[ngbr] = next;	
				parent[ngbr] = cur;
				q.push(ngbr);
			}
			//not a direct edge
			else if (c[ngbr] == curColor) return false;
		}
	}
	return true;
}

int main() {
	// freopen("in", "r", stdin);
	int n;
	while (cin >> n && n != 0) {
		c.assign(n, UNCOLORED);
		parent.assign(n, -1);
		int e;
		cin >> e;
		while (e--) {
			int u, v;
			cin >> u >> v;
			addEdge(u, v);
		}
		if (isBipartitie(0)) {
			cout << "BICOLORABLE.\n";
		}
		else {
			cout << "NOT BICOLORABLE.\n";
		}
		for (int i = 0;  i < n; ++i) g[i].clear();
	}

}