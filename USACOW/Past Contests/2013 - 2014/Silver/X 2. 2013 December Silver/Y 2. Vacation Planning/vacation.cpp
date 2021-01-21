/*
ID: izhang01
TASK: vacation
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("vacation.in", "r", stdin);
    freopen("vacation.out", "w", stdout);
}

const int maxn = 200;
const long long inf = 1e18;
vector<pair<int, int>> adj[maxn];
long long dist[maxn][maxn];


int main() {
    setIO();
    int n, m, k, q;
    cin >> n >> m >> k >> q;
    int a, b, c;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> c;
        --a, --b;
        adj[a].emplace_back(b, c);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            dist[i][j] = inf;
        }
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> qu; // first = dist, second = ind
        qu.push(make_pair(0, i));
        dist[i][i] = 0;
        while (!qu.empty()) {
            pair<long long, int> cur = qu.top();
            qu.pop();
            if (cur.first != dist[i][cur.second]) {
                continue;
            }
            for (pair<int, int> j : adj[cur.second]) {
                if (cur.first + j.second < dist[i][j.first]) {
                    qu.push(make_pair(dist[i][j.first] = cur.first + j.second, j.first));
                }
            }
        }
    }
    pair<int, long long> sol;
    for (int i = 0; i < q; ++i) {
        cin >> a >> b;
        --a, --b;
        long long cur = inf;
        for (int j = 0; j < k; ++j) {
            if (dist[a][j] == -inf || dist[j][b] == -inf) {
                continue;
            }
            cur = min(cur, dist[a][j] + dist[j][b]);
        }
        if (a < k || b < k) {
            cur = min(cur, dist[a][b]);
        }
        if (cur != inf) {
            ++sol.first;
            sol.second += cur;
        }
    }
    cout << sol.first << "\n";
    cout << sol.second << "\n";
    return 0;
}
