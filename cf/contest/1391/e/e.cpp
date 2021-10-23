/* Author: izhang05
 * Time: 10-07-2021 16:21:54
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 5e5;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
vector<int> adj[maxn];
bool vis[maxn], found = false;
int n;
vector<int> path;
vector<vector<int>> nodes;
void dfs(int c, int p, int d) {
    vis[c] = true;
    path.push_back(c);
    if (2 * (d + 1) >= n) {
        found = true;
        return;
    }
    if (d >= (int) nodes.size()) {
        nodes.push_back(vector<int>{c});
    } else {
        nodes[d].push_back(c);
    }
    for (auto &i : adj[c]) {
        if (!vis[i]) {
            dfs(i, c, d + 1);
            if (found) {
                return;
            }
        }
    }
    path.pop_back();
}

void solve() {
    int m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        adj[i].clear();
        vis[i] = false;
    }
    found = false;
    path.clear();
    nodes.clear();
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(0, -1, 0);
    if (found) {
        cout << "PATH\n";
        cout << path.size() << "\n";
        for (auto &i : path) {
            cout << i + 1 << " ";
        }
        cout << "\n";
    } else {
        cout << "PAIRING\n";
        int pairs = (((n + 1) / 2) + 1) / 2;
        cout << pairs << "\n";
        int cnt = 0;
        for (auto &i : nodes) {
            for (int j = 0; j + 1 < (int) i.size(); j += 2) {
                cout << i[j] + 1 << " " << i[j + 1] + 1 << "\n";
                if (++cnt == pairs) {
                    break;
                }
            }
            if (cnt == pairs) {
                break;
            }
        }
    }
}

int main() {
    setIO("1");

    int test_case_number = 1;
    cin >> test_case_number;
    while (test_case_number--) {
        solve();
    }
    return 0;
}
