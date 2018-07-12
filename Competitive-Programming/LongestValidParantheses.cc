int longestValidParentheses(string s) {
    int left = 0, right = 0, res = 0;
    for (char c: s) {
        if (c == '(') left++;
        else right++;
        if (right > left) left = right = 0;
        if (left == right) res = max(res, left + right);
    }
    reverse(s.begin(), s.end());
    left = 0, right = 0;
    for (char c: s) {
        if (c == ')') left++;
        else right++;
        if (right > left) left = right = 0;
        if (left == right) res = max(res, left + right);
    }
    return res;
}
