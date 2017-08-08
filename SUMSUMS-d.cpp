#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef vector<vector<ll> > vii;
typedef vector<ll> vi;

const int m = 98765431;
int k;
vi b;

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


vi sol(int n){
	//TLE since k could be of the range 50000
	
	//creating transformation mat
	vii t(k, vi(k, 0));

	if (n < 1) return b;

	for(int i = 0; i < k; ++i){
		for(int j = 0; j < k; ++j){
			if (i != j) t[i][j] = 1;
		}
	}

	vii tn = pow(t, n);
	vi ans;
	ll x = 0;

	for(int r = 0; r < k; ++r){
		for(int c = 0; c < k; ++c){
			x += (tn[r][c] * b[c]) % m;
			x %= m; 
		}
		ans.push_back(x);
		x = 0;
	}
	return ans;
}


int main(){
	cin >> k;
	int n; cin >> n;
	b.resize(k);

	for(int i = 0; i < k; ++i){
		cin >> b[i];
	}

	vi ans = sol(n);
	for(int i = 0; i < k; ++i){
		cout << ans[i] << "\n";
	}
}