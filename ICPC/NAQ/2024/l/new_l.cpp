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
bool sn[mxn][mxn];
set<vector<pair<int, int>>> vis;

bool valid(int x, int y) {
    return x >= 0 && y >= 0 && x < n && y < m;
}

bool dfs(const vector<pair<int, int>> &cur) {
    vis.insert(cur);
    if (sn[cur[0].first][cur[0].second]) {
        return true;
    }
    vector<pair<int, int>> nxt_cur(int(cur.size()));
    for (int i = 1; i < int(cur.size()); ++i) {
        nxt_cur[i] = cur[i - 1];
    }
    for (int i = 0; i < 4; ++i) {
        int nx = cur[0].first + dx[i], ny = cur[0].second + dy[i];
        if (valid(nx, ny)) {
            bool good = true;
            for (int j = 0; j < min(int(cur.size()), max(2, int(cur.size()) - 1)); ++j) {
                if (cur[j].first == nx && cur[j].second == ny) {
                    good = false;
                    break;
                }
            }
            if (good) {
                nxt_cur[0] = {nx, ny};
                if (vis.find(nxt_cur) != vis.end()) {
                    continue;
                }
                if (dfs(nxt_cur)) {
                    return true;
                }
            }
        }
    }
    return false;
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
                sn[i][j] = true;
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
    vector<pair<int, int>> snake(tail + 1);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] >= 0) {
                snake[grid[i][j]] = {i, j};
                if (grid[i][j] >= 1) {
                    sn[i][j] = true;
                }
            }
        }
    }
    cout << (dfs(snake) ? 1 : 0) << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
