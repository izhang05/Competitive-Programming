#include <bits/stdc++.h>

using namespace std;

mt19937 rng((uint32_t) chrono::steady_clock::now().time_since_epoch().count());
//#define DEBUG
void setIO(string name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
    freopen((name + ".out").c_str(), "w", stderr);
#endif
}
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 505;

int dp[maxn][maxn], mn[maxn][maxn];
vector<int> classes[maxn];

int main() {
    setIO("b");
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < m; ++j) {
            if (s[j] == '1') {
                classes[i].push_back(j);
            }
        }
    }
    memset(mn, 0x3f, sizeof(mn));
    for (int i = 0; i < n; ++i) {
        mn[i][0] = 0;
        for (int j = 0; j < (int) classes[i].size(); ++j) {
            for (int l = j; l < (int) classes[i].size(); ++l) {
                mn[i][l - j + 1] = min(mn[i][l - j + 1], classes[i][l] - classes[i][j] + 1);
            }
        }
#ifdef DEBUG
        for (int j = 0; j <= (int) classes[i].size(); ++j) {
            cout << mn[i][j] << " ";
        }
        cout << "\n";
#endif
    }
    memset(dp, 0x3f, sizeof(dp));
    for (int i = 0; i < (int) classes[0].size() + 1; ++i) {
        dp[0][i] = mn[0][classes[0].size() - i];
    }
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j <= k; ++j) {
            int cur = dp[i][j];
            if (cur == inf) {
                continue;
            }
            for (int skip = 0; skip <= (int) classes[i + 1].size() && j + skip <= k; ++skip) {
                dp[i + 1][j + skip] = min(dp[i + 1][j + skip], cur + mn[i + 1][(int) classes[i + 1].size() - skip]);
            }
        }
    }
    int sol = inf;
    for (int i = 0; i <= k; ++i) {
        sol = min(sol, dp[n - 1][i]);
    }
    cout << sol << "\n";
    return 0;
}
