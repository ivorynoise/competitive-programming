#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
void iofile() {
    freopen("/home/deepak/ds-algo/in", "r", stdin);
}

class SegmentTree {
    vector<int> tree;
    int left(int i) {return (i << 1) + 1;}
    int right(int i) {return (i << 1) + 2;}
    const int inf = (int)1e9;

public:
    explicit SegmentTree(unsigned int n) {
        tree.resize(n, inf);
    }

    void build(int root, int be, int en, const vector<int>& v) {
        if (be > en) return;
        
        if (be == en) {
            tree[root] = v[be];
            return;
        }

        int mid = (be + en) / 2;
        build(left(root), be, mid, v);
        build(right(root), mid + 1, en,v);

        tree[root] = min(tree[left(root)], tree[right(root)]);
    }


    int query(int root, int be, int en, int i, int j, const vi& v) {
        if (be > en || j < be || i > en) {
            return inf;
        }

        if (i <= be && en <= j) {
            return tree[root];
        }

        int mid = (be + en) / 2;
        int x = query(left(root), be, mid, i, j, v);
        int y = query(right(root), mid + 1, en, i, j, v);
        return min(x, y);
    }

    void update(int root, int be, int en, int i, int x, const vi& v) {
        if (be > en || i < be || i > en) {
            return;
        }

        if (be == en) {
            tree[root] = x;
            return;
        }

        int mid = (be + en) / 2;
        update(left(root), be, mid, i, x, v);
        update(right(root), mid + 1, en, i, x, v);
        tree[root] = min(tree[left(root)], tree[right(root)]);

    }
};

void inputVec(vector<int>& ans) {
    for (int& x : ans) {
        cin >> x;
    }
}

int main(){
    iofile();
    unsigned int n, q;
    cin >> n >> q;
    vi v(n);
    inputVec(v);

    SegmentTree rmq(4*n);
    rmq.build(0, 0, n - 1, v);

    int x, y, ans;

    for(int i = 0; i < q; ++i){
        char c;
        cin >> c >> x >> y;
        switch(c){
            case 'q':
                ans = rmq.query(0, 0, n - 1, x-1, y-1, v);
                cout << ans << endl;
                break;
            case 'u':
                rmq.update(0, 0, n-1, x-1, y, v);
        }

    }
    return 0;
}