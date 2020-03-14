#include <bits/stdc++.h>
using namespace std;
const int inf           = 1<<28;
const int D             = (int)1e6+5;
typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<vi>      vvi;
typedef vector<bool>    vb;
typedef long long       lli;
#define sc              scanf
#define scd(a)          scanf("%d", &a)
#define scs(a)          scanf("%s", a)
#define prd(a)           printf("%d\n", a)
#define freq            first
#define val             second
#define pb(a)           push_back(a)
#define all(a)          a.begin(),a.end()
void inputVec(vi&v)     {for (auto&i : v)scd(i);}
void printVec(vi&v)     {for (auto&i : v)prd(i);}
void printMat(vvi& mat) {for (auto&v : mat) {for (auto&x : v)cout << x << " ";} cout << endl;}
int left(int i)         {return i << 1;}
int right(int i)        {return (i << 1) + 1;}
int mid(int a, int b)   {return (a + b) >> 1;}
int mid1(int a, int b)  {return ((a+b)>>1)+1;}
void iofile()           {freopen(R"(../in)", "r", stdin);freopen(R"(../out)", "w", stdout);}
/*************************/
vi v;
vvi t;

// Time Complexity 4nLogn??
void build(int root, int be, int en){
    if (be > en) return;
    if (be == en){
        t[root].push_back(v[be]);
        return;
    }
    build(left(root), be, mid(be, en));
    build(right(root), mid1(be, en), en);
    t[root].resize(en-be+1);
    merge(all(t[left(root)]), all(t[right(root)]), t[root].begin());
}

// log4n + logN
int query(int root, int be, int en, int i, int j, int k){
    if (be > en || i > en || j < be) return  0;

    if (i <= be && j >= en){
        return t[root].end()-upper_bound(all(t[root]), k);
    }

    int q1 = query(left(root), be, mid(be, en), i, j, k);
    int q2 = query(right(root), mid1(be, en), en, i, j, k);
    return q1+q2;
}

int main(){
//    iofile();
    int n;
    scd(n);
    v.resize(n);
    t.resize(4*n+10);
    inputVec(v);
    int q;
    scd(q);
    build(1, 0,n-1);
    int a, b, k;
    int last_ans = 0;
    for (int i = 0; i < q; ++i) {
        sc("%d%d%d", &a, &b,&k);
        last_ans=query(1,0,n-1,max(a^last_ans,0)-1, min(b^last_ans,n)-1, k^last_ans);
        prd(last_ans);
    }
    return 0;
}