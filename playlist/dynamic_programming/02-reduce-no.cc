// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <algorithm>
using namespace std;
const int inf = (int)1e9;

int memo[10000];

int reduceNo(int n){
  if (n == 1) return 0;
  int q1 = inf, q2 = inf, q3 = inf;

  if (memo[n] != -1) return memo[n];  // because this has already been computed! No recomputation

  if (n % 3 == 0) q1 = 1 + reduceNo(n / 3);
  if (n % 2 == 0) q2 = 1 + reduceNo(n / 2);
  q3 = 1 + reduceNo(n - 1);

  memo[n] = min(q1, min(q2, q3)); // memoize has to be done!
  return memo[n];
}

int reduceNo_DP(int n){ // bottom up approach
  int dp[10000];
  // setting the base cases
  dp[0] = 0;  dp[2] = 1;
  dp[1] = 0;  dp[3] = 1;

  // compute the ans for n
  for(int curNum = 4; curNum <= n; ++curNum){
    int q1 = inf;
    int q2 = inf;
    int q3 = inf;
    if (curNum % 3 == 0) q1 = 1 + dp[curNum/3];
    if (curNum % 2 == 0) q2 = 1 + dp[curNum/2];
    q3 = 1 + dp[curNum - 1];
    dp[curNum] = min(q1, min(q2, q3));
  }
  return dp[n];
}


int main(){
  int n;
  cin >> n;
  fill(memo, memo + n + 1, -1); // for loop
  int ans = reduceNo_DP(n);
  cout << ans;
}