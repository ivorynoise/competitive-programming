#include<iostream>
using namespace std;
#define mod 1000000000
int size;

void multiply(long long int a[][10],long long int b[][10]){
    int i,j,k;
    long long int ans[20][20]={};
    for(i=0;i<size;i++){
        for(j=0;j<size;j++){
            for(k=0;k<size;k++){
                ans[i][j]=(ans[i][j] + a[i][k]*b[k][j])%mod;
                ans[i][j]=ans[i][j]%mod;
            }
        }
    }
    for(i=0;i<size;i++){
        for(j=0;j<size;j++){
         a[i][j]=ans[i][j];   
        }
    }
    
}

void power(long long int second[][10],long long int n){
    long long int current[20][10]={},i,j;
    for(i=0;i<size;i++){
        for(j=0;j<size;j++)
            current[i][j]=second[i][j];
    }
    if(n<=1){
        return;
    }
    if(n&1){
         power(second,n-1);
        multiply(second ,current);
    }
    else{
        power(second,n/2);
    multiply(second,second);
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int i,j;cin>>size;
        long long int n,b[20],c[20];
        for(i=0;i<size;i++){
            cin>>b[i];
        }
        for(i=0;i<size;i++){
            cin>>c[i];
        }
        cin>>n;
        if(n<=size){
            cout<<b[size-n]<<"\n";
        }else{
            long long int second[20][10]={},ans=0;
            for(i=0;i<size;i++){
                second[0][i]=c[i];
            }
            for(i=1;i<size;i++){
                second[i][i-1]=1;
            }
            long long int e=n-size;
            power(second,e);
            
            for(i=0;i<size;i++){
                ans=(ans+second[0][i]*b[size-i-1])%mod;
                ans%=mod;
            }
            // for(i=0;i<size;i++){
            //     for(j=0;j<size;j++)
            //         cout<<second[i][j]<<" ";
            //     cout<<"\n";
            // }
            cout<<ans<<"\n";
            
        }
    }
}