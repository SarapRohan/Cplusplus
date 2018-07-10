#include <iostream>
#include <vector>

typedef vector<int> vi;
typedef vector<vi> vvi;

using namespace std;
int coin(vi v, vvi memo, int s, int e) {
    if(s > e) return 0;
    if(memo[s][e] != 0) return memo[s][e];
    int a = v[s] + min(coin(v, memo, s + 2, e), coin(v, memo, s + 1, e -1));
    int b = v[e] + min(coin(v, memo, s, e - 2), coin(v, memo, s + 1, e - 1));
    return (memo[s][e] = max(a, b));
}

int main() {
    vi v = {1, 5, 8, 4};
    int n = v.size();
    vvi memo(n, vector<int>(n, 0));
    cout<<coin(v, memo, 0, n - 1);
    return 0;
}
