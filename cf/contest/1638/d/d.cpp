/* Author: izhang
 * Time: 02-16-2022 17:31:33
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e3 + 5;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
int grid[maxn][maxn];
int n, m;

int good(int x, int y) {
    if (x < 0 || y < 0 || x >= n - 1 || y >= m - 1) {
        return false;
    }
    int c = -1;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            if (grid[x + i][y + j] != 0) {
                c = grid[x + i][y + j];
            }
        }
    }
    if (c == -1) {
        return false;
    }
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            if (grid[x + i][y + j] != c && grid[x + i][y + j] != 0) {
                return false;
            }
        }
    }
    return c;
}

void test_case() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }
    vector<array<int, 3>> sol;
    queue<array<int, 3>> q;
    vector<pair<int, int>> four;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < m - 1; ++j) {
            if (good(i, j)) {
                q.push({i, j, grid[i][j]});
                four.emplace_back(i, j);
            }
        }
    }
    for (auto &i : four) {
        for (int k = 0; k < 2; ++k) {
            for (int l = 0; l < 2; ++l) {
                grid[i.first + k][i.second + l] = 0;
            }
        }
    }

    while (!q.empty()) {
        array<int, 3> cur = q.front();
        q.pop();
        sol.push_back(cur);
        for (int i = cur[0] - 1; i <= cur[0] + 1; ++i) {
            for (int j = cur[1] - 1; j <= cur[1] + 1; ++j) {
                int c = good(i, j);
                if (c) {
                    q.push({i, j, c});
                    for (int k = 0; k < 2; ++k) {
                        for (int l = 0; l < 2; ++l) {
                            grid[i + k][j + l] = 0;
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j]) {
                cout << -1 << "\n";
                return;
            }
        }
    }
    reverse(sol.begin(), sol.end());
    cout << sol.size() << "\n";
    for (auto &i : sol) {
        cout << i[0] + 1 << " " << i[1] + 1 << " " << i[2] << "\n";
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
