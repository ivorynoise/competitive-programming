
// Knapsack
int Knapsack(vec price, vec wt, int maxWt) {
	int n = price.size();
	mat dp(n + 1, vec(maxWt + 1, 0));

	for (int item = 1; item <= n; ++item) {
		for (int cwt = 1; cwt <= maxWt; ++cwt) {
			int valOfItem = price[item - 1];
			int profitPick = (wt[item - 1] <= cwt) ? valOfItem + dp[item - 1][cwt - wt[item - 1]] : 0;
			int profitLeft = dp[item - 1][cwt];
			dp[item][cwt] = max(profitPick, profitLeft);
		}
	}

	// print items
	int i = n;
	int j = maxWt;
	while(i > 0 && j > 0){
		// if curItem was picked
		int cwt = j - wt[i - 1];
		if (dp[i][j] != dp[i][cwt]){
			cout << price[i - 1] << " ";
			--i;
			j = cwt;
		}
		else {
			--i;
		}
	}

	return dp[n][maxWt];
}