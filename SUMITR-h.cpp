#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int ans=0,i,n,v[1010][1010],j;
        cin>>n;
        for(i=0;i<n;i++){
            for(j=0;j<i+1;j++)
                cin>>v[i][j];
        }
        for(i=n-2;i>=0;i--){
            for(j=0;j<i+1;j++){
                v[i][j]+=max(v[i+1][j],v[i+1][j+1]);
            }
        }
        cout<<v[0][0]<<"\n";
    }
    return 0;
}

/*Submitted code :
#include<iostream>
using namespace std;main(){int t;cin>>t;while(t--){int ans=0,i,n,v[110][110],j;cin>>n;for(i=0;i<n;i++){for(j=0;j<i+1;j++)cin>>v[i][j];}for(i=n-2;i>=0;i--){for(j=0;j<i+1;j++){v[i][j]+=max(v[i+1][j],v[i+1][j+1]);}}cout<<v[0][0]<<"\n";}}
*/