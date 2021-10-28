/* Author: izhang05
 * Time: 10-23-2021 12:45:02
**/
#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifndef TEST
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
    freopen((name + ".out").c_str(), "w", stderr);
#endif
}
const int maxn = 1e5 + 5;
map<int, int> pre[maxn];
set<int> seen[maxn];

int lis(const vector<int> &a) {
    vector<int> dp;
    for (int i : a) {
        int pos = lower_bound(dp.begin(), dp.end(), i) - dp.begin();
        if (pos == (int) dp.size()) {
            if ((int) dp.size()) {
                pre[int(dp.size())][i] = *prev(seen[int(dp.size()) - 1].upper_bound(i));
            }
            seen[int(dp.size())].insert(i);
            dp.push_back(i);
        } else {
            dp[pos] = i;
            if (pos) {
                pre[pos][i] = *prev(seen[pos - 1].upper_bound(i));
            }
            seen[pos].insert(i);
        }
    }
    return (int) dp.size();
}

int main() {
    setIO("itout");
    int n;
    long long k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int cnt = lis(a);
    vector<int> nums;
    int cur = *seen[cnt - 1].rbegin();

    for (int i = cnt - 1; i >= 0; --i) {
        nums.push_back(cur);
        cur = pre[i][cur];
    }
    reverse(nums.begin(), nums.end());
    int j = 0;
    vector<int> sol;
    for (int i = 0; i < n; ++i) {
        if (j == cnt || a[i] != nums[j]) {
            sol.push_back(a[i]);
        } else {
            ++j;
        }
    }
    sort(sol.begin(), sol.end());
    cout << n - cnt << "\n";
    for (auto &i : sol) {
        cout << i << "\n";
    }

    return 0;
}
