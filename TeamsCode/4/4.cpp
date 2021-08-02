#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
    freopen((name + ".out").c_str(), "w", stderr);
#endif
}

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e3 + 5;

int dist[maxn][maxn], n, m;
pair<int, int> dp[maxn][maxn];
char grid[maxn][maxn];
pair<int, int> nxt[maxn][maxn];
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

bool valid(int x, int y) {
    return x >= 0 && y >= 0 && x < n && y < m;
}

pair<int, int> get(int x, int y) {
    if (dp[x][y] != make_pair(-1, -1)) {
        return dp[x][y];
    }
    if (nxt[x][y] == make_pair(-1, -1)) {
        return dp[x][y] = {x, y};
    } else {
        return dp[x][y] = get(nxt[x][y].first, nxt[x][y].second);
    }

}

int main() {
    setIO("1");
    int k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
            dp[i][j] = nxt[i][j] = {-1, -1};
        }
    }

    for (int i = 0; i < k; ++i) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        --a, --b, --c, --d;
        nxt[a][b] = {c, d};
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            get(i, j);
        }
    }
    memset(dist, 0x3f, sizeof(dist));
    dist[0][0] = 0;
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> q;
    q.push({0, {0, 0}});
    while (!q.empty()) {
        pair<int, pair<int, int>> cur = q.top();
        q.pop();
        if (dist[cur.second.first][cur.second.second] != cur.first) {
            continue;
        }
        int cur_dist = cur.first;
        for (int i = 0; i < 4; ++i) {
            int nx = cur.second.first + dx[i], ny = cur.second.second + dy[i];
            pair<int, int> next = dp[cur.second.first][cur.second.second];
            if (cur_dist < dist[next.first][next.second]) {
                q.push({dist[next.first][next.second] = cur_dist, {next.first, next.second}});
            }
            if (valid(nx, ny) && grid[nx][ny] != '#') {
                if (cur_dist + 1 < dist[nx][ny]) {
                    q.push({dist[nx][ny] = cur_dist + 1, {nx, ny}});
                }
            }
        }
    }
    cout << dist[n - 1][m - 1] << "\n";
    return 0;
}
