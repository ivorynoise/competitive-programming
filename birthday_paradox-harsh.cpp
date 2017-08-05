#include<iostream>
#include<stdio.h>
using namespace std;


int main(){
    int cur_day=365;
    double ans=1.0,a1=1.00;
    for(int i=0;i<80;i++){
        if(i!=0 && i%5==0){
             cout<<i<<" ";
             printf("%.13lf\n",1.00-ans);
            
        }
        //cout<<cur_day<<" ";
        ans*=(double)(cur_day/365.00);
        cur_day--;
    }
    return 0;
}