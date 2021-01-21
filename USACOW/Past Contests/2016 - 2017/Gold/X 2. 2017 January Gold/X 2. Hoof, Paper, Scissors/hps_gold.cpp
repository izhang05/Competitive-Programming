/*
ID: izhang01
TASK: hps_gold
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);
}

const int maxn = 1e5 + 1;

int n, k, dp[maxn][21][3]; // dp[num_games][num_switches][move]
vector<int> gestures;
vector<vector<int> > pre;

int main() {
    setIO();
    cin >> n >> k;
    gestures.resize(n);
    pre.resize(n);
    char a;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        if (a == 'H') {
            gestures[i] = 0;
        } else if (a == 'P') {
            gestures[i] = 1;
        } else {
            gestures[i] = 2;
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= min(k, i); ++j) {
            for (int state = 0; state < 3; ++state) {
                if (j == 0) {
                    dp[i][j][state] = max(dp[i][j][state], dp[i - 1][j][state] + int(gestures[i - 1] == state));
                } else {
                    int best = max({dp[i - 1][j][state], dp[i - 1][j - 1][(state + 1) % 3],
                                    dp[i - 1][j - 1][(state + 2) % 3]}) + int(gestures[i - 1] == state);
                    dp[i][j][state] = max(dp[i][j][state], best);
                }
            }
        }
    }

    cout << max({dp[n][k][0], dp[n][k][1], dp[n][k][2]}) << "\n";
    return 0;
}

