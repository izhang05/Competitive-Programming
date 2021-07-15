/* Author: izhang05
 * Time: 07-15-2021 14:11:07
**/
#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e6 + 5;
int n;
vector<int> adj[maxn], radj[maxn];
int comp[maxn], in_deg[maxn], out_deg[maxn], par[maxn];
bool vis[maxn];
vector<int> todo, components;
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

void reset() {
    for (int i = 0; i < n; ++i) {
        adj[i].clear();
        radj[i].clear();
        comp[i] = -1;
        par[i] = 0;
        in_deg[i] = 0, out_deg[i] = 0;
        vis[i] = false;
    }
    todo.clear();
    components.clear();
}

void gen() {
    for (int i = 0; i < n; ++i) {
        if (!vis[i]) {
            dfs(i);
        }
    }
    reverse(todo.begin(), todo.end());
    for (auto &i : todo) {
        if (comp[i] == -1) {
            dfs2(i, i);
            components.push_back(i);
        }
    }
}

void solve() {
    reset();
    int m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        radj[b].push_back(a);
        ++out_deg[a], ++in_deg[b];
        par[b] = a;
    }
    if (n == 1) {
        cout << "No\n";
        return;
    }
    for (int i = 0; i < n; ++i) {
        if (in_deg[i] <= 1 || out_deg[i] <= 1) {
            cout << "Yes\n";
        }
        if (in_deg[i] <= 1) {
            cout << n - 1 << " " << 1 << "\n";
            for (int j = 1; j <= n; ++j) {
                if (j != par[i] + 1) {
                    cout << j << " ";
                }
            }
            cout << "\n";
            cout << par[i] + 1 << "\n";
            return;
        } else if (out_deg[i] <= 1) {
            cout << 1 << " " << n - 1 << "\n";
            cout << i + 1 << "\n";
            for (int j = 1; j <= n; ++j) {
                if (j != i + 1) {
                    cout << j << " ";
                }
            }
            cout << "\n";
            return;
        }
    }
    cout << "No\n";
}

int main() {
    setIO("1");

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
