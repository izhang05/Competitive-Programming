#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    vector<long long> calc_pre(vector<int> &h) {
        int n = int(h.size());
        vector<long long> pre(n);
        stack<pair<long long, long long>> cur;
        cur.emplace(0, -1);
        long long cur_val = 0;
        for (int i = 0; i < n; ++i) {
            cur_val += (long long) h[i];
            while (cur.top().first > h[i]) {
                pair<long long, long long> cur_top = cur.top();
                cur.pop();
                cur_val += (cur_top.second - cur.top().second) * (h[i] - cur_top.first);
            }
            cur.emplace(h[i], i);
            pre[i] = cur_val;
        }
        return pre;
    }

public:
    long long maximumSumOfHeights(vector<int> &h) {
        int n = int(h.size());
        vector<long long> pre = calc_pre(h);
        reverse(h.begin(), h.end());
        vector<long long> suf = calc_pre(h);
//        for (auto &i: pre) {
//            cout << i << " ";
//        }
//        cout << "\n";
//        for (auto &i: suf) {
//            cout << i << " ";
//        }
//        cout << "\n";
        reverse(h.begin(), h.end());
        long long sol = 0;
        for (int i = 0; i < n; ++i) {
//            cout << i << " " << pre[i] - h[i] + suf[n - i - 1] << "\n";
            sol = max(sol, pre[i] - h[i] + suf[n - i - 1]);
        }
        return sol;
    }
};


int main() {
    vector<int> a{5, 3, 4, 1, 1};
    Solution x;
    cout << x.maximumSumOfHeights(a);
}