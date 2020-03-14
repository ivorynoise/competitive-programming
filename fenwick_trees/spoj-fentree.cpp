#include <bits/stdc++.h>
using namespace std;
const int inf           = 1<<28;
const int D             = (int)1e6+5;
typedef long long       lli;
typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<vi>      vvi;
typedef vector<bool>    vb;
#define sc              scanf
#define scd(a)          scanf("%d", &a)
#define scs(a)          scanf("%s", a)
#define prd(a)          printf("%d\n", a)
#define fr              first
#define sec             second
#define pb(a)           push_back(a)
#define all(a)          a.begin(),a.end()
void clr()              {char c; while((c=getchar())!= '\n' && c != EOF);}
void inputVec(vi&v)     {for (auto&i : v)scd(i);}
void printVec(vi&v)     {for (auto&i : v)prd(i);}
void printMat(vvi& mat) {for (auto&v : mat) {for (auto&x : v)cout << x << " ";} cout << endl;}
int left(int i)         {return i << 1;}
int right(int i)        {return (i << 1) + 1;}
int mid(int a, int b)   {return (a + b) >> 1;}
int mid1(int a, int b)  {return ((a+b)>>1)+1;}
void iofile()           {freopen(R"(../in)", "r", stdin);freopen(R"(../out)", "w", stdout);}
/*************************/
//int v[D];
//lli t[D];
vi v;
vector<lli> t;

void update(int i, int val, int n){
    while(i <= n){
        t[i]+= val;
        i += i&(-i);
    }
}

void build(int n){
    for(int i = 1; i <= n; ++i){
        update(i, v[i],n);
    }
}

lli getPrefixSum(int i){
    lli ans = 0;
    while(i > 0){
        ans += t[i];
        i -= i&(-i);
    }
    return  ans;
}

lli query(int l, int r){
    return getPrefixSum(r) - getPrefixSum(l - 1);
}

int main(){
    iofile();
    int n;
    scd(n);
    v.resize(n + 1);
    t.resize(n+1, 0);
    for (int j = 1; j <= n; ++j) {
        scd(v[j]);
    }
    int q;
    scd(q);clr();
    char c;
    int l,r;
    build(n);
    for (int i = 0; i < q; ++i) {
        sc("%c %d %d", &c,&l,&r);clr();
        lli ans = 0;
        switch(c){
            case 'u':
                update(l, r,n); // i x
                break;
            case 'q' :
                ans = query(l,r);
                printf("%lld\n",ans);
        }
    }
    return 0;
}