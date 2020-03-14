// no of elements less than or equal to x upperbound
// no of elements less than x lowerbound
// basic implementation

// TODO solve using BIT/SegTree

#include <bits/stdc++.h>
using namespace std;
/*ONLY FOR GNU*/
#include <ext/pb_ds/assoc_container.hpp>    // Common file
#include <ext/pb_ds/tree_policy.hpp>        // Including tree_order_statistics_node_update
using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
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
int n,q, BLOCKSIZE;
const int DIM = 30000+5;
const int QDIM= 200000+1;
int arr[DIM];
int cnt[DIM];
int qans[QDIM];
iii queries[QDIM];

void mo_algo(){
    int ans = 1;
    int curL = 0;
    int curR = 0;
    cnt[arr[curL]] = 1;

    for(int i = 0; i < q; ++i){
        int L = get<0>(queries[i]);
        int R = get<1>(queries[i]);
        int queryIdx = get<2>(queries[i]);

        while(curL < L){
            // remove
            int curElem = arr[curL];
            if (cnt[curElem] == 1){
                --ans;
            }
            --cnt[curElem];
            ++curL;
        }

        while(curL > L){
            // add
            int curEle = arr[curL-1];
            if (cnt[curEle] == 0){
                ++ans;
            }
            ++cnt[curEle];
            --curL;
        }

        while(curR < R){
            // add
            int curEle = arr[curR+1];
            if (cnt[curEle] == 0){
                ++ans;
            }
            ++cnt[curEle];
            ++curR;
        }

        while (curR > R){
            // remove
            int curEle = arr[curR];
            if (cnt[curEle] == 1){
                --ans;
            }
            --cnt[curEle];
            --curR;
        }
        qans[queryIdx] = ans;
    }
}
int main(){
    iofile();
    scd(n);
    map<int, int> m;
    for(int i = 0; i < n; ++i){
        scd(arr[i]);
        m[arr[i]];
    }

    // coordinate compression
    int pos = 0;
    for(auto& cur:m){
        cur.second = pos++;
    }
    for(int i = 0; i < n; ++i){
        arr[i] = m[arr[i]];
    }

    scd(q);
    for(int i = 0; i < q; ++i){
        int l, r;
        scd(l); scd(r);
        get<0>(queries[i]) = l-1;
        get<1>(queries[i]) = r-1;
        get<2>(queries[i]) = i;
    }

    BLOCKSIZE = ceil(sqrt(n));
    sort(queries, queries+q, [](const iii& a, const iii& b){
        int l1 = get<0>(a), l2 = get<0>(b);
        int r1 = get<1>(a), r2 = get<1>(b);
        // same block number
        if (l1/BLOCKSIZE == l2/BLOCKSIZE){
            return r1 < r2;
        }
        return l1/BLOCKSIZE < l2/BLOCKSIZE;
    });

    mo_algo();
    for(int i = 0; i < q; ++i){
        prd(qans[i]);
    }
    return 0;
}