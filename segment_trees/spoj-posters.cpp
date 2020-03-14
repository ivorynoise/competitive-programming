// http://www.spoj.com/problems/POSTERS/
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
const int D             = (int)1e7+5;
typedef long long       lli;
typedef pair<int, int>  ii;
typedef tuple<int, int, int> iii;
typedef vector<int>     vi;
typedef vector<vi>      vvi;
typedef vector<bool>    vb;
#define sc              scanf               /*remember that %c %n %[] does NOT consume whitespaces*/
#define scd(a)          scanf("%d", &a)
#define scs(a)          scanf("%s", a)
#define prd(a)          printf("%d\n", a)
#define fr              first
#define sec             second
#define pb(a)           push_back(a)
#define all(a)          a.begin(),a.end()
#define mmset(a, b)     memset(a, b, sizeof(a))
void inputVec(vi&v)     {for (auto&i : v)scd(i);}
void printVec(vi&v)     {for (auto&i : v)prd(i);}
void printMat(vvi& mat) {for (auto&v : mat) {for (auto&x : v)cout << x << " ";} cout << endl;}
int left(int i)         {return i << 1;}
int right(int i)        {return (i << 1) + 1;}
int mid(int a, int b)   {return (a + b) >> 1;}
int mid1(int a, int b)  {return ((a+b)>>1)+1;}
void iofile()           {freopen(R"(../in)", "r", stdin);freopen(R"(../out)", "w", stdout);}
/*************************/

// variable
int lazy[4*D+5];
set<int> s;
int n;

void shift(int root){
    lazy[left(root)] = lazy[root];
    lazy[right(root)] = lazy[root];
    lazy[root] = 0;
}

void update(int root, int be, int en, int i, int j, int val){
    if (be > en || j < be || i > en) return;

    if (i <= be && j >= en){
        // new value to come
       // if (lazy[root] != 0){   // this is not req
//            shift(root);
//        }
        lazy[root] = val;
        return;;
    }

    if (lazy[root]){    // propogate deeper
        shift(root);
        lazy[root] = 0;
    }

    update(left(root), be, mid(be, en), i, j, val);
    update(right(root), mid1(be, en), en, i, j, val);
}

void query(int root, int be, int en, int i, int j){
    if (be > en || j < be || i > en) return;

    if ((i <= be && j >= en)){ // segment within the range
        if(lazy[root])s.insert(lazy[root]); // think all possible cases
        return;
    }
    if ((be <= i && en >= j) && lazy[root] != 0){ // poster is overlapped with this poster
        s.insert(lazy[root]);
        return;
    }
    query(left(root), be, mid(be, en), i, j);
    query(right(root), mid1(be, en), en, i, j);
}

int main(){
    iofile();
    int t;
    scd(t);
    for(int i = 0; i < t; ++i){
        scd(n);
        mmset(lazy, 0);
        s.clear();
        int maxPoster = 0;
        for(int j = 1; j <= n; ++j){
            int l,r;
            scd(l);
            scd(r);
            maxPoster = max(maxPoster, r);  // depends on Ai, not n; O(10^7 log (10^7))
            update(1, 1, D, l, r, j);
        }
        for(int j = 1; j <= maxPoster; ++j){
            query(1, 1, D, j,j);            // without coordinate compression this is not going to cover the interleaves
        }
        prd(s.size());
    }
    return 0;
}