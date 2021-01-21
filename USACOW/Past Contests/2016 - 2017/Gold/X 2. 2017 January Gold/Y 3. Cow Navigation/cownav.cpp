/*
ID: izhang01
TASK: cownav
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("cownav.in", "r", stdin);
    freopen("cownav.out", "w", stdout);
}
const int maxn = 20, dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1}, inf = 0x3f3f3f3f; // 0: up, 1: right, 2: down, 3: left
int dist[maxn][maxn][4][maxn][maxn][4];                                              // x, y, and direction for both cows
char grid[maxn][maxn];
int n;
bool valid(pair<int, int> x) {
    return x.first >= 0 && x.first < n && x.second >= 0 && x.second < n && grid[x.first][x.second] == 'E';
}

int main() {
    setIO();
    cin >> n;
    memset(dist, 0x3f, sizeof(dist));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
        }
    }
    dist[n - 1][0][0][n - 1][0][1] = 0;
    queue<pair<vector<int>, int>> q;
    pair<int, int> destination{0, n - 1};
    q.push(make_pair(vector<int>{n - 1, 0, 0, n - 1, 0, 1}, 0));
    while (!q.empty()) {
        pair<vector<int>, int> cur = q.front();
        q.pop();
        if (dist[cur.first[0]][cur.first[1]][cur.first[2]][cur.first[3]][cur.first[4]][cur.first[5]] != cur.second) {
            continue;
        }
        int cur_dist = cur.second;
        pair<int, int> f{cur.first[0], cur.first[1]}, s{cur.first[3], cur.first[4]};
        int f_dir = cur.first[2], s_dir = cur.first[5];

        // move forward
        pair<int, int> next_f = pair<int, int>{f.first + dx[f_dir], f.second + dy[f_dir]};
        pair<int, int> next_s = pair<int, int>{s.first + dx[s_dir], s.second + dy[s_dir]};
        if (!valid(next_f) || f == destination) {
            next_f = f;
        }
        if (!valid(next_s) || s == destination) {
            next_s = s;
        }
        if (dist[next_f.first][next_f.second][f_dir][next_s.first][next_s.second][s_dir] > cur_dist + 1) {
            q.push(make_pair(vector<int>{next_f.first, next_f.second, f_dir, next_s.first, next_s.second, s_dir}, dist[next_f.first][next_f.second][f_dir][next_s.first][next_s.second][s_dir] = cur_dist + 1));
        }

        // turn left 90 degrees(dir - 1)
        int next_f_dir = (f_dir - 1 + 4) % 4, next_s_dir = (s_dir - 1 + 4) % 4;
        if (dist[f.first][f.second][next_f_dir][s.first][s.second][next_s_dir] > cur_dist + 1) {
            q.push(make_pair(vector<int>{f.first, f.second, next_f_dir, s.first, s.second, next_s_dir}, dist[f.first][f.second][next_f_dir][s.first][s.second][next_s_dir] = cur_dist + 1));
        }
        // turn right 90 degrees(dir + 1)
        next_f_dir = (f_dir + 1) % 4, next_s_dir = (s_dir + 1) % 4;
        if (dist[f.first][f.second][next_f_dir][s.first][s.second][next_s_dir] > cur_dist + 1) {
            q.push(make_pair(vector<int>{f.first, f.second, next_f_dir, s.first, s.second, next_s_dir}, dist[f.first][f.second][next_f_dir][s.first][s.second][next_s_dir] = cur_dist + 1));
        }
    }
    int sol = inf;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            sol = min(sol, dist[0][n - 1][i][0][n - 1][j]);
        }
    }
    cout << sol << "\n";
    return 0;
}
