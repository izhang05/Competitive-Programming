#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    freopen("1.out", "w", stderr);
#endif
}
//#define DEBUG
const int maxn = 4e3;
int state[maxn][maxn], surround[maxn][maxn];
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

bool valid(int x, int y) {
    return x >= 0 && y >= 0;
}

int main() {
    setIO();
    int n, sol = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        x += 1000, y += 1000;
        if (state[x][y] == 2) {
            state[x][y] = 1;
            --sol;
        } else if (state[x][y] == 1) {
            assert(false);
        } else {
            state[x][y] = 1;
            queue<pair<int, int>> q;
            for (int j = 0; j < 4; ++j) {
                int nx = x + dx[j], ny = y + dy[j];
                ++surround[nx][ny];
                if (state[nx][ny] && surround[nx][ny] == 3) {
                    q.push({nx, ny});
                }
            }
            while (!q.empty()) {
                pair<int, int> cur = q.front();
                q.pop();
                if (surround[cur.first][cur.second] == 3) {
                    int nx, ny;
                    for (int j = 0; j < 4; ++j) {
                        nx = cur.first + dx[j], ny = cur.second + dy[j];
                        if (!state[nx][ny]) {
                            break;
                        }
                    }
                    ++sol;
                    state[nx][ny] = 2;
                    for (int j = 0; j < 4; ++j) {
                        int nnx = nx + dx[j], nny = ny + dy[j];
                        ++surround[nnx][nny];
                        if (state[nnx][nny] && surround[nnx][nny] == 3) {
                            q.push({nnx, nny});
                        }
                    }
                }
            }
        }
        cout << sol << "\n";
#ifdef DEBUG
        cout << "State: "
             << "\n";
        for (int i = 0; i < 7; ++i) {
            for (int j = 0; j < 7; ++j) {
                cout << state[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
        cout << "Surround: "
             << "\n";
        for (int i = 0; i < 7; ++i) {
            for (int j = 0; j < 7; ++j) {
                cout << surround[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
#endif
    }
    return 0;
}
