#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("snowboots.in", "r", stdin);
    freopen("snowboots.out", "w", stdout);
}
const int maxn = 255;

int f[maxn], s[maxn], d[maxn], val[maxn][maxn];
bool visited[maxn][maxn];
int n, b;

int dfs(int pos, int boot) {
    // we've reached the end
    if (pos == n - 1) {
        return boot;
    }
    // we've already processed this state
    if (visited[pos][boot]) {
        return val[pos][boot];
    }
    visited[pos][boot] = true;
    int sol = 1e9;
    // try all possible steps forward
    for (int i = pos + 1; i < n && i <= d[boot] + pos; ++i) {
        if (f[i] <= s[boot]) {
            sol = min(sol, dfs(i, boot));
        }
    }
    // try all possible next boots
    for (int i = boot + 1; i < b; ++i) {
        if (f[pos] <= s[i]) {
            sol = min(sol, dfs(pos, i));
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
