#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen((name + ".in").c_str(), "r", stdin);
//    freopen((name + ".out").c_str(), "w", stdout);
//    freopen((name + ".out").c_str(), "w", stderr);
#endif
}
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e5 + 5;
vector<int> adj[maxn];
int sol;
bool vis[maxn];

void dfs(int c) {
    ++sol;
    vis[c] = true;
    for (auto &i : adj[c]) {
        if (!vis[i]) {
            dfs(i);
        }
    }
}

int main() {
    setIO("1");

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
    }
    for (int i = 0; i < n; ++i) {
        sol = -1;
        memset(vis, false, sizeof(vis));
        dfs(i);
        cout << sol << "\n";
    }
    return 0;
}
