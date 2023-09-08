/* Author: izhang
 * Time: 09-04-2023 19:04:52
**/
#include <bits/stdc++.h>

using namespace std;

#if defined LOCAL || defined DEBUG

#include <debug.h>

#else
struct dbg {
    template<class c>
    dbg &operator<<(const c &) { return *this; }
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
#endif

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

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, mxn = 105;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
char grid[mxn][mxn];
int dist[mxn][mxn];
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int n, m;

bool valid(int x, int y) {
    return x >= 0 && y >= 0 && x < n && y < m;
}

void test_case() {
    cin >> n >> m;
    memset(dist, 0x3f, sizeof(dist));
    queue<pair<int, int>> q;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < m; ++j) {
            grid[i][j] = s[j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int k = 0; k < 4; ++k) {
                int nx = i + dx[k], ny = j + dy[k];
                if (!valid(nx, ny) || grid[nx][ny] == '.') {
                    q.emplace(i, j);
                    dist[i][j] = 1;
                }
            }
        }
    }
    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = cur.first + dx[i], ny = cur.second + dy[i];
            if (valid(nx, ny)) {
                if (dist[nx][ny] > dist[cur.first][cur.second] + 1) {
                    dist[nx][ny] = dist[cur.first][cur.second] + 1;
                    q.emplace(nx, ny);
                }
            }
        }
    }
    int mx_dist = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            mx_dist = max(mx_dist, dist[i][j]);
        }
    }
    if (mx_dist < 10) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == '.') {
                    cout << "..";
                } else {
                    cout << "." << dist[i][j];
                }
            }
            cout << "\n";
        }
    } else {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == '.') {
                    cout << "...";
                } else {
                    if (dist[i][j] < 10) {
                        cout << ".." << dist[i][j];
                    } else if (dist[i][j] < 100) {
                        cout << "." << dist[i][j];
                    } else {
                        cout << dist[i][j];
                    }
                }
            }
            cout << "\n";
        }
    }
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
