#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

long long int k,ans=0;

//gcd using euclidean
int gcd(int a,int b){
    if(a==0)
        return b;
    return gcd(b%a,a);
}

//function returns the lcm of 2 elements
int function(int a, int b){
    int g=gcd(a,b);
    return((a*b)/g);
}

//calculates the lcm for the given subset
int LcmOfCurrent(vector<int> v){
    int lcm=v[0];
    for(int i=1;i<v.size();i++){
        lcm=function(lcm,v[i]);
    }
    return lcm;
}

//getMeAnswers calculates the answer for the current case
void getMeAnswers(int arr[],int n,int index,vector<int> &v){
    if(index==n){
        //if size Of subset formed=0, return
        if(v.size()==0)
            return;
        int lcmOfSubset=LcmOfCurrent(v);
        //if a single element in the subset, add it to answer
        //subtract the answer, in case of even number of elements
        //Raw implementation of inclusion-exclusion principle
        if(v.size()%2==0)
            ans=ans-k/lcmOfSubset;
        else
            ans=ans+k/lcmOfSubset;
       return;
    }
    //Do not include the current element
    getMeAnswers(arr,n,index+1,v);
    //Include the current element
    v.push_back(arr[index]);
    getMeAnswers(arr,n,index+1,v);
    //backtrack ;)
    v.pop_back();
}

int main(){
    int t;
    cin>>t;
    while(t--){
        vector<int> v;
        int i,n,arr[30]={};
        cin>>n;
        //resets the global variable of ans=0
        ans=0;
        for(i=0;i<n;i++){
            cin>>arr[i];
        }
        cin>>k;
        getMeAnswers(arr,n,0,v);
        cout<<ans<<"\n";
    }
}