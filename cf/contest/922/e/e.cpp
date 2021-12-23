/* Author: izhang05
 * Time: 12-22-2021 21:47:49
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

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e3 + 5, maxc = 1e4 + 5;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
long long dp[maxn][maxc]; // dp[tree][sol] = max mana

void test_case() {
    int n;
    long long w, b, x;
    cin >> n >> w >> b >> x;
    vector<int> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    vector<long long> cost(n);
    for (int i = 0; i < n; ++i) {
        cin >> cost[i];
    }
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i <= c[0]; ++i) {
        dp[0][i] = max(dp[0][i], w - i * cost[0]);
    }

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < maxc; ++j) {
            long long &cur = dp[i][j];
            for (int k = 0; k <= min(j, c[i]); ++k) {
                if (dp[i - 1][j - k] == -1) {
                    continue;
                }
                long long new_cap = min(w + (j - k) * b, dp[i - 1][j - k] + x);
                cur = max(cur, new_cap - k * cost[i]);
            }
        }
    }
    for (int i = maxc - 1; i >= 0; --i) {
        if (dp[n - 1][i] != -1) {
            cout << i << "\n";
            return;
        }
    }
    cout << 0 << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
