#include <bits/stdc++.h>

using namespace std;

mt19937 rng((uint32_t) chrono::steady_clock::now().time_since_epoch().count());
//#define DEBUG
void setIO(string name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
    freopen((name + ".out").c_str(), "w", stderr);
#endif
}
const int mod = 1e9 + 7, maxn = 1e5 + 5;
const long long inf = 1e18;
vector<pair<int, int>> adj[maxn];
long long dist[maxn];

int main() {
    setIO("b");
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        --a, --b;
        adj[a].emplace_back(b, c);
        adj[b].emplace_back(a, c);
    }
    for (int i = 0; i < n; ++i) {
        dist[i] = inf;
    }
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> q;
    for (int i = 0; i < k; ++i) {
        int a, b;
        cin >> a >> b;
        --a;
        q.push({b, a});
    }
    int sol = 0;
    dist[0] = 0;
    q.push({0, 0});
    while (!q.empty()) {
        int node = q.top().second;
        long long d = q.top().first;
        q.pop();
        if (dist[abs(node)] < d) {
            continue;
        }
        if (node > 0) {
            if (dist[node] == d) {
                continue;
            }
            dist[node] = d;
            ++sol;
        } else {
            node *= -1;
        }
        for (auto i : adj[node]) {
            long long nd = d + i.second;
            if (dist[i.first] > nd) {
                q.push({dist[i.first] = nd, -i.first});
            }
        }
    }
    cout << k - sol << "\n";
    return 0;
}
