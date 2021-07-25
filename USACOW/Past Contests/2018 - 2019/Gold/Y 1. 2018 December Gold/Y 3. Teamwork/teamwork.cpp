/*
ID: izhang01
TASK: teamwork
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("teamwork.in", "r", stdin);
    freopen("teamwork.out", "w", stdout);
}

const int maxn = 1e4 + 1;
int n, k, dp[maxn], skill[maxn];

int main() {
    setIO();
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> skill[i];
    }
    dp[0] = skill[0];
    for (int i = 1; i < n; ++i) {
        int best = 0;
        for (int j = i; j >= max(0, i - k + 1); --j) {
            best = max(best, skill[j]);
            if (j == 0) {
                dp[i] = max(dp[i], best * (i - j + 1));
            } else {
                dp[i] = max(dp[i], dp[j - 1] + best * (i - j + 1));
            }
        }
    }
    cout << dp[n - 1] << "\n";
    return 0;
}
