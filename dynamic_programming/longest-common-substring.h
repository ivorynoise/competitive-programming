// Longest common substring
int lcstr(string a, string b) {
	int alen = a.size();
	int blen = b.size();

	// len of substring ending at i,j
	mat dp(alen + 1, vec(blen + 1, 0));
	int ans = 0;
	int x = 0, y = 0;

	for (int i = 1; i <= alen; ++i) {
		for (int j = 1; j <= blen; ++j) {
			// len of previous substring
			int prevLen = dp[i - 1][j - 1];
			if (a[i - 1] == b[j - 1]) {
				dp[i][j] = 1 + prevLen;
			}
			else {
				dp[i][j] = 0;
			}
			if (ans < dp[i][j]){
				ans = dp[i][j];
				x = i - 1;
				y = j - 1;
			}
		}
	}
	printMat(dp);

	int len = ans;
	while(len){
		cout << a[x];
		--x; --y;
		--len;
	}

	return ans;
}