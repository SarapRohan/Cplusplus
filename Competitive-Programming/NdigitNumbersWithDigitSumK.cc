#include <iostream>
#include <vector>

typedef vector<int> vi;
typedef vector<vi> vvi;

using namespace std;

int count(int n, int k, vvi &memo) {
    if(n == 0) {
        if(k == 0) return 1;
        else return 0;
    }
    if(memo[n][k] != -1) return memo[n][k];
    int ans = 0;
    for(int  i = 0; i < 10; i++) {
        if(k - i >= 0)
           ans += count(n - 1, k - i, memo);
    }
    return (memo[n][k] = ans);
}
int main() {
    int n = 3;
    int k = 6;
    int cnt = 0;
    int ans;
    vvi memo(100, vector<int> (500, -1));
    for(int i = 1; i < 10; i++) {
        if(k - i >= 0)
          ans += count(n - 1, k - i, memo);
        else break;
    }
    cout<<ans<<endl;
    return 0;
}
