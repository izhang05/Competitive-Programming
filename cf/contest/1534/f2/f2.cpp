/* Author: izhang05
 * Time: 07-16-2021 14:54:16
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

int ind(int x, int y) {
    return x * m + y;
}

int col(int ind) {
    return ind % m;
}

int row(int ind) {
    return ind / m;
}

pair<int, int> loc(int ind) {
    return {row(ind), col(ind)};
}

bool valid(int x, int y) {
    return x >= 0 && y >= 0 && x < n && y < m;
}

vector<int> graph[maxn];
int in_deg[maxn], goal[maxn];
vector<int> s;
pair<int, int> dp[maxn];

pair<int, int> solve(int c) {
    if (vis[c]) {
        return dp[c];
    }
    vis[c] = true;
    for (auto &i : graph[c]) {
        pair<int, int> next = solve(i);
        dp[c] = {min(dp[c].first, next.first), max(dp[c].second, next.second)};
    }
    return dp[c];
}

int main() {
    setIO("1");
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
    set<int> special;
    for (int j = 0; j < m; ++j) {
        int pre = -1, cnt = 0;
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
                ++cnt;
                if (cnt == a[j]) {
                    special.insert(ind(i, j));
                }
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
                graph[comp[i]].push_back(comp[j]);
                ++in_deg[comp[j]];
            }
        }
    }
    memset(goal, -1, sizeof(goal));
    memset(vis, false, sizeof(vis));
    set<int> to_erase;
    queue<int> q;
    for (auto &i : special) {
        if (goal[comp[i]] == -1) {
            q.push(comp[i]);
            vis[comp[i]] = true;
            goal[comp[i]] = i;
        } else {
            to_erase.insert(i);
        }
    }
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (auto &i : graph[cur]) {
            if (goal[comp[i]] != -1) {
                to_erase.insert(goal[comp[i]]);
            }
            if (!vis[i]) {
                vis[i] = true;
                q.push(i);
            }
        }
    }
    for (auto &i : to_erase) {
        special.erase(i);
    }
#ifdef DEBUG
    for (auto &i : special) {
        cout << i << "\n";
    }
#endif
    s = vector<int>(special.begin(), special.end());
    sort(s.begin(), s.end(), [](int left, int right) {
        return col(left) < col(right);
    });
#ifdef DEBUG
    cout << "sorted:"
         << "\n";
    for (auto &i : s) {
        cout << i << "\n";
    }
#endif
    memset(vis, false, sizeof(vis));
    for (auto &i : components) {
        dp[i] = {inf, -inf};
    }
    for (int i = 0; i < int(s.size()); ++i) {
        dp[comp[s[i]]] = {i, i};
    }
    vector<pair<int, int>> seg;
    for (auto &i : components) {
        pair<int, int> cur = solve(i);
        if (cur.first != inf) {
            seg.push_back(cur);
        }
    }
    sort(seg.begin(), seg.end());
#ifdef DEBUG
    for (auto &i : seg) {
        cout << i.first << " " << i.second << "\n";
    }
#endif
    int sol = 0, cur_right = -1, mx_right = -1, j = 0;
    for (int i = 0; i < int(s.size()); ++i) {
        while (j < int(seg.size()) && seg[j].first == i) {
            mx_right = max(mx_right, seg[j].second);
            ++j;
        }
        if (i > cur_right) {
            ++sol;
            cur_right = mx_right;
        }
    }
    cout << sol << "\n";
    return 0;
}
