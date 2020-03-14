// matrix chain multiplication
int matmul(vec dim, int be, int en, auto& dp) {

	// if one or 0 matrix
	if (be == en || be + 1 == en) return 0;

	if (dp[be][en] != -1) return dp[be][en];

	int best = INT_MAX;

	for (int i = be + 1; i <= en - 1; ++i) {
		int lans = matmul(dim, be, i, dp);
		int rans = matmul(dim, i, en, dp);
		int ans = lans + rans + dim[be] * dim[i] * dim[en];
		best = min(ans, best);
	}
	return dp[be][en] = best;
}


int matmul2(vec dim, int be, int en, auto& dp){
	int n = en - be + 1;
	// multiply matrices of len 2 upto n
	for(int len = 2; len <= n; ++len){
		// shift this len
		for(int j = 0; j <= n - len - 1; ++j){
			int srt = j;
			int end = j + len;
			int mnm = 1e6;
			for(int k = 1; k <= len - 1; ++k){
				int q1 = dp[srt][srt + k];
				int q2 = dp[srt + k][end];
				int q3 = dim[srt]*dim[srt + k]* dim[end];
				mnm = min(mnm, q1 + q2 + q3);
			}
			dp[srt][end] = mnm;
		}
	}
	return dp[0][n - 1];
}





/*
Learning: DO NOT THINK COMPUTERS.

int matmul2(vec dim){
	int n = dim.size();

	mat dp(n, vec(n, 0));

	for(int len = 2; len < n; ++len){

		int en = n - 2;
		int best = INT_MAX;
		for(int be = n - len - 1; be >= 0; --be, --en){

			for(int k = be; k < en; ++k){
				int ans = dp[be][k] + dim[be]*dim[k]*dim[en] + dp[k][en];
				best= min(ans, best);
			}

			dp[be][en] = best;
		}

	}
	printMat(dp);
	return dp[0][n - 1];
}*/