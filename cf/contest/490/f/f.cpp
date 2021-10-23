/* Author: izhang05
 * Time: 10-06-2021 17:30:51
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 6e3 + 5;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

int r[maxn];
vector<int> adj[maxn];

int sol = 0;
vector<int> dp;

void dfs(int c, int p) {
    int pos = lower_bound(dp.begin(), dp.end(), r[c]) - dp.begin();
    pair<int, int> change;
    if (pos == (int) dp.size()) {
        dp.push_back(r[c]);
        change.first = -1;
    } else {
        change = {pos, dp[pos]};
        dp[pos] = r[c];
    }
    sol = max(sol, (int) dp.size());
    for (auto &i : adj[c]) {
        if (i != p) {
            dfs(i, c);
        }
    }
    if (change.first == -1) {
        dp.pop_back();
    } else {
        dp[change.first] = change.second;
    }
}

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> r[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 0; i < n; ++i) {
        dfs(i, -1);
    }
    cout << sol << "\n";
}

int main() {
    setIO("1");

    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
