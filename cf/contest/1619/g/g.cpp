/* Author: izhang
 * Time: 02-25-2022 23:31:49
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 2e5 + 5;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
struct DSU {
    int par[maxn], depth[maxn], mn[maxn];

    void init(int n) {
        for (int i = 0; i < n; ++i) {
            par[i] = i;
            depth[i] = 0;
        }
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
            mn[yroot] = min(mn[yroot], mn[xroot]);
            return true;
        }
        return false;
    }
    bool same(int x, int y) {
        return get(x) == get(y);
    }
};

void test_case() {
    int n, k;
    cin >> n >> k;
    DSU d;
    d.init(n);
    vector<pair<pair<int, int>, int>> a(n);
    map<int, set<pair<int, int>>> x, y;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first.first >> a[i].first.second >> a[i].second;
        d.mn[i] = a[i].second;
        x[a[i].first.first].insert({a[i].first.second, i});
        y[a[i].first.second].insert({a[i].first.first, i});
    }
    for (int i = 0; i < n; ++i) {
        const set<pair<int, int>> &cur_x = x[a[i].first.first];
        auto it = cur_x.lower_bound({a[i].first.second, inf});
        if (it != cur_x.end() && it->first <= a[i].first.second + k) {
            d.merge(i, it->second);
        }
        it = cur_x.lower_bound({a[i].first.second, -inf});
        if (it != cur_x.begin() && a[i].first.second <= prev(it)->first + k) {
            d.merge(i, prev(it)->second);
        }
        const set<pair<int, int>> &cur_y = y[a[i].first.second];
        it = cur_y.lower_bound({a[i].first.first, inf});
        if (it != cur_y.end() && it->first <= a[i].first.first + k) {
            d.merge(i, it->second);
        }
        it = cur_y.lower_bound({a[i].first.first, -inf});
        if (it != cur_y.begin() && a[i].first.first <= prev(it)->first + k) {
            d.merge(i, prev(it)->second);
        }
    }
    set<pair<int, int>, greater<>> comp;
    for (int i = 0; i < n; ++i) {
        comp.insert({d.mn[d.get(i)], d.get(i)});
    }
    int sol = 0;
    while (!comp.empty() && comp.begin()->first > sol) {
        comp.erase(comp.begin());
        if (comp.empty() || comp.begin()->first <= sol) {
            break;
        }
        ++sol;
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
