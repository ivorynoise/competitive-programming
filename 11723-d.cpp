#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
int main(){
	int nstreets, nNumbers;
		// Scanner s = new Scanner(System.in);

		// nstreets = s.nextInt();
		// nNumbers = s.nextInt();
		cin >> nstreets >> nNumbers;
		int c = 0;
		while (nstreets != 0 && nNumbers != 0) {
			nstreets -= nNumbers;
			// int nAlpha = (int)Math.ceil((double)nstreets / nNumbers);
			int nAlpha = ceil(1.0 * nstreets / nNumbers);

			printf("Case %d: ", ++c);

			if (nAlpha > 26) puts("impossible");
			else cout << nAlpha << "\n";

			// nstreets = s.nextInt();
			// nNumbers = s.nextInt();
			cin >> nstreets >> nNumbers;
		}
}