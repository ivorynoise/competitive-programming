#include <bits/stdc++.h>
using namespace std;

int main() {
    char s[100010],half[100010];
    cin>>s;
    int i,len=strlen(s);
    for(i=0;i<len/2;i++){
        half[i]=s[i];
    }
    sort(half,half+len/2);
    if(len%2==0){
        do{
            cout<<half;
            for(int i=len/2-1;i>=0;i--){
                cout<<half[i];
            }
            cout<<"\n";
        }while(next_permutation(half,half+len/2));
        
    }
    else{
        do{
            cout<<half;
            cout<<s[len/2];
            for(int i=len/2-1;i>=0;i--){
                cout<<half[i];
            }
            cout<<"\n";
        }while(next_permutation(half,half+len/2));
        
    }
	return 0;
}
