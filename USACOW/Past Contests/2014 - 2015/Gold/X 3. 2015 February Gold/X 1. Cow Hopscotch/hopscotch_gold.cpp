/*
ID: izhang01
TASK: hopscotch
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("hopscotch.in", "r", stdin);
    freopen("hopscotch.out", "w", stdout);
}
//#define DEBUG
const int maxn = 755, mod = 1e9 + 7;
int grid[maxn][maxn];
long long dp[maxn][maxn];

int main() {
    setIO();
#ifdef LOCAL
    auto start_time = std::chrono::high_resolution_clock::now();
#endif
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }
    for (int row = 0; row < n; ++row) {
        long long total = 0;
        map<int, long long> val;
        for (int i = 0; i < row + 1; ++i) {
            total += dp[i][0];
            total %= mod;
            val[]
        }
    }
    cout << dp[n - 1][m - 1] % mod << "\n";
#ifdef LOCAL
    auto end_time = std::chrono::high_resolution_clock::now();
    cout << setprecision(6) << fixed;
    cout << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end_time - start_time).count() << " seconds" << endl;
#endif
    return 0;
}
