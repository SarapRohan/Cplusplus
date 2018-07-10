#include <iostream>
#include <vector>

typedef vector<int> vi;
typedef vector<vi> vvi;
using namespace std;

int length(vi v, int prev, int index) {
    if(index == v.size()-1) return 0;
    int ans1 = 0;
    if(v[index] > prev) {
        ans1 = 1 + length(v, v[index], index + 1);
    }
    int ans2 = length(v, prev, index + 1);
    return max(ans1, ans2);
}

int length(vi v, int previndex, int index, vvi &memo) {
    if(index == v.size() - 1) return 0;
    if(memo[previndex + 1][index] >= 0) {
        return memo[previndex + 1][index];
    }
    int ans1 = 0;
    if(previndex < 0 or v[index] > v[previndex]) {
        ans1 = 1 + length(v, index, index + 1, memo);
    }
    int ans2 = length(v, previndex, index + 1, memo);
    memo[previndex + 1][index] = max(ans1, ans2);
    return memo[previndex + 1][index];
}

int main() {
    vi v = {10,9,2,5,3,7,101,18};
    cout<<length(v, INT_MIN, 0)<<endl;
    vi v2(v.size(), -1);
    vvi memo(v.size(), v2);
    cout<<length(v, -1, 0, memo)<<endl;
    vector<int> dp(v.size());
    dp.push_back(1);
    int res = 0;
    for(int i = 0; i < v.size(); i++) {
        int ans = 0;
        for(int j = 0; j < i; j++) {
            if(v[i] > v[j]) ans = max(ans, dp[j]);
        }
        dp[i] = ans + 1;
        res = max(res, dp[i]);
    }
    cout<<res<<endl;
    return 0;
}
