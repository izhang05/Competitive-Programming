#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair <ll, ll> pll;
typedef tree<int, null_type, less < int>, rb_tree_tag, tree_order_statistics_node_update>
ordered_set;

std::mt19937_64 rng(std::chrono::system_clock::now().time_since_epoch().count());

#define Set(a, s) memset(a, s, sizeof(a))

void setPrec() { cout << fixed << setprecision(15); }

void unsyncIO() { cin.tie(0)->sync_with_stdio(0); }

void setIn(string s) { freopen(s.c_str(), "r", stdin); }

void setOut(string s) { freopen(s.c_str(), "w", stdout); }

void setIO(string s = "") {
    unsyncIO();
    setPrec();
    if (s.size()) {
        setIn(s + ".in");
        setOut(s + ".out"); // for USACO
    }
}

const int inf = 1000000007;
const ll llinf = 1000000000000000003;

const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
// const int dx[8] = { 1, 1, 1, 0, 0, -1, -1, -1}, dy[8] = { 1, 0, -1, 1, -1, 1, 0, -1};

// cross product
ll cross(ll a1, ll b1, ll a2, ll b2) { return (a1 * b2 - a2 * b1); }

ll ccw(pii a, pii b, pii c) {
    return cross(b.first - a.first, b.second - a.second, c.first - a.first, c.second - a.second);
}

// #pragma GCC optimize("Ofast")
// #pragma GCC optimization("unroll-loops")
// #pragma GCC target("avx,avx2,fma")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

const int maxd = 10;

class SegtreeNode {
public:
    vector<int> sums;
    int lazy_val;

    SegtreeNode() {
        sums = vector<int>(maxd);
        lazy_val = -1;
    }

    void update(ll val, int node_left, int node_right) {
        ll curr = node_right - node_left + 1;
        for (int i = 0; i < maxd; i++) {
            curr = curr * val % inf;
            sums[i] = curr;
        }
        lazy_val = val;
    }

    void merge(SegtreeNode x) {
        for (int i = 0; i < maxd; i++) {
            sums[i] += x.sums[i];
        }
    }

    void print() {
        for (int i = 0; i < maxd; i++) {
            cout << sums[i] << " ";
        }
        cout << endl;
    }
};

template<typename node_t>
class Segtree {
public:
    int size;
    vector <node_t> nodes;

    Segtree(int n) {
        nodes = vector<node_t>(4 * n, node_t());
        size = n;
    }

    void lazy_prop(int node, int node_left, int node_right) {
        if (nodes[node].lazy_val != -1) {
            int node_mid = node_left + (node_right - node_left) / 2;
            nodes[2 * node].update(nodes[node].lazy_val, node_left, node_mid);
            nodes[2 * node + 1].update(nodes[node].lazy_val, node_mid + 1, node_right);
            nodes[node].lazy_val = -1;
        }
    }

    void merge(int node) {
        nodes[node] = node_t();
        nodes[node].merge(nodes[2 * node]);
        nodes[node].merge(nodes[2 * node + 1]);
    }

    void _update(int node, int node_left, int node_right, int update_left, int update_right, int val) {
        if (node_left >= update_left && node_right <= update_right) {
            nodes[node].update(val, node_left, node_right);
            return;
        }
        lazy_prop(node, node_left, node_right);
        int node_mid = node_left + (node_right - node_left) / 2;
        if (update_left <= node_mid) {
            _update(2 * node, node_left, node_mid, update_left, update_right, val);
        }
        if (update_right > node_mid) {
            _update(2 * node + 1, node_mid + 1, node_right, update_left, update_right, val);
        }
        merge(node);
    }

    void update(int update_left, int update_right, int val) { _update(1, 0, size - 1, update_left, update_right, val); }

    node_t _query(int node, int node_left, int node_right, int query_left, int query_right) {
        if (node_left >= query_left && node_right <= query_right) {
            return nodes[node];
        }
        lazy_prop(node, node_left, node_right);
        int node_mid = node_left + (node_right - node_left) / 2;
        node_t res = node_t();
        if (query_left <= node_mid) {
            res.merge(_query(2 * node, node_left, node_mid, query_left, query_right));
        }
        if (query_right > node_mid) {
            res.merge(_query(2 * node + 1, node_mid + 1, node_right, query_left, query_right));
        }
        return res;
    }

    node_t query(int query_left, int query_right) { return _query(1, 0, size - 1, query_left, query_right); }

    void debug() {
        cout << "SEGTREE:\n";
        for (int i = 0; i < size; i++) {
            query(i, i).print();
        }
        cout << "---------\n";
    }
};

int n;
Segtree<SegtreeNode> segtree(0);
vector <vector<int>> queries;
vector<int> ans;

vector <vector<int>> adj;

void dfs(int query) {
    if (query != 0) {
        if (queries[query - 1][0] == 1) {
            segtree.update(queries[query - 1][2], queries[query - 1][3], queries[query - 1][4]);
        }
        ans[query - 1] = segtree.query(0, n - 1).sums[queries[query - 1][1]];
    }
    // cout << query << endl;
    // segtree.debug();
    for (int i: adj[query]) {
        dfs(i);
    }
};

int main() {
    setIO();
    int q;
    cin >> n >> q;
    adj.resize(q + 1);
    for (int i = 0; i < q; i++) {
        int type, d;
        cin >> type >> d;
        d--;
        if (type == 1) {
            int l, r, x;
            cin >> l >> r >> x;
            l--;
            r--;
            queries.push_back({type, d, l, r, x});
            adj[i].push_back(i + 1);
        } else {
            int x;
            cin >> x;
            queries.push_back({type, d, x});
            adj[x].push_back(i + 1);
        }
    }
    ans.resize(q);
    segtree = Segtree<SegtreeNode>(n);
    dfs(0);
    for (int i = 0; i < q; i++) {
        cout << ans[i] << endl;
    }
    return 0;
}