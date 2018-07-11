#include <iostream>
using namespace std;
int main() {
    //range : 0 to 9
    vector<int> v = {1, 4, 1, 2, 7, 5, 2};
    vector<int> count(10, 0);
    for (int i : v) count[i]++;
    for (int i = 1; i < 10; i++) count[i] += count[i - 1];
    vector<int> out(v.size());
    for (int i : v) out[--count[i]] = i;
    for (int i : out) cout<<i<<" ";
    return 0;
}
