#include<iostream>
using namespace std;

int gcdExtended(int a, int b, int *x, int *y)
{
    if (a == 0)
    {
        *x = 0;
        *y = 1;
        return b;
    }
 
    int x1, y1; 
    int gcd = gcdExtended(b%a, a, &x1, &y1);
    *x = y1 - (b/a) * x1;
    *y = x1;
 
    return gcd;
}

int FindModInverse(int remain,int num){
    int x,y;
    gcdExtended(remain,num,&x,&y);
    return x;
}

int main(){
    int remainders[100010]={},numbers[100010]={},n;
    long long int product=1,ans=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>numbers[i]>>remainders[i];
        product*=numbers[i];
    }
    for(int i=0;i<n;i++){
        int invAnswer=FindModInverse(product/numbers[i],numbers[i]);
        if(invAnswer<0)
           invAnswer+=numbers[i];
        // cout<<invAnswer<<" ";
        ans+=(product/numbers[i])*remainders[i]*invAnswer;
    }
     cout<<ans%product;
    return 0;
}