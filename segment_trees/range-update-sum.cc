#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
void iofile() {freopen("/home/deepak/ds-algo/in", "r", stdin);}
void inputVec(vector<int>& ans){for(int& x : ans) {cin >> x;}}
const int inf = (int)1e9;
int left(int i) {return (i << 1) + 1;}
int right(int i) {return (i << 1) + 2;}
int mid(int a, int b) { return (a + b) >> 1; }


vi tree, tmp, arr;

void build(int root, int be, int en) {
    if (be > en) return;
    if (be == en) {
        tree[root] = arr[be];
        return;
    }

    int m = mid(be, en);
    build(left(root), be, m);
    build(right(root), m + 1, en);
    tree[root] = tree[left(root)] + tree[right(root)];
}

void update(int root, int be, int en, int i, int j, int val) {
    if (be > en || en < i || j < be) {
        return;
    }

    if (i <= be && en <= j) {
        val += tmp[root];
        tmp[root] = 0;
        tree[root] = (en - be + 1) * val + tree[root];
        tmp[left(root)] += val;     // problem!!
        tmp[right(root)]  += val;
        return;
    }

    int m = mid(be, en);
    update(left(root), be, m, i, j, val);
    update(right(root), m + 1, en, i, j, val);
    tree[root] = tree[left(root)] + tree[right(root)];
}

int query(int root, int be, int en, int i, int j) {
    if (be > en || en < i || j < be) {
        return 0;
    }

    if (i <= be && en <= j) {
        int val = tmp[root];
        tmp[root] = 0;
        tree[root] = (en - be + 1) * val + tree[root];
        tmp[left(root)] += val;     // problem!!
        tmp[right(root)]  += val;
        return tree[root];
    }

    int m = mid(be, en);
    int x = query(left(root), be, m, i, j);
    int y = query(right(root), m+1, en, i, j);
    return x + y;
}

int main(){
    iofile();
    int n,q; cin >> n >> q;
    tree.resize(4*n, 0);
    arr.resize(n, 0);
    tmp.resize(4*n, 0);
    inputVec(arr);
    build(0, 0, n-1);
    int x, y, ans;

    for(int i = 0; i < q; ++i){
        char c;
        cin >> c >> x >> y;
        switch(c){
            case 'q':
                ans = query(0, 0, n - 1, x-1, y-1);
                cout << ans << endl;
                break;
            case 'u':
                int val;
                cin >> val;
                update(0, 0, n-1, x-1, y-1, val);
        }

    }
    return 0;
}
