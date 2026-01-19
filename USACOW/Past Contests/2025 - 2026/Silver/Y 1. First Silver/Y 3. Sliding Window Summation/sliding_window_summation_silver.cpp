#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<vector<int>> cnt(n, vector<int>(2));
    for (int i = n - k; i < n; ++i) {
        ++cnt[i][1];
        bool cur = 1;
        for (int j = i - k; j >= 0; j -= k) {
            if (s[j] != s[j + 1]) {
                cur ^= 1;
            }
            ++cnt[i][cur];
        }
    }
    int mn = 0, mx = 0, cur_mx = 0, cur_mn = 0, mn_diff = 1e9;
    for (int i = n - k; i < n; ++i) {
        mx += max(cnt[i][1], cnt[i][0]);
        mn += min(cnt[i][1], cnt[i][0]);
        mn_diff = min(mn_diff, max(cnt[i][1], cnt[i][0]) - min(cnt[i][1], cnt[i][0]));
        if (cnt[i][1] >= cnt[i][0]) {
            cur_mx ^= 1;
        } else {
            cur_mn ^= 1;
        }
    }
    if (cur_mx != s.back() - '0') {
        mx -= mn_diff;
    }
    if (cur_mn != s.back() - '0') {
        mn += mn_diff;
    }
    cout << mn << " " << mx << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
