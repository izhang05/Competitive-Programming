/* Author: izhang
 * Time: 09-09-2023 03:55:45
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

const int mxn = 2e5 + 5;

int par[mxn], sz[mxn];
set<int> que[mxn];

int get(int x) {
    return par[x] == x ? x : get(par[x]);
}

vector<int> merge(int x, int y) {
    int xroot = get(x), yroot = get(y);
    if (sz[xroot] > sz[yroot]) {
        swap(xroot, yroot);
    }
    // sz[yroot] >= sz[xroot]
    vector<int> res;
    if (xroot != yroot) {
        for (auto &i: que[xroot]) {
            if (que[yroot].find(i) != que[yroot].end()) {
                res.push_back(i);
            }
            que[yroot].insert(i);
        }
        par[xroot] = yroot;
        sz[yroot] += sz[xroot];
    }
    return res;
}

bool same(int x, int y) {
    return get(x) == get(y);
}

//using namespace kactl;
const int inf = 0x3f3f3f3f, mod = 1e9 + 7; //998244353;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

void test_case() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<pair<int, pair<int, int>>> edges(m);
    for (int i = 0; i < n; ++i) {
        par[i] = i, sz[i] = 1;
    }
    for (int i = 0; i < m; ++i) {
        int u, v, t;
        cin >> u >> v >> t;
        --u, --v;
        edges[i] = {t, {u, v}};
    }
    sort(edges.begin(), edges.end());
    vector<pair<int, int>> sol(q), queries(q);
    for (int i = 0; i < q; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        queries[i] = {a, b};
        que[a].insert(i);
        que[b].insert(i);
    }
    int pre = -1;
    vector<int> process;
    for (auto &i: edges) {
        dbg() << i.first << " " << process;
        if (i.first != pre) {
            for (auto &j: process) {
                sol[j].first = pre;
                sol[j].second = sz[get(queries[j].first)];
            }
            process.clear();
        }
        int a = i.second.first, b = i.second.second;
        if (!same(a, b)) {
            for (auto &j: merge(a, b)) {
                process.push_back(j);
            }
        }
        pre = i.first;
    }
    for (auto &j: process) {
        sol[j].first = pre;
        sol[j].second = sz[get(j)];
    }
    for (auto &i: sol) {
        cout << i.first << " " << i.second << "\n";
    }

}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
