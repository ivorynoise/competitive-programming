// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <iomanip>
using namespace std;

int maxProfit(int arr[], int n){
  int dp[100][100] = {};

  int year = n;

  for(int i = 0; i < n; ++i){
    dp[i][i] = year*arr[i];
  }
  --year;

  for(int len = 2; len <= n; ++len){
    int srt = 0;
    int end = n - len;
    while(srt <= end){
      int en = srt + len - 1;
      dp[srt][en] = max(
        dp[srt + 1][en] + year*arr[srt],
        dp[srt][en - 1] + year*arr[en]
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
  int n;
  cin >> n;
  for(int i = 0; i < n; ++i){
    cin >> arr[i];
  } 

  int ans = maxProfit(arr, n);
  cout << ans;
}