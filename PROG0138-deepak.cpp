//Birthday paradox
#include <bits/stdc++.h>
using namespace std;

const double days = 365;

void prob(){
	double pDiff = 1;
	int fav = 364;

	for(int i = 2; i < 5; ++i){
		pDiff *= fav / days;
		--fav;
	}

	//5 to 75
	for(int i = 5; i <= 75; ++i){
		pDiff *= fav / days;
		--fav;

		if (i % 5 == 0){
			printf("%d %0.12f\n", i, 1 - pDiff);
		}

	}
}

int main(){
	prob();
}