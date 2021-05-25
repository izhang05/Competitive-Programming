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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e5 + 5;

vector<int> adj[maxn];
vector<pair<int, int>> sol;
int depth[maxn], dp[maxn];
bool pos = true;

void dfs(int c, int p, int d) {
    depth[c] = d;
    for (auto &i : adj[c]) {
        if (i != p) {
            if (!depth[i]) {
                sol.emplace_back(c, i);
                dfs(i, c, d + 1);
                dp[c] += dp[i];
            } else if (depth[i] < depth[c]) {
                ++dp[c];
                sol.emplace_back(c, i);
            } else if (depth[i] > depth[c]) {
                --dp[c];
            }
        }
    }
    if (c != 1 && !dp[c]) {
        pos = false;
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
    dfs(1, 0, 1);
    if (pos) {
        for (auto &i : sol) {
            cout << i.first << " " << i.second << "\n";
        }
    } else {
        cout << 0 << "\n";
    }
    return 0;
}
