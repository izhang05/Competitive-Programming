#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long maximumSumOfHeights(vector<int> &h) {
        int n = int(h.size());
        long long sol = 0;
        for (int i = 0; i < n; ++i) {
            long long cur = h[i];
            int pre = h[i];
            for (int j = i - 1; j >= 0; --j) {
                pre = min(pre, h[j]);
                cur += pre;
            }
            pre = h[i];
            for (int j = i + 1; j < n; ++j) {
                pre = min(pre, h[j]);
                cur += pre;
            }
            sol = max(sol, cur);
        }
        return sol;
    }
};
