#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
ll mod;// = 1000000007;
void printMat(vvi& a) {
	for (int i = 0; i < a.size(); ++i)
	{	for (int j = 0; j < a[0].size(); ++j)cout << a[i][j] << " ";
		cout << "\n";
	}
}

vvi mul(const vvi& a, const vvi& b) {
	vvi c(a.size(), vi(b[0].size(), 0));

	for (int r = 0; r < a.size(); ++r) {
		for (int j = 0; j < b[0].size(); ++j) {
			for (int x = 0; x < b.size(); ++x) {
				c[r][j] += (a[r][x] % mod) * (b[x][j] % mod);
				c[r][j] %= mod;
			}
		}
	}
	return c;
}

vvi pow(const vvi& a, int n) {
	if (n <= 1) return a;
	if (n & 1) return mul(a, pow(a, n - 1));

	vvi ans = pow(a, n / 2);
	ans = mul(ans, ans);
	return ans;
}

ll sum(int n, vi& b, vi& c) {
	if (n < 1) return 0;

	int k = b.size();
	vvi t(k + 1, vi(k + 1, 0));

	for (int i = 0; i <= k; ++i) {
		for (int j = 0; j <= k; ++j) {
			//for last row
			if (i != k && j == i + 1) t[i][j] = 1;
			else if (i == k && j != 0) t[i][j] = c[j-1];
			// else if (i == 0 && j == 1) t[i][j] = 1;
		}
	}
	t[0][0] = t[0][1] = 1;

	vvi tn = pow(t, n);
	// printMat(tn);
	ll ans  = 0;
	//the R0b0 is the answer
	for (int i = 0; i < k; ++i) {
		// cout << t[0][1+i] << endl;
		ans += (tn[0][i + 1] * b[i]) % mod;
		ans %= mod;
	}
	// cout << ans << endl;
	return ans;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int k; cin >> k;
		vi b(k);
		for (int i = 0; i < k; ++i) cin >> b[i];
		vi c(k);
		for (int i = 0; i < k; ++i) cin >> c[k - i - 1];
		ll m, n;
		cin >> m >> n >> mod;
		ll m_ = sum(m - 1, b, c);
		ll n_ = sum(n, b, c);
		// int ans = (n==1&& m<=1) ? b[0] : (n_ - m_ + mod);
		ll ans = (n_- m_ + mod) % mod;
		//ALWAYS handle negative mods
		cout << ans << "\n";
	}
}
