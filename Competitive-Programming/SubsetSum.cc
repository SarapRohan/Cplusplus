int subsetSum(vector<int> v, int s) {
    int dp[s + 1] = {0};
    dp[0] = 1;
    for(int n : v) {
        for(int i = s; i >= n; i--)
            dp[i] += dp[i - n];
    }
    return dp[s];
}
