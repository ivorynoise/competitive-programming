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
void iofile(){freopen(R"(../in)", "r", stdin);};

const int D = 100001;
#define sc scanf
#define scd(a) scanf("%d", &a)
#define pr(a) printf("%d\n", a)
#define freq first
#define val second
// IGNORE ABOVE THIS LINE
/*************/

int n, q, a[D];
ii t[4*D][3];

void mergeInt(ii l[], ii r[], ii a[]){
    // prefix
    if (l[0].val == r[0].val){
        a[0].freq = l[0].freq + r[0].freq;
        a[0].val = l[0].val;
    }
    else{
        a[0].freq = l[0].freq;
        a[0].val = l[0].val;
    }

    // suffix
    if (l[2].val == r[2].val){
        a[2].freq = l[2].freq + r[2].freq;
        a[2].val = l[2].val;
    }
    else{
        a[2].freq = r[2].freq;
        a[2].val = r[2].val;
    }

    // total
    if (l[1].freq > r[1].freq){
        a[1].freq = l[1].freq;
        a[1].val = l[1].val;
    }
    else{
        a[1].freq = r[1].freq;
        a[1].val = r[1].val;
    }

    if(l[2].val == r[0].val){
        int tmp = l[2].freq + r[0].freq;
        if (tmp > a[1].freq){
            a[1].freq = tmp;
            a[1].val = l[2].val;
        }
    }
}

void build(int root, int be, int en){
    if (be > en){
        return;
    }
    if (be == en){
        t[root][0].val = a[be];
        t[root][0].freq = 1;
        t[root][1].val = a[be];
        t[root][1].freq = 1;
        t[root][2].val = a[be];
        t[root][2].freq = 1;
        return;
    }
    build(left(root), be, mid(be, en));
    build(right(root), mid(be, en)+1, en);
    mergeInt(t[left(root)], t[right(root)], t[root]);
}

void query(int root, int be, int en, int i, int j, ii a[]){
    if (be > en || j < be || i > en){
        return;
    }

    if (i <= be && en <= j){
        a[0] = t[root][0];
        a[1] = t[root][1];
        a[2] = t[root][2];
        return;
    }

    ii l[3], r[3];
    query(left(root), be, mid(be,en), i, j, l);
    query(right(root), mid(be,en)+1, en, i, j,r);
    mergeInt(l, r, a);
}


int main(){
    // iofile();
    while(true){
        scd(n);
        if (n == 0) break;
        scd(q);
        for(int i = 0; i < n; ++i){
            scd(a[i]);
        }
        build(1, 0, n-1);
        int i,j;
        for(int k = 1; k <= q; ++k){
            sc("%d %d", &i, &j);
            ii a[3];
            query(1, 0, n-1, i-1, j-1,a);
            pr(a[1].freq);
        }
    }
    return 0;
}