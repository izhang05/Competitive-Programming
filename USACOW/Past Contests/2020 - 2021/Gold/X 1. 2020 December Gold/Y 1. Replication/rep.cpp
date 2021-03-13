#include <bits/stdc++.h>

using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
    freopen((s + "1.out").c_str(), "w", stderr);
#endif
}
const long long dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
//#define DEBUG
const long long maxn = 1e3 + 5;
long long rock_dist[maxn][maxn];
bool center[maxn][maxn], vis[maxn][maxn];
char grid[maxn][maxn];

int main() {
    setIO("2");
    long long n, d;
    cin >> n >> d;
    queue<pair<long long, pair<long long, long long>>> start, rocks;
    for (long long i = 0; i < n; ++i) {
        for (long long j = 0; j < n; ++j) {
            cin >> grid[i][j];
            if (grid[i][j] == 'S') {
                center[i][j] = true;
                start.push({0, {i, j}});
                grid[i][j] = '.';
            }
            if (grid[i][j] == '#') {
                rocks.push({0, {i, j}});
            }
        }
    }
    while (!rocks.empty()) {
        long long dist = rocks.front().first;
        pair<long long, long long> cur = rocks.front().second;
        rocks.pop();
        for (long long i = 0; i < 4; ++i) {
            long long nx = cur.first + dx[i], ny = cur.second + dy[i];
            if (nx >= 0 && ny >= 0 && !rock_dist[nx][ny] && grid[nx][ny] == '.') {
                rocks.push({rock_dist[nx][ny] = dist + 1, {nx, ny}});
            }
        }
    }
#ifdef DEBUG
    cout << "rock_dist: "
         << "\n";
    for (long long i = 0; i < n; ++i) {
        for (long long j = 0; j < n; ++j) {
            cout << rock_dist[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
#endif
    while (!start.empty()) {
        long long t = start.front().first;
        pair<long long, long long> cur = start.front().second;
        start.pop();
        for (long long i = 0; i < 4; ++i) {
            long long nx = cur.first + dx[i], ny = cur.second + dy[i];
            if (grid[nx][ny] == '.' && !center[nx][ny] && t < d * rock_dist[cur.first][cur.second] && t < d * rock_dist[nx][ny]) {
                center[nx][ny] = true;
                start.push({t + 1, {nx, ny}});
            }
        }
    }
#ifdef DEBUG
    cout << "center: "
         << "\n";
    for (long long i = 0; i < n; ++i) {
        for (long long j = 0; j < n; ++j) {
            cout << center[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
#endif
    priority_queue<pair<long long, pair<long long, long long>>> q;
    for (long long i = 0; i < n; ++i) {
        for (long long j = 0; j < n; ++j) {
            if (center[i][j]) {
                vis[i][j] = true;
                q.push({rock_dist[i][j] - 1, {i, j}});
            }
        }
    }
    while (!q.empty()) {
        long long remain = q.top().first;
        pair<long long, long long> cur = q.top().second;
        q.pop();
        if (remain == 0) {
            continue;
        }
        for (long long i = 0; i < 4; ++i) {
            long long nx = cur.first + dx[i], ny = cur.second + dy[i];
            if (nx >= 0 && ny >= 0 && grid[nx][ny] == '.' && !vis[nx][ny]) {
                vis[nx][ny] = true;
                q.push({remain - 1, {nx, ny}});
            }
        }
    }
#ifdef DEBUG
    cout << "vis: "
         << "\n";
    for (long long i = 0; i < n; ++i) {
        for (long long j = 0; j < n; ++j) {
            cout << vis[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
#endif
    long long sol = 0;
    for (long long i = 0; i < n; ++i) {
        for (long long j = 0; j < n; ++j) {
            sol += vis[i][j];
        }
    }
    cout << sol << "\n";
    return 0;
}
