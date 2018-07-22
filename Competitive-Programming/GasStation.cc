#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<int> gas = {1, 2, 3, 4, 5};
    vector<int> cost = {3, 4, 5, 1, 2};
    int n = gas.size();
    int min_cost = INT_MAX, start_index;
    for (int i = 0; i < n; i++)
        if (gas[i] > cost[i])
            if (min_cost > cost[i]) {
                min_cost = cost[i];
                start_index = i;
            }
    return 0;
}
