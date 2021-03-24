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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e3 + 5;
int dist[maxn][maxn][4], n, m;
char grid[maxn][maxn];
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

bool valid(int x, int y) {
    return x >= 0 && y >= 0 && x < n && y < m && grid[x][y] != '*';
}

int main() {
    setIO("1");
    cin >> n >> m;
    memset(dist, 0x3f, sizeof(dist));
    pair<int, int> dest;
    queue<pair<pair<int, int>, int>> q;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
            if (grid[i][j] == 'S') {
                dest = {i, j};
            } else if (grid[i][j] == 'T') {
                dist[i][j][0] = dist[i][j][1] = dist[i][j][2] = dist[i][j][3] = 0;
                q.push({{i, j}, 0});
                q.push({{i, j}, 1});
                q.push({{i, j}, 2});
                q.push({{i, j}, 3});
            }
        }
    }
    while (!q.empty()) {
        pair<pair<int, int>, int> cur = q.front();
        q.pop();
        int cur_dist = dist[cur.first.first][cur.first.second][cur.second];
        for (int i = 0; i < 4; ++i) {
            int nx = cur.first.first + dx[i], ny = cur.first.second + dy[i];
            if (valid(nx, ny)) {
                if (i == cur.second) {
                    if (dist[nx][ny][cur.second] > cur_dist) {
                        dist[nx][ny][cur.second] = cur_dist;
                        q.push({{nx, ny}, cur.second});
                    }
                } else if (dist[nx][ny][i] > cur_dist + 1) {
                    dist[nx][ny][i] = cur_dist + 1;
                    q.push({{nx, ny}, i});
                }
            }
        }
    }
    int sol = inf;
    for (int i = 0; i < 4; ++i) {
        sol = min(sol, dist[dest.first][dest.second][i]);
    }
#ifdef DEBUG
    cout << sol << "\n";
#endif
    if (sol <= 2) {
        cout << "YES"
             << "\n";
    } else {
        cout << "NO"
             << "\n";
    }
    return 0;
}
