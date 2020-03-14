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
typedef long long       lli;
typedef pair<int, int>  ii;
typedef tuple<int, int, int> iii;
typedef vector<int>     vi;
typedef vector<vi>      vvi;
typedef vector<bool>    vb;
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
void inputVec(vi&v)     {for (auto&i : v)scd(i);}
void printVec(vi&v)     {for (auto&i : v)prd(i);}
void printMat(vvi& mat) {for (auto&v : mat) {for (auto&x : v)cout << x << " ";} cout << endl;}
int left(int i)         {return i << 1;}
int right(int i)        {return (i << 1) + 1;}
int mid(int a, int b)   {return (a + b) >> 1;}
int mid1(int a, int b)  {return ((a+b)>>1)+1;}
void iofile()           {freopen(R"(../in)", "r", stdin);freopen(R"(../out)", "w", stdout);}
/*************************/
const int D             = (int)4e4+5;
ii q[D];
set<int> s;
int t[2*D*4];

void shift(int root){
    t[left(root)] = t[root];
    t[right(root)] = t[root];
}

// update
void update(int root, int be, int en, int i, int j, int val){
    if (be >en or j < be or  i>en) return;

    // segment lies within the range
    if (i <= be and en <= j){
        t[root] = val;
        return;
    }
    if (t[root]){
        shift(root);
        t[root] = 0;
    }
    update(left(root), be, mid(be, en), i, j, val);
    update(right(root), mid1(be,en), en, i, j, val);
}

// query
void query(int root, int be, int en, int i, int j){
    if (be > en or j < be or i > en) return;

    // if segment lies in the range
    if (i <= be and j >= en){
        if (t[root] != 0) s.insert(t[root]);
        return;
    }

    // if poster covers the entire segment
    if (be <= i && en >= j && t[root]){
        s.insert(t[root]);
        return;
    }
    query(left(root), be, mid(be, en), i, j);
    query(right(root), mid1(be, en), en, i, j);
}

int main(){
    iofile();
    int tc;
    scd(tc);
    for(int k = 0; k < tc; ++k){
        mmset(t,0);
        s.clear();

        int n;
        scd(n);
        // coordinate compression
        map<int,int> m;
        for(int j = 1; j <= n; ++j) {
            int l, r;
            scd(l);
            scd(r);
            q[j] = make_pair(l,r);
//            pr("%d %d\n",l,r);
            m[l] = 0;
            m[r] = 0;
        }
        int pos = 1;
        for(auto it = m.begin(); it != m.end(); ++it){
            it->sec = pos;
            ++pos;
        }
        int maxLen = 0;
        for(int j = 1; j <= n; ++j){
            int l, r;
//            pr("%d %d\t", q[j].fr, q[j].sec);
            l = m[q[j].fr];
            r = m[q[j].sec];
//            pr("%d %d\n", l, r);
            maxLen = max(maxLen, r);
            q[j] = make_pair(l,r);
        }

        for(int i = 1; i <= n; ++i) {
            int l, r;
            l = q[i].fr;
            r = q[i].sec;
            update(1, 1, maxLen, l, r, i);
        }

        for(int i = 1; i <= maxLen; ++i){
            query(1, 1, maxLen, i, i);
        }
        prd(s.size());
    }
    return 0;
}