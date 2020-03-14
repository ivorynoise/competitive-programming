// Solve using BIT
// http://codeforces.com/blog/entry/10183
#include <bits/stdc++.h>
using namespace std;
/*ONLY FOR GNU*/
#include <ext/pb_ds/assoc_container.hpp>    // Common file
#include <ext/pb_ds/tree_policy.hpp>        // Including tree_order_statistics_node_update
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
/* tree.find_by_order(i) == gives element at ith position in tree
 tree.order_by_key(val)== gives iterator to upper_bound(x)*/
/* GNU SPECIFIC ENDS*/
const int inf           = 1<<28;
const int D             = (int)1e6+5;
typedef long long       lli;
typedef pair<int, int>  ii;
typedef tuple<int, int, int, int> iiii;
typedef vector<int>     vi;
typedef vector<vi>      vvi;
typedef vector<bool>    vb;
#define sc              scanf               /*remember that %c %n %[] does NOT consume whitespaces*/
#define scd(a)          scanf("%d", &a)
#define scs(a)          scanf("%s", a)
#define prd(a)           printf("%d\n", a)
#define fr            first
#define sec             second
#define pb(a)           push_back(a)
#define all(a)          a.begin(),a.end()
void inputVec(vi&v)     {for (auto&i : v)scd(i);}
void printVec(vi&v)     {for (auto&i : v)prd(i);}
void printMat(vvi& mat) {for (auto&v : mat) {for (auto&x : v)cout << x << " ";} cout << endl;}
int left(int i)         {return i << 1;}
int right(int i)        {return (i << 1) + 1;}
int mid(int a, int b)   {return (a + b) >> 1;}
int mid1(int a, int b)  {return ((a+b)>>1)+1;}
void iofile()           {
    freopen(R"(..\in)", "r", stdin);
     freopen(R"(..\out)", "w", stdout);
}
/*************************/
int n, q;
ii arr[D];
iiii que[D];
int BIT[D];
int ans[D];

int query(int idx){
    int ans = 0;
    while(idx){
        ans += BIT[idx];
        idx -= idx &(-idx);
    }
    return  ans;
}

int query(int l, int r){
    return  query(r) - query(l - 1);
}

void update(int idx){
    while(idx <= n){
        BIT[idx] += 1;
        idx += idx & (-idx);
    }
}

int main() {
   iofile();
    scd(n);
    int x;
    for (int i = 1; i <= n; ++i) {
        scd(x);
        arr[i] = make_pair(x, i);
    }
    sort(arr + 1, arr + n + 1, greater<ii>()); // sort in descending order
    scd(q);
    int l, r, k;
    for (int i = 1; i <= q; ++i) {
        scd(l);
        scd(r);
        scd(k);
        que[i] = make_tuple(k, l, r, i);
    }
    sort(que + 1, que + q + 1, greater<iiii>()); // sort queries based on k

    int curQuery = 1;
    int curArrPos = 1;
    
    while (curQuery <= q) {
        int curK = get<0>(que[curQuery]);
        while (curArrPos <= n && arr[curArrPos].fr > curK) {
            update(arr[curArrPos].sec); // update this particular index in original array
            ++curArrPos;
        }
        int querAns = query(get<1>(que[curQuery]), get<2>(que[curQuery]));
        ans[get<3>(que[curQuery])] = querAns;
        ++curQuery;
    }
    for (int i = 1; i <= q; ++i) {
        prd(ans[i]);
    }
    return 0;
}