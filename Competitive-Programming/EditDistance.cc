int minDistance(string s, string t) {
    int n = s.length();
    int m = t.length();
    vector<int> dp(n + 1, 0);
    for (int j = 0; j <= n; j++) dp[j] = j;
    for (int i = 1; i <= m; i++) {
        int prev = dp[0];
        dp[0] = i;
        for (int j = 1; j <= n; j++) {
            int temp = dp[j];
            if (s[j - 1] == t[i - 1]) dp[j] = prev;
            else dp[j] = min(prev, min(dp[j], dp[j - 1])) + 1;
            prev = temp;
        }
    }
    return dp.back();
}
