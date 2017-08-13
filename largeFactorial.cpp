#include <bits/stdc++.h>
using namespace std;

typedef int digit;

void mul(vector<digit>& v, int n){
	int carry = 0;
	int prod = 0;

	for(int i = 0; i < v.size(); ++i){
		prod = v[i] * n + carry;
		v[i] = prod % 10;
		carry = prod / 10;
	}

	while(carry){
		v.push_back(carry % 10);
		carry /= 10;
	}
}

void factorial(int n){
	vector<digit> v(1,1);

	for(int i = 2; i <= n; ++i){
		mul(v, i);
	}

	for(int i = v.size() - 1; i >=0; --i){
		cout << v[i];
	}
}

int main(){
	int n;
	cin >> n;
	factorial(n);	
}