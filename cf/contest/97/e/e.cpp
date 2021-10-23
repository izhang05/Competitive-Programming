/* Author: izhang05
 * Time: 10-08-2021 11:12:00
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e5 + 5;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
vector<int> adj[maxn];
bool vis[maxn];

void dfs(int c, int p, int d) {
    vis[c] = true;
    for (auto &i : adj[c]) {
        if (i != p) {
            if (!vis[i]) {
                dfs(i, c, d + 1);
            } else {
                vis[c] = true;
            }
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        a[adj].push_back(b);
        b[adj].push_back(a);
    }
    int q;
    cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;
        --a, --b;
    }
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        solve();
    }
    return 0;
}
