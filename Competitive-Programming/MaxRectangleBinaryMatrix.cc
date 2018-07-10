int maxArea(vector<int> v) {
    stack<int> s;
    int max_area = 0, top, area;
    int i = 0;
    while (i < v.size()) {
        if (s.empty() or v[i] >= v[s.top()]) s.push(i++);
        else {
            top = s.top();
            s.pop();
            area = v[top] * (s.empty() ? i : i - s.top() - 1);
            max_area = max(max_area, area);
        }
    }
    while(!s.empty()) {
        top = s.top();
        s.pop();
        area = v[top] * (s.empty() ? i : i - s.top() - 1);
        max_area = max(max_area, area);
    }
    return max_area;
}

int maximalRectangle(vector<vector<int>>& mat) {
    if(mat.empty()) return 0;
    int n = mat[0].size();
    int m = mat.size();
    int res = 0;
    vector<int> dp(n, 0);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if(mat[i][j] == 0) dp[j] = 0;
            else dp[j]++;
        }
        res = max(res, maxArea(dp));
    }
    return res;
}
