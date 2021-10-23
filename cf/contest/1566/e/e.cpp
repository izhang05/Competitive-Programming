/* Author: izhang05
 * Time: 09-14-2021 23:47:15
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 2e5 + 5;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
vector<int> adj[maxn];
int num_child[maxn], num_buds, leaves, deg[maxn];

bool dfs(int c, int p) {
    bool bud = true;
    for (auto &i : adj[c]) {
        if (i != p) {
            if (dfs(i, c)) {
                --num_child[c];
            } else if (num_child[i]) {
                bud = false;
            }
        }
    }
    if (!num_child[c] && c) {
        ++leaves;
    }
    if (bud && num_child[c]) {
        if (c) {
            ++num_buds;
        }
        return true;
    } else {
        return false;
    }
}

void solve() {
    int n;
    cin >> n;
    num_buds = 0, leaves = 0;
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
    for (int i = 0; i < n; ++i) {
        num_child[i] = adj[i].size() - (i != 0);
    }
    dfs(0, -1);
    cout << leaves - num_buds + (num_child[0] == 0) << "\n";
}

int main() {
    setIO("1");

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
