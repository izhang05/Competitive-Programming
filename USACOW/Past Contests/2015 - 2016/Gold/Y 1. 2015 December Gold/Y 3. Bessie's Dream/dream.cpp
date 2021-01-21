/*
ID: izhang01
TASK: dream
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("dream.in", "r", stdin);
    freopen("dream.out", "w", stdout);
}

const int maxn = 1e3, inf = 0x3f3f3f3f;
int grid[maxn][maxn], dist[maxn][maxn][2][4], dx[]{0, 0, 1, -1}, dy[]{1, -1, 0, 0}, n, m;

bool valid(int x, int y) {
    return x >= 0 && y >= 0 && x < n && y < m && grid[x][y];
}
struct state {
    int x, y;
    bool smell;
    int dir;
};
int main() {
    setIO();
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }
    memset(dist, 0x3f, sizeof(dist));
    dist[0][0][0][0] = 0;
    queue<state> q;
    q.push(state{0, 0, false, 0});
    while (!q.empty()) {
        state cur = q.front();
        q.pop();
        if (grid[cur.x][cur.y] != 4) {
            for (int i = 0; i < 4; ++i) {
                int next_x = cur.x + dx[i], next_y = cur.y + dy[i];
                if (valid(next_x, next_y)) {
                    if (grid[next_x][next_y] == 1 || (grid[next_x][next_y] == 3 && cur.smell)) {
                        if (dist[next_x][next_y][cur.smell][i] > dist[cur.x][cur.y][cur.smell][cur.dir] + 1) {
                            dist[next_x][next_y][cur.smell][i] = dist[cur.x][cur.y][cur.smell][cur.dir] + 1;
                            q.push(state{next_x, next_y, cur.smell, i});
                        }
                    } else if (grid[next_x][next_y] == 2) {
                        if (dist[next_x][next_y][1][i] > dist[cur.x][cur.y][cur.smell][cur.dir] + 1) {
                            dist[next_x][next_y][1][i] = dist[cur.x][cur.y][cur.smell][cur.dir] + 1;
                            q.push(state{next_x, next_y, true, i});
                        }
                    } else if (grid[next_x][next_y] == 4) {
                        if (dist[next_x][next_y][0][i] > dist[cur.x][cur.y][cur.smell][cur.dir] + 1) {
                            dist[next_x][next_y][0][i] = dist[cur.x][cur.y][cur.smell][cur.dir] + 1;
                            q.push(state{next_x, next_y, false, i});
                        }
                    }
                }
            }
        } else { // cur cell is purple
            int next_x = cur.x + dx[cur.dir], next_y = cur.y + dy[cur.dir];
            bool moved = false;
            if (valid(next_x, next_y)) {
                if (grid[next_x][next_y] == 1 || (grid[next_x][next_y] == 3 && cur.smell)) {
                    if (dist[next_x][next_y][cur.smell][cur.dir] > dist[cur.x][cur.y][cur.smell][cur.dir] + 1) {
                        dist[next_x][next_y][cur.smell][cur.dir] = dist[cur.x][cur.y][cur.smell][cur.dir] + 1;
                        q.push(state{next_x, next_y, cur.smell, cur.dir});
                    }
                    moved = true;
                } else if (grid[next_x][next_y] == 2) {
                    if (dist[next_x][next_y][1][cur.dir] > dist[cur.x][cur.y][cur.smell][cur.dir] + 1) {
                        dist[next_x][next_y][1][cur.dir] = dist[cur.x][cur.y][cur.smell][cur.dir] + 1;
                        q.push(state{next_x, next_y, true, cur.dir});
                    }
                    moved = true;
                } else if (grid[next_x][next_y] == 4) {
                    if (dist[next_x][next_y][0][cur.dir] > dist[cur.x][cur.y][cur.smell][cur.dir] + 1) {
                        dist[next_x][next_y][0][cur.dir] = dist[cur.x][cur.y][cur.smell][cur.dir] + 1;
                        q.push(state{next_x, next_y, false, cur.dir});
                    }
                    moved = true;
                }
            }
            if (!moved) {
                for (int i = 0; i < 4; ++i) {
                    next_x = cur.x + dx[i], next_y = cur.y + dy[i];
                    if (valid(next_x, next_y)) {
                        if (grid[next_x][next_y] == 1 || (grid[next_x][next_y] == 3 && cur.smell)) {
                            if (dist[next_x][next_y][cur.smell][i] > dist[cur.x][cur.y][cur.smell][cur.dir] + 1) {
                                dist[next_x][next_y][cur.smell][i] = dist[cur.x][cur.y][cur.smell][cur.dir] + 1;
                                q.push(state{next_x, next_y, cur.smell, i});
                            }
                        } else if (grid[next_x][next_y] == 2) {
                            if (dist[next_x][next_y][1][i] > dist[cur.x][cur.y][cur.smell][cur.dir] + 1) {
                                dist[next_x][next_y][1][i] = dist[cur.x][cur.y][cur.smell][cur.dir] + 1;
                                q.push(state{next_x, next_y, true, i});
                            }
                        } else if (grid[next_x][next_y] == 4) {
                            if (dist[next_x][next_y][0][i] > dist[cur.x][cur.y][cur.smell][cur.dir] + 1) {
                                dist[next_x][next_y][0][i] = dist[cur.x][cur.y][cur.smell][cur.dir] + 1;
                                q.push(state{next_x, next_y, false, i});
                            }
                        }
                    }
                }
            }
        }
    }

    int sol = inf;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 4; ++j) {
            sol = min(sol, dist[n - 1][m - 1][i][j]);
        }
    }
    cout << (sol == inf ? -1 : sol) << "\n";
    return 0;
}
