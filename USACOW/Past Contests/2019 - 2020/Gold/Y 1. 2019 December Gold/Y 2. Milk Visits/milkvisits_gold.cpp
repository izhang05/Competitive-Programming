/*
ID: izhang01
TASK: milkvisits
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    freopen("milkvisits.in", "r", stdin);
    freopen("milkvisits.out", "w", stdout);
}
//#define DEBUG
const int maxn = 1e5 + 5, maxs = 17;
int t[maxn], depth[maxn], up[maxn][maxs];
bool sol[maxn];
vector<int> adj[maxn];
vector<pair<pair<int, int>, int>> endp[maxn];
stack<int> last[maxn];

struct query {
    int x, y, type;
};

int jmp(int x, int d) {
    for (int i = 0; i < maxs; i++) {
        if ((d >> i) & 1) {
            x = up[x][i];
        }
    }
    return x ?: -1; // modification to return -1 if not found
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
void dfs1(int c, int p, int d) {
    up[c][0] = p;
    depth[c] = d;
    for (int i : adj[c]) {
        if (i != p) {
            dfs1(i, c, d + 1);
        }
    }
}

void dfs2(int c, int p) {
    last[t[c]].push(c);
    for (pair<pair<int, int>, int> i : endp[c]) {
        int y = i.first.first, type = i.first.second;
        if (!last[type].empty()) {
            int l = lca(c, y);
#ifdef DEBUG
            cout << i.second << " " << c << " " << y << " " << type << " " << l << " " << depth[l] << " " << last[type].top() << " " << depth[last[type].top()] << "\n";
#endif
            if (depth[last[type].top()] >= depth[l]) {
                sol[i.second] = true;
            }
        }
    }
    for (int i : adj[c]) {
        if (i != p) {
            dfs2(i, c);
        }
    }
    last[t[c]].pop();
}

int main() {
    setIO();
#ifdef LOCAL
    auto start_time = chrono::high_resolution_clock::now();
#endif
    int n, m;
    cin >> n >> m;
    for (int i = 1; i < n + 1; ++i) {
        cin >> t[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs1(1, 0, 0);
    for (int i = 1; i < maxs; ++i) {
        for (int j = 1; j < n + 1; ++j) {
            up[j][i] = up[up[j][i - 1]][i - 1];
        }
    }
    vector<query> q(m);
    for (int i = 0; i < m; ++i) {
        int x, y, type;
        cin >> x >> y >> type;
        q[i] = query{x, y, type};
        endp[x].emplace_back(make_pair(y, type), i);
    }
    dfs2(1, 0);
    for (int i = 1; i < n + 1; ++i) {
        endp[i].clear();
    }
    for (int i = 0; i < m; ++i) {
        endp[q[i].y].emplace_back(make_pair(q[i].x, q[i].type), i);
    }
#ifdef DEBUG
    for (int i = 0; i < m; ++i) {
        cout << sol[i];
    }
    cout << "\n";
#endif
    dfs2(1, 0);
    for (int i = 0; i < m; ++i) {
        cout << sol[i];
    }
    cout << "\n";

#ifdef LOCAL
    auto end_time = chrono::high_resolution_clock::now();
    cout << setprecision(6) << fixed;
    cout << "Execution time: " << chrono::duration_cast<chrono::duration<double>>(end_time - start_time).count() << " seconds" << endl;
#endif
    return 0;
}
