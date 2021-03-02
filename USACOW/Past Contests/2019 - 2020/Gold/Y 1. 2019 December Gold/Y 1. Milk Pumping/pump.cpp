/*
ID: izhang01
TASK: pump
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("pump.in", "r", stdin);
    freopen("pump.out", "w", stdout);
}

const int maxn = 1000;
vector<vector<int> > adj[maxn]; // vector<index, cost, flow>
int dist[maxn];

int main() {
    setIO();
    int n, m;
    cin >> n >> m;
    double sol = 0;
    int a, b, c, d;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> c >> d;
        --a, --b;
        adj[a].push_back(vector<int>{b, c, d});
        adj[b].push_back(vector<int>{a, c, d});
    }
    for (int i = 1; i < 1001; ++i) {
        for (int j = 0; j < n; ++j) {
            dist[j] = 1e9;
        }
        dist[0] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
        q.push(make_pair(0, 0));
        while (!q.empty()) {
            pair<int, int> cur = q.top();
            q.pop();
            for (auto j : adj[cur.second]) {
                if (j[2] >= i && cur.first + j[1] < dist[j[0]]) {
                    dist[j[0]] = cur.first + j[1];
                    q.push(make_pair(dist[j[0]], j[0]));
                }
            }
        }
        if (dist[n - 1] != 1e9) {
            sol = max(sol, (double) i / (dist[n - 1]));
        }
    }
    cout << (int) (sol * 1e6) << "\n";
    return 0;
}
