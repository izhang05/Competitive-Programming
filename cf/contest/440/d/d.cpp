/* Author: izhang05
 * Time: 07-21-2021 20:47:09
**/
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 405;
int dp[maxn][maxn], edge[maxn];
vector<pair<int, int>> adj[maxn], par[maxn][maxn];
int n, k;

void dfs(int c, int p) {
    for (int i = 0; i <= k; ++i) {
        dp[c][i] = inf;
    }
    dp[c][1] = 0;
    for (auto &i : adj[c]) {
        if (i.first != p) {
            dfs(i.first, c);
            edge[i.first] = i.second;
            for (int j = k; j >= 1; --j) {
                ++dp[c][j];
                int from = 0;
                for (int l = 1; l < j; ++l) {
                    if (dp[c][j - l] + dp[i.first][l] < dp[c][j]) {
                        dp[c][j] = dp[c][j - l] + dp[i.first][l];
                        from = l;
                    }
                }
                par[c][j] = par[c][j - from];
                par[c][j].emplace_back(i.first, from);
            }
        }
    }
}

void print(int c, int num) {
    for (auto &i : par[c][num]) {
        if (i.second) {
            print(i.first, i.second);
        } else {
            cout << edge[i.first] << " ";
        }
    }
}

int main() {
    setIO("1");

    cin >> n >> k;
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].emplace_back(b, i + 1);
        adj[b].emplace_back(a, i + 1);
    }
    dfs(0, -1);
    int sol = dp[0][k], ind = 0;
    for (int i = 1; i < n; ++i) {
        if (dp[i][k] + 1 < sol) {
            sol = dp[i][k] + 1;
            ind = i;
        }
    }
    cout << sol << "\n";
    if (ind) {
        cout << edge[ind] << " ";
    }
    print(ind, k);
    return 0;
}
