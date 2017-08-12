#include<iostream>
using namespace std;

#define mod 1000000007
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
    int t;
    cin>>t;
    while(t--){
        long long int a,b;
        cin>>a>>b;
        long long int myArray[3][3]={},answera=0,answerb=0;
        if(a==0)
            answera=0;
        else if(a==1)
            answera=0;
        else if(a==2)
            answera=1;
        else if(a==3)
            answera=2;
        else{
            myArray[0][0]=1;myArray[0][1]=1;myArray[1][0]=1;myArray[1][1]=0;
            power(myArray,a);
            answera=(myArray[0][0]-1)%mod;
        }
        
        if(b<=2){
            answerb=b;
        }
        else{
            myArray[0][0]=1;myArray[0][1]=1;myArray[1][0]=1;myArray[1][1]=0;
            power(myArray,b+1);
            answerb=(myArray[0][0]-1)%mod;
            
        }
        
        cout<<(answerb-answera+mod)%mod<<"\n";
    }
}