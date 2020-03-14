#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vec;
typedef vector<vec> mat;

const int inf = 1e8;
void inputVec(vector<int>& ans) {
	for (int& x : ans) {
		cin >> x;
	}
}

ostream& printVec(vector<int>& ans) {
	for (int x : ans) {
		cout << x << " ";
	}
	cout << endl;
	return cout;
}

void printMat(vector<vector<int> > mat) {
	for (auto& v : mat) {
		for (auto& x : v) {
			cout << x << " ";
		}
		cout << endl;
	}
}

template<class T>
void printTwoD(T arr, int m, int n){
	for(int i = 0;  i < m; ++i){
		for(int j = 0; j < n; ++j){
//			setbuf(stdout, 0);
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << "*****************\n";
}

template<class T>
void print(T x) {cout << x << endl;}
void iofile() {
	freopen("/home/deepak/ds-algo/in", "r", stdin);
}

#include "lis.h"
#include "lcs.h"
#include "knapsack.h"
#include "longest-common-substring.h"
#include "matrix-chain.h"
#include "ugly-numbers.h"
#include "boolean-paranthesization.h"

int main() {
	iofile();
//	setbuf(stdout, 0);
	// // LIS
	// // 5 2 7 4 3 8
	// int n;
	// cin >> n;
	// vec v(n, 0);
	// inputVec(v);
	// int ans = lis1(v);
	// print(ans);

	// // LCS
	// string a, b;
	// cin >> a >> b;
	// int ans = lcs(a,b);
	// print(ans);

	// // Knapsack
	// int n; cin >> n;
	// vec val(n), wt(n);
	// inputVec(val);
	// inputVec(wt);
	// int k; cin >> k;
	// int ans = Knapsack(val, wt, k);
	// cout << ans;

	// // longest common substring
	// string a, b;
	// cin >> a >> b;
	// int ans = lcstr(a, b);
	// cout << ans;


	// // matrix mul
	// int n; cin >> n;
	// vec dim(n);
	// inputVec(dim);

	// mat d(n, vec(n, 0));
	// int ans = matmul2(dim, 0, n - 1, d);
	// print(ans);
	// printMat(d);

	// int ans = matmul2(dim);
	// print(ans);

	// ugly numbers
	// int n; cin >> n;
	// print(ugly(n));


	// boolean paranthesization
	string op, sym;
	cin >> sym >> op;
	// int ans = numWays(sym, 0, sym.size() - 1, op, 0, op.size() - 1, true);
	int ans = numWays2(sym, op);
	print(ans);
	print(cnt);
}