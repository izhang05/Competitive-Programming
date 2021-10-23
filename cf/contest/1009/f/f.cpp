/* Author: izhang05
 * Time: 10-16-2021 15:55:00
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e6 + 5;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
vector<int> adj[maxn];
map<int, int> occ[maxn];
pair<int, int> max_d[maxn]; // pair<max depth array value, -index of max depth array value>
int sol[maxn];

void dfs(int c, int p, int d) {
    occ[c][d] = 1;
    max_d[c] = {1, -d};
    for (auto &i : adj[c]) {
        if (i != p) {
            dfs(i, c, d + 1);
            if (occ[i].size() > occ[c].size()) {
                swap(occ[c], occ[i]);
                swap(max_d[c], max_d[i]);
            }
            for (auto &j : occ[i]) {
                occ[c][j.first] += j.second;
                max_d[c] = max(max_d[c], {occ[c][j.first], -j.first});
            }
            occ[i].clear();
        }
    }
    sol[c] = -max_d[c].second - d;
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
    dfs(0, -1, 0);
    for (int i = 0; i < n; ++i) {
        cout << sol[i] << "\n";
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
