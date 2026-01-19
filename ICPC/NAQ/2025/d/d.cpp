/* Author: izhang
 * Time: 10-11-2025 13:55:14
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

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, mxn = 55;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

int n, m;
bool grid[mxn][mxn], vis[mxn][mxn][4], finish = false, found = false;
int dest_x, dest_y;


const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

// 0 = down, 1 = right, 2 = up, 3 = left

bool valid(int x, int y) {
    return x >= 0 && y >= 0 && x < n && y < m && grid[x][y];
}


void dfs(int x, int y, int d) {
//    cout << x << " " << y << " " << d << "\n";
    if (x == dest_x && y == dest_y) {
        finish = true;
        found = true;
        return;
    }
    if (vis[x][y][d]) {
        finish = true;
        return;
    }
    vis[x][y][d] = true;
    int nd = (d + 1) % 4;
    int nx = x + dx[nd], ny = y + dy[nd];
    if (valid(nx, ny)) {
        dfs(nx, ny, nd);
        return;
    }
    nx = x + dx[d], ny = y + dy[d];
    if (valid(nx, ny)) {
        dfs(nx, ny, d);
        return;
    }
    nd = (d - 1 + 4) % 4;
    dfs(x, y, nd);
}


void test_case() {
    cin >> n >> m;
    int x, y;
    cin >> x >> y;
    --x, --y;
    cin >> dest_x >> dest_y;
    --dest_x, --dest_y;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < m; ++j) {
            grid[i][j] = (s[j] == '0');
        }
    }
    dfs(x, y, 1);
    cout << found << "\n";
}


int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
