#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    vector<Node*> c;
    Node(int x){
        data = x; 
    }
};

map<int, Node*> m;
vector<int> v;
Node* root = NULL;

int cntLeaves(Node* root){
    if (root == NULL) return 0;
    
    bool isLeaf = true;
    for(int i = 0; i < root->c.size(); ++i){
        if (root->c[i] != NULL) isLeaf = false;
    }
    if (isLeaf) return 1;

    int ans = 0;
    for(int i = 0; i < root->c.size(); ++i){
        ans += cntLeaves(root->c[i]);
    }
    return ans;
}

int main(){
    int n, curPar;
    cin >> n;

    for(int i = 0; i < n; ++i){
        cin >> curPar;
        v.push_back(curPar);
        m[i] = new Node(i);
    }

    for(int i = 0; i < n; ++i){
        int curNode = i;
        int curPar = v[i];
        if (curPar == -1){
            root = m[i];
            continue;
        }
        m[curPar]->c.push_back(m[curNode]);
    }

    int delNode; cin >> delNode;
    Node* par = m[v[delNode]];
    for(int i = 0; par && i < par->c.size(); ++i){
        if (par->c[i] == m[delNode]){
            par->c[i] = NULL;
        }
    }

    if (!par) root = NULL;
    
    int ans = cntLeaves(root);
    cout << ans << endl;
}