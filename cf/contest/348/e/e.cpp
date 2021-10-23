/* Author: izhang05
 * Time: 10-18-2021 14:26:55
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e5 + 5, maxs = 20;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
vector<pair<int, int>> adj[maxn];

pair<int, int> down[maxn], up_dp[maxn]; // pair<dist, split node>
bool pilgrim[maxn];
int val[maxn], par[maxn];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> mx[maxn];
pair<int, int> sol;

int up[maxn][maxs], depth[maxn], n;

int jmp(int x, int d) {
    for (int i = 0; i < maxs; i++) {
        if ((d >> i) & 1) {
            x = up[x][i];
        }
    }
    return x;
}

int lca(int x, int y) {
    if (depth[x] < depth[y]) {
        swap(x, y);
    }
    x = jmp(x, depth[x] - depth[y]);
    if (x == y) {
        return x;
    }
    for (int i = maxs - 1; i >= 0; --i) {
        int new_x = up[x][i], new_y = up[y][i];
        if (new_x != new_y) {
            x = new_x, y = new_y;
        }
    }
    return up[x][0];
}

int dist(int x, int y) {
    int l = lca(x, y);
    return depth[x] - depth[l] + depth[y] - depth[l];
}

void dfs(int c = 0, int p = -1, int d = 0) {
    up[c][0] = p;
    depth[c] = d;
    for (auto &i : adj[c]) {
        if (i.first != p) {
            dfs(i.first, c, d + 1);
        }
    }
}

void build() {
    for (int i = 1; i < maxs; ++i) {
        for (int j = 0; j < n; ++j) {
            if (up[j][i - 1] == -1) {
                up[j][i] = -1;
            } else {
                up[j][i] = up[up[j][i - 1]][i - 1];
            }
        }
    }
}

void dfs1(int c, int p) {
    par[c] = p;
    if (pilgrim[c]) {
        down[c] = {0, c};
        mx[c].push({0, c});
    } else {
        down[c] = {-inf, -1};
    }
    for (auto &i : adj[c]) {
        if (i.first != p) {
            dfs1(i.first, c);
            if (down[i.first].first == -inf) {
                continue;
            }
            mx[c].push({down[i.first].first + i.second, down[i.first].second});
            if (int(mx[c].size()) > 3) {
                mx[c].pop();
            }
            if (down[i.first].first + i.second > down[c].first) {
                down[c] = down[i.first];
                down[c].first += i.second;
            } else if (down[i.first].first + i.second == down[c].first) {
                down[c].second = c;
            }
        }
    }
}

void dfs2(int c, int p, int len) {
    if (p != -1) {
        up_dp[c] = {up_dp[p].first + len, up_dp[p].second};
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> cur_mx = mx[p];
        while (!cur_mx.empty()) {
            pair<int, int> cur = cur_mx.top();
            cur_mx.pop();
            if (cur == make_pair(down[c].first + len, down[c].second)) {
                continue;
            }
            if (cur.first + len > up_dp[c].first) {
                up_dp[c] = cur;
                up_dp[c].first += len;
            } else if (cur.first + len == up_dp[c].first) {
                up_dp[c].second = p;
            }
        }
    }
    if (pilgrim[c]) {
        if (up_dp[c].first > down[c].first) {
            ++val[c], ++val[up_dp[c].second];
            int l = lca(c, up_dp[c].second);
            --val[l];
            if (l) {
                --val[par[l]];
            }
        } else if (down[c].first > up_dp[c].first) {
            ++val[down[c].second];
            --val[c];
        }
    }
    for (auto &i : adj[c]) {
        if (i.first != p) {
            dfs2(i.first, c, i.second);
        }
    }
}

void dfs3(int c, int p) {
    for (auto &i : adj[c]) {
        if (i.first != p) {
            dfs3(i.first, c);
            val[c] += val[i.first];
        }
    }
    if (!pilgrim[c]) {
        if (val[c] > sol.first) {
            sol = {val[c], 1};
        } else if (val[c] == sol.first) {
            ++sol.second;
        }
    }
}

void solve() {
    int m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a;
        cin >> a;
        --a;
        pilgrim[a] = true;
    }
    for (int i = 0; i < n - 1; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        --a, --b;
        adj[a].emplace_back(b, c);
        adj[b].emplace_back(a, c);
    }
    up_dp[0] = {-inf, -1};
    dfs(), build();
    dfs1(0, -1), dfs2(0, -1, 0), dfs3(0, -1);
    cout << sol.first << " " << sol.second << "\n";
#ifdef DEBUG
    for (int i = 0; i < n; ++i) {
        if (pilgrim[i]) {
            cout << i << ": " << down[i].first << " " << down[i].second << "\n";
        }
    }
    for (int i = 0; i < n; ++i) {
        if (pilgrim[i]) {
            cout << i << ": " << up_dp[i].first << " " << up_dp[i].second << "\n";
        }
    }
#endif
}

int main() {
    setIO("3");

    int test_case_number = 1;
    while (test_case_number--) {
        solve();
    }
    return 0;
}
