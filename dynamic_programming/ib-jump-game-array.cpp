#include <iostream>
#include <vector>
using namespace std;

bool canJump(vector<int> A) {
    int n = A.size();
    vector<int> dp(n, 0);
    dp[0] = 1;

    for (int j = 0; j < n; ++j) {
        int nj = A[j];
        int srt = j + 1;
        int end = min(n - 1, srt + nj);
        while (dp[j] && srt <= end) {
            dp[srt] = 1;
            if (dp[n - 1]) return 1;
            ++srt;
        }
    }
    return dp[n - 1];
}

int main(){
    vector<int> a = {0, 2};
    canJump(a);
}