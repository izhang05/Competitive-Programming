/* Author: izhang
 * Time: 04-17-2023 09:54:41
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, mxn = 1e5 + 5;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
long long sz[mxn], imp[mxn], a[mxn], par[mxn];
vector<int> adj[mxn];
set<pair<long long, int>, greater<>> child[mxn];

void dfs0(int c, int p) {
    sz[c] = 1;
    imp[c] = a[c];
    par[c] = p;
    for (auto &i : adj[c]) {
        if (i != p) {
            dfs0(i, c);
            sz[c] += sz[i];
            imp[c] += imp[i];
            child[c].emplace(sz[i], -i);
        }
    }
}

void test_case() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        int node1, node2;
        cin >> node1 >> node2;
        --node1, --node2;
        adj[node1].push_back(node2);
        adj[node2].push_back(node1);
    }
    dfs0(0, -1);
    while (m--) {
        int t, x;
        cin >> t >> x;
        --x;
        if (t == 1) {
            cout << imp[x] << "\n";
        } else {
            if (child[x].empty()) {
                continue;
            }
            long long c = -child[x].begin()->second, pre_imp = imp[c], pre_sz = sz[c], p = par[x];
            child[x].erase({sz[c], -c});
            child[p].erase({sz[x], -x});
            imp[c] = imp[x];
            sz[c] = sz[x];
            imp[x] -= pre_imp;
            sz[x] -= pre_sz;
            child[c].insert({sz[x], -x});
            child[p].insert({sz[c], -c});
        }
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
