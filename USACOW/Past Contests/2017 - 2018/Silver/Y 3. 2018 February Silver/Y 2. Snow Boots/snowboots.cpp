/*
ID: izhang01
TASK: snowboots
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("snowboots.in", "r", stdin);
    freopen("snowboots.out", "w", stdout);
}


int main() {
    setIO();

    int n, b;
    cin >> n >> b;
    bool dp[n][b];

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        for (int j = 0; j < b; ++j) {
            dp[i][j] = false;
        }
    }
    vector<pair<int, int> > boots(b); // first = max_depth, second = max_dist
    for (int i = 0; i < b; ++i) {
        cin >> boots[i].first >> boots[i].second;
    }
    for (int i = 0; i < b; ++i) {
        dp[0][i] = true;
    }

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < b; ++j) {
            if (boots[j].first >= a[i]) {
                for (int k = max(i - boots[j].second + 1, 0); k < i; ++k) {
                    if (dp[k][j]) {
                        dp[i][j] = true;
                        break;
                    }
                }
                if (!dp[i][j]) {
                    for (int k = 0; k < j; ++k) {
                        if (dp[i][k]) {
                            dp[i][j] = true;
                            break;
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < b; ++j) {
            cout << dp[i][j] << "";
        }
        cout << "\n";
    }

    for (int i = 0; i < b; ++i) {
        if (dp[n - 1][i]) {
            cout << i << "\n";
            return 0;
        }
    }
    return 0;
}

