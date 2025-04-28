#include<bits/stdc++.h>

using namespace std;
const int mxn = 55, inf = 0x3f3f3f3f;
int dist[mxn][mxn], grid[mxn][mxn];

int man(pair<int, int> x, pair<int, int> y) {
    return abs(x.first - y.first) + abs(x.second - y.second);
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<vector<pair<int, int>>> p(k);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
            --grid[i][j];
            p[grid[i][j]].emplace_back(i, j);
        }
    }
    memset(dist, 0x3f, sizeof(dist));
    for (auto i: p[0]) {
        dist[i.first][i.second] = 0;
    }
    for (int i = 1; i < k; ++i) {
        for (auto &j: p[i]) {
            for (auto &l: p[i - 1]) {
                dist[j.first][j.second] = min(dist[j.first][j.second], dist[l.first][l.second] + man(j, l));
            }
        }
    }
    int sol = inf;
    for (auto i: p[k - 1]) {
        sol = min(sol, dist[i.first][i.second]);
    }
    cout << (sol == inf ? -1 : sol) << "\n";
}