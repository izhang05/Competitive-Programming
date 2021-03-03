#include <bits/stdc++.h>

using namespace std;

mt19937 rng((uint32_t) chrono::steady_clock::now().time_since_epoch().count());
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T>
using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T>
using indexed_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T>
void print(T a, string sep = " ", string end = "\n") {
    for (auto i : a) {
        cout << i << sep;
    }
    cout << end;
}
//#define DEBUG
void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    freopen("1.out", "w", stderr);
#endif
}
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxp = 7, maxn = 1e5 + 5;
long long dp[maxn][1 << maxp], a[maxn], s[maxn][maxp];

bool cmp(int x, int y) {
    return a[x] > a[y];
}

int main() {
#ifdef LOCAL
    auto start_time = chrono::high_resolution_clock::now();
#endif
    setIO();
    int n, p, k;
    cin >> n >> p >> k;
    vector<int> players(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        players[i] = i;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < p; ++j) {
            cin >> s[i][j];
        }
    }

    sort(players.begin(), players.end(), cmp);
#ifdef DEBUG
    cout << "players: ";
    print(players);
#endif
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int mask = 0; mask < (1 << p); ++mask) {
            long long &cur = dp[i][mask];
            if (dp[i - 1][mask] != -1) {
                cur = dp[i - 1][mask];
                int taken = i - __builtin_popcount(mask);
                if (taken <= k) {
                    cur = max(cur, dp[i - 1][mask] + a[players[i - 1]]);
                }
            }
            for (int j = 0; j < p; ++j) {
                if (mask & (1 << j) && dp[i - 1][mask ^ (1 << j)] != -1) {
                    cur = max(cur, dp[i - 1][mask ^ (1 << j)] + s[players[i - 1]][j]);
                }
            }
        }
    }

#ifdef DEBUG
    for (int i = 1; i < n + 1; ++i) {
        for (int mask = 0; mask < (1 << p); ++mask) {
            cout << dp[i][mask] << " ";
        }
        cout << "\n";
    }
    cout << "sol: ";
#endif

    cout << dp[n][(1 << p) - 1] << "\n";

#ifdef LOCAL
    auto end_time = chrono::high_resolution_clock::now();
    cout << setprecision(6) << fixed;
    cout << "Execution time: " << chrono::duration_cast<chrono::duration<double>>(end_time - start_time).count() << " seconds" << endl;
#endif
    return 0;
}
