#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
tuple<int, int, int> kadane(vi v) {
    int sum, res;
    sum = res = v[0];
    int start, end;
    start = end = 0;
    for (int i = 1; i < v.size(); i++) {
        if (v[i] > v[i] + sum) {
            start = i;
            sum = v[i];
        } else {
            sum = sum + v[i];
        }
        if (sum >  res) {
            end = i;
            res = sum;
        }
    }
    return make_tuple(res, start, end);
}
int main() {
    vvi v = {{1, 2, -1, -4, -20},
               {-8, -3, 4, 2, 1},
               {3, 8, 10, 1, 3},
               {-4, -1, 1, 7, -6}};
    int m = v.size();
    int n = v[0].size();
    int top, bottom, left, right;
    int res_sum = v[0][0];
    cout<<res_sum<<endl;
    for (int i = 0; i < n; i++) {
        vi sum_array(m, 0);
        for (int j = i; j < n; j++) {
            for (int k = 0; k < m; k++)
                sum_array[k] += v[k][j];
            int sum, start, finish;
            tie(sum, start, finish) = kadane(sum_array);
            for (int l : sum_array) cout<<l<<" ";
            cout<<i<<" "<<j<<" "<<sum<<" "<<start<<" "<<finish<<endl;
            if (sum > res_sum) {
                res_sum = sum;
                left = i;
                right = j;
                top = start;
                bottom = finish;
            }
        }
    }
    for (int i = top; i <= bottom; i++) {
        for (int j = left; j <= right; j++) {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<res_sum<<endl;
    return 0;
}
