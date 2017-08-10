#include <stdio.h>
#include<iostream>
 
using namespace std;
 
long long int a[1000010]={0};
 
long long int max(long long int a,long long int b)
{
    if(a>b)
      return a;
      return b;
}
long long int answer (long long int p)
{
   if(p<=1000000)
     return a[p];
   else
     return (answer(p/2)+answer(p/3)+answer(p/4));
}
int main() 
{
        long long int n;
        //answer is always gonna be i for such a case
        for(int i=0;i<=11;i++)
             a[i]=i;
        for(int i=12;i<=1000000;i++)
             a[i]=a[i/2]+a[i/4]+a[i/3];
     while(cin>>n)
	{
		printf("%lld\n",answer(n));
	}
	return 0;
}  