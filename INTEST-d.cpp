#include <iostream>
#include <cstdio>
using namespace std;
int main(){
	int n, k, x, c = 0;
	cin >> n >> k;
	while(n--){
		//use scanf for high input
		scanf("%d", &x);
		if (x % k == 0) ++c;
	}
	cout << c;
}