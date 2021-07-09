/* Author: izhang05
 * Time: 07-09-2021 16:29:50
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
vector<int> adj[maxn], adj_dfs[maxn];
bool visited[maxn];
int depth[maxn], par[maxn];
int k;

void dfs(int c, int p, int d) {
    visited[c] = true;
    depth[c] = d;
    for (auto &i : adj[c]) {
        if (i != p) {
            if (!visited[i]) {
                adj_dfs[c].push_back(i);
                par[i] = c;
                dfs(i, c, d + 1);
            } else {
                if (depth[c] > depth[i] && depth[c] - depth[i] + 1 <= k) {
                    cout << 2 << "\n";
                    cout << depth[c] - depth[i] + 1 << "\n";
                    while (c != i) {
                        cout << c + 1 << " ";
                        c = par[c];
                    }
                    cout << i + 1 << "\n";
                    exit(0);
                }
            }
        }
    }
}
vector<int> sol;

void dfs2(int c, int p, int m) {
    if (depth[c] % 2 == m) {
        sol.push_back(c + 1);
        if (int(sol.size()) == (k + 1) / 2) {
            cout << 1 << "\n";
            for (auto &i : sol) {
                cout << i << " ";
            }
            cout << "\n";
            exit(0);
        }
    }
    for (auto &i : adj_dfs[c]) {
        if (i != p) {
            dfs2(i, c, m);
        }
    }
}

int main() {
    setIO("1");

    int n, m;
    cin >> n >> m >> k;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(0, -1, 0);
    dfs2(0, -1, 0);
    sol.clear();
    dfs2(0, -1, 1);
    cout << "WTMOO :angery:"
         << "\n";
    return 0;
}
