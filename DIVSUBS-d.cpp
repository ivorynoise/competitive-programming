//codechef : pigeonhole
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
const int mod = 1000000007;
void printMat(vvi& a){for(int i=0;i<a.size();++i){for(int j=0;j<a[0].size();++j)cout<<a[i][j]<<" ";}cout<<"\n";}
const int sze = 100010;

int main(){
	int t; cin >> t;
	// Each element of the multiset is a positive integer, not exceeding 109.
	//Alert sum can exceed int range

	int arr[sze];
	ll sum[sze] = {};

	while(t--){
		int n;
		cin >> n;

		for(int i = 0; i < n; ++i){
			cin >> arr[i];
			sum[i+1] = arr[i] + sum[i];	//prev + cur
		}

		int* remainder = new int[n];
		fill(remainder, remainder + n, -1);

		int be = -1;
		int en = -1;

		for(int i = 0; i <= n; ++i){
			int& curIdx = remainder[sum[i] % n]; 

			if (curIdx != -1) {
				//this remainder has been previously visited
				be = curIdx;
				en = i;
				break;
			}
			else {
				curIdx = i;
			}
		}

		cout << en-be <<"\n";	//no of elements in a range
		++be;
		while(be <= en) {
			cout << be << " ";
			be++;
		}

		cout << "\n";
		delete [] remainder;

	}
}