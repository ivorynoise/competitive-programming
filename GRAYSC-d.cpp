//codechef-pigeonhole
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
const int mod = 1000000007;
const int sze = 100010;
void printMat(vvi& a) {for (int i = 0; i < a.size(); ++i) {for (int j = 0; j < a[0].size(); ++j)cout << a[i][j] << " ";} cout << "\n";}
int main() {
	ll arr[100000];
	int n;
	cin >> n;
	for (int i = 0 ; i < n; ++i) {
		cin >> arr[i];
	}

	if (n >= 130) {
		cout << "Yes";
		return 0;
	}

	sort(arr, arr + n);
	for(int i = 0; i < n-3; ++i){
		for(int j = i + 1; j < n -2; ++j ){
			for(int k = j + 1; k < n - 1; ++k){
				ll toFind = arr[i] ^ arr[j] ^ arr[k];
				if (binary_search(arr + k + 1, arr + n, toFind)) {
					//returns true or false
					cout << "Yes";
					return 0;
				}
			}
		}
	}

	cout << "No";
}