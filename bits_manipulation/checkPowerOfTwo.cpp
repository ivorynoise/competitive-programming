
#include<iostream>

using namespace std;

bool checkPowerOfTwo(int n){
    return !(n && (n & (n-1)));
}

int main(){
  cout<<checkPowerOfTwo(8);
  return 0;
}
