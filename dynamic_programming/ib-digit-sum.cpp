#include <iostream>
#include <vector>
using namespace std;

// const int km = 1000000007;
// int dp[1000][1000];

// int solve2(int n, int s, int be){
//     if (n == be){
//         return s == 0;
//     }

//     if (dp[be][s] != -1) return dp[be][s];

//     int ans = 0;
//     if (be == 0){
//         for(int dig = 1; dig <= 9; ++dig){
//             int diff = s - dig;
//             if (diff >= 0){
//                 ans += solve2(n, diff, be + 1) % km;
//                 ans %= km;
//             }
//         }
//     }
//     else {
//         for(int dig = 0; dig <= 9; ++dig){
//             int diff = s - dig;
//             if (diff >= 0){
//                 ans += solve2(n, diff, be + 1) % km;
//                 ans %= km;

//             }
//         }
//     }
//     return dp[be][s] = ans;
// }

// int Solution::solve(int n, int s) {
//     memset(dp, -1, sizeof dp);
//     return solve2(n, s, 0);
// }

int solve(int n, int s){
    int dp[4][10] = {};
    const int km = 1000000007;

    for(int dig = 0; dig <= 9; ++dig){
        dp[1][dig] = 1;
    }

    for(int len = 2; len <= n; ++len){
        for(int j = 0; j <= s; ++j){
            int ans = 0;
            for(int dig = 0; dig <= 9; ++dig){
                int diff = j - dig;
                if (diff < 0){
                    break;
                }
                ans += (1 + dp[len - 1][diff]) % km;
            }
            dp[len][j] = ans - dp[len-1][j];
        }
    }
    return dp[n][s];
}

// TODO write a dp solution; leading zeroes are not being handled

int main(){
//    vector<int>

//    canJump(a);
//    memset(dp, -1, sizeof dp);
    cout << solve(2, 2);
}