#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    freopen("1.out", "w", stderr);
#endif
}
//#define DEBUG
const int maxn = 305;
int dp[maxn][maxn];

int main() {
    setIO();
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = n - 1; i >= 0; --i) {
        for (int j = i + 1; j < n; ++j) {
            if (a[i] == a[j]) {
                dp[i][j] = max(dp[i][j], 1 + dp[i + 1][j - 1]);
            }
            for (int k = i + 1; k < j; ++k) {
                dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
    cout << n - dp[0][n - 1] << "\n";
    return 0;
}
