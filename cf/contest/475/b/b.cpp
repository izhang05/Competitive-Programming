/* Author: izhang
 * Time: 08-10-2022 18:09:34
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

const int maxn = 25;
vector<pair<int, int>> adj[maxn][maxn];

bool visited[maxn][maxn];

void dfs(int x, int y) {
    visited[x][y] = true;
    for (auto &i : adj[x][y]) {
        if (!visited[i.first][i.second]) {
            dfs(i.first, i.second);
        }
    }
}

void test_case() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        char c;
        cin >> c;
        if (c == '<') {
            for (int j = 0; j < m - 1; ++j) {
                adj[i][j + 1].emplace_back(i, j);
            }
        } else {
            for (int j = 0; j < m - 1; ++j) {
                adj[i][j].emplace_back(i, j + 1);
            }
        }
    }
    for (int i = 0; i < m; ++i) {
        char c;
        cin >> c;
        if (c == '^') {
            for (int j = 0; j < n - 1; ++j) {
                adj[j + 1][i].emplace_back(j, i);
            }
        } else {
            for (int j = 0; j < n - 1; ++j) {
                adj[j][i].emplace_back(j + 1, i);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            memset(visited, false, sizeof(visited));
            visited[i][j] = true;
            dfs(i, j);
            for (int k = 0; k < n; ++k) {
                for (int l = 0; l < m; ++l) {
                    if (!visited[k][l]) {
                        cout << "NO\n";
                        return;
                    }
                }
            }
        }
    }
    cout << "YES"
         << "\n";
    return;
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
