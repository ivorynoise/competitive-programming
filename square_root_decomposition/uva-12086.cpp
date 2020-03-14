// no of elements less than or equal to x upperbound-v.end
// no of elements less than x lowerbound - v.begin
// fflush(stdout) ("%I64d")
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
const int D             = 200000+5;
int BSIZE;
int n, m;
int arr[D], prei[D];

void pre(){
    int curBlock = -1;  // sentinel
    for(int i = 0; i < n; ++i){
        if (i % BSIZE == 0){
            ++curBlock;
        }
        prei[curBlock]+=arr[i];
    }
}

void pointupdate(int idx, int val){
    --idx;
    int curBlock = idx / BSIZE;
    prei[curBlock]-= arr[idx];
    arr[idx] = val;
    prei[curBlock]+= arr[idx];
}

int query(int l, int r){
    --l;--r;
    int curBlock = l / BSIZE;
    int ans = 0;
    while(l <= r){
        if (l%BSIZE == 0 && min(n-1, l+BSIZE-1)<= r){
            if (l/BSIZE != curBlock) ++curBlock;
            ans += prei[curBlock];
            l += BSIZE;
        }
        else {
            ans += arr[l];
            ++l;
        }
    }
    return ans;
}

int main(){
    iofile();
    int x;
    int cnt = 0;
    while(true){
        scd(x);
        if (!x) break;
        if (cnt) puts("");
        n = x;
        BSIZE = ceil(sqrt(n));
        for(int i = 0; i < n; ++i){
            scd(arr[i]);
        }
        mmset(prei, 0);
        pre();
        char c[4];
        pr("Case %d:\n", ++cnt);
        while(true) {
            sc("%s", c);
            if (c[0]=='E') break;
            else if (c[0]=='S'){
                int idx, val;
                scd(idx);scd(val);
                pointupdate(idx, val);
            }
            else if (c[0]=='M'){
                int l,r;
                scd(l);scd(r);
                int ans = query(l, r);
                prd(ans);
            }
        }
    }
    return 0;
}
