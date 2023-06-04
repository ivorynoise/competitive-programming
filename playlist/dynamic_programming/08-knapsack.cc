// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

int knapsack(int wt[100], int val[100], int n, int threshold){
  int dp[100][100];

  // set the base cases
  for(int capacity = 0; capacity <= threshold; ++capacity){
    dp[0][capacity] = 0;
  }

  for(int item = 0; item <= n; ++item){
    dp[item][0] = 0;
  }

  for(int item = 1; item <= n; ++item){
    for(int capacity = 1; capacity <= threshold; ++capacity){
      int q1 = -1, q2 = -1;
      if (wt[item - 1] <= capacity){
        // pick the item
        int remCap = capacity - wt[item-1];
        q1 = val[item-1] + dp[item-1][remCap];
      }
      q2 = dp[item-1][capacity];    // leave the item
      dp[item][capacity] = max(q1, q2);
    }
  }
  return dp[n][threshold];
}


int main() {
  int val[100], wt[100];
  int n, threshold;
  cin >> n >> threshold;

  for (int i = 0; i < n; ++i) cin >> wt[i];
  for (int i = 0; i < n; ++i) cin >> val[i];

  int ans = knapsack(wt, val, n, threshold);
  cout << ans; 
  
  return 0;
}