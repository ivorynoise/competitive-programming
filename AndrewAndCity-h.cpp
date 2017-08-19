#include<iostream>
using namespace std;
#define mod 1000000007

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,i;
		long long int arr[100010],left[100010],right[100010],ans=0;
		cin>>n;
		for(i=0;i<n;i++)
			cin>>arr[i];
		left[0]=arr[0];
		for(i=1;i<n;i++)
			left[i]=max(left[i-1],arr[i]);
		right[n-1]=arr[n-1];
		for(i=n-2;i>=0;i--){
			right[i]=max(right[i+1],arr[i]);
		}	
		for(i=0;i<n;i++){
			int f=min(left[i],right[i]);
			ans+= (f-arr[i] + mod)%mod;
			ans%=mod;
		}
		cout<<ans<<"\n";
	}
}