#include<iostream>
using namespace std;

#define mod 1000000007
int size=2;


void multiply(long long int a[][3],long long int b[][3]){
    int i,j,k;
    long long int ans[3][3]={};
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

void power(long long int second[][3],long long int n){
    long long int current[3][3]={},i,j;
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
        long long int n;
        cin>>n;
        if(n==0)
            {cout<<"0\n";continue;}
        if(n==1)
            {cout<<"2\n";continue;}
        else{
            long long int myArray[3][3];
              myArray[0][0]=1;myArray[0][1]=1;myArray[1][0]=1;myArray[1][1]=0;
            power(myArray,n+2);
            cout<<myArray[0][0]%mod<<"\n";
        }
    }
    return 0;
}