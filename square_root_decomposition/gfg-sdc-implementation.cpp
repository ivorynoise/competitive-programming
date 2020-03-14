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
const int D             = (int)4e4+5;

int pre[100];
int arr[100];
int BSIZE;
int n;
void preprocess(){
    BSIZE = ceil(sqrt(n));
    for(int curBlock = 0; curBlock < BSIZE; ++curBlock){
        int srt = curBlock*BSIZE;
        int end = min(n, srt+BSIZE);
        while(srt < end){
            pre[curBlock] += arr[srt];
            ++srt;
        }
    }
}

void pointUpdate(int idx, int val){
    int blockNum = idx/BSIZE;
    pre[blockNum] -= arr[idx];
    arr[idx] = val;
    pre[blockNum] += arr[idx];
}

int query(int l, int r){
    int srt = l;
    int end = r;
    int curBlock = l/BSIZE;
    int ans = 0;
    while(srt <= end){
        if (srt % BSIZE == 0 && srt + BSIZE - 1 <= end){
            if (l/BSIZE != curBlock) curBlock++;
            ans += pre[curBlock];
            srt += BSIZE;
        }
        else{
            ans+=arr[srt];
            ++srt;
        }
    }
    return  ans;
}


int main(){
    iofile();
    scd(n);
    for(int i = 0; i < n; ++i){
        scd(arr[i]);
    }
    preprocess();
    int l, r;
    scd(l);scd(r);
    cout << query(l,r) << endl;
    int idx; scd(idx);
    int val; scd(val);
    pointUpdate(idx,val);
    scd(l);scd(r);
    cout << query(l,r) << endl;
}

