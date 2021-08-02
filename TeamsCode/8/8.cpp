#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
//    freopen((name + ".in").c_str(), "r", stdin);
//    freopen((name + ".out").c_str(), "w", stdout);
//    freopen((name + ".out").c_str(), "w", stderr);
#endif
}

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 5e5 + 5, maxd = 50;
vector<int> adj[maxn];
int down[maxn][maxd], up[maxn][maxd];

void dfs1(int c, int p) {
    down[c][0] = 1;
    for (auto &i : adj[c]) {
        if (i != p) {
            dfs1(i, c);
            for (int j = 1; j < maxd; ++j) {
                down[c][j] += down[i][j - 1];
            }
        }
    }
}

void dfs2(int c, int p) {
    if (p != -1) {
        for (int i = 1; i < maxd; ++i) {
            up[c][i] += up[p][i - 1] + down[p][i - 1];
            if (i - 2 >= 0) {
                up[c][i] -= down[c][i - 2];
            }
        }
    }
    for (auto &i : adj[c]) {
        if (i != p) {
            dfs2(i, c);
        }
    }

}

int main() {
    setIO("1");
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            adj[i].clear();
            for (int j = 0; j < maxd; ++j) {
                down[i][j] = up[i][j] = 0;
            }
        }
        for (int i = 1; i < n; ++i) {
            adj[n % i].push_back(i);
            adj[i].push_back(n % i);
        }
        dfs1(0, -1);
        dfs2(0, -1);
        int sol = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < maxd; ++j) {
                sol = max(sol, down[i][j] + up[i][j]);
            }
        }
        cout << sol << "\n";
    }
    return 0;
}
