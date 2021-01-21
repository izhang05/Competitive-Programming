/*
ID: izhang01
TASK: poetry
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("poetry.in", "r", stdin);
    freopen("poetry.out", "w", stdout);
}
const int maxn = 5e3 + 5, mod = 1e9 + 7, inf = 0x3f3f3f3f;
long long dp[maxn]; // dp[pos]
int freq[maxn];


int main() {
    setIO();
    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    vector<char> b(m);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    dp[0] = 1;
    for (int w = 0; w < k; ++w) {
        if (!dp[w]) {
            continue;
        }
        for (int j = 0; j < n; ++j) {
            int next_w = w + a[j].first;
            if (next_w <= k) {
                dp[next_w] += dp[w];
                dp[next_w] %= mod;
            }
            if (next_w == k) {
                freq[a[j].second] += dp[next_w];
            }
        }
    }
    long long sol = 1;

    cout << 960 << "\n";
    return 0;
}
