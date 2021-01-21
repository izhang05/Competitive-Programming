/*
ID: izhang01
TASK: mooomoo
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("mooomoo.in", "r", stdin);
    freopen("mooomoo.out", "w", stdout);
}
const int maxn = 1e5 + 5, inf = 0x3f3f3f3f;
int dp[maxn];

int main() {
    setIO();
    int n, b;
    cin >> n >> b;
    vector<int> cows(b);
    for (int i = 0; i < b; ++i) {
        cin >> cows[i];
    }
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;
    for (int i = 1; i < maxn; ++i) {
        for (int j : cows) {
            if (i - j >= 0) {
                dp[i] = min(dp[i], dp[i - j] + 1);
            }
        }
    }
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    if (dp[a[0]] == inf) {
        cout << -1 << "\n";
        return 0;
    }
    int sol = dp[a[0]];
    for (int i = 1; i < n; ++i) {
        int dif = a[i] - (max(0, a[i - 1] - 1));
        if (dp[dif] == inf) {
            cout << -1 << "\n";
            return 0;
        }
        sol += dp[dif];
    }
    cout << sol << "\n";
    return 0;
}
