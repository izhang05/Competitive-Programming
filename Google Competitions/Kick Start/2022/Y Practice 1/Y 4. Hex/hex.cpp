#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen(("in" + name + ".txt").c_str(), "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("out.txt", "w", stderr);
#endif
}

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 105;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
char grid[maxn][maxn];
bool visited[maxn][maxn];
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

int n;
bool valid(int x, int y) {
    return x >= 0 && y >= 0 && x < n && y < n;
}

int solve() {
    int r = 0, b = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == 'R') {
                ++r;
            } else if (grid[i][j] == 'B') {
                ++b;
            }
        }
    }
    if (abs(r - b) >= 2) {
        return 4;
    }
    int r_win = false, b_win = false;
    memset(visited, false, sizeof(visited));
    queue<pair<int, int>> q;
    for (int i = 0; i < n; ++i) {
        if (grid[0][i] == 'R') {
            q.push({0, i});
            visited[0][i] = true;
        }
    }
    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = cur.first + dx[i], ny = cur.second + dy[i];
            if (valid(nx, ny) && !visited[nx][ny] && grid[nx][ny] == 'R') {
                q.push({nx, ny});
                visited[nx][ny] = true;
            }
        }
        int nx = cur.first - 1, ny = cur.second + 1;
        if (valid(nx, ny) && !visited[nx][ny] && grid[nx][ny] == 'R') {
            q.push({nx, ny});
            visited[nx][ny] = true;
        }
        nx = cur.first + 1, ny = cur.second - 1;
        if (valid(nx, ny) && !visited[nx][ny] && grid[nx][ny] == 'R') {
            q.push({nx, ny});
            visited[nx][ny] = true;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (grid[n - 1][i] == 'R' && visited[n - 1][i]) {
            r_win = true;
        }
    }
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < n; ++i) {
        if (grid[i][0] == 'B') {
            q.push({i, 0});
            visited[i][0] = true;
        }
    }
    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = cur.first + dx[i], ny = cur.second + dy[i];
            if (valid(nx, ny) && !visited[nx][ny] && grid[nx][ny] == 'B') {
                q.push({nx, ny});
                visited[nx][ny] = true;
            }
        }
        int nx = cur.first - 1, ny = cur.second + 1;
        if (valid(nx, ny) && !visited[nx][ny] && grid[nx][ny] == 'B') {
            q.push({nx, ny});
            visited[nx][ny] = true;
        }
        nx = cur.first + 1, ny = cur.second - 1;
        if (valid(nx, ny) && !visited[nx][ny] && grid[nx][ny] == 'B') {
            q.push({nx, ny});
            visited[nx][ny] = true;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (grid[i][n - 1] == 'B' && visited[i][n - 1]) {
            b_win = true;
        }
    }
    return r_win + 2 * b_win;
}

void test_case() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
        }
    }
    int res = solve();

    if (res == 4 || res == 3) {
        cout << "Impossible\n";
        return;
    } else if (res == 0) {
        cout << "Nobody wins\n";
        return;
    } else {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                char cur = grid[i][j];
                if (cur != '.') {
                    grid[i][j] = '.';
                    if (solve() == 0) {
                        if (res == 1) {
                            cout << "Red wins\n";
                            return;
                        } else {
                            cout << "Blue wins\n";
                            return;
                        }
                    }
                    grid[i][j] = cur;
                }
            }
        }
    }
    cout << "Impossible\n";
}

int main() {
    setIO("1");
    int test_case_number = 1;
    cin >> test_case_number;
    for (int i = 1; i <= test_case_number; ++i) {
        cout << "Case #" << i << ": ";
        test_case();
    }
}
