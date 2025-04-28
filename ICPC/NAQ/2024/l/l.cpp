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

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, mxn = 12;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

int n, m;
int grid[mxn][mxn];
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
bool reach[mxn][mxn], vis[mxn][mxn];

bool valid(int x, int y) {
    return x >= 0 && y >= 0 && x < n && y < m;
}

void dfs(int x, int y) {
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        if (!valid(nx, ny)) {
            continue;
        }
        reach[nx][ny] = true;
        if (!vis[nx][ny] && grid[nx][ny] == -1) {
            vis[nx][ny] = true;
            dfs(nx, ny);
        }
    }
}

int

void dfs2(int x, int y, int depth, bool found) {
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        if (!valid(nx, ny)) {
            continue;
        }
        reach[nx][ny] = true;
        if (!vis[nx][ny] && grid[nx][ny] == -1) {
            vis[nx][ny] = true;
            dfs(nx, ny);
        }
    }
}


void test_case() {
    cin >> n >> m;
    int tail = 0;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < m; ++j) {
            if (s[j] == 'A') {
                grid[i][j] = -2;
            } else if (s[j] == '.') {
                grid[i][j] = -1;
            } else if (s[j] >= 'a') {
                grid[i][j] = 10 + s[j] - 'a';
            } else {
                grid[i][j] = s[j] - '0';
            }
            tail = max(tail, grid[i][j]);
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 0) {
//                vis[i][j] = true;
                reach[i][j] = true;
                dfs(i, j);
            }
        }
    }
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < m; ++j) {
//            cout << reach[i][j];
//        }
//        cout << "\n";
//    }
//    cout << "\n";
//
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < m; ++j) {
//            cout << vis[i][j];
//        }
//        cout << "\n";
//    }
//    cout << "\n";


    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (reach[i][j]) {
                if (grid[i][j] == -2 || grid[i][j] == tail) {
                    cout << 1 << "\n";
                    return;
                }
                if (grid[i][j] >= 1) {

                }
            }
        }
    }
    cout << 0 << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
