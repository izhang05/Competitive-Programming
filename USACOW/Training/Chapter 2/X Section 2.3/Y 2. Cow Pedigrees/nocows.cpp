/*
ID: izhang01
TASK: nocows
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    freopen("nocows.in", "r", stdin);
    freopen("nocows.out", "w", stdout);
    freopen("nocows.out", "w", stderr);
}
//#define DEBUG
const int mod = 9901, maxn = 205, maxk = 105;

int dp[maxn][maxk][maxn]; // dp[i][j][k] - dp[num nodes][max height][num nodes with max height]

int main() {
    setIO();
    int n, k;
    cin >> n >> k;
    dp[1][1][1] = 1;
    for (int i = 1; i < n; i+=2) {
        for (int j = 1; j < k; ++j) {
            for (int l = 1; l <= i; ++l) {
                dp[i+2][j][]
            }
        }
    }

    int sol = 0;
    for (auto &i : dp[n][k]) {
        sol += i;
        sol %= mod;
    }
    cout << sol << "\n";
    return 0;
}
