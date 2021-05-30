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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 2e5 + 5;

vector<int> adj[maxn];
int leaf[maxn];
vector<pair<int, int>> rem, add, disconnected;

bool dfs(int c, int p) {
    vector<int> nodes;
    bool l = true;
    for (auto &i : adj[c]) {
        if (i != p) {
            if (dfs(i, c)) {
                l = false;
                nodes.push_back(i);
            }
        }
    }
    if (p != -1) {
        nodes.push_back(p);
    }
    bool ret = true;
    for (int i = 2; i < (int) nodes.size(); ++i) {
        if (nodes[i] != p) {
            rem.emplace_back(c + 1, nodes[i] + 1);
            add.emplace_back(leaf[nodes[0]] + 1, nodes[i] + 1);
#ifdef DEBUG
            cout << c << " " << nodes[0] << " " << nodes[i] << " " << leaf[nodes[0]] << "\n";
#endif
            leaf[nodes[0]] = leaf[nodes[i]];
        } else {
            ret = false;
            rem.emplace_back(c + 1, nodes[i] + 1);
            disconnected.emplace_back(leaf[nodes[0]] + 1, leaf[nodes[1]] + 1);
        }
    }
    if (l) {
        leaf[c] = c;
    } else {
        leaf[c] = leaf[nodes[0]];
#ifdef DEBUG
        cout << c << " " << nodes[0] << " " << leaf[c] << "\n";
#endif
    }
    return ret;
}

int main() {
    setIO("c");

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            adj[i].clear();
        }
        for (int i = 0; i < n - 1; ++i) {
            int a, b;
            cin >> a >> b;
            --a, --b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        dfs(0, -1);
        disconnected.emplace_back(leaf[0] + 1, -1);
        for (int i = 0; i < (int) disconnected.size() - 1; ++i) {
            add.emplace_back(disconnected[i].second, disconnected[i + 1].first);
        }
        assert(rem.size() == add.size());
        cout << rem.size() << "\n";
        add.emplace_back(0, 0);
        for (int i = 0; i < int(rem.size()); ++i) {
            cout << rem[i].first << " " << rem[i].second << " " << add[i].first << " " << add[i].second << "\n";
        }
        rem.clear();
        add.clear();
        disconnected.clear();
    }
    return 0;
}
