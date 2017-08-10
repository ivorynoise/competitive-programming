#include<iostream>
using namespace std;
 
int dp[2005][2005];
int main(){
    int s,n,size[2010],values[2010];
    cin>>s>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>size[i]>>values[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=s;j++){
            if(j < size[i]){
            dp[i][j]=dp[i-1][j];
            }
            else{
                dp[i][j]=max(values[i]+dp[i-1][j-size[i]],dp[i-1][j]);
            }
        }
    }
    cout<<dp[n][s];
    return 0;
} 