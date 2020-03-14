// longest increasing subsequence
int lis1(vec& v){
	int n = v.size();

	vec dp(n, 1);
	int ans = (n == 0) ? 0 : 1;
	
	for(int i = 1; i < n; ++i){
		for(int j = 0; j < i; ++j){
			if (v[i] >= v[j]){
				dp[i] = dp[j] + 1; 
			}
			ans = max(ans, dp[i]);
		}
	}

	int i = max_element(dp.begin(), dp.end()) - dp.begin();
	int val = v[i];
	int len = dp[i];

	while(i >= 0){
		if (len == dp[i] && v[i] <= val){
			val = v[i];
			cout << val << " ";
			--len;
		}
		--i;
	}

	return ans;
}


// NLogN
int greaterThan(vec& v, int be, int en, int x){
	if (be > en) return -1;

	int mid = (be + en) / 2;
	if (v[mid] >= x){
		// search for a smaller greater
		int ans = greaterThan(v, be, mid - 1, x);
		return ans == -1 ? mid : ans;
	}
	return greaterThan(v, mid + 1, en, x);
}

int lis2(vec& v){
	int n = v.size();

	vec endElement;

	for(int i = 0; i < n; ++i){
		int pos = greaterThan(endElement, 0, endElement.size() - 1, v[i]);
		if (pos == -1){
			// no element greater than the current element
			// push
			endElement.push_back(v[i]);
		} else {
			endElement[pos] = v[i];
		}
	}
	printVec(endElement);

	return endElement.size();
}
