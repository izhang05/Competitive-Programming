/* Author: izhang05
 * Time: 08-13-2021 12:26:09
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
pair<int, int> ret[maxn];
int no_ret[maxn];
int k;

void dfs1(int c, int p, int d) {
    ret[c] = {inf, 0};
    bool leaf = true;
    int max_add = 0;
    for (auto &i : adj[c]) {
        if (i != p) {
            leaf = false;
            dfs1(i, c, d + 1);
            if (ret[i].first - d <= k) {
                ret[c].second += ret[i].second;
                ret[c].first = min(ret[c].first, ret[i].first);
                max_add = max(max_add, no_ret[i] - ret[i].second);
            } else {
                max_add = max(max_add, no_ret[i]);
            }
        }
    }
    no_ret[c] = ret[c].second + max_add;
    if (leaf) {
        ret[c] = {d, 1};
        no_ret[c] = 1;
    }
}

void solve() {
    int n;
    cin >> n >> k;
    for (int i = 1; i < n; ++i) {
        int p;
        cin >> p;
        --p;
        adj[i].push_back(p);
        adj[p].push_back(i);
    }
    dfs1(0, -1, 0);
    cout << no_ret[0] << "\n";
}

int main() {
    setIO("1");

    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
