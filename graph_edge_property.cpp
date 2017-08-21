#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
const int mod = 1000000007;
const int sze = 100010;
int dr[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dc[] = {0, 1, 1, 1, 0, -1, -1 , -1};

//detects if a cycle is present in the graph or not
//also prints all 
// backedge EXPLORED-->UNVISITED
// treeedge EXPLORED-->EXPLORED
// forward cross edge EXPLORED-->VISITED
enum pstate {VISITED, UNVISITED, EXPLORED};	//p for possible
vector<pstate> state;
vi parent;
vi g[205];	//graph g can contain maximum 100 vertices
void addEdge(int u, int v, bool isBidirectonal) {
	//adds edge from ver u--v
	g[u].push_back(v);
	if (isBidirectonal) g[v].push_back(u);
}

void graphcheck(int src){
	state[src] = EXPLORED;

	for(auto ngbr : g[src]){
		if (state[ngbr] == UNVISITED){		//Explored to Unvisited
			parent[ngbr] = src;
			cout << "TREE-EDGE : " << src << "-->" << ngbr << endl;
			graphcheck(ngbr);
		}
		else if (state[ngbr] == EXPLORED && ngbr != parent[src]){
				//parent[ngbr] != src prevents bidirectional edge to be considered as back edge
				cout << "BACK-EDGE :" << src << "-->" << ngbr << endl;
				//cycle detected
			}
		else if (state[ngbr] == VISITED){
			cout << "FORWARD-EDGE :" << src << "-->" << ngbr << endl ;
		}
	}
	state[src] = VISITED;
}


int main(){
	freopen("in","r", stdin);
	int n; cin >> n;
	int u, v, dir;
	while (cin >> u && cin >> v && cin >> dir) {
		addEdge(u, v, dir);
	}
	parent.resize(n);
	state.assign(n, UNVISITED);
	for(int i = 0; i < n; ++i) if (state[i] == UNVISITED) graphcheck(i);

}