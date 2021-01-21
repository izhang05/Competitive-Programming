/*
ID: izhang01
TASK: wifi
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("wifi.in", "r", stdin);
    freopen("wifi.out", "w", stdout);
}

const int maxn = 2e3;
long long dp[maxn];
int n, a, b;
vector<int> cows;

long long sol(int c) {
    if (dp[c] >= 0) {
        return dp[c];
    }
    long long &res = dp[c];
    res = 2 * a + b * (cows[c] - cows[0]);
    for (int i = 0; i < c; ++i) {
        res = min(res, sol(i) + 2 * a + b * (cows[c] - cows[i + 1]));
    }
    return res;
}

int main() {
    setIO();
    cin >> n >> a >> b;
    cows.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> cows[i];
        dp[i] = -1;
    }
    sort(cows.begin(), cows.end());
    long long res = sol(n - 1);
    if (res % 2 == 0) {
        cout << res / 2 << "\n";
    } else {
        cout << res / 2 << ".5" << "\n";
    }
    return 0;
}
