#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
const int mod = 1000000007;
const int sze = 100010;
int dr[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dc[] = {0, 1, 1, 1, 0, -1, -1 , -1};

vi g[100];	//graph g can contain maximum 100 vertices

void addEdge(int u, int v) {
	//adds edge from ver u--v
	g[u].push_back(v);
	g[v].push_back(u);
}


//articulation points
enum state {UNVISITED = -1};
vi articulation_points;
int discTime;
int rootChildren;
int dfsRoot;
vi low;		//low[x] : lowest time required to visit a vertex from x
vi disc; 	//disc[x] : discovery time of x; initially set to UNVISITED
vi parent;	//parent[x] : parent of x

void findArticulationPoints(int src) {
	//src visited with discovery time discTime
	//lets us assume that lowest vertex that can be visited takes time discTime
	++discTime;
	disc[src] = discTime;
	low[src] = discTime;

	for (int i = 0; i < (int)g[src].size(); ++i) {
		int ngbr = g[src][i];
		if (disc[ngbr] == UNVISITED) {
			//neigbr is undiscovered, find all ap from ngbr
			parent[ngbr] = src;
			if (parent[ngbr] == dfsRoot) ++rootChildren;
			findArticulationPoints(ngbr);

			//parent[src] != ngbr since we are checking the unvisited nodes
			if (low[ngbr] >= disc[src]) {
				//the lowest time required to discover a vertex from my ngbr is greater than
				//the discovery time of mine; hence I am an ap
				// if (src > (int)articulation_points.size()) {
				articulation_points[(src)] = true;
				// }
			}
			// else {
			//otherwise I am a trivial node :(
			//it means even if I am removed, my ngbr can be visited
			low[src] = min(low[src], low[ngbr]);
			// }
		}
		else {
			//if my ngbr has a vertex that can be discovered in lesser time than mine
			//then lowest time of mine should also be updated
			if (parent[src] != ngbr) {	//not a direct edge
				low[src] = min(low[src], low[ngbr]);
			}
		}
	}
}

void ap(int N, int src) {
	discTime = 0;
	rootChildren = 0;
	dfsRoot = src;
	disc.assign(N, UNVISITED);
	low.assign(N, 0);
	articulation_points.assign(N, false);
	parent.resize(N);
	findArticulationPoints(src);
	if (rootChildren > 1) articulation_points[dfsRoot] = true;

}



int main() {
	freopen("in", "r", stdin);
	int N, src;
	cin >> N >> src;
	int u, v;
	while (cin >> u && cin >> v) addEdge(u, v);
	ap(N, src);
	for (auto& x : articulation_points) cout << x <<  " ";
}