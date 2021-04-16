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
const int maxn = 2005;
int ne[maxn][maxn], state[maxn][maxn], sol = 0;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

void modify(int x, int y, int add) {
    if (state[x][y] == 1) {
        --sol;
        return;
    }
    if (add == 1) {
        ++sol;
    }
    state[x][y] = add;
    int neigh = 0;
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        ++ne[nx][ny];
        if (ne[nx][ny] == 3 && state[nx][ny]) {
            for (int j = 0; j < 4; ++j) {
                int nnx = nx + dx[j], nny = ny + dy[j];
                if (!state[nnx][nny]) {
                    modify(nnx, nny, 1);
                }
            }
        }
        if (state[nx][ny]) {
            ++neigh;
        }
    }
    if (neigh == 3) {
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if (!state[nx][ny]) {
                modify(nx, ny, 1);
            }
        }
    }
}

int main() {
    setIO();
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        pair<int, int> a;
        cin >> a.first >> a.second;
        a.first += 500;
        a.second += 500;
        modify(a.first, a.second, 2);
        cout << sol << "\n";
    }
    return 0;
}
