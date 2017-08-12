#include<iostream>
using namespace std;

#define mod 98765431
int size=2;
void multiply(long long int first[][3],long long int second[][3])
{
    long long int answer[10][10]={};
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            for(int k=0;k<size;k++){
                answer[i][j]=answer[i][j] + (first[i][k]%mod * second[k][j]%mod)%mod;
                answer[i][j]%=mod;
            }
        }
    }
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            first[i][j]=answer[i][j];
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
    int n,i;
    long long int t;
    long long int cows[50010],initial_sum=0;
    cin>>n>>t;
    for(int i=0;i<n;i++){
        cin>>cows[i];
        cows[i]%=mod;
        initial_sum+=cows[i];
        initial_sum%=mod;
    }
    long long int ans=0,myArray[3][3],newAnswer=0;
    myArray[0][0]=n-1;myArray[0][1]=0;myArray[1][0]=1;myArray[1][1]=-1;
    power(myArray,t);
    // for(int i=0;i<size;i++){
    //     for(int j=0;j<size;j++)
    //         cout<<myArray[i][j]<<" ";
    //     cout<<"\n";
    // }
    for(i=0;i<n;i++){
        newAnswer=(myArray[1][0]%mod*initial_sum%mod)%mod + (myArray[1][1]%mod*cows[i]%mod)%mod; 
        newAnswer=(newAnswer+mod)%mod;
        cout<<newAnswer<<"\n";
    }
    return 0;
}