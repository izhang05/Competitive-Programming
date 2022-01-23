/* Author: izhang
 * Time: 01-22-2022 23:48:59
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxk = 18, maxn = 2e5 + 5;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
int dp[1 << maxk];

int n, k;
string s;

bool check(int x) {
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;
    vector<vector<int>> pre(k, vector<int>(n + 1));
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < n; ++j) {
            pre[i][j + 1] = pre[i][j];
            if (s[j] != '?' && s[j] != 'a' + i) {
                ++pre[i][j + 1];
            }
        }
    }
    vector<vector<int>> good(k);
    for (int i = 0; i < k; ++i) {
        for (int j = x; j <= n; ++j) {
            if (pre[i][j] == pre[i][j - x]) {
                good[i].push_back(j - x);
            }
        }
    }
    for (int mask = 0; mask < (1 << k); ++mask) {
        for (int i = 0; i < k; ++i) {
            if (!(mask & (1 << i))) {
                auto it = lower_bound(good[i].begin(), good[i].end(), dp[mask]);
                if (it != good[i].end()) {
                    dp[mask | (1 << i)] = min(dp[mask | (1 << i)], *it + x);
                }
            }
        }
    }
    return dp[(1 << k) - 1] != inf;
}

void test_case() {
    cin >> n >> k >> s;
    int lo = 0, hi = n, mid, res;
    while (lo <= hi) {
        mid = (lo + hi) / 2;
        if (check(mid)) {
            res = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    cout << res << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
