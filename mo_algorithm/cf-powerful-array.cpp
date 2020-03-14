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
const int D             = (int)200000+3;
const int DIM           = (int)1e6+5;
int n, t;
lli arr[D];
iii q[D];
int BLOCKSIZE;
lli qans[D];
lli ans = 0;
int cnt[D];

void add(int idx){
    // element to be add
    lli s = arr[idx];
    int& a = cnt[s];
//    ans += (2LL*a+1LL)*s; // (K+1)^2.s = K2 + 12 + 2ks  // k being freq of the number
    ++a;
}

void remove(int idx){
    // element to be subtracted
    lli s = arr[idx];
    int& a = cnt[s];
    ans += (1LL-2LL*a)*s;
    --a;
}

void mo_algo(){
    int curL, curR;
    curL = 0;
    curR = 0;

    for(int i = 1; i <= t; ++i){
        const auto& curq = q[i];
        int L = get<0>(curq);
        int R = get<1>(curq);
        int qIdx = get<2>(curq);

        // remove
        while(curL < L){
            remove(curL);
            ++curL;
        }
        // add
        while(curL > L){
            add(curL-1);
            --curL;
        }
        // add
        while(curR < R){
            add(curR+1);
            ++curR;
        }
        // remove
        while(curR > R){
            remove(curR);
            --curR;
        }
        qans[qIdx] = ans;
    }
}


int main(){
    // iofile();
    scd(n); scd(t);
    for(int i = 1; i <= n; ++i){
        scd(arr[i]);
    }
    for(int i = 1; i <= t; ++i){
        int l, r;
        scd(l);
        scd(r);
        q[i] = make_tuple(l, r, i);
    }
    BLOCKSIZE = ceil(sqrt(n));
    sort(q+1, q+t+1, [](const iii&a, const iii&b){
        int l1,l2,r1,r2;
        l1 = get<0>(a); r1=get<1>(a);
        l2 = get<0>(b); r2=get<1>(b);
        if (l1/BLOCKSIZE == l2/BLOCKSIZE){
            return r1 < r2;
        }
        return l1 < l2;
    });
    mo_algo();
    for(int i = 1; i <= t; ++i){
//        pr("%I64d\n", qans[i]);
        cout << qans[i] << endl;
    }
    return  0;
}