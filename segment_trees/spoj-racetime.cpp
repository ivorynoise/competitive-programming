// no of elements less than or equal to x upperbound-v.end
// no of elements less than x lowerbound - v.begin
// fflush(stdout) ("%I64d")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>    // Common file
#include <ext/pb_ds/tree_policy.hpp>        // Including tree_order_statistics_node_update
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
/*
 * tree.find_by_order(key) == gives iterator at key th position in tree...arr[i]
 * tree.order_of_key(key)== number of elements that are smaller than key...i for arr[i]
 * GNU SPECIFIC ENDS
 */
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
const int D             = (int)1e5+5;
map<int, int> m[4*D];
int arr[D];
int n, q;

void mergeMap(int a, int b, int c){
    auto& mapA = m[a];
    auto& mapB = m[b];
    auto& mapC = m[c];
    auto i = mapA.begin();
    auto j = mapB.begin();
    auto ei = mapA.end();
    auto ej = mapB.end();

    while(i != ei && j != ej){
        int x = i->first;
        int y = j->first;
        if (x == y){
            mapC[x] = mapA[x] + mapB[y];
            ++i;
            ++j;
        }
        else if (x > y){
            mapC[y] = mapB[y];
            ++j;
        }
        else {
            mapC[x] = mapA[x];
            ++i;
        }
    }
    while(i != ei){
        mapC[i->first] = i->second;
        ++i;
    }
    while(j != ej){
        mapC[j->first] = j->second;
        ++j;
    }
}

void build(int id, int be, int en){
    if (be > en){
        return;
    }
    if (be == en){
        int curElem = arr[be];
        m[id][curElem] = 1;
        return;
    }
    build(left(id), be, mid(be, en));
    build(right(id), mid1(be, en), en);
    mergeMap(left(id), right(id), id);

}
int query(int id, int be, int en, int i, int j, int val){
    if (be > en or j < be or i > en) return 0;

    if (i <= be and j >= en){
        return
    }

}
void update(int id, int be, int en, int i, int val){

}

int main(){
    scd(n);
    for(int i = 0; i < n; ++i){
        scd(arr[i]);
    }
    build(1, 0, n-1);
    for(int i = 0; i < q; ++i){
        char c;
        sc(" %c", &c);
        if (c=='M'){
            int idx, val;
            sc("%d %d", &idx, &val);
            update(1, 0, n-1, idx-1, val);    //idx , val
        }
        else {
            int l, r, ai;
            sc("%d %d %d", &l, &r, &ai);
            int ans = query(1, 0, n-1, l-1, r-1, ai);
            prd(ans);
        }
    }
    return 0;
}