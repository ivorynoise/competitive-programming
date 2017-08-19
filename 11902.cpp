#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
const int mod = 1000000007;
const int sze = 110;
void printMat(vvi& a) {for (int i = 0; i < a.size(); ++i) {for (int j = 0; j < a[0].size(); ++j)cout << a[i][j] << " ";} cout << "\n";}

int g[sze][sze];
char visited[sze];	//basically isDominator
int n;
char design[2 * sze];

void dfs(int src, int nodeToBeRemoved) {
	if (src == nodeToBeRemoved) return;
	visited[src] = 'N';

	for (int ngbr = 0; ngbr < n; ++ngbr) {
		if (g[src][ngbr] == 1 && visited[ngbr] == 'Y') {
			dfs(ngbr, nodeToBeRemoved);
		}
	}
}


void printDominators() {
	char allConnected[sze];
	memset(visited, 'Y', sizeof visited);
	dfs(0, n + 1);
	for (int i = 0; i < n; ++i) {
		allConnected[i] = visited[i];
		// cout << allConnchroected << endl;
	}
	
	//all connected contains all the vertices that are reachable from zero

	cout << design << "\n";
	
	for (int curVer = 0; curVer < n; ++curVer) {
		memset(visited, 'Y', sizeof visited);
		//all visited vertices will be set to N 
		dfs(0, curVer);
		putchar('|');
		// for (int i = 0; i < n; ++i) {
		// 	if (allConnected[i] == 'Y') visited[i] = 'N';
		// }
		for (int i = 0; i < n; ++i) {
			//If all nodes are visited after removing curVer or curVer is disonncected from 
			//src
			if (visited[i] == 'N' || allConnected[i] == 'Y' ){
				putchar('N');
			}
			else putchar('Y');
			putchar('|');
		}
		putchar('\n');
		cout << design << "\n";
	}
}

int main() {
	int t, caseno = 0;
	cin >> t;
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				scanf("%d", &g[i][j]);
			}
		}
		design[0] = design[2 * n] = '+';
		for (int i = 1; i < 2 * n; ++i) {
			design[i] = '-';
		}
		design[2 * n + 1] = '\0';
		printf("Case %d:\n", ++caseno);
		printDominators();
	}
}