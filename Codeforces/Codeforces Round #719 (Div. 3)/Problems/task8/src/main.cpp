#include <bits/stdc++.h>

using namespace std;

const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const long long inf = 1e18;
const int maxn = 2e3 + 5;
long long dist_orig[maxn][maxn], dist_dest[maxn][maxn];
int grid[maxn][maxn];

int n, m;

bool valid(int x, int y) {
    return x >= 0 && y >= 0 && x < n && y < m && grid[x][y] != -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    int w;
    cin >> n >> m >> w;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
            dist_orig[i][j] = inf;
            dist_dest[i][j] = inf;
        }
    }
    dist_orig[0][0] = 0;
    queue<pair<int, int>> q;
    q.push({0, 0});
    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = cur.first + dx[i], ny = cur.second + dy[i];
            if (valid(nx, ny)) {
                if (dist_orig[cur.first][cur.second] + w < dist_orig[nx][ny]) {
                    dist_orig[nx][ny] = dist_orig[cur.first][cur.second] + w;
                    q.push({nx, ny});
                }
            }
        }
    }
    long long best_orig = inf;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] > 0) {
                best_orig = min(best_orig, dist_orig[i][j] + grid[i][j]);
            }
        }
    }
    dist_dest[n - 1][m - 1] = 0;
    q.push({n - 1, m - 1});
    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = cur.first + dx[i], ny = cur.second + dy[i];
            if (valid(nx, ny)) {
                if (dist_dest[cur.first][cur.second] + w < dist_dest[nx][ny]) {
                    dist_dest[nx][ny] = dist_dest[cur.first][cur.second] + w;
                    q.push({nx, ny});
                }
            }
        }
    }
    long long best_dest = inf;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] > 0) {
                best_dest = min(best_dest, dist_dest[i][j] + grid[i][j]);
            }
        }
    }
    long long sol = min(dist_orig[n - 1][m - 1], best_orig + best_dest);
    cout << (sol == inf ? -1 : sol) << "\n";
    return 0;
}
