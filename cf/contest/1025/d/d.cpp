/* Author: izhang05
 * Time: 06-28-2021 16:41:06
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 705;

bool dp[maxn][maxn][2], g[maxn][maxn];

bool val(int i, int j, int k) {
    bool cur = true;
    if (k - 1 >= i) {
        cur &= dp[i][k - 1][1];
    }
    if (k + 1 <= j) {
        cur &= dp[k + 1][j][0];
    }
    return cur;
}

int main() {
    setIO("1");

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (gcd(a[i], a[j]) > 1) {
                g[i][j] = true;
            }
        }
    }
    for (int len = 1; len <= n; ++len) {
        for (int i = 0, j = i + len - 1; j < n; ++i, ++j) {
            if (i > 0) {
                for (int k = i; k <= j; ++k) {
                    dp[i][j][0] |= g[i - 1][k] & val(i, j, k);
                }
            }
            if (j + 1 < n) {
                for (int k = i; k <= j; ++k) {
                    dp[i][j][1] |= g[k][j + 1] & val(i, j, k);
                }
            }
        }
    }
    for (int k = 0; k < n; ++k) {
        if (val(0, n - 1, k)) {
            cout << "Yes\n";
            return 0;
        }
    }
    cout << "No\n";
    return 0;
}
