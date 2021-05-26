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
template<class T>
void print(T a, string sep = " ", string end = "\n") {
    for (auto i : a) {
        cout << i << sep;
    }
    cout << end;
}
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e4 + 5;
vector<pair<int, int>> adj[maxn];
int depth[maxn], good[maxn], bad[maxn];
bool visited[maxn], color[maxn], pos = true;

set<int> cur_sol, sol;
vector<int> span, back;

void dfs(int c, int p, int d, int co) {
    depth[c] = d;
    color[c] = co;
    for (auto &i : adj[c]) {
        if (i.first != p) {
            if (!depth[i.first]) {
                dfs(i.first, c, d + 1, co ^ 1);
                good[c] += good[i.first];
                bad[c] += bad[i.first];
            } else if (depth[i.first] > depth[c]) {
                if (color[i.first] == color[c]) {
                    back.push_back(i.second);
                    --bad[c];
                } else {
                    --good[c];
                }
            } else {
                if (color[i.first] == color[c]) {
                    ++bad[c];
                } else {
                    ++good[c];
                }
            }
        }
    }
}

void dfs2(int c, int id) {
    visited[c] = true;
    for (auto &i : adj[c]) {
        if (!visited[i.first]) {
            dfs2(i.first, i.second);
        }
    }
    if (id) {
        if (bad[c] == (int) back.size() && !good[c]) {
            span.push_back(id);
        }
    }
}

void bipart(int c, int p, int co) {
    visited[c] = true;
    color[c] = co;
    for (auto &i : adj[c]) {
        if (i.first != p) {
#ifdef DEBUG
            cout << c << " " << i.first << " " << color[c] << " " << color[i.first] << "\n";
#endif
            if (!visited[i.first]) {
                cur_sol.insert(i.second);
                bipart(i.first, c, co ^ 1);
            } else {
                if (color[i.first] == color[c]) {
                    pos = false;
                } else {
                    cur_sol.insert(i.second);
                }
            }
        }
    }
}

int main() {
    setIO("b");

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].emplace_back(b, i + 1);
        adj[b].emplace_back(a, i + 1);
    }
    int b = 0;
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            bipart(i, 0, 0);
            if (!pos) {
                if (!b) {
                    b = i;
                } else {
                    cout << 0 << "\n";
                    return 0;
                }
            } else {
                for (auto &j : cur_sol) {
                    sol.insert(j);
                }
            }
            pos = true;
            cur_sol.clear();
        }
    }
#ifdef DEBUG
    cout << b << "\n";
#endif
    if (b) {
        memset(color, 0, sizeof(color));
        dfs(b, 0, 1, 0);
        memset(visited, 0, sizeof(visited));
        dfs2(b, 0);
        if (back.size() > 1) {
            back.clear();
        }
        sol.clear();
        for (auto &i : back) {
            sol.insert(i);
        }
        for (auto &i : span) {
            sol.insert(i);
        }
        cout << sol.size() << "\n";
        print(sol);
    } else {
        cout << sol.size() << "\n";
        print(sol);
    }
    return 0;
}
