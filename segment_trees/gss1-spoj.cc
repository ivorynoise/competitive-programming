#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
void iofile() {freopen("/home/deepak/ds-algo/in", "r", stdin);}
void inputVec(vector<int>& ans) {for (int& x : ans) {cin >> x;}}
const int inf = (int)1e9;
int left(int i) {return (i << 1) + 1;}
int right(int i) {return (i << 1) + 2;}
int mid(int a, int b) { return (a + b) >> 1; }
template<typename T> T maxElement(T n) {return n;}
template<typename T, class... Args>T maxElement(T x, Args... a) {T ans = maxElement(a...); return max(ans, x);}
typedef int integer;

/*********************************/
struct Pair
{
    integer total, pre, post, mxm;
    Pair() {}
    Pair(integer a, integer b, integer c, integer d) {
        total = a;
        pre = b;
        post = c;
        mxm = d;
    }
};
vector<Pair> tree;
vi v;

void build(int root, int a, int b) {
    if (b < a) return;

    if (a == b) {
        Pair p(v[a], v[a], v[a], v[a]);
        tree[root] = p;
        return;
    }

    build(left(root), a, mid(a, b));
    build(right(root), mid(a, b) + 1, b);
    Pair p;
    Pair l = tree[left(root)];
    Pair r = tree[right(root)];
    p.total = l.total + r.total;
    p.pre = maxElement(l.pre, p.total, l.total + r.pre);
    p.post = maxElement(l.post + r.total, r.total, p.total);
    p.mxm = maxElement(l.mxm, r.mxm, l.post + r.pre);
    tree[root] = p;
}

Pair query(int root, int a, int b, int x, int y) {
    if (a > b || b < x || y < a) {
        return Pair(-inf, -inf, -inf, -inf);
    }

    if (x <= a && b <= y) {
        return tree[root];
    }

    Pair l = query(left(root), a, mid(a,b), x, y);
    Pair r = query(right(root), mid(a, b)+ 1,b, x, y);
    Pair p;
    p.total = l.total + r.total;
    p.pre = maxElement(l.pre, p.total, l.total + r.pre);
    p.post = maxElement(l.post + r.total, r.total, p.total);
    p.mxm = maxElement(l.mxm, r.mxm, l.post + r.pre);
    return p;

}

int query(int l, int r, int n) {
    Pair ans = query(0, 0, n - 1, l - 1, r - 1);
    return ans.mxm;
}

int main() {
    iofile();
    int n;
    cin >> n;
    v.resize(n);
    tree.resize(4 * n);
    inputVec(v);
    build(0, 0, n - 1);
    int q;
    cin >> q;
    int l , m;
    for (int i = 0; i < q; ++i) {
        cin >> l >> m;
        integer ans = query(l, m, n);
        cout << ans << endl;
    }
    return 0;
}