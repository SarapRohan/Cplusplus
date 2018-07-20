#include <bits/stdc++.h>
using namespace std;
int main() {
    string s = "catsanddog";
    vector<string> wordDict = {"cat", "cats", "and", "sand", "dog"};
    unordered_set<string> set(wordDict.begin(), wordDict.end());
    int l = s.length();
    int minlen = INT_MAX, maxlen = INT_MIN;
    for (string x : wordDict) {
        minlen = min(minlen, (int)x.length());
        maxlen = max(maxlen, (int)x.length());
    }
    vector<vector<string> > v(l + 1, vector<string>(0));
    v[l].push_back("");
    for (int start = l - 1; start >= 0; start--) {
        for (int length = minlen; length <= maxlen and start + length <= l; length++) {
            string x = s.substr(start, length);
            if (set.count(x)) {
                int prefix = start + length;
                for (string st :  v[prefix]) 
                    v[start].push_back(x + (st.empty() ? "" : " ") + st);
            }
        }
    }
    for (string x : v[0]) cout<<x<<endl;
    return 0;
}
