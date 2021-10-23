/* Author: izhang05
 * Time: 10-10-2021 19:46:29
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e5 + 5;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
struct edge {
    int to, a, b;
};

struct Line {
    mutable long long k, m, p;
    bool operator<(const Line &o) const { return k < o.k; }
    bool operator<(long long x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
    // (for doubles, use inf = 1/.0, div(a,b) = a/b)
    static const long long inf = LLONG_MAX;
    long long div(long long a, long long b) { // floored division
        return a / b - ((a ^ b) < 0 && a % b);
    }
    bool isect(iterator x, iterator y) {
        if (y == end()) return x->p = inf, 0;
        if (x->k == y->k) {
            x->p = x->m > y->m ? inf : -inf;
        } else {
            x->p = div(y->m - x->m, x->k - y->k);
        }
        return x->p >= y->p;
    }
    void add(long long k, long long m) {
        auto z = insert({k, m, 0}), y = z++, x = y;
        while (isect(y, z)) {
            z = erase(z);
        }
        if (x != begin() && isect(--x, y)) {
            isect(x, y = erase(y));
        }
        while ((y = x) != begin() && (--x)->p >= y->p) {
            isect(x, erase(y));
        }
    }
    long long query(long long x) {
        assert(!empty());
        auto l = *lower_bound(x);
        return l.k * x + l.m;
    }
};

LineContainer total;

void convexsum(LineContainer &a, LineContainer &b) {
    auto it1 = a.begin(), it2 = b.begin();
    while (it1 != a.end() && it2 != b.end()) {
        total.add((it1->k) + (it2->k), (it1->m) + (it2->m));
        if ((it1->p) < (it2->p)) {
            it1++;
        } else {
            it2++;
        }
    }
}

void merge_all(int l, int r, vector<LineContainer> &paths) {
    if (l >= r) {
        return;
    }
    int mid = (l + r) / 2;
    merge_all(l, mid, paths);
    merge_all(mid + 1, r, paths);

    convexsum(paths[l], paths[mid + 1]);
    for (auto it : paths[mid + 1]) {
        paths[l].add(it.k, it.m);
    }
}

vector<edge> adj[maxn];

long long sol;
int sub[maxn];
bool vis[maxn];

int find_size(int v, int p) {
    sub[v] = 1;
    for (auto &i : adj[v]) {
        if (i.to != p && !vis[i.to]) {
            sub[v] += find_size(i.to, v);
        }
    }
    return sub[v];
}

int centroid(int v, int p, int s) {
    for (auto &i : adj[v]) {
        if (i.to != p && !vis[i.to] && sub[i.to] > s / 2) {
            return centroid(i.to, v, s);
        }
    }
    return v;
}

LineContainer cur;

void dfs(int c, int p, long long m, long long b) {
    if (adj[c].size() == 1) {
        cur.add(m, b);
    }
    for (auto &i : adj[c]) {
        if (i.to != p && !vis[i.to]) {
            dfs(i.to, c, m + i.a, b + i.b);
        }
    }
}

void solve(int v) {
    find_size(v, -1);
    int c = centroid(v, -1, sub[v]);
    vis[c] = true;
    vector<LineContainer> paths;
    for (auto &i : adj[c]) {
        if (!vis[i.to]) {
            cur = LineContainer{};
            dfs(i.to, c, i.a, i.b);
            paths.push_back(cur);
        }
    }
    if (int(paths.size() == 1)) {
        for (auto &i : paths[0]) {
            total.add(i.k, i.m);
        }
    }
    merge_all(0, int(paths.size()) - 1, paths);
    for (auto &i : adj[c]) {
        if (!vis[i.to]) {
            solve(i.to);
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n - 1; ++i) {
        int u, v, a, b;
        cin >> u >> v >> a >> b;
        --u, --v;
        adj[u].push_back({v, a, b});
        adj[v].push_back({u, a, b});
    }
    solve(0);
    total.add(0, 0); // for n = 1 case
    for (int i = 0; i < m; ++i) {
        cout << total.query(i) << " \n"[i == m - 1];
    }
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        solve();
    }
    return 0;
}
