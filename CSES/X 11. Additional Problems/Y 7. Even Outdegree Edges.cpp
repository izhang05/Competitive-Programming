#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
    freopen((name + ".out").c_str(), "w", stderr);
#endif
}
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e5 + 5;
vector<int> adj[maxn];
int visited[maxn], deg[maxn], t = 1;

vector<pair<int, int>> sol;

void dfs(int c, int p) {
    visited[c] = t++;
    for (auto &i : adj[c]) {
        if (i != p) {
            if (!visited[i]) {
                dfs(i, c);
                if (deg[i]) {
                    sol.emplace_back(i, c);
                    deg[i] ^= 1;
                } else {
                    sol.emplace_back(c, i);
                    deg[c] ^= 1;
                }
            } else if (visited[c] < visited[i]) {
                sol.emplace_back(c, i);
                deg[c] ^= 1;
            }
        }
    }
}

int main() {
    setIO("7");
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            dfs(i, 0);
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (deg[i]) {
            cout << "IMPOSSIBLE"
                 << "\n";
            return 0;
        }
    }
    for (auto &i : sol) {
        cout << i.first << " " << i.second << "\n";
    }
    return 0;
}
