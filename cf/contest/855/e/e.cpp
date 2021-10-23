/* Author: izhang05
 * Time: 09-10-2021 10:43:59
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxs = 60, maxb = 11;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

long long dp[maxb][maxs][1 << maxb];

long long solve(int b, int x) {
    if (x <= 0) {
        return 0;
    }
    vector<int> num;
    while (x) {
        num.push_back(x % b);
        x /= b;
    }
    reverse(num.begin(), num.end());
    int n = int(num.size());
    long long res = 0;
    for (int i = 0; i < n - 1; ++i) {
        res += dp[b][i][0];
        if (i) {
            res -= dp[b][i - 1][1];
        }
    }
    int cur = 0;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i == 0; j < num[i]; ++j) {
            res += dp[b][n - (i + 1) - 1][cur ^ (1 << j)];
        }
        cur ^= (1 << num[i]);
    }
    cur ^= (1 << num[n - 1]);
    if (!cur) {
        ++res;
    }
    return res;
}

int main() {
    setIO("3");
    for (int b = 2; b <= 10; ++b) {
        for (int j = 1; j < b; ++j) {
            dp[b][0][1 << j] = 1;
        }
        for (int i = 1; i < maxs; ++i) {
            for (int mask = 0; mask < (1 << b); ++mask) {
                for (int j = 0; j < b; ++j) {
                    dp[b][i][mask ^ (1 << j)] += dp[b][i - 1][mask];
                }
            }
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int b, l, r;
        cin >> b >> l >> r;
        cout << solve(b, r) - solve(b, l - 1) << "\n";
    }
    return 0;
}
