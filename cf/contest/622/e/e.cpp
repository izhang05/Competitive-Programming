/* Author: izhang05
 * Time: 11-03-2021 18:36:25
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
set<int> vals[maxn];
map<int, int> cur;
void dfs(int c, int p, int d) {
    bool leaf = true;
    for (auto &i : adj[c]) {
        if (i != p) {
            leaf = false;
            dfs(i, c, d + 1);
        }
    }
    if (leaf) {
        ++cur[d];
    }
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
    int sol = 0;
    for (auto &i : adj[0]) {
        cur.clear();
        dfs(i, 0, 0);
        for (auto &j : cur) {
            if (j.second > 1) {
                cur[j.first + 1] += j.second - 1;
            }
            sol = max(sol, j.first + 1);
        }
    }
    cout << sol << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        solve();
    }
    return 0;
}
