/*
ID: izhang01
TASK: pieaters
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    freopen("pieaters.in", "r", stdin);
    freopen("pieaters.out", "w", stdout);
    freopen("pieaters.out", "w", stderr);
}
//#define DEBUG
struct cow {
    long long w, l, r;
};
template<class T>
bool ckmax(T &a, const T &b) {
    return a < b ? a = b, 1 : 0;
}

const int maxn = 305;
long long dp[maxn][maxn]; // dp[i][j] = best solution in range [i,j] where i<=l && r<=j for all cows
long long mx[maxn][maxn][maxn];

int main() {
    setIO();
    int n, m;
    cin >> n >> m;
    vector<cow> a(m);
    for (int i = 0; i < m; ++i) {
        cin >> a[i].w >> a[i].l >> a[i].r;
        --a[i].l, --a[i].r;
        for (int j = a[i].l; j <= a[i].r; ++j) {
            ckmax(mx[j][a[i].l][a[i].r], a[i].w);
        }
    }
    for (int k = 0; k < n; ++k) {
        for (int len = 1; len <= n; ++len) {
            for (int i = 0, j = i + len - 1; j < n; ++i, ++j) {
                ckmax(mx[k][i][j], mx[k][i + 1][j]);
                if (j) {
                    ckmax(mx[k][i][j], mx[k][i][j - 1]);
                }
            }
        }
    }
    for (int i = n - 1; i >= 0; --i) {
        for (int j = i; j < n; ++j) {
            for (int k = i; k <= j; ++k) {
                ckmax(dp[i][j], dp[i][k] + dp[k + 1][j]);
                if (k) {
                    ckmax(dp[i][j], dp[i][k - 1] + dp[k + 1][j] + mx[k][i][j]);
                } else {
                    ckmax(dp[i][j], dp[k + 1][j] + mx[k][i][j]);
                }
            }
        }
    }
    cout << dp[0][n - 1] << "\n";
    return 0;
}
