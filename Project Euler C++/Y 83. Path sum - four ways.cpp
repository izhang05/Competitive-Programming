#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, n = 80, dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const long long INFL = 0x3f3f3f3f3f3f3f3f;
long long grid[n][n], dist[n][n];
vector<pair<pair<int, int>, long long>> adj[n][n];

bool valid(int x, int y) {
    return x >= 0 && y >= 0 && x < n && y < n;
}

int main() {
    freopen("Y 83.txt", "r", stdin);
    for (auto &i : grid) {
        for (auto &j : i) {
            cin >> j;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < 4; ++k) {
                int nx = i + dx[k], ny = j + dy[k];
                if (valid(nx, ny)) {
                    adj[i][j].push_back({{nx, ny}, grid[nx][ny]});
                    adj[nx][ny].push_back({{i, j}, grid[i][j]});
                }
            }
        }
    }
    memset(dist, 0x3f, sizeof(dist));
    priority_queue<pair<long long, pair<int, int>>, vector<pair<long long, pair<int, int>>>, greater<>> q;
    dist[0][0] = grid[0][0];
    q.push({grid[0][0], {0, 0}});
    while (!q.empty()) {
        pair<long long, pair<int, int>> cur = q.top();
        q.pop();
        if (dist[cur.second.first][cur.second.second] != cur.first) {
            continue;
        }
        for (auto &i : adj[cur.second.first][cur.second.second]) {
            if (cur.first + i.second < dist[i.first.first][i.first.second]) {
                q.push({dist[i.first.first][i.first.second] = cur.first + i.second, {i.first.first, i.first.second}});
            }
        }

    }
    cout << dist[n - 1][n - 1] << "\n";
    return 0;
}
