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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 2e5 + 5;
vector<pair<int, int>> adj[maxn];
long long down[maxn][2], up[maxn][2];

void dfs1(int c, int p) {
    for (auto i : adj[c]) {
        if (i.first != p) {
            dfs1(i.first, c);
            if (i.second == 0) {
                down[c][0] += 1 + down[i.first][0];
            } else {
                down[c][1] += 1 + down[i.first][0] + down[i.first][1];
            }
        }
    }
}

void dfs2(int c, int p, int w) {
    if (p != -1) {
        array<long long, 2> d{down[p][0], down[p][1]};
        if (w == 0) {
            up[c][0] += 1 + up[p][0];
            d[0] -= 1 + down[c][0];
            up[c][0] += d[0];
        } else {
            up[c][1] += 1 + up[p][0] + up[p][1];
            d[1] -= 1 + down[c][0] + down[c][1];
            up[c][1] += d[0] + d[1];
        }
    }
    for (auto i : adj[c]) {
        if (i.first != p) {
            dfs2(i.first, c, i.second);
        }
    }
}

int main() {
    setIO("b");

    int n;
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        --a, --b;
        adj[a].emplace_back(b, c);
        adj[b].emplace_back(a, c);
    }
    dfs1(0, -1);
    dfs2(0, -1, -1);
#ifdef DEBUG
    for (int j = 0; j < n; ++j) {
        cout << down[j][0] << " " << down[j][1] << " " << up[j][0] << " " << up[j][1] << "\n";
    }
#endif
    long long sol = 0;
    for (int i = 0; i < n; ++i) {
        sol += down[i][0] + down[i][1] + up[i][0] + up[i][1];
    }
    cout << sol << "\n";
    return 0;
}
