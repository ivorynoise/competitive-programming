// https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/roy-and-coin-boxes-1/description/
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
void iofile() {freopen("/home/deepak/ds-algo/in", "r", stdin);}
void inputVec(vector<int>& ans){for(int& x : ans) {cin >> x;}}
const int inf = (int)1e9;
int left(int i) {return (i << 1) + 1;}
int right(int i) {return (i << 1) + 2;}
int mid(int a, int b) { return (a + b) >> 1; }

vi tree, lazy, v, arr;

void update(int root, int a, int b, int i, int j){
    if (a > b || j < a || i > b) return;

    if (i <= a && b <= j){
        int val = 1;
        val+=tree[root];
        if (a == b){
            // leaf node
            tree[root] = val;
        }
        else {
            tree[root] = 0;
            tree[left(root)] = val;
            tree[right(root)] = val;
        }
    }

    update(left(root), a, mid(a, b), i, j);
    update(right(root), mid(a, b) + 1, b, i, j);;
}


int query(int root, int a, int b, int i, int j){
    if (a > b || j < a || i > b) return 0;

    if (i <= a && b <= j){
        int val = 1;
        val+=tree[root];
        if (a == b){
            // leaf node
            tree[root] = val;
        }
        else {
            tree[root] = 0;
            tree[left(root)] = val;
            tree[right(root)] = val;
        }
        return tree[root];
    }

    int x = query(root,a,mid(a,b), i,j);
    int y = query(root, mid(a,b)+1,b, i,j);
    return max(x,y);
}

int main(){
    iofile();
    int n, m;
    cin >> n >> m;
    tree.resize(4*n);
    lazy.resize(4*n);
    v.resize(n);
//    inputVec(v);
    // build(0, 0, n-1);

    int l,r;
    for(int i = 0; i < m; ++i){
        cin >> l >> r;
        update(0, 0, n-1, l-1, r-1);
    }

    arr.resize(n, 0);
    for(int i = 0; i < n; ++i){
        int noc=query(0, 0, n -1, i, i);
        arr[noc]++;
    }

    vi dp(m+1, 0);
    dp[m] = arr[m];
    for(int i = m-1; m>=0; --m){
        dp[i] = dp[i +1]+arr[i];
    }

    int q, d;
    for(int i = 0; i < q; ++i){
        cin >> d;
        if (d > m) cout << 0 << endl;
        cout << dp[d] << endl;
    }
    return 0;

}