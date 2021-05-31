/*
ID: izhang01
TASK: 248
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("248.in", "r", stdin);
    freopen("248.out", "w", stdout);
}
const int maxn = 250, inf = 0x3f3f3f3f;
int dp[maxn][maxn]; // dp[i][j] = number if entire interval can be collapsed into one number, otherwise inf

int main() {
    setIO();
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int sol = 0;
    for (int len = 0; len < n; ++len) {
        for (int i = 0; i + len < n; ++i) {
            int j = i + len;
            dp[i][j] = -1;
            if (len == 0) {
                dp[i][j] = a[i];
            }
            for (int k = i; k < j; ++k) {
                if (dp[i][k] != -1 && (dp[i][k] == dp[k + 1][j])) {
                    dp[i][j] = max(dp[i][j], dp[i][k] + 1);
                }
            }
            sol = max(sol, dp[i][j]);
        }
    }
    cout << sol << "\n";
    return 0;
}
