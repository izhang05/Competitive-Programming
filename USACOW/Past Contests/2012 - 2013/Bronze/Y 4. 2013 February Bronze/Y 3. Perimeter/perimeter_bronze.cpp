/*
ID: izhang01
TASK: perimeter
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("perimeter.in", "r", stdin);
    freopen("perimeter.out", "w", stdout);
}
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1}, maxn = 1e2 + 2;
int state[maxn][maxn], sol = 0, n;

bool valid(int x, int y) {
    return x >= 0 && y >= 0 && x < maxn && y < maxn;
}

void dfs(int x, int y) {
    state[x][y] = 1;
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        if (valid(nx, ny)) {
            if (state[nx][ny] == 2) {
                ++sol;
            } else if (state[nx][ny] == 0) {
                dfs(nx, ny);
            }
        }
    }
}


int main() {
    setIO();
    cin >> n;
    int a, b;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        state[a][b] = 2;
    }
    dfs(0, 0);
    cout << sol << "\n";
    return 0;
}
