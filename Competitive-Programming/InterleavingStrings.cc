bool isInterleave(string s, string t, string x) {
    int m = t.length();
    int n = s.length();
    vector<bool> dp(n + 1, false);
    dp[0] = true;
    for (int j = 1; j <= n; j++)
        if (x[j - 1] == s[j - 1] and dp[j - 1]) dp[j] = true;
    for (int i = 1; i <= m; i++) {
        if (x[i - 1] != t[i - 1] or !dp[0]) dp[0] = false;
        for (int j = 1; j <= n; j++) {
            if (x[i + j - 1] == s[j - 1] and x[i + j - 1] == t[i - 1] and (dp[j] or dp[j - 1])) dp[j] = true;
            else if (x[i + j - 1] == s[j - 1] and dp[j - 1]) dp[j] = true;
            else if (x[i + j - 1] == t[i - 1] and dp[j]) dp[j] = true;
            else dp[j] = false;
        }
    }
    return dp.back();
}
