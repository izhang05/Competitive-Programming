#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    //freopen("solution.out", "w", stdout);
    freopen("1.in", "r", stdin);
#endif
}

const long long maxn = 1e5, mod = 1e9 + 7, inf = 1e18;
long long dist[maxn];
int min_dp[maxn], max_dp[maxn], routes[maxn];
vector<pair<int, int>> adj[maxn];

int main() {
    setIO();
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        dist[i] = inf;
    }
    dist[0] = 0;
    routes[0] = 1;
    int a, b, c;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> c;
        --a, --b;
        adj[a].emplace_back(b, c);
    }
    priority_queue<pair<long long, int> > q; // first = dist, second = index
    q.push(make_pair(0, 0));
    while (!q.empty()) {
        pair<long long, int> cur = q.top();
        q.pop();
        for (pair<int, int> i : adj[cur.second]) {
            if (-cur.first + i.second < dist[i.first]) {
                dist[i.first] = -cur.first + i.second;
                routes[i.first] = routes[cur.second];
                min_dp[i.first] = min_dp[cur.second] + 1;
                max_dp[i.first] = max_dp[cur.second] + 1;
                q.push(make_pair(-dist[i.first], i.first));
            } else if (-cur.first + i.second == dist[i.first]) {
                routes[i.first] += routes[cur.second];
                routes[i.first] %= mod;
                min_dp[i.first] = min(min_dp[i.first], min_dp[cur.second] + 1);
                max_dp[i.first] = max(max_dp[i.first], max_dp[cur.second] + 1);
            }
        }
    }
    cout << dist[n - 1] << " " << routes[n - 1] << " " << min_dp[n - 1] << " " << max_dp[n - 1] << "\n";
    return 0;
}
