// Longest Common subsequence
int lcs(string& a, string& b) {
	int aLen = a.size();
	int bLen = b.size();
	mat dp(aLen, vec(bLen, 0));

	// preprocessing
	dp[0][0] = a[0] == b[0];
	for (int i = 1; i < bLen; ++i) {
		dp[0][i] = a[0] == b[i] ? 1 : dp[0][i-1];
	}

	for (int i = 1; i < aLen; ++i) {
		dp[i][0] = a[i] == b[0] ? 1 : dp[i-1][0];
	}

	for (int i = 1; i < aLen; ++i) {
		for (int j = 1; j < bLen; ++j) {
			int cur = dp[i - 1][j - 1] + (a[i] == b[j]);
			dp[i][j] = max(cur, max(dp[i - 1][j], dp[i][j - 1]));
		}
	}

	printMat(dp);

	int i = max(aLen, bLen) - 1;
	int j = min(aLen, bLen) - 1;
	string str;
	while(i >= 0 && j >= 0){
		if (a[i] == b[j]){
			str += a[i];
			--j;
		}
		if (i - 1 < 0 && dp[i][j] != 0){
			str += a[i];
		}
		--i;
		
	}
	print(str);

	return dp[aLen - 1][bLen - 1];
}