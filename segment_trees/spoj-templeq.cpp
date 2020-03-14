#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define PII       pair<int,int>
#define all(c)    c.begin(),c.end()
#define sz(c)     (int)c.size()
#define clr(c)    c.clear()
#define pb        push_back
#define mp        make_pair
#define cin(x)    scanf("%d",&x)
#define MOD		1000000007
#define EPS		1E-10
void iofile()           {freopen(R"(../in)", "r", stdin);freopen(R"(../out)", "w", stdout);}

const int maxn = 100010;
int posInTree[maxn];
int posInArray[maxn];
vector< PII > temp;

int segtree[4 * maxn];
int lazy[4 * maxn];

void buildTree(int l, int r, int pos)
{
    lazy[pos] = 0;
    if(l == r)
    {
        segtree[pos] = temp[l - 1].first;
        return;
    }
    int mid = (l + r) >> 1;
    buildTree(l, mid, 2 * pos);
    buildTree(mid + 1, r, 2 * pos + 1);
    segtree[pos] = max(segtree[2 * pos], segtree[2 * pos + 1]);
}

void lazy_update(int l, int r, int pos)
{
    if(!lazy[pos]) return;
    segtree[pos] += lazy[pos];
    if(l != r)
    {
        lazy[2 * pos] += lazy[pos];
        lazy[2 * pos + 1] += lazy[pos];
    }
    lazy[pos] = 0;
}

int n;

// return index of lowest
int getID(int l, int r, int pos, int reqd)
{
    int mid = (l + r) >> 1;
    lazy_update(l, r, pos);
    if(l != r)
    {
        lazy_update(l, mid, 2 * pos);
        lazy_update(mid+1,r,2*pos+1);
    }
    if(segtree[pos] < reqd) return n + 1;
    if(l == r) return l;
    if(segtree[2 * pos] >= reqd)
        return getID(l, mid, 2 * pos, reqd);
    else
        return getID(mid + 1, r, 2 * pos + 1, reqd);
}

//subtract one over range
void update(int lQ, int rQ, int val, int l, int r, int pos)
{
    lazy_update(l, r, pos);
    if(l > r or lQ > rQ) return;
    if(l > rQ or r < lQ) return;
    if(l >= lQ && r <= rQ)
    {
        lazy[pos] += val;
        lazy_update(l,r,pos);
        return;
    }
    int mid = (l + r) >> 1;
    update(lQ, rQ, val, l, mid, 2 * pos);
    update(lQ, rQ, val, mid + 1, r, 2 * pos + 1);
    segtree[pos] = max(segtree[2 * pos], segtree[2 * pos + 1]);
}

int getVal(int idx, int l, int r, int pos)
{
    lazy_update(l,r,pos);
    if(l == r) return segtree[pos];
    int mid = (l + r) >> 1;
    if(mid >= idx)
        return getVal(idx, l, mid, 2 * pos);
    else
        return getVal(idx, mid + 1, r, 2 * pos + 1);
}

void debug()
{
    cout << "DEBUG\n";
    for(int i = 1; i <= n; i++)
        cout << i << " : " << getVal(posInTree[i], 1, n, 1) << "\n";
    cout << "END\n";
}

int main()
{
    iofile();
    int q;
    cin(n);
    cin(q);
    for(int i = 1; i <= n; i++)
    {
        int x;
        cin(x);
        temp.pb({x, i});
    }
    sort(all(temp));
    for(int i = 1; i <= n; i++)
    {
        int idx = temp[i - 1].second;
        posInTree[idx] = i;
        posInArray[i] = idx;
    }
    buildTree(1, n, 1);
    while(q--)
    {
        int t;
        cin(t);
        int x;
        cin(x);
        if(t == 3)
        {
            int startId = getID(1, n, 1, x);
            update(startId, n, -1, 1, n, 1);
        }
        else if(t == 2)
        {
            int ans = n - getID(1, n, 1, x) + 1;
            printf("%d\n", ans);
        }
        else
        {
            int val = getVal(posInTree[x], 1, n, 1);
            int id2 = posInArray[getID(1, n, 1, val + 1) - 1];
            int id1 = x;
            int t2 = posInTree[id2];
            int t1 = posInTree[id1];
            posInArray[t1] = id2, posInArray[t2] = id1;
            posInTree[id1] = t2, posInTree[id2] = t1;
            update(posInTree[x], posInTree[x], 1, 1, n, 1);
        }
    }
    return 0;
}