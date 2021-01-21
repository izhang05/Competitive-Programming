/*
ID: izhang01
TASK: distant
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("distant.in", "r", stdin);
    freopen("distant.out", "w", stdout);
}

// Simple Floyd-Warshall that the official solution says shouldn't work, but it does

const int maxn = 30;
const long long inf = 1e18;
long long dist[maxn * maxn][maxn * maxn];
char grid[maxn][maxn];


int main() {
    setIO();
    int n, a, b;
    cin >> n >> a >> b;
    long long sol = 0;
    for (int i = 0; i < n * n; ++i) {
        for (int j = 0; j < n * n; ++j) {
            dist[i][j] = inf;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
            if (i != 0) {
                int first = (i - 1) * n + j, second = i * n + j;
                if (grid[i][j] == grid[i - 1][j]) {
                    dist[first][second] = dist[second][first] = a;
                } else {
                    dist[first][second] = dist[second][first] = b;
                }
            }
            if (j != 0) {
                int first = i * n + j - 1, second = i * n + j;
                if (grid[i][j] == grid[i][j - 1]) {
                    dist[first][second] = dist[second][first] = a;
                } else {
                    dist[first][second] = dist[second][first] = b;
                }
            }
        }
    }
    for (int k = 0; k < n * n; ++k) {
        for (int i = 0; i < n * n; ++i) {
            for (int j = 0; j < n * n; ++j) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    for (int i = 0; i < n * n; ++i) {
        for (int j = 0; j < n * n; ++j) {
            if (dist[i][j] != inf) {
                sol = max(sol, dist[i][j]);
            }
        }
    }
    cout << sol << "\n";
    return 0;
}
