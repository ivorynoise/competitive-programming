#include<iostream>
using namespace std;

int main(){
    int k,l,m;
    bool dp[1000010]={};
    cin>>k>>l>>m;
    dp[1]=true;dp[l]=true;dp[k]=true;
    for(int i=2;i<=1000000;i++){
        if(i-k>=0 && dp[i-k]==false)
            dp[i]=true;
        if(i-1>=0 && dp[i-1]==false)
            dp[i]=true;
        if(i-l>=0 && dp[i-l]==false)
            dp[i]=true;
    }
    while(m--){
        int n;
        cin>>n;
        if(dp[n]==true)
            cout<<"A";
        else
            cout<<"B";
    }
    return 0;
}