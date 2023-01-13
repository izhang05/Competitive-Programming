#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("snowboots.in", "r", stdin);
    freopen("snowboots.out", "w", stdout);
}
const int maxn = 255;
int n, b, f[maxn], s[maxn], d[maxn], val[maxn][maxn];
bool visited[maxn][maxn];

int dfs(int pos, int boot) {
    // returns the answer starting at this particular vertex (pos, boot) going to tile N
    if (pos == n - 1) {
        return boot;
    }
    if (visited[pos][boot]) {
        return val[pos][boot];
    }
    visited[pos][boot] = true;
    int sol = 1e9;
    // move to all possible locations
    for (int nxt_pos = pos + 1; nxt_pos < n && nxt_pos <= pos + d[boot]; ++nxt_pos) {
        if (f[nxt_pos] <= s[boot]) {
            // snow depth at nxt_pos <= s_boot
            sol = min(sol, dfs(nxt_pos, boot));
        }
    }

    // if pos = 1, boot = 1 -> (1, 2), (1, 3), (1, 4) ... (1, b)
    // if pos = 1, boot = 2 -> (1, 3), (1, 4) ... (1, b)
    // the same state can be visited multiple times -> TLE :(
    // adding the visited array fixes this issue

    // move to all possible boot change states
    for (int nxt_boot = boot + 1; nxt_boot < b; ++nxt_boot) {
        if (f[pos] <= s[nxt_boot]) {
            sol = min(sol, dfs(pos, nxt_boot));
        }
    }
    val[pos][boot] = sol;
    return sol;
}

int main() {
    setIO();
    cin >> n >> b;
    for (int i = 0; i < n; ++i) {
        cin >> f[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> s[i] >> d[i];
    }

    cout << dfs(0, 0) << "\n";

    return 0;
}
