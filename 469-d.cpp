#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
const int mod = 1000000007;
const int sze = 100010;
int dr[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dc[] = {0, 1, 1, 1, 0, -1, -1 , -1};
char g[110][110];
char t[110][110];

int m, n;		//no of vertices

int floodFill(int r, int c, char c1, char c2) {
	if (r >= n || r < 0 || c >= m || c < 0 || t[r][c] == c2) return 0;

	int ans = 1;
	if (t[r][c] == c1) t[r][c] = c2;	//visited

	for (int i = 0; i  < 8; ++i) {
		ans += floodFill(r + dr[i], c + dc[i], c1, c2);
	}
	// g[r][c] = c1;	//backtracking can't be used because 1 cell at be visited in one go
	//Once visited it must not be visited again
	return ans;

}

int main() {
	// freopen("in","r", stdin);
	int t1;
	cin >> t1;

	cin.getline(g[0], 100);	//consumes endl
	cin.getline(g[0], 100);	//consumes blank line

	while (t1--) {
		int i = 0;	//curline
		m = n = 0;
		while (isalpha(cin.peek()) && cin.getline(g[i++], 100)) n++;	//fills the matrix
		m = strlen(g[0]);
		int r, c;
		char rowCol[100];
		while (cin.getline(rowCol, 100) && strlen(rowCol) != 0) {
			sscanf(rowCol, "%d%d", &r, &c);
			copy(&g[0][0], &g[110][0], &t[0][0]); //use copy with containers
			// memcpy(t, g, sizeof g);
			cout << floodFill(--r, --c, 'W', 'L') << "\n";
		}
		if (t1) cout << "\n";
	}
}