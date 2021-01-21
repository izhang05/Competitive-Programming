/*
ID: izhang01
TASK: mroute
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("mroute.in", "r", stdin);
    freopen("mroute.out", "w", stdout);
}

const int maxn = 500;
int dist[maxn];
vector<array<int, 3>> adj[maxn];

int main() {
    setIO();
    int n, m, x, maxc;
    cin >> n >> m >> x;
    int sol = 1e9;
    int a, b, c, d;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> c >> d;
        --a, --b;
        adj[a].push_back(array<int, 3>{{b, c, d}});
        adj[b].push_back(array<int, 3>{{a, c, d}});
        maxc = max(maxc, d);
    }
    for (int i = 1; i < maxc + 1; ++i) {
        for (int j = 0; j < n; ++j) {
            dist[j] = 1e9;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.push(make_pair(0, 0));
        dist[0] = 0;
        while (!q.empty()) {
            pair<int, int> cur = q.top();
            q.pop();
            for (auto j : adj[cur.second]) {
                if (j[2] >= i && cur.first + j[1] < dist[j[0]]) {
                    q.push(make_pair(dist[j[0]] = cur.first + j[1], j[0]));
                }
            }
        }
        if (dist[n - 1] == 1e9) {
            break;
        }
        sol = min(sol, dist[n - 1] + x / i);
    }
    cout << sol << "\n";
    return 0;
}
