/* Author: izhang
 * Time: 01-10-2022 10:58:13
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 2e5 + 5, maxs = 32;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
vector<pair<long long, pair<int, int>>> edges;

struct dsu {
    int par[maxn], depth[maxn], comps;
    void init(int n) {
        for (int i = 0; i < n; ++i) {
            par[i] = i;
            depth[i] = 1;
        }
        comps = n;
    }
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
            --comps;
            return true;
        }
        return false;
    }

    bool same(int x, int y) {
        return get(x) == get(y);
    }
};

void test_case() {
    int n, m;
    cin >> n >> m;
    edges.clear();
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        --a, --b;
        edges.emplace_back(c, make_pair(a, b));
    }
    long long sol = 0, cur = 0;
    for (int i = 0; i < maxs - 1; ++i) {
        cur |= 1ll << i;
    }
    dsu d{};
    for (int i = maxs - 1; i >= 0; --i) {
        cur ^= 1ll << i;
        d.init(n);
        for (auto &j : edges) {
            if ((j.first | cur) == cur) {
                d.merge(j.second.first, j.second.second);
            }
        }
        if (d.comps != 1) {
            cur ^= 1ll << i;
            sol ^= 1ll << i;
        }
    }
    cout << sol << "\n";
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
