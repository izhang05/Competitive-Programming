#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
    freopen((name + ".out").c_str(), "w", stderr);
#endif
}
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e5 + 5, k = 320;
int dp[maxn + k][k], cnt[maxn];

int main() {
    setIO("1");
    int n, q;
    cin >> n >> q;
    while (q--) {
        int a, l, d;
        cin >> a >> l >> d;
        --a;
        if (d >= k) {
            for (int i = a; i < a + l * d; i += d) {
                ++cnt[i];
            }
        } else {
            ++dp[a][d];
            --dp[a + l * d][d];
        }
    }
    for (int j = 1; j < k; ++j) {
        for (int i = 0; i < n; ++i) {
            if (i - j >= 0) {
                dp[i][j] += dp[i - j][j];
            }
            cnt[i] += dp[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << cnt[i] << " \n"[i == n - 1];
    }
    return 0;
}
