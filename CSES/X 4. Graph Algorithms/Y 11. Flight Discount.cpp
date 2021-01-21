#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    //freopen("solution.out", "w", stdout);
    freopen("1.in", "r", stdin);
#endif
}

const int maxn = 1e5;
long long dist[maxn][2];
vector<pair<int, int> > adj[maxn];

int main() {
    setIO();
    int n, m;
    cin >> n >> m;
    int a, b, c;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> c;
        --a, --b;
        adj[a].emplace_back(b, c);
    }
    for (int i = 0; i < n; ++i) {
        dist[i][0] = 1e18;
        dist[i][1] = 1e18;
    }
    priority_queue<pair<long long, pair<int, int> >, vector<pair<long long, pair<int, int> > >, greater<> > q;
    q.push(make_pair(0, make_pair(0, 0)));
    dist[0][0] = 0;
    while (!q.empty()) {
        pair<long long, pair<int, int> > cur = q.top();
        q.pop();
        if (dist[cur.second.first][cur.second.second] == cur.first) {
            for (pair<int, int> i : adj[cur.second.first]) {
                if (cur.second.second == 0) {
                    if (cur.first + i.second < dist[i.first][0]) {
                        dist[i.first][0] = cur.first + i.second;
                        q.push(make_pair(cur.first + i.second, make_pair(i.first, 0)));
                    }
                    if (cur.first + i.second / 2 < dist[i.first][1]) {
                        dist[i.first][1] = cur.first + i.second / 2;
                        q.push(make_pair(cur.first + i.second / 2, make_pair(i.first, 1)));
                    }
                } else {
                    if (cur.first + i.second < dist[i.first][1]) {
                        dist[i.first][1] = cur.first + i.second;
                        q.push(make_pair(cur.first + i.second, make_pair(i.first, 1)));
                    }
                }
            }
        }
    }
    cout << min(dist[n - 1][0], dist[n - f1][1]) << "\n";
    return 0;
}
