/*
ID: izhang01
TASK: nocross
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("nocross.in", "r", stdin);
    freopen("nocross.out", "w", stdout);
}
const int maxn = 1e3 + 5;
int dp[maxn][maxn], pre[maxn][maxn];

int main() {
    setIO();
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    int sol = 0;
    for (int i = 1; i < n + 1; ++i) {
        for (int j = 1; j < n + 1; ++j) {
            if (abs(a[i - 1] - b[j - 1]) <= 4) {
                dp[i][j] = pre[i - 1][j - 1] + 1;
                sol = max(sol, dp[i][j]);
            }
            pre[i][j] = max({pre[i - 1][j], pre[i][j - 1], dp[i][j]});
        }
    }
    cout << sol << "\n";
    return 0;
}
