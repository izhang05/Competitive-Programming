/* Author: izhang05
 * Time: 06-29-2021 15:12:31
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
#define int long long
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e5 + 5;
vector<int> adj[maxn];
int deg[maxn], c[maxn];

signed main() {
    setIO("1");

    int n;
    cin >> n;
    vector<vector<int>> cost(3, vector<int>(n));
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> cost[i][j];
        }
    }
    for (int i = 0; i < n - 1; ++i) {
        int d, e;
        cin >> d >> e;
        --d, --e;
        adj[d].push_back(e);
        adj[e].push_back(d);
        ++deg[d];
        ++deg[e];
    }
    int root = -1;
    for (int i = 0; i < n; ++i) {
        if (deg[i] >= 3) {
            cout << -1 << "\n";
            return 0;
        }
        if (deg[i] == 1) {
            root = i;
        }
    }
    assert(root != -1);
    pair<long long, pair<int, int>> sol;
    sol.first = 1e18;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (i == j) {
                continue;
            }
            vector<int> color{i, j, 3 - (i + j)};
            int node = adj[root][0], p = root;
            int cur = cost[i][root] + cost[j][node], ind = 2;
            while (true) {
                int next;
                for (auto &k : adj[node]) {
                    if (k != p) {
                        next = k;
                        break;
                    }
                }
                p = node;
                node = next;
                cur += cost[color[ind]][node];
                if (deg[node] == 1) {
                    break;
                }
                ++ind;
                ind %= 3;
            }
            sol = min(sol, {cur, {i, j}});
        }
    }
    cout << sol.first << "\n";

    vector<int> color{sol.second.first + 1, sol.second.second + 1, 3 - (sol.second.first + sol.second.second) + 1};
    int node = adj[root][0], p = root;
    int ind = 2;
    c[root] = color[0], c[node] = color[1];
    while (true) {
        int next;
        for (auto &k : adj[node]) {
            if (k != p) {
                next = k;
                break;
            }
        }
        p = node;
        node = next;
        c[node] = color[ind];
        if (deg[node] == 1) {
            break;
        }
        ++ind;
        ind %= 3;
    }
    for (int i = 0; i < n; ++i) {
        cout << c[i] << " ";
    }
    cout << "\n";
    return 0;
}
