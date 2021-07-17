/* Author: izhang05
 * Time: 07-17-2021 15:02:17
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 3e5 + 5;
int n;
vector<int> adj[maxn], radj[maxn];
int comp[maxn], cost[maxn];
bool vis[maxn];
vector<int> todo, components;
void dfs1(int c) {
    vis[c] = true;
    for (auto &i : adj[c]) {
        if (!vis[i]) {
            dfs1(i);
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
            dfs1(i);
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

void ae(int a, int b) {
    adj[a].push_back(b);
    radj[b].push_back(a);
}
pair<int, int> mn[maxn];

int main() {
    setIO("1");
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> cost[i];
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        ae(a, b);
    }
    gen();
    for (auto &i : components) {
        mn[i] = {inf, 0};
    }
    for (int i = 0; i < n; ++i) {
        if (cost[i] < mn[comp[i]].first) {
            mn[comp[i]].first = cost[i];
            mn[comp[i]].second = 1;
        } else if (cost[i] == mn[comp[i]].first) {
            ++mn[comp[i]].second;
        }
    }
    long long sol = 0, ways = 1;
    for (auto &i : components) {
        sol += mn[i].first;
        ways *= mn[i].second;
        ways %= mod;
    }
    cout << sol << " " << ways << "\n";
    return 0;
}
