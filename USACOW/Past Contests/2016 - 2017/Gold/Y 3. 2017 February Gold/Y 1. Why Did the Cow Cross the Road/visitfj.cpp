/*
ID: izhang01
TASK: visitfj
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("visitfj.in", "r", stdin);
    freopen("visitfj.out", "w", stdout);
}

const int inf = 1e9, maxn = 100;

int grid[maxn][maxn], dist[maxn][maxn][3];
int dx[4]{0, 0, 1, -1}, dy[4]{1, -1, 0, 0};

int n, t;

bool valid(pair<int, int> x) {
    return x.first >= 0 && x.first < n && x.second >= 0 && x.second < n;
}

int main() {
    setIO();
    cin >> n >> t;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
            for (int k = 0; k < 3; ++k) {
                dist[i][j][k] = inf;
            }
        }
    }
    dist[0][0][0] = 0;
    priority_queue<pair<int, pair<pair<int, int>, int> > > q;
    q.push(make_pair(0, make_pair(make_pair(0, 0), 0)));
    while (!q.empty()) {
        int d = -q.top().first;
        pair<int, int> pos = q.top().second.first;
        int state = q.top().second.second;
        q.pop();
        if (dist[pos.first][pos.second][state] == d) {
            for (int i = 0; i < 4; ++i) {
                pair<int, int> next = make_pair(pos.first + dx[i], pos.second + dy[i]);
                if (valid(next)) {
                    if (state != 2) {
                        if (dist[next.first][next.second][state + 1] > d + t) {
                            dist[next.first][next.second][state + 1] = d + t;
                            q.push(make_pair(-dist[next.first][next.second][state + 1], make_pair(next, state + 1)));
                        }
                    } else {
                        if (dist[next.first][next.second][0] > d + t + grid[next.first][next.second]) {
                            dist[next.first][next.second][0] = d + t + grid[next.first][next.second];
                            q.push(make_pair(-dist[next.first][next.second][0], make_pair(next, 0)));
                        }
                    }
                }
            }
        }
    }
    cout << min({dist[n - 1][n - 1][0], dist[n - 1][n - 1][1], dist[n - 1][n - 1][2]}) << "\n";
    return 0;
}
