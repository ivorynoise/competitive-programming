#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
const int mod = 1000000007;


vvi mul(const vvi& a, const vvi& b){
	vvi c(a.size(), vi(b[0].size(), 0));

	for(int r = 0; r < a.size(); ++r){
		for(int j = 0; j < b[0].size(); ++j){
			for(int x = 0; x < b.size(); ++x){
				c[r][j] += (a[r][x] % mod) * (b[x][j] % mod);
				c[r][j] %= mod;
			}
		}
	}
	return c;
}

vvi pow(const vvi& a, int n){
	if (n <= 1) return a;
	if (n & 1) return mul(a, pow(a, n-1));

	vvi ans = pow(a, n/2);
	ans = mul(ans, ans);
	return ans;
}

ll sum(int n){
	vvi t = {
		{1, 1, 0},		//the last 0 will be modified accordingly
		{0, 0, 1},
		{0, 1, 1}
	};

	vvi tn = pow(t, n);

	// for(int i = 0; i < tn.size(); ++i){
	// 	for(int j = 0; j < tn[0].size(); ++j){
	// 		cout << tn[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }

	ll ans = tn[0][2] % mod; 
	return ans;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		ll n, m;
		cin >> n >> m;

		m = sum(m+1);
		n = sum(n);
		cout << (m - n + mod) % mod << "\n"; 
	}
	return 0;
	
}
