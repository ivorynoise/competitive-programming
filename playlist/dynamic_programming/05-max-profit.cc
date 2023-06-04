// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;
int cnt = 0;
int memo[100][100];


int maxProfit(int arr[], int be, int en, int year){
  ++cnt;
  if (be > en){
    return 0;
  }

  if (memo[be][en] != -1) return memo[be][en];

  int q1 = arr[be] * year + maxProfit(arr, be + 1, en, year + 1);     // sell from beg
  int q2 = arr[en] * year + maxProfit(arr, be, en - 1, year + 1);     // sell from end
  int ans = max(q1, q2);
  memo[be][en] = ans;   // ans for this particular range [be, en]
  return ans;
}

int maxProfit(int arr[], int n){
  int dp[100][100] = {};
  int year = n;

  for(int i = 0; i < n; ++i){
    dp[i][i] = year * arr[i];
  }
  --year;

  for(int len = 2; len <= n; ++len){
    int srt = 0;
    int end = n - len;
    while(srt <= end){
      int endwindow = srt + len - 1;
      dp[srt][endwindow] = max(
        arr[srt]*year + dp[srt+1][endwindow],
        arr[endwindow]*year + dp[srt][endwindow -1]
        );
      ++srt;
    }
    --year;
  }

  for(int i = 0; i < n; ++i){
    for(int j = 0; j < n; ++j){
      cout << setw(3) << dp[i][j] << " ";
    }
    cout << endl;
  }

  return dp[0][n-1];
}



int main(){
  int arr[100];
  int n;          // no of bottles kept on table
  cin >> n;
  for(int i = 0; i < n; ++i){
    cin >> arr[i];  // prices of bottles
  } 
  // memset(memo, -1, sizeof(memo));
  // int ans = maxProfit(arr, 0, n - 1, 1);
  int ans = maxProfit(arr, n);
  cout << ans << endl;
  cout << cnt;
}