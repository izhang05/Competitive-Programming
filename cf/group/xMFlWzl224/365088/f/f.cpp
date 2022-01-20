/* Author: izhang
 * Time: 01-19-2022 18:01:20
**/
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 2e3 + 5;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
int n, m;
char grid[maxn][maxn];

pair<int, int> dist[maxn][maxn];

const int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
bool valid(int x, int y) {
    return x >= 0 && y >= 0 && x < n && y < m;
}

void test_case() {
    cin >> n >> m;
    int r, c, x, y;
    cin >> r >> c >> x >> y;
    --r, --c;
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
        for (int j = 0; j < m; ++j) {
            dist[i][j] = {inf, inf};
        }
    }
    dist[r][c] = {0, 0};
    queue<pair<int, int>> q;
    q.push({r, c});
    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = cur.first + dx[i], ny = cur.second + dy[i];
            if (!valid(nx, ny)) {
                continue;
            }
            pair<int, int> new_dist = dist[cur.first][cur.second];
            if (i == 2) {
                ++new_dist.second;
            } else if (i == 3) {
                ++new_dist.first;
            }
            if (grid[nx][ny] == '.' && dist[nx][ny] > new_dist) {
                q.push({nx, ny});
                dist[nx][ny] = new_dist;
            }
        }
    }
    int sol = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (dist[i][j].first <= x && dist[i][j].second <= y) {
                ++sol;
            }
        }
    }
    cout << sol << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
