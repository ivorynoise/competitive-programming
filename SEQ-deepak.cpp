#include<bits/stdc++.h>
using namespace std;

typedef vector<vector<int> > vii;
typedef vector<int> vi;
typedef long long int ll;
const int m = (int)1e9;
int k;
vi b;
vi c;

//matrix mul
vii mul(const vii& A, const vii& B) {
	vii C(k, vi(k, 0));

	for (int r = 0; r < k; ++r) {
		for (int c = 0; c < k; ++c) {
			for (int x = 0; x < k; ++x) {
				C[r][c] += (A[r][x] * B[x][c]) % m;
				C[r][c] %= m;
			}
		}
	}
	return C;
}

//matrix exponentiation
vii pow(vii& A, int n) {
	if (n <= 1) return A;

	//if odd
	if (n & 1) return mul(A, pow(A, n - 1));

	vii ans = pow(A, n / 2);
	return mul(ans, ans);
}

int sol(int n){
	vii t(k, vi(k, 0));

	if (n <= k) return b[n - 1];
	
	//setting transformation matrix
	for(int r = 0; r < k; ++r){
		for(int c = 0; c < k; ++c){
			if (r == 0) t[r][c] = b[c];
			else if (r == c + 1) t[r][c] = 1;
			else t[r][c] = 0;
		}
	}

	//setting f
	vi f(k);
	copy(c.rbegin(), c.rend(), f.begin());

	//compute T^n
	int exp = n;
	vii tn = pow(t, exp);

	ll ans = 0;
	// getting the first row
	for(int i = 0; i < k; ++i){
		ans += (tn[0][i] * f[i]) % m;
		ans %= m;
	}
	return ans;

}

int main() {
	int t;
	cin >> t;
	while (t--)
	{	
		cin >> k;
		b.resize(k);
		c.resize(k);

		for (int i = 0; i < k; ++i) {
			cin >> b[i];
		}

		for (int i = 0; i < k; ++i) {
			cin >> c[i];
		}

		int n;
		cin >> n;
		cout << sol(n) << "\n";	//never use endl
		b.clear();
		c.clear();
	}

}