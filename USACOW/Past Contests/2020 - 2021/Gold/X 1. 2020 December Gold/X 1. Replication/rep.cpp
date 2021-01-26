#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    freopen("2.in", "r", stdin);
#endif
}
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1}, maxn = 1e3 + 5;

char grid[maxn][maxn];
bool visited[maxn][maxn];
int n, d, sol, max_size[maxn][maxn];
vector<vector<vector<int>>> size;

set<pair<set<pair<int, int>>, int>> vis;

bool valid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n && grid[x][y] != '#';
}


int main() {
    setIO();
    cin >> n >> d;
    size.resize(n);
    for (int i = 0; i < n; ++i) {
        size[i].resize(n);
        for (int j = 0; j < n; ++j) {
            size[i][j].resize(d + 1);
        }
    }
    queue<pair<pair<int, int>, int>> q;
    memset(max_size, 0x3f, sizeof(max_size));

    return 0;
}
