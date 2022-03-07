/* Author: izhang
 * Time: 03-03-2022 15:58:10
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 55;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
struct dsu {
    int par[maxn]{}, depth[maxn]{};

    dsu(int n) {
        for (int i = 0; i < n; ++i) {
            par[i] = i;
            depth[i] = 1;
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
            return true;
        }
        return false;
    }

    bool same(int x, int y) {
        return get(x) == get(y);
    }
};
struct edge {
    int u, v, w;
    bool operator==(const edge &o) const {
        return u == o.u && v == o.v && w == o.w;
    }
    bool operator!=(const edge &o) const {
        return u != o.u || v != o.v || w != o.w;
    }
    friend ostream &operator<<(ostream &os, const edge &edge) {
        os << "u: " << edge.u << " v: " << edge.v << " w: " << edge.w;
        return os;
    }
};

int n;
vector<edge> edges;
pair<long long, long long> kruskal(int x) {
    dsu d(n);
    sort(edges.begin(), edges.end(), [x](auto left, auto right) {
        return abs(left.w - x) == abs(right.w - x) ? tie(left.u, left.v) < tie(right.u, right.v) : abs(left.w - x) < abs(right.w - x);
    });
    pair<long long, long long> cur;
    for (auto &i : edges) {
        if (d.merge(i.u, i.v)) {
            cur.first += abs(i.w - x);
            if (i.w <= x) {
                ++cur.second;
            } else {
                --cur.second;
            }
        }
    }
    return cur;
}

void test_case() {
    int m;
    cin >> n >> m;
    edges.resize(m);
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        --a, --b;
        edges[i] = {a, b, c};
    }

    map<int, pair<long long, long long>> change;
    change[0] = kruskal(0);
    vector<edge> pre(edges.begin(), edges.end());
    int lo = 0, hi, mid, res;
    while (lo < 1e8 + 5) {
        dbg() << lo;
        ++lo;
        hi = 1e8 + 5;
        res = -1;
        while (lo <= hi) {
            mid = (lo + hi) / 2;
            sort(edges.begin(), edges.end(), [mid](auto left, auto right) {
                return abs(left.w - mid) == abs(right.w - mid) ? tie(left.u, left.v) < tie(right.u, right.v) : abs(left.w - mid) < abs(right.w - mid);
            });
            if (pre != edges) {
                res = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        if (res != -1) {
            change[res] = kruskal(res);
            swap(edges, pre);
        }
    }
    vector<int> weights;
    for (auto &i : edges) {
        weights.push_back(i.w);
    }
    for (auto &i : weights) {
        change[i] = kruskal(i);
    }
    dbg() << change;
    dbg() << kruskal(0);

    int p, k, a, b, c;
    cin >> p >> k >> a >> b >> c;
    vector<int> q(k);
    for (int i = 0; i < p; ++i) {
        cin >> q[i];
    }
    for (int i = p; i < k; ++i) {
        q[i] = int((q[i - 1] * (long long) a + b) % c);
    }
    sort(q.begin(), q.end());
    long long sol = 0;
    vector<pair<long long, pair<long long, long long>>> cha(change.begin(), change.end());
    dbg() << cha;
    int j = 0;
    for (int i = 0; i < k; ++i) {
        while (j + 1 < int(cha.size()) && cha[j + 1].first <= q[i]) {
            ++j;
        }
        sol ^= cha[j].second.first + cha[j].second.second * (q[i] - cha[j].first);
    }
    cout << sol << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
