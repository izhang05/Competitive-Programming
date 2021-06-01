#include <bits/stdc++.h>

using namespace std;

#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
    freopen((name + ".out").c_str(), "w", stderr);
#endif
}
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 2e5 + 5;

vector<int> adj[maxn];
int main() {
    setIO("c");
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> d(n, inf), dp(n, inf);
        for (int i = 0; i < n; ++i) {
            adj[i].clear();
        }
        for (int i = 0; i < m; ++i) {
            int a, b;
            cin >> a >> b;
            --a, --b;
            adj[a].push_back(b);
        }
        d[0] = 0;
        queue<int> q;
        q.push(0);
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (auto &i : adj[cur]) {
                if (d[i] > d[cur] + 1) {
                    q.push(i);
                    d[i] = d[cur] + 1;
                }
            }
        }
        vector<pair<int, int>> nodes(n);
        for (int i = 0; i < n; ++i) {
            nodes[i] = {d[i], i};
        }
        sort(nodes.begin(), nodes.end());
        reverse(nodes.begin(), nodes.end());
        for (int j = 0; j < n; ++j) {
            int cur = nodes[j].second;
            dp[cur] = d[cur];
            for (auto &i : adj[cur]) {
                if (d[i] > d[cur]) {
                    dp[cur] = min(dp[cur], dp[i]);
                } else {
                    dp[cur] = min(dp[cur], d[i]);
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            cout << dp[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
