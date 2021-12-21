/* Author: izhang05
 * Time: 12-19-2021 22:53:33
**/
#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen(("in" + name + ".txt").c_str(), "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("out.txt", "w", stderr);
#endif
}
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e5 + 5;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

set<int> occ[maxn];

void test_case() {
    int n, m, s, e;
    cin >> n >> m >> s >> e;
    int sol = 0;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> b(m);
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
        occ[b[i]].insert(i);
    }
    vector<int> dp{-1};
    for (int i = 0; i < n; ++i) {
        vector<int> new_dp(dp.begin(), dp.end());
        for (int j = 0; j < int(dp.size()); ++j) {
            auto it = occ[a[i]].upper_bound(dp[j]);
            if (it == occ[a[i]].end()) {
                continue;
            }
            if (j != int(dp.size()) - 1) {
                new_dp[j + 1] = min(new_dp[j + 1], *it);
            } else if (int(dp.size()) <= s / e) {
                new_dp.push_back(*it);
            }
        }
        swap(dp, new_dp);
        for (int j = 0; j < int(dp.size()); ++j) {
            if (s - (i + 1) - (dp[j] + 1) - j * e >= 0) {
                sol = max(sol, j);
            }
        }
    }
    cout << sol << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
