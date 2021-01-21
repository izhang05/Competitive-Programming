#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    freopen("solution.out", "w", stdout);
    freopen("2.in", "r", stdin);
#endif
}

const int maxn = 1001, maxf = 100;
int dp[maxn][maxn], pre[maxf][maxn]; // dp[last_pos][pos_of_first_group]

// dp[i][j] = min_element(dp[j]) + k + num_conflict


int cost (int x, int y) { // cost in range (x, y]
    int sol = 0;
    for (auto i : pre) {
        sol += i[y + 1] - i[x + 1] > 1 ? i[y + 1] - i[x + 1]: 0;
    }
    return sol;
}


int main() {
    setIO();

    int t;
    cin >> t;
    while (t--) {
        int n, k, f;
        cin >> n >> k;
        for (int i = 0; i < n; ++i) {
            cin >> f;
            --f;
            for (int j = 0; j < maxf; ++j) {
                if (j == f) {
                    pre[j][i + 1] = pre[j][i] + 1;
                } else {
                    pre[j][i + 1] = pre[j][i];
                }
            }
            for (int j = 0; j < n; ++j) {
                dp[i][j] = 1e9;
            }
        }
        for (int i = 0; i < n; ++i) {
            dp[i][0] = k + cost(-1, i);
        }
        for (int i = 0; i < n; ++i) {
            int best = 1e9;
            for (int j = 0; j < n; ++j) {
                best = min(best, dp[i][j]);
            }
            for (int j = i + 1; j < n; ++j) {
                dp[j][i] = min(dp[j][i], best + k + cost(i, j));
            }
            if (i == n - 1) {
                cout << best << "\n";
            }
        }
    }
    return 0;
}
