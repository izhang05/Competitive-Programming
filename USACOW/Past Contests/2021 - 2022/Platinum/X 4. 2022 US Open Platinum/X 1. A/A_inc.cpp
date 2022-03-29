#include <bits/stdc++.h>

using namespace std;

#if defined LOCAL || defined DEBUG
#include <debug.h>
#else
struct dbg {
    template<class c>
    dbg &operator<<(const c &) { return *this; }
};
#endif

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
const int inf = 0x3f3f3f3f, maxn = 305;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
long long dp[maxn][maxn];

long long merge(long long a, long long b) {
    return max(a, b) + 1;
}

int main() {
    setIO("1");

    int n;
    cin >> n;
    vector<long long> a(n);
    memset(dp, 0x3f, sizeof(dp));
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        dp[i][i + 1] = a[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        dp[i][i + 2] = merge(a[i], a[i + 1]);
    }
    for (int r = 0; r <= n; ++r) {
        for (int l = 0; l < r; ++l) {
            for (int i = l + 1; i < r - 1; ++i) {
                for (int j = i + 1; j <= i + 1; ++j) {
                    long long cur = min(merge(merge(dp[l][i], dp[i][j]), dp[j][r]), merge(dp[l][i], merge(dp[i][j], dp[j][r])));
                    dp[l][r] = min(dp[l][r], cur);
                }
            }
        }
    }
    long long sol = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            sol += dp[i][j];
            dbg() << i << " " << j << " " << dp[i][j];
        }
    }
    cout << sol << "\n";
    return 0;
}
