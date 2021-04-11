#include <bits/stdc++.h>

using namespace std;

mt19937 rng((uint32_t) chrono::steady_clock::now().time_since_epoch().count());
//#define DEBUG
void setIO(string name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
    freopen((name + ".out").c_str(), "w", stderr);
#endif
}
#define int long long
const int inf = 0x3f3f3f3f, mod = 998244353ll, maxn = 1e3 + 5;

long long sol = 0, dp[maxn][maxn], last[maxn], pre[maxn][maxn], n, k;
vector<long long> a;

void solve(int x) {
    for (int i = 0; i < n; ++i) {
        last[i] = -1;
        for (int j = 0; j <= k; ++j) {
            dp[i][j] = 0;
            pre[i][j] = 0;
        }
    }

    int i = -1;
    for (int j = 0; j < n; ++j) {
        while (i + 1 < j && a[i + 1] + x <= a[j]) {
            ++i;
        }
        last[j] = i;
    }
#ifdef DEBUG
    cout << "last:"
         << "\n";
    for (int i = 0; i < n; ++i) {
        cout << last[i] << " ";
    }
    cout << "\n";
#endif
    for (int i = 0; i < n; ++i) {
        dp[i][1] = 1;
        pre[i][1] = i + 1;
    }
    for (int i = 2; i <= k; ++i) {
        for (int j = 0; j < n; ++j) {
            if (last[j] == -1) {
                continue;
            }
            dp[j][i] = pre[last[j]][i - 1];
            dp[j][i] %= mod;
            pre[j][i] = pre[j - 1][i] + dp[j][i];
            pre[j][i] %= mod;
        }
    }
#ifdef DEBUG
    for (int i = 0; i <= k; ++i) {
        for (int l = 0; l < n; ++l) {
            cout << dp[l][i] << " ";
        }
        cout << "\n";
    }
#endif
    sol += pre[n - 1][k];
    sol %= mod;
#ifdef DEBUG
    cout << sol << "\n";
#endif
}

signed main() {
    setIO("b");
    cin >> n >> k;
    a.resize(n);
    long long mx = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    sort(a.begin(), a.end());
    for (long long i = 1; i * (k - 1) <= mx; ++i) {
#ifdef DEBUG
        cout << "solve: " << i << "\n";
#endif
        solve(i);
    }
    cout << sol << "\n";
    return 0;
}
