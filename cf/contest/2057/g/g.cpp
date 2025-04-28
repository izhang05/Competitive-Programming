/* Author: izhang
 * Time: 01-04-2025 11:44:01
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

const int inf = 0x3f3f3f3f, mod = 1e9 + 7; //998244353;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

int n, m;

bool valid(int x, int y) {
    return x >= 0 && y >= 0 && x < n && y < m;
}

vector<vector<char>> grid;
vector<vector<int>> val, cur_c;

int calc(int x, int y) {
    int cur = val[x][y];
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        if (valid(nx, ny)) {
            cur += val[nx][ny];
        }
    }
    return cur;
}

void test_case() {
    cin >> n >> m;
    grid.clear();
    val.clear();
    cur_c.clear();
    grid = vector<vector<char>>(n, vector<char>(m));
    val = vector<vector<int>>(n, vector<int>(m));
    cur_c = vector<vector<int>>(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == '.') {
                continue;
            }
            val[i][j] = 1;
            for (int k = 0; k < 4; ++k) {
                int nx = i + dx[k], ny = j + dy[k];
                if (!valid(nx, ny) || grid[nx][ny] == '.') {
                    ++val[i][j];
                }
            }
        }
    }
    set<pair<int, pair<int, int>>, greater<>> s;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == '.') {
                continue;
            }
            cur_c[i][j] = calc(i, j);
            s.insert({cur_c[i][j], {i, j}});
        }
    }
    while (!s.empty() && s.begin()->first) {
        pair<int, pair<int, int>> cur = *s.begin();
        int x = cur.second.first, y = cur.second.second;
//        for (int i = 0; i < n; ++i) {
//            for (int j = 0; j < m; ++j) {
//                dbg() << val[i][j];
//            }
//            dbg();
//        }
//
//        for (int i = 0; i < n; ++i) {
//            for (int j = 0; j < m; ++j) {
//                dbg() << cur_c[i][j];
//            }
//            dbg();
//        }
//
//
//        dbg() << cur.first << " " << x << " " << y;
        s.erase(s.begin());
        grid[x][y] = 'S';
        val[x][y] = 0;
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if (valid(nx, ny)) {
                val[nx][ny] = 0;
            }
        }
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if (valid(nx, ny)) {
                s.erase({cur_c[nx][ny], {nx, ny}});
                cur_c[nx][ny] = calc(nx, ny);
                s.insert({cur_c[nx][ny], {nx, ny}});
                for (int j = 0; j < 4; ++j) {
                    int nnx = nx + dx[j], nny = ny + dy[j];
                    if (valid(nnx, nny)) {
                        s.erase({cur_c[nnx][nny], {nnx, nny}});
                        cur_c[nnx][nny] = calc(nnx, nny);
                        s.insert({cur_c[nnx][nny], {nnx, nny}});
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << grid[i][j];
        }
        cout << "\n";
    }
}

int main() {
    setIO("1");

    int test_case_number = 1;
    cin >> test_case_number;
    while (test_case_number--) {
        test_case();
        dbg();
    }
    return 0;
}
