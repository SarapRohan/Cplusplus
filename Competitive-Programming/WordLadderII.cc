void dfs(string start, string end, map<string, vector<string> > m, vector<string> ans, vector<vector<string> > &res) {
    if (start == end) {
        ans.push_back(end);
        res.push_back(ans);
    }
    for (auto word : m[start]) {
        ans.push_back(word);
        dfs(word, end, m, ans, res);
        ans.pop_back();
    }
}
vector<vector<string> > Solution::findLadders(string start, string end, vector<string> &dict) {
    vector<vector<string> > res;
    unordered_set<string> words(dict.begin() + 1, dict.end() - 1);
    unordered_set<string> head = { start };
    unordered_set<string> tail = { end };
    unordered_set<string> toVisit;
    map<string, vector<string> > m;
    bool rev = false, stop = false;
    while (not head.empty() and not tail.empty()) {
        if (head.size() > tail.size()) {
            rev = !rev;
            head.swap(tail);
        }
        for (auto word: head) {
            for (int i = 0; i < word.length(); i++) {
                string cur = word;
                for (char c = 'a'; c <= 'z'; c++) {
                    cur[i] = c;
                    if (tail.count(cur)) {
                        if (not rev) m[word].push_back(cur);
                        else m[cur].push_back(word);
                        stop = true;
                    } 
                    if (words.count(cur)) {
                        if (not rev) m[word].push_back(cur);
                        else m[cur].push_back(word);
                        words.erase(cur);
                        toVisit.insert(cur);
                    }
                }
            }
        }
        head.swap(tail);
        if (stop) break;
    }
    vector<string> ans;
    dfs(start, end, m, ans, res);
    return res;
}
