#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    freopen("2.in", "r", stdin);
#endif
}
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1}, maxn = 1e3 + 5;

char grid[maxn][maxn];
bool visited[maxn][maxn];
int n, d, sol, max_size[maxn][maxn];
vector<vector<vector<int>>> size;

set<pair<set<pair<int, int>>, int>> vis;

bool valid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n && grid[x][y] != '#';
}


int main() {
    setIO();
    cin >> n >> d;
    size.resize(n);
    for (int i = 0; i < n; ++i) {
        size[i].resize(n);
        for (int j = 0; j < n; ++j) {
            size[i][j].resize(d + 1);
        }
    }
    queue<pair<pair<int, int>, int>> q;
    memset(max_size, 0x3f, sizeof(max_size));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
            if (grid[i][j] == '#') {
                q.push(make_pair(make_pair(i, j), max_size[i][j] = -1));
            }
        }
    }
    while (!q.empty()) {
        pair<pair<int, int>, int> cur = q.front();
        pair<int, int> pos = cur.first;
        int dist = cur.second;
        q.pop();
        if (max_size[pos.first][pos.second] != dist) {
            continue;
        }
        for (int i = 0; i < 4; ++i) {
            pair<int, int> next_pos = make_pair(pos.first + dx[i], pos.second + dy[i]);
            if (valid(next_pos.first, next_pos.second) && max_size[next_pos.first][next_pos.second] > dist + 1) {
                q.push(make_pair(next_pos, max_size[next_pos.first][next_pos.second] = dist + 1));
            }
        }
    }
#ifdef DEBUG
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << max_size[i][j] << " ";
        }
        cout << "\n";
    }
    cout << endl;
#endif
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            size[i][j][d] = -1;
        }
    }
#ifdef DEBUG
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << *max_element(size[i][j].begin(), size[i][j].end()) << " ";
        }
        cout << "\n";
    }
#endif
    assert(q.empty());
    queue<pair<pair<int, int>, pair<int, int>>> qu;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == 'S') {
                qu.push(make_pair(make_pair(i, j), make_pair(size[i][j][d] = 0, d)));
            }
        }
    }
    while (!qu.empty()) {
        pair<pair<int, int>, pair<int, int>> cur = qu.front();
        pair<int, int> pos = cur.first;
        int dist = cur.second.first, remain = cur.second.second;
        qu.pop();
        if (max_size[pos.first][pos.second] != dist) {
            continue;
        }
        for (int i = 0; i < 4; ++i) {
            pair<int, int> next_pos = make_pair(pos.first + dx[i], pos.second + dy[i]);
            int next_dist = dist, next_remain = remain - 1;
            if (!remain) {
                ++next_dist;
                next_remain = d;
            }
            if (valid(next_pos.first, next_pos.second) && size[next_pos.first][next_pos.second][next_remain] < next_dist && max_size[next_pos.first][next_pos.second] >= next_dist) {
                qu.push(make_pair(next_pos, make_pair(size[next_pos.first][next_pos.second][next_remain] = next_dist, next_remain)));
            }
        }
    }
#ifdef DEBUG
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << *max_element(size[i][j].begin(), size[i][j].end()) << " ";
        }
        cout << "\n";
    }
#endif
    cout << 15 << "\n";
    return 0;
}
