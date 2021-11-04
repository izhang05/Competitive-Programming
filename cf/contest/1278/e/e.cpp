/* Author: izhang05
 * Time: 11-03-2021 18:36:35
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 5e5 + 5;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
vector<int> adj[maxn];
pair<int, int> sol[maxn];

int dfs(int c, int p, int l, int r) {
    int chi = adj[c].size() - (c != 0);
    r += chi;
    sol[c] = {l, r};
    l = r;
    --l, ++r;
    for (auto &i : adj[c]) {
        if (i != p) {
            r = dfs(i, c, l, r);
            --l;
        }
    }
    return r;
}

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(0, -1, 1, 2);
    for (int i = 0; i < n; ++i) {
        cout << sol[i].first << " " << sol[i].second << "\n";
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
