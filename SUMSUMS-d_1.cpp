#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N = 50000;
ll n, t;
ll cows[N];
const ll m = 98765431;

//mult(ll[][] ll[][])
void mul(ll a[][2], ll b[][2]){
	ll c[2][2]={};
	for(ll i = 0; i < 2; ++i){
		for(ll j = 0; j < 2; ++j){
			for(ll x = 0; x < 2; ++x){
				c[i][j] += (a[i][x] * b[x][j]) % m;
				c[i][j] %= m;	
			}
		}
	}

	for(ll i = 0; i < 2; ++i){
		for(ll j = 0; j < 2; ++j)
			a[i][j] = c[i][j];
	}
}



//pow(ll[][], t)
void pow(ll mat[][2], ll n){
	if (n <= 1) return;

	if (n&1) {
		ll tmp[2][2] = {
			{mat[0][0], mat[0][1]},
			{mat[1][0], mat[1][1]}
		};
		pow(mat, n-1);
		mul(mat, tmp);
		return;
	}

	pow(mat, n/2);
	mul(mat, mat);
}

void transform(ll tn[][2]){
	if (t == 0) return;
	pow(tn, t);
}


int main(){
	cin >> n >> t;
	ll s =0;

	for(ll i = 0; i < n; ++i){
		cin >> cows[i];
		s += cows[i] % m;
		s %= m;
	}	
		ll tn[2][2] = {
			{n-1, 0},
			{1, -1}
		};

		transform(tn);
		// cout << tn[0][0] << " " << tn[0][1] << " " << tn[1][0] << " " << tn[1][1] << " " << endl;;

	for(ll i = 0; i < n; ++i){
		//S1 = (n - 1)S0
		//c[1] = S0 - c(0)

		ll f[2][1] = {{s}, {cows[i]}};
		ll ans = (tn[1][0]*f[0][0]%m) + (tn[1][1] * f[1][0])%m;

		//this might be negative
		cout << ((ans+m) % m) << "\n";

	}
}