// https://www.interviewbit.com/problems/kth-manhattan-distance-neighbourhood/
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
const int inf = 1e6;

bool check(int i, int j, int m, int n){
    return
    i >= 0 && i < m &&
    j >= 0 && j < n;
}

vector<vector<int> > solve(int A, vector<vector<int> > &B) {
    int m = B.size();
    int n = B[0].size();

    vector<vi> before(m, vi(n, -inf));
    vector<vi> current(m, vi(n, 0));

    int r[] = {0,-1,+1,0,0};
    int c[] = {0,0,0,+1,-1};

    for(int k = 0; k < A; ++k){
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                int best = B[i][j];
                for(int dir = 0; dir < 5; ++dir){
                    int next_i = i + r[dir];
                    int next_c = j + c[dir];
                    if (check(next_i, next_c, m, n)){
                        best = max(best, before[next_i][next_c]);
                    }
                }
                current[i][j] = best;
            }
        }
        swap(before, current);
    }
    return before;
}

int main(){
    vector<vi> B = {{1,2,4}, {4,5,8}};
    int A = 2;
    solve(A, B);
}