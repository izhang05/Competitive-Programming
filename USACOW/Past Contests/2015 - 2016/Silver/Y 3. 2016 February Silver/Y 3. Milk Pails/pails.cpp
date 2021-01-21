/*
ID: izhang01
TASK: pails
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("pails.in", "r", stdin);
    freopen("pails.out", "w", stdout);
}

int x, y, k, m;
const int maxn = 101;
int visited[maxn][maxn];
int sol = 1e9;

void dfs(int left, int right, int count) {
    visited[left][right] = count;
    sol = min(sol, (abs(left + right - m)));
//    cout << left + right << " " << left << " " << right << "\n";
    if (count >= k) {
        return;
    }
    // Add to bucket
    if (count + 1 < visited[x][right]) {
        dfs(x, right, count + 1);
    }
    if (count + 1 < visited[left][y]) {
        dfs(left, y, count + 1);
    }
    // Pour from one to another
    if (count + 1 < visited[min(x - left, right) + left][right - min(x - left, right)]) {
        dfs(min(x - left, right) + left, right - min(x - left, right), count + 1);
    }
    if (count + 1 < visited[left - min(y - right, left)][min(y - right, left) + right]) {
        dfs(left - min(y - right, left), min(y - right, left) + right, count + 1);
    }
    // Empty bucket
    if (count + 1 < visited[0][right]) {
        dfs(0, right, count + 1);
    }
    if (count + 1 < visited[left][0]) {
        dfs(left, 0, count + 1);
    }
}


int main() {
    setIO();
    cin >> x >> y >> k >> m;
    for (int i = 0; i < maxn; ++i) {
        for (int j = 0; j < maxn; ++j) {
            visited[i][j] = 1e9;
        }
    }
    dfs(0, 0, 0);
    cout << sol << "\n";
    assert(sol != 1e9);
    return 0;
}
