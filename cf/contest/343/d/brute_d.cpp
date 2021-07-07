/* Author: izhang05
 * Time: 07-06-2021 23:11:58
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e3 + 5;
vector<int> adj[maxn];
bool par[maxn][maxn];

void dfs(int c, int p, vector<int> parents) {
    parents.push_back(c);
    for (auto &i : parents) {
        par[i][c] = true;
    }
    for (auto &i : adj[c]) {
        if (i != p) {
            dfs(i, c, parents);
        }
    }
}

int main() {
    setIO("1");
    int n;
    cin >> n;
    vector<int> val(n);
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(0, -1, vector<int>());
    int q;
    cin >> q;
    while (q--) {
        int t, c;
        cin >> t >> c;
        --c;
        if (t == 1) {
            for (int i = 0; i < n; ++i) {
                if (par[c][i]) {
                    val[i] = 1;
                }
            }
        } else if (t == 2) {
            for (int i = 0; i < n; ++i) {
                if (par[i][c]) {
                    val[i] = 0;
                }
            }
        } else {
            cout << val[c] << "\n";
        }
    }
    return 0;
}
