int coinSumInfinite(vector<int>& v, int target) {
	int dp[target + 1] = {0};
	dp[0] = 1;
	for(int i = 1; i <= target; i++) {
		for(int x : v)
			if(x <= i) dp[i] += dp[i - x];
	}
	return dp[target];
}
