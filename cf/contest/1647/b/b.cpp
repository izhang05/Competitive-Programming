/* Author: izhang
 * Time: 03-15-2022 01:44:00
**/
#include <bits/stdc++.h>

using namespace std;

#if defined LOCAL || defined DEBUG
#include <debug.h>
#else
struct dbg {
    template<class c>
    dbg &operator<<(const c &) { return *this; }
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
#endif

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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7; //998244353;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int n, m;

bool valid(int x, int y) {
    return x >= 0 && y >= 0 && x < n && y < m;
}

void test_case() {
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m)), visited(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < m; ++j) {
            a[i][j] = s[j] - '0';
        }
    }
    dbg() << a;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (visited[i][j] || a[i][j] == 0) {
                continue;
            }
            queue<pair<int, int>> q;
            pair<int, int> x = {i, i}, y = {j, j};
            q.push({i, j});
            visited[i][j] = true;
            while (!q.empty()) {
                pair<int, int> cur = q.front();
                q.pop();
                for (int k = 0; k < 4; ++k) {
                    int nx = cur.first + dx[k], ny = cur.second + dy[k];
                    if (valid(nx, ny) && !visited[nx][ny] && a[nx][ny] == 1) {
                        x.first = min(x.first, nx);
                        x.second = max(x.second, nx);
                        y.first = min(y.first, ny);
                        y.second = max(y.second, ny);
                        visited[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }
            }
            for (int k = x.first; k <= x.second; ++k) {
                for (int l = y.first; l <= y.second; ++l) {
                    if (a[k][l] == 0) {
                        cout << "NO"
                             << "\n";
                        return;
                    }
                }
            }
        }
    }
    cout << "YES"
         << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    cin >> test_case_number;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
