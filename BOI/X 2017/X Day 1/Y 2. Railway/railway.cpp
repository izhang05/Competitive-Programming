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

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e5 + 5, maxs = 20;
vector<pair<int, int>> adj[maxn];
int up[maxn][maxs], depth[maxn], n, tin[maxn];

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

vector<int> sol;

int k;
unordered_map<int, int> diff[maxn];
int cnt[maxn];

void dfs2(int c, int p, int path) {
    for (auto &i : diff[c]) {
        if (i.second > 0) {
            ++cnt[c];
        }
    }
    for (auto &i : adj[c]) {
        if (i.first != p) {
            dfs2(i.first, c, i.second);
            if (diff[i.first].size() > diff[c].size()) {
                swap(diff[i.first], diff[c]);
                swap(cnt[i.first], cnt[c]);
            }
            for (auto &j : diff[i.first]) {
                diff[c][j.first] += j.second;
                int cur = diff[c][j.first];
                if (cur <= j.second && cur > 0) {
                    ++cnt[c];
                } else if (cur <= 0 && cur - j.second > 0) {
                    --cnt[c];
                }
            }
            diff[i.first].clear();
        }
    }
    if (cnt[c] >= k) {
        sol.push_back(path + 1);
    }
}

int main() {
    setIO("1");
    int m;
    cin >> n >> m >> k;
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].emplace_back(b, i);
        adj[b].emplace_back(a, i);
    }
    dfs();
    build();
    for (int i = 0; i < m; ++i) {
        int s;
        cin >> s;
        vector<int> a(s);
        for (int j = 0; j < s; ++j) {
            cin >> a[j];
            --a[j];
        }
        int l = a[0];
        for (int j = 0; j < s; ++j) {
            ++diff[a[j]][i];
            l = lca(l, a[j]);
        }
        diff[l][i] -= s;
    }
    dfs2(0, -1, -1);
    sort(sol.begin(), sol.end());
    cout << sol.size() << "\n";
    for (auto &i : sol) {
        cout << i << " ";
    }
    cout << "\n";
    return 0;
}
