#include<bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;

	int l = s.size() / 2;
	sort(s.begin(), s.begin() + l);
	// cout << s << endl;

	do {

		copy(s.begin(), s.begin() + l, ostream_iterator<char>(cout, ""));
		if (s.size() & 1) cout << s[l];
		// copy(s.rbegin()-l, s.rend(), ostream_iterator<char>(cout, ""));
		//doesn't work

		for(int i = l - 1; i >=0; --i) cout << s[i];

		cout << "\n";

	} while (next_permutation(s.begin(), s.begin() + l));
}