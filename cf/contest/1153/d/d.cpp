/* Author: izhang05
 * Time: 06-28-2021 23:03:49
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 3e5 + 5;
vector<int> adj[maxn];
bool t[maxn];
int leafs, dp[maxn];

void dfs(int c, int p) {
    bool leaf = true;
    if (t[c]) {
        dp[c] = inf;
    }
    for (auto &i : adj[c]) {
        if (i != p) {
            leaf = false;
            dfs(i, c);
            if (!t[c]) {
                dp[c] += dp[i];
            } else {
                dp[c] = min(dp[c], dp[i]);
            }
        }
    }
    if (leaf) {
        ++leafs;
        dp[c] = 1;
    }
}

int main() {
    setIO("1");

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
    }
    for (int i = 1; i < n; ++i) {
        int a;
        cin >> a;
        --a;
        adj[i].push_back(a);
        adj[a].push_back(i);
    }
    dfs(0, -1);
    cout << leafs + 1 - dp[0] << "\n";
    return 0;
}
