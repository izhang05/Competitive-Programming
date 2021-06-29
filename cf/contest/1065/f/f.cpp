/* Author: izhang05
 * Time: 06-27-2021 12:26:50
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
vector<int> adj[maxn];
int n, k, sol, dp[maxn]; // dp[i] = maximum number of leafs j visited in subtree i with depth[j] - depth[i] >= k

unordered_map<int, int> dfs(int c, int p, int d) {
    unordered_map<int, int> cur;
    bool leaf = true;
    for (auto &i : adj[c]) {
        if (i != p) {
            leaf = false;
            unordered_map<int, int> u = dfs(i, c, d + 1);
            if (u.size() > cur.size()) {
                swap(u, cur);
            }
            for (auto &j : u) {
                cur[j.first] += j.second;
            }
            dp[c] = max(dp[c], dp[i]);
        }
    }
    if (leaf) {
        cur[d] = 1;
    }
    if (cur.find(d + k) != cur.end()) {
        dp[c] += cur[d + k];
    }
#ifdef DEBUG
    cout << c << " " << dp[c] << "\n";
    for (auto &i : cur) {
        cout << i.first << " " << i.second << "\n";
    }
    cout << "\n";
#endif
    if (c == 0) {
        sol = dp[c];
        for (auto &i : cur) {
            if (i.first - d < k) {
                sol += i.second;
            }
        }
    }
    return cur;
}

int main() {
    setIO("3");

    cin >> n >> k;
    for (int i = 0; i < n - 1; ++i) {
        int a;
        cin >> a;
        --a;
        adj[i + 1].push_back(a);
        adj[a].push_back(i + 1);
#ifdef DEBUG
        cout << i + 1 << " " << a << "\n";
#endif
    }
    dfs(0, -1, 0);
    cout << sol << "\n";
    return 0;
}
