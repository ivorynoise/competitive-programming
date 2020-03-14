// no of elements less than or equal to x upperbound
// no of elements less than x lowerbound
// TODO solve in O(N*log(N)*log(N))
// TODO https://discuss.codechef.com/questions/94448/merge-sort-tree-tutorial

#include <bits/stdc++.h>

using namespace std;
/*ONLY FOR GNU*/
#include <ext/pb_ds/assoc_container.hpp>    // Common file
#include <ext/pb_ds/tree_policy.hpp>        // Including tree_order_statistics_node_update

using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
/* tree.find_by_order(i) == gives element at ith position in tree
 tree.order_by_key(val)== gives iterator to upper_bound(x)*/
/* GNU SPECIFIC ENDS*/
const int inf = 1 << 28;
typedef long long lli;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
#define sc              scanf               /*remember that %c %n %[] does NOT consume whitespaces*/
#define scd(a)          scanf("%d", &a)
#define scs(a)          scanf("%s", a)
#define pr              printf
#define prd(a)          printf("%d\n", a)
#define fr              first
#define sec             second
#define pb(a)           push_back(a)
#define all(a)          a.begin(),a.end()
#define mmset(a, b)     memset(a, b, sizeof(a))

void inputVec(vi &v) { for (auto &i : v)scd(i); }

void printVec(vi &v) { for (auto &i : v)prd(i); }

void printMat(vvi &mat) {
    for (auto &v : mat) { for (auto &x : v)cout << x << " "; }
    cout << endl;
}

int left(int i) { return i << 1; }

int right(int i) { return (i << 1) + 1; }

int mid(int a, int b) { return (a + b) >> 1; }

int mid1(int a, int b) { return ((a + b) >> 1) + 1; }

void iofile() {
    freopen(R"(../in)", "r", stdin);
    freopen(R"(../out)", "w", stdout);
}

/*************************/
const int D = (int) 4e4 + 5;
vi arr, t[4 * D];
int n, q;

void build(int id, int be, int en) {
    if (be > en) return;
    if (be == en) {
        t[id].pb(be);
        return;
    }
    build(left(id), be, mid(be, en));
    build(right(id), mid1(be, en), en);
    merge(all(t[left(id)]), all(t[right(id)]), back_inserter(t[id]),
          [](const int &a, const int &b) { return arr[a] < arr[b]; }
    );
}

int query(int id, int be, int en, int l, int r, int k){

}

int main() {
    scd(n);
    scd(q);
    for (int i = 1; i <= n; ++i) {
        scd(arr[i]);
    }
    build(1, 1, n);
    for (int i = 1; i <= q; ++i) {
        int l, r, k;
        scd(l);
        scd(r);
        scd(k);
        int ans = query(1, 1, n, l, r, k);
        prd(ans);
    }
    return 0;


}