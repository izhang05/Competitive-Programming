/* Author: izhang05
 * Time: 08-15-2021 10:35:03
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
const long long INFL = 0x3f3f3f3f3f3f3f3f;

struct forest {
    int m{};
    vector<int> adj[maxn];
    int par[maxn], depth[maxn];

    int get(int x) {
        return par[x] == x ? x : par[x] = get(par[x]);
    }

    bool merge(int x, int y) {
        int xroot = get(x), yroot = get(y);
        if (depth[xroot] > depth[yroot]) {
            swap(xroot, yroot);
        }
        if (xroot != yroot) {
            par[xroot] = yroot;
            depth[yroot] = max(depth[yroot], depth[xroot] + 1);
            return true;
        }
        return false;
    }

    bool same(int x, int y) {
        return get(x) == get(y);
    }
};

void solve() {
    int n;
    cin >> n;
    forest a, b;
    cin >> a.m >> b.m;
    for (int i = 0; i < n; ++i) {
        a.par[i] = i;
        b.par[i] = i;
    }
    for (int i = 0; i < a.m; ++i) {
        int c, d;
        cin >> c >> d;
        --c, --d;
        a.merge(c, d);
        a.adj[c].push_back(d);
        a.adj[d].push_back(c);
    }
    for (int i = 0; i < b.m; ++i) {
        int c, d;
        cin >> c >> d;
        --c, --d;
        b.merge(c, d);
        b.adj[c].push_back(d);
        b.adj[d].push_back(c);
    }
    vector<pair<int, int>> sol;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (!a.same(i, j) && !b.same(i, j)) {
                a.merge(i, j);
                b.merge(i, j);
                sol.emplace_back(i + 1, j + 1);
            }
        }
    }
    cout << sol.size() << "\n";
    for (auto &i : sol) {
        cout << i.first << " " << i.second << "\n";
    }
}

int main() {
    setIO("1");

    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
