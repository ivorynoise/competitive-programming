#include<iostream>
using namespace std;

int main(){
    long long int ans=0;
    int i,n,arr[10010];
    cin>>n;
    for(i=0;i<n;i++)
        cin>>arr[i];
    int beg=0,en=n-1;
    while(beg<=en){
        if(arr[beg]<=arr[en]){
            long long int current =(en-beg) * arr[beg];
            if(current > ans)
                ans=current;
            beg++;
        }
        else{
            long long int current =(en-beg) * arr[en];
            if(current > ans)
                ans=current;
            en--;
        }
    }
    cout<<ans;
    return 0;
}