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
const int maxn = 1e3 + 5;
char grid[maxn][maxn];
int n, m;
bool valid(int x, int y) {
    return x >= 0 && y >= 0 && x < n && y < m;
}
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int main() {
    setIO();
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }
    int sol = 0;
    set<pair<pair<int, int>, pair<int, int>>> ones;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            vector<pair<int, int>> cur;
            if (grid[i][j] == 'G') {
                for (int k = 0; k < 4; ++k) {
                    int nx = i + dx[k], ny = j + dy[k];
                    if (valid(nx, ny)) {
                        if (grid[nx][ny] == 'C') {
                            cur.emplace_back(nx, ny);
                        }
                    }
                }
            }
            if (cur.size() > 2) {
                ++sol;
            } else if (cur.size() == 2) {
                sort(cur.begin(), cur.end());
                ones.insert({cur[0], cur[1]});
            }
        }
    }
    cout << sol + ones.size() << "\n";
    return 0;
}
