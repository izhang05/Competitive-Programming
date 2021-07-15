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

int n;
vector<int> adj[maxn], radj[maxn];
int comp[maxn];
bool vis[maxn];
vector<int> todo, comps;
void dfs(int c) {
    vis[c] = true;
    for (auto &i : adj[c]) {
        if (!vis[i]) {
            dfs(i);
        }
    }
    todo.push_back(c);
}
void dfs2(int c, int v) {
    comp[c] = v;
    for (auto &i : radj[c]) {
        if (comp[i] == -1) {
            dfs2(i, v);
        }
    }
}

void gen() {
    memset(comp, -1, sizeof(comp));
    for (int i = 0; i < n; ++i) {
        if (!vis[i]) {
            dfs(i);
        }
    }
    reverse(todo.begin(), todo.end());
    for (auto &i : todo) {
        if (comp[i] == -1) {
            dfs2(i, i);
            comps.push_back(i);
        }
    }
}


long long dp[maxn], group[maxn];
set<int> graph[maxn];

long long solve(int x) {
    if (dp[x]) {
        return dp[x];
    }
    dp[x] = group[x];
    for (auto &i : graph[x]) {
        dp[x] += solve(i);
    }
    return dp[x];
}

int main() {
    setIO("1");
    int m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        radj[b].push_back(a);
    }
    gen();
    for (int i = 0; i < n; ++i) {
        ++group[comp[i]];
        for (auto &j : adj[i]) {
            if (comp[i] != comp[j]) {
                graph[comp[i]].insert(comp[j]);
            }
        }
    }
    for (auto &i : comps) {
        solve(i);
    }
    for (int i = 0; i < n; ++i) {
        cout << dp[comp[i]] - 1 << "\n";
    }
    return 0;
}
