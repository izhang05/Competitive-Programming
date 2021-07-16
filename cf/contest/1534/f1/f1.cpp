/* Author: izhang05
 * Time: 07-16-2021 13:54:14
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
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 4e5 + 5;
vector<vector<char>> grid;
int n, m;
int ind(int x, int y) {
    return x * m + y;
}

bool valid(int x, int y) {
    return x >= 0 && y >= 0 && x < n && y < m;
}

vector<int> adj[maxn], radj[maxn];
int comp[maxn];
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
    for (int i = 0; i < n * m; ++i) {
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
#ifdef DEBUG
    cout << "add: " << a << " " << b << "\n";
#endif
    adj[a].push_back(b);
    radj[b].push_back(a);
}

vector<int> graph[maxn];
int in_deg[maxn];

int main() {
    setIO("3");
    cin >> n >> m;
    grid.resize(n);
    for (auto &i : grid) {
        i.resize(m);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }
    vector<int> a(m);
    for (int i = 0; i < m; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] != '#') {
                continue;
            }
            for (int k = 0; k < 4; ++k) {
                int nx = i + dx[k], ny = j + dy[k];
                if (valid(nx, ny) && grid[nx][ny] == '#') {
                    ae(ind(i, j), ind(nx, ny));
                }
            }
        }
    }
    for (int j = 0; j < m; ++j) {
        int pre = -1;
        for (int i = n - 1; i >= 0; --i) {
            if (pre != -1) {
                if (j && grid[i][j - 1] == '#') {
                    ae(ind(i, j - 1), ind(pre, j));
                }
                if (j + 1 < m && grid[i][j + 1] == '#') {
                    ae(ind(i, j + 1), ind(pre, j));
                }
            }
            if (grid[i][j] == '#') {
                if (pre != -1) {
                    ae(ind(i, j), ind(pre, j));
                }
                pre = i;
            }
        }
    }
    gen();
    for (int i = 0; i < n * m; ++i) {
        for (auto &j : adj[i]) {
            if (comp[i] != comp[j]) {
                ++in_deg[comp[j]];
            }
        }
    }
    set<int> sol;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == '#' && in_deg[comp[ind(i, j)]] == 0) {
                sol.insert(comp[ind(i, j)]);
            }
        }
    }
    cout << sol.size() << "\n";
#ifdef DEBUG
    for (auto &i : sol) {
        cout << i << "\n";
    }
#endif
    return 0;
}
