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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 2e3 + 10;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
struct rect {
    int x1, y1, x2, y2;
};
int pre[maxn][maxn];
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
bool visited[maxn][maxn];

int n, t;
bool valid(int x, int y) {
    return x >= 0 && y >= 0 && x < 2 * n + 2 && y < 2 * n + 2;
}

void dfs(int x, int y) {
    visited[x][y] = true;
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        if (valid(nx, ny) && !visited[nx][ny] && pre[nx][ny] % 2 == pre[x][y] % 2) {
            dfs(nx, ny);
        }
    }
}


int main() {
    setIO("1");
    cin >> n >> t;
    vector<rect> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].x1 >> a[i].y1 >> a[i].x2 >> a[i].y2;
        ++pre[a[i].x1][a[i].y1], --pre[a[i].x2][a[i].y1], --pre[a[i].x1][a[i].y2], ++pre[a[i].x2][a[i].y2];
    }
    for (int i = 1; i < maxn; ++i) {
        for (int j = 1; j < maxn; ++j) {
            pre[i][j] += pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];
        }
    }
    int white = 0, black = 0;
    for (int i = 0; i < 2 * n + 2; ++i) {
        for (int j = 0; j < 2 * n + 2; ++j) {
            if (!visited[i][j]) {
                if (pre[i][j] % 2 == 0) {
                    ++white;
                } else {
                    ++black;
                }
                dfs(i, j);
            }
        }
    }
    if (t == 1) {
        cout << white + black << "\n";
    } else {
        cout << white << " " << black << "\n";
    }
    //    sort(a.begin(), a.end(), [](auto left, auto right) {
    //        return left.y2 < right.y2;
    //    });
    //    long long white = 1, black = 0;
    //    vector<pair<int, int>> cont(n);
    //    set<pair<int, int>> seen;
    //    for (int i = 0; i < n; ++i) {
    //        auto it = seen.lower_bound({a[i].x1, 0});
    //        cont[i].second = 1;
    //        while (it != seen.end()) {
    //
    //            it = seen.erase(it);
    //        }
    //        white += cont[i].first, black += cont[i].second;
    //        seen.insert({a[i].x1, i});
    //    }
    //
    //    cout << white << " " << black << "\n";
    return 0;
}
