/* Author: izhang05
 * Time: 07-08-2021 14:15:02
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 5e3 + 5;
vector<pair<int, int>> adj[maxn];
int depth[maxn], color[maxn], state[maxn];
bool cycle = false;

void dfs(int c, int d) {
    state[c] = 1;
    depth[c] = d;
    for (auto &i : adj[c]) {
        if (!state[i.first]) {
            color[i.second] = 1;
            dfs(i.first, d + 1);
        } else {
            if (state[i.first] == 1) {
                color[i.second] = 2;
                cycle = true;
            } else {
                color[i.second] = 1;
            }
        }
    }
    state[c] = 2;
}

int main() {
    setIO("1");

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].emplace_back(b, i);
    }
    for (int i = 0; i < n; ++i) {
        if (!state[i]) {
            dfs(i, 0);
        }
    }
    if (cycle) {
        cout << 2 << "\n";
    } else {
        cout << 1 << "\n";
    }
    for (int i = 0; i < m; ++i) {
        cout << color[i] << " \n"[i == m - 1];
    }
    return 0;
}
