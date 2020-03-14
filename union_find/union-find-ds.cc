#include <bits/stdc++.h>
using namespace std;

class UnionSet{
	vector<int> v, sze;
public:

	UnionSet(int N){
		v.resize(N, 0);
		sze.resize(N, 1);

		for(int i = 0; i < N; ++i){
			v[i] = i;
		}
	}

	int root(int x){
		while(x != v[x]){
			v[x] = v[v[x]];	// flattening the tree log*N
			x = v[x];
		}
		return x;
	}

	bool sameSet(int x, int y){
		return root(x) == root(y);
	}

	void setUnion(int x, int y){
		int root_x = root(x);
		int root_y = root(y);

		if (sze[root_x] > sze[root_y]){
			sze[root_x] += sze[root_y];
			v[root_y] = root_x;
		}
		else {
			sze[root_y] += sze[root_x];
			v[root_x] = root_y;
		}
	}
};


int main(){
	UnionSet u(5);
	u.setUnion(0, 1);
	u.setUnion(1, 4);
	cout << u.sameSet(0, 4);
	cout << u.root(4);
	cout << u.sameSet(1, 3);
}