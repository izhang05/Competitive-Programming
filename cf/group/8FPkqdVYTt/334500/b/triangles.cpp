/* Author: izhang05
 * Time: 09-16-2021 14:35:03
**/
#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifndef TEST
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
    freopen((name + ".out").c_str(), "w", stderr);
#endif
}
const int maxn = 305;
char grid[maxn][maxn];
int full_pre[maxn][maxn][maxn];
int n;

int get_pre(pair<int, int> x, pair<int, int> y) {
    if (min(x.first, x.second) < 0) {
        int add = -min(x.first, x.second);
        x.first += add, x.second += add;
    }
    if (max(x.first, x.second) >= n) {
        int sub = max(x.first, x.second) - n + 1;
        x.first -= sub, x.second -= sub;
    }
    if (min(x.first, x.second) < 0) {
        return 0;
    }

    if (min(y.first, y.second) < 0) {
        int add = -min(y.first, y.second);
        y.first += add, y.second += add;
    }
    if (max(y.first, y.second) >= n) {
        int sub = max(y.first, y.second) - n + 1;
        y.first -= sub, y.second -= sub;
    }
    if (min(y.first, y.second) < 0) {
        return 0;
    }
    return
}

int main() {
    setIO("triangles");
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            full_pre[i][j][0] = grid[i][j] == '.';
            for (int k = 1; max(i, j) + k < n; ++k) {
                full_pre[i][j][k] = full_pre[i][j][k - 1] + (grid[i + k][j + k] == '.');
            }
        }
    }
    int sol = 0;
    for (int l = 2; l < 2 * n; l += 2) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                // (i - l, j) -> (i, j + l)
                pair<int, int> cur{i, j + l};
                if (cur.second >= n) {
                    if ()
                }
                sol += full_pre[i][j + l];
            }
        }
    }
    cout << sol << "\n";
    return 0;
}
