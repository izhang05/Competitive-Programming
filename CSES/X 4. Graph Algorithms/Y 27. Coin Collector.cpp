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

const int maxn = 1e5 + 5;

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
long long dp[maxn], group[maxn], a[maxn];
vector<int> rgraph[maxn];

long long solve(int x) {
    if (dp[x]) {
        return dp[x];
    }
    dp[x] = group[x];
    for (auto &i : rgraph[x]) {
        dp[x] = max(dp[x], solve(i) + group[x]);
    }
    return dp[x];
}

int main() {
    setIO("27");
    int m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        comp[i] = -1;
        cin >> a[i];
    }
    for (int i = 0; i < m; ++i) {
        int b, c;
        cin >> b >> c;
        --b, --c;
        adj[b].push_back(c);
        radj[c].push_back(b);
    }
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
    for (int i = 0; i < n; ++i) {
        group[comp[i]] += a[i];
        for (auto &j : adj[i]) {
            if (comp[i] != comp[j]) {
                //                cout << comp[j] << " " << comp[i] << "\n";
                rgraph[comp[j]].push_back(comp[i]);
            }
        }
    }
    long long sol = 0;
    for (auto &i : comps) {
        sol = max(sol, solve(i));
    }
    cout << sol << "\n";
    return 0;
}