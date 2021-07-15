/* Author: izhang05
 * Time: 07-15-2021 15:49:39
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e5 + 5;
vector<int> adj[maxn], radj[maxn];
bool vis[maxn];
int sz, in_deg[maxn];
queue<int> q;

void dfs(int c) {
    if (!in_deg[c]) {
        q.push(c);
    }
    ++sz;
    vis[c] = true;
    for (auto &i : adj[c]) {
        if (!vis[i]) {
            dfs(i);
        }
    }
    for (auto &i : radj[c]) {
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
        ++in_deg[b];
        radj[b].push_back(a);
    }
    int sol = 0;
    for (int i = 0; i < n; ++i) {
        if (!vis[i]) {
            sz = 0;
            dfs(i);
            int found = 0;
            while (!q.empty()) {
                int cur = q.front();
                q.pop();
                ++found;
                for (auto &j : adj[cur]) {
                    if (--in_deg[j] == 0) {
                        q.push(j);
                    }
                }
            }
            sol += sz;
            if (found == sz) {
                --sol;
            }
        }
    }
    cout << sol << "\n";
    return 0;
}
