#include<iostream>
using namespace std;

int dp[2005][2005]={};
int main(){
    int i,j,n,arr[2005];
    long long int cumulative[2005]={};
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>arr[i];
    for(i=1;i<=n;i++){
        dp[i][i]=arr[i];
    }
    for(i=1;i<=n;i++){
        cumulative[i]=arr[i]+cumulative[i-1];
    }
    for(int range=1;range<=n;range++){
        for(int be=1;be+range<=n;be++){
            int en=be+range;
            int a1=dp[be+1][en] + arr[be] + cumulative[en]-cumulative[be];
            int a2=dp[be][en-1] + arr[en] + cumulative[en-1]-cumulative[be-1];
            dp[be][en]=max(a1,a2);
        }
    }
    /*for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }*/
    cout<<dp[1][n];
}