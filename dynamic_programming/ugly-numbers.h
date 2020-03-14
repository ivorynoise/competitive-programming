
int ugly(int n) {
	vec dp(n, 0);

	dp[0] = 1;

	int i2, i3, i5;
	i2 = i3 = i5 = 0;

	for (int i = 1; i < n; ++i) {
		int cur_ugly_number = dp[i - 1];

		if (dp[i2] * 2 <= cur_ugly_number) {
			++i2;
		}

		if (dp[i3] * 3 <= cur_ugly_number) {
			++i3;
		}

		if (dp[i5] * 5 <= cur_ugly_number) {
			++i5;
		}

		int ans = min(dp[i2] * 2, min(dp[i3] * 3,  dp[i5] * 5));
		if (ans == dp[i2]) ++i2;
		if (ans == dp[i3]) ++i3;
		if (ans == dp[i5]) ++i5;
		dp[i] = ans;
	}
	return dp[n - 1];
}