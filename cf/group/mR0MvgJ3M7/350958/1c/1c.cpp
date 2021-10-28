/* Author: izhang05
 * Time: 10-27-2021 09:33:10
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e3 + 5;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
vector<pair<int, int>> adj[maxn];
int dist[maxn][maxn];

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    memset(dist, 0x3f, sizeof(dist));
    vector<pair<int, int>> edges(m);
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        --a, --b;
        adj[a].emplace_back(b, c);
        adj[b].emplace_back(a, c);
        edges[i] = {a, b};
    }
    for (int i = 0; i < n; ++i) {
        dist[i][i] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
        q.push({0, i});
        while (!q.empty()) {
            pair<int, int> cur = q.top();
            q.pop();
            for (auto &j : adj[cur.second]) {
                if (dist[i][j.first] > cur.first + j.second) {
                    q.push({dist[i][j.first] = cur.first + j.second, j.first});
                }
            }
        }
    }
    int sol = 0;
    vector<pair<int, int>> paths(k);
    for (int i = 0; i < k; ++i) {
        cin >> paths[i].first >> paths[i].second;
        --paths[i].first, --paths[i].second;
        sol += dist[paths[i].first][paths[i].second];
    }
    for (auto &i : edges) {
        int cur = 0;
        for (auto &j : paths) {
            cur += min({dist[j.first][j.second], dist[j.first][i.first] + dist[i.second][j.second], dist[j.first][i.second] + dist[i.first][j.second]});
        }
        sol = min(sol, cur);
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
