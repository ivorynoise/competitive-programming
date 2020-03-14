#include <bits/stdc++.h>
using namespace std;

const int inf = 1e8;


class UnweightedGraph {
	int nv;
public:
	vector<vector<int> > v;

	UnweightedGraph(int n) {
		nv = n;
		v.resize(nv);
	}

	void addEdge(int src, int dest, bool isBiDirectional = true) {
		v[src].push_back(dest);
		if (isBiDirectional) v[dest].push_back(src);
	}

	int size() {
		return nv;
	}
};


class WeightedGraph {
	int nv;
public:
	vector<vector<pair<int, int> > > v;	// id, wt

	WeightedGraph(int n) {
		nv = n;
		v.resize(n);
	}

	void addEdge(int src, int dest, int wt, bool isBiDirectional = true) {
		v[src].push_back(make_pair(dest, wt));
		if (isBiDirectional) {
			v[dest].push_back(make_pair(src, wt));
		}
	}

	int size() {
		return nv;
	}
};

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

#include "advance.h"

int main() {
	// WeightedGraph wg(3);
	// wg.addEdge(0, 1, 4, false);
	// wg.addEdge(0, 2, 1, false);
	// wg.addEdge(2, 1, -2, true);


	// bool isNegCycle = false;
	// auto ans = bellmanFord(wg, 0, isNegCycle);
	// printVec(ans);
	// cout << isNegCycle;

	//Floyd Warshall
	// WeightedGraph wg(5);
	// wg.addEdge(0,1,2,0);
	// wg.addEdge(0,4,3,0);
	// wg.addEdge(0,2,1,0);
	// wg.addEdge(2,4,1,0);
	// wg.addEdge(2,1,1,0);
	// wg.addEdge(1,3,4,0);
	// wg.addEdge(3,4,5,0);;
	// wg.addEdge(3,2,3,0);
	// wg.addEdge(3,0,1,0);
	// auto ans = floydWarshall(wg);
	// printMat(ans);

	// Prim
	WeightedGraph wg(5);
	wg.addEdge(0, 1, 4);
	wg.addEdge(0, 2, 4);
	wg.addEdge(0, 4, 6);
	wg.addEdge(4, 3, 9);
	wg.addEdge(0, 3, 6);
	wg.addEdge(3, 2, 8);
	wg.addEdge(1, 2, 2);
	int ans = kruskal(wg);
	cout << ans;
}