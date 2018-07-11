int deleteAndEarn(vector<int>& v) {
	map<int, int> m;
	for(int i : v) m[i]++;
	int prev = 0, cur = 0;
	for(auto it : m) {
		if(m.find(it.first - 1) == m.end()) {
			prev = cur;
			cur += (it.second)*(it.first);
		} else {
			int temp = max(prev + (it.first)*(it.second), cur);
			prev = cur;
			cur = temp;
		}
	}
	return cur;
}
