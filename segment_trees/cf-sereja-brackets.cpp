#include <bits/stdc++.h>
using namespace std;
const int inf = 1e6;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef long long lli;
void inputVec(vi&v) {for (auto&i : v)cin >> i;}
void printVec(vi&v) {for (auto&i : v)cout << i << " "; cout << endl;}
void printMat(vvi& mat) {for (auto&v : mat) {for (auto&x : v)cout << x << " ";} cout << endl;}
int left(int i) {return i << 1;}
int right(int i) {return (i << 1) + 1;}
int mid(int a, int b) {return (a + b) >> 1;}
int mid1(int a, int b){ return ((a+b)>>1)+1;}
void iofile(){freopen(R"(../in)", "r", stdin);};
const int D = 1e6+5;
#define sc scanf
#define scd(a) scanf("%d", &a)
#define scs(a) scanf("%s", a)
#define pr(a) printf("%d\n", a)
#define freq first
#define val second

// IGNORE ABOVE THIS LINE
/*************/

int t[4*D][3];
char a[D];
void mergeInt(int l[], int r[], int a[]){
   int tmp = min(l[0],r[1]);
    a[2]=l[2]+r[2]+2*tmp;
    a[1]=l[1]+(r[1]-tmp);
    a[0]=r[0]+(l[0]-tmp);
}

void build(int root, int be, int en){
    if(be > en) return;

    if (be == en){
        t[root][0]=a[be]=='(';
        t[root][1]=a[be]==')';
        t[root][2]=0;
        return;
    }
    build(left(root), be, mid(be,en));
    build(right(root), mid1(be,en), en);
    mergeInt(t[left(root)], t[right(root)], t[root]);
}

void query(int root, int be, int en, int i, int j, int a[]){
    if (be > en || j < be || i > en){
        return;
    }
    if (i <= be && en <= j){
        a[0]=t[root][0];
        a[1]=t[root][1];
        a[2]=t[root][2];
        return;
    }
    int l[3] = {}, r[3]={};
    query(left(root), be, mid(be,en), i, j, l);
    query(right(root), mid1(be,en), en,i, j,r);
    mergeInt(l,r,a);
}

int main(){
//    iofile();
    int n,m;
    int l,r;
    scs(a);
    scd(m);
    n=strlen(a);
    build(1,0,n-1);
    for(int i = 0; i < m; ++i){
        scd(l);
        scd(r);
        int tmp[3]={};
        query(1,0,n-1,l-1,r-1,tmp);
        pr(tmp[2]);
    }
    return 0;
}
