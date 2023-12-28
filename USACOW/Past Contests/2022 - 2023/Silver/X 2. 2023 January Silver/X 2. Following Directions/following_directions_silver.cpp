#include <bits/stdc++.h>

using namespace std;

#if defined LOCAL || defined DEBUG
#include <debug.h>
#else
struct dbg {
    template<class c>
    dbg &operator<<(const c &) { return *this; }
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
#endif

void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen(("in" + name + ".txt").c_str(), "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("out.txt", "w", stderr);
#endif
}
const int maxn = 1505, dx[2] = {1, 0}, dy[2] = {0, 1};
int grid[maxn][maxn], cost[maxn][maxn], n;

int dp(int x, int y) {
    if (cost[x][y] != -1) {
        return cost[x][y];
    }
    int nx = x + dx[grid[x][y]], ny = y + dy[grid[x][y]];
    return cost[x][y] = dp(nx, ny);
}

int solve() {
    memset(cost, -1, sizeof(cost));
    for (int i = 0; i < n; ++i) {
        cost[n][i] = grid[n][i];
        cost[i][n] = grid[i][n];
    }
    int sol = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            sol += dp(i, j);
        }
    }
    return sol;
}
