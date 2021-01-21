/*
ID: izhang01
TASK: tractor
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("tractor.in", "r", stdin);
    freopen("tractor.out", "w", stdout);
}
const int maxn = 501;
int n, d, goal, cur;
int grid[maxn][maxn];
bool visited[maxn][maxn];


void start_dfs(int x, int y) {
    visited[node][dist] = true;
    ++cur;
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
    if (node != n - 1) {
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
    cin >> n;
    goal = (n * n + 1) / 2;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
        }
    }
    int low = 0, high = 1e9, mid, sol;
    while (low <= high) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                visited[i][j] = false;
            }
        }
        mid = (low + high) / 2;
        d = mid;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!visited[i][j]) {
                    cur = 0;
                    start_dfs(i, j);
                    if (cur >= goal) {
                        break;
                    }
                }
            }
            if (cur >= goal) {
                break;
            }
        }
        if (cur >= goal) {
            sol = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    cout << sol << "\n";
    return 0;
}
