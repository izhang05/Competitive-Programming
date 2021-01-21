/*
ID: izhang01
TASK: ccski
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("ccski.in", "r", stdin);
    freopen("ccski.out", "w", stdout);
}
const int maxn = 501;
int m, n, num_way, cur_way, d;
int grid[maxn][maxn];
bool way[maxn][maxn];
bool visited[maxn][maxn];
pair<int, int> start;


void start_dfs(int x, int y) {
    visited[node][dist] = true;
    if (way[node][dist]) {
        ++cur_way;
    }
    if (node != 0) {
        if (!visited[node - 1][dist] && abs(grid[node - 1][dist] - grid[node][dist]) <= d) {
            start_dfs(node - 1, dist);
        }
    }
    if (dist != 0) {
        if (!visited[node][dist - 1] && abs(grid[node][dist - 1] - grid[node][dist]) <= d) {
            start_dfs(node, dist - 1);
        }
    }
    if (node != m - 1) {
        if (!visited[node + 1][dist] && abs(grid[node + 1][dist] - grid[node][dist]) <= d) {
            start_dfs(node + 1, dist);
        }
    }
    if (dist != n - 1) {
        if (!visited[node][dist + 1] && abs(grid[node][dist + 1] - grid[node][dist]) <= d) {
            start_dfs(node, dist + 1);
        }
    }
}


int main() {
    setIO();
    cin >> m >> n;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
        }
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> way[i][j];
            num_way += way[i][j];
            start = pair<int, int> {i, j};
        }
    }
    int low = 0, high = 1e9, mid, sol;
    while (low <= high) {
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                visited[i][j] = false;
            }
        }
        mid = (low + high) / 2;
        cur_way = 0;
        d = mid;
        start_dfs(start.first, start.second);
        if (cur_way == num_way) {
            sol = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    cout << sol << "\n";
    return 0;
}
