#include <bits/stdc++.h>

using namespace std;

const int mxn = 505;

int dp[mxn][mxn]; // [i, j)

int main() {
    ios_base::sync_with_stdio();
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    memset(dp, 0x3f, sizeof(dp));
    map<int, int> ind;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
        a[i] = n - 1 - a[i];
        dp[i][i + 1] = 0;
        ind[a[i]] = i;
    }
    for (int i = n - 1; i >= 0; --i) {
        for (int j = i + 1; j <= n; ++j) {
//            cout << i << " " << j << ": ";
            int prev;
            for (int k = i + 1; k < j; ++k) {
                int orig = dp[i][j];
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + abs(ind[k - 1] - ind[j - 1]));
                if (dp[i][j] < orig) {
                    prev = k;
                }
            }
//            cout << dp[i][j] << " " << prev << "\n";
        }
    }
    cout << dp[0][n] << "\n";
}
