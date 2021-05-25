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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 2e5 + 5;
vector<int> adj[maxn];
vector<vector<int>> sol;

int depth[maxn]; // also used as a visited array

bool dfs(int c, int p, int d) {
    depth[c] = d;
    vector<int> nodes;
    for (auto &i : adj[c]) {
        if (i != p) {
            if (!depth[i]) {
                if (dfs(i, c, d + 1)) {
                    nodes.push_back(i);
                }
            } else if (depth[i] > depth[c]) {
                nodes.push_back(i);
            }
            assert(depth[i] != depth[c]);
        }
    }
    if (nodes.size() % 2 == 0 || p == 0) {
        for (int i = 0; i < int(nodes.size()) / 2; ++i) {
            sol.push_back({nodes[2 * i], c, nodes[2 * i + 1]});
        }
        return true;
    } else {
        nodes.push_back(p);
        for (int i = 0; i < int(nodes.size()) / 2; ++i) {
            sol.push_back({nodes[2 * i], c, nodes[2 * i + 1]});
        }
        return false;
    }
}

int main() {
    setIO("b");

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 1; i <= n; ++i) {
        if (!depth[i]) {
            dfs(i, 0, 1);
        }
    }
    cout << sol.size() << "\n";
    for (auto &i : sol) {
        print(i);
    }
    return 0;
}
