#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
const int mod = 1000000007;
const int sze = 100010;
vi g[30];

int toInt(char c) { return c - 'A';}

void bfs(int src, vector<bool>& visited) {

	queue<int> q;
	q.push(src);
	visited[src] = true;

	while(!q.empty()){
		int cur = q.front();
		q.pop();

		for(int i = 0; i < (int)g[cur].size(); ++i){
			int v = g[cur][i];
			if (visited[v] == false){
				q.push(v);
				visited[v] = true;
			}
		}
	}

}

int connectedComponents(int n){
	vector<bool> visited;
	visited.assign(n, false);
	int cc = 0;

	for (int ver = 0; ver < n; ++ver) {
		if (!visited[ver]) {
			bfs(ver, visited);
			++cc;
		}
	}
	return cc;
}


int main() {
	int t;
	cin >> t;
	char inp[100];
	cin.getline(inp, 100);	//consumes all the whitespace after t
	cin.getline(inp , 100);	//consumes the first line

	while (t--) {
		char n; cin >> n;
		int N = toInt(n) + 1;

		cin.getline(inp, 100);
		//reading edges

		while (cin.getline(inp, 100) && strlen(inp) > 0) {
			g[toInt(inp[0])].push_back(toInt(inp[1]));
			g[toInt(inp[1])].push_back(toInt(inp[0]));
		}

		cout << connectedComponents(N) << "\n";
		//output of the two consecutive shall be seperated by a blank line
		if (t) 
			cout << "\n";
		for(auto& v : g) v.clear();	//clearing all adjlists in the g array
	}
}