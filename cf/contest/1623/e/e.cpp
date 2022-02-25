/* Author: izhang
 * Time: 01-12-2022 13:16:51
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
namespace kactl {
#define rep(i, from, to) for (int(i) = from; (i) < (to); ++(i))
#define all(x) x.begin(), (x).end()
#define sz(x) (int) (x).size()
    typedef long long ll;
    typedef pair<int, int> pii;
    typedef vector<int> vi;

    /**
     * Author: Simon Lindholm
     * Date: 2016-10-08
     * License: CC0
     * Source: me
     * Description: Segment tree with ability to add or set values of large intervals, and compute max of intervals.
     * Can be changed to other things.
     * Use with a bump allocator for better performance, and SmallPtr or implicit indices to save memory.
     * Time: O(\log N).
     * Usage: Node* tr = new Node(v, 0, sz(v));
     * Status: stress-tested a bit
     */

    const long long inf = 1e18;
    struct Node {
        Node *l = 0, *r = 0;
        long long lo, hi, mset = inf, madd = 0, val = 0;
        Node(int lo, int hi) : lo(lo), hi(hi) {} // Large interval of -inf
        Node(vi &v, int lo, int hi) : lo(lo), hi(hi) {
            if (lo + 1 < hi) {
                int mid = lo + (hi - lo) / 2;
                l = new Node(v, lo, mid);
                r = new Node(v, mid, hi);
                val = l->val + r->val;
            } else
                val = v[lo];
        }
        long long query(int L, int R) {
            if (R <= lo || hi <= L) return 0;
            if (L <= lo && hi <= R) return val;
            push();
            return l->query(L, R) + r->query(L, R);
        }
        void set(int L, int R, int x) {
            if (R <= lo || hi <= L) return;
            if (L <= lo && hi <= R) mset = x, val = (hi - lo) * x, madd = 0;
            else {
                push(), l->set(L, R, x), r->set(L, R, x);
                val = l->val + r->val;
            }
        }
        void add(int L, int R, int x) {
            if (R <= lo || hi <= L) return;
            if (L <= lo && hi <= R) {
                if (mset != inf) mset += x;
                else
                    madd += x;
                val += x;
            } else {
                push(), l->add(L, R, x), r->add(L, R, x);
                val = l->val + r->val;
            }
        }
        void push() {
            if (!l) {
                int mid = lo + (hi - lo) / 2;
                l = new Node(lo, mid);
                r = new Node(mid, hi);
            }
            if (mset != inf)
                l->set(lo, hi, mset), r->set(lo, hi, mset), mset = inf;
            else if (madd)
                l->add(lo, hi, madd), r->add(lo, hi, madd), madd = 0;
        }
    };

    /**
     * Author: Benjamin Qi, Oleksandr Kulkov, chilli
     * Date: 2020-01-12
     * License: CC0
     * Source: https://codeforces.com/blog/entry/53170, https://github.com/bqi343/USACO/blob/master/Implementations/content/graphs%20(12)/Trees%20(10)/HLD%20(10.3).h
     * Description: Decomposes a tree into vertex disjoint heavy paths and light
     * edges such that the path from any leaf to the root contains at most log(n)
     * light edges. Code does additive modifications and max queries, but can
     * support commutative segtree modifications/queries on paths and subtrees.
     * Takes as input the full adjacency list. VALS\_EDGES being true means that
     * values are stored in the edges, as opposed to the nodes. All values
     * initialized to the segtree default. Root must be 0.
     * Time: O((\log N)^2)
     * Status: stress-tested against old HLD
     */

    template<bool VALS_EDGES>
    struct HLD {
        int N, tim = 0;
        vector<vi> adj;
        vi par, siz, depth, rt, pos;
        Node *tree;
        HLD(vector<vi> adj_)
            : N(sz(adj_)), adj(adj_), par(N, -1), siz(N, 1), depth(N),
              rt(N), pos(N), tree(new Node(0, N)) {
            dfsSz(0);
            dfsHld(0);
        }
        void dfsSz(int v) {
            if (par[v] != -1) adj[v].erase(find(all(adj[v]), par[v]));
            for (int &u : adj[v]) {
                par[u] = v, depth[u] = depth[v] + 1;
                dfsSz(u);
                siz[v] += siz[u];
                if (siz[u] > siz[adj[v][0]]) swap(u, adj[v][0]);
            }
        }
        void dfsHld(int v) {
            pos[v] = tim++;
            for (int u : adj[v]) {
                rt[u] = (u == adj[v][0] ? rt[v] : u);
                dfsHld(u);
            }
        }
        template<class B>
        void process(int u, int v, B op) {
            for (; rt[u] != rt[v]; v = par[rt[v]]) {
                if (depth[rt[u]] > depth[rt[v]]) swap(u, v);
                op(pos[rt[v]], pos[v] + 1);
            }
            if (depth[u] > depth[v]) swap(u, v);
            op(pos[u] + VALS_EDGES, pos[v] + 1);
        }
        void modifyPath(int u, int v, int val) {
            process(u, v, [&](int l, int r) { tree->set(l, r, val); });
        }
        long long queryPath(int u, int v) { // Modify depending on problem
            long long res = 0;
            process(u, v, [&](int l, int r) {
                res += tree->query(l, r);
            });
            return res;
        }
        long long querySubtree(int v) { // modifySubtree is similar
            return tree->query(pos[v] + VALS_EDGES, pos[v] + siz[v]);
        }
    };
    /**
     * Author: Lukas Polacek
     * Date: 2009-10-30
     * License: CC0
     * Source: folklore/TopCoder
     * Description: Computes partial sums a[0] + a[1] + ... + a[pos - 1], and updates single elements a[i],
     * taking the difference between the old and new value.
     * Time: Both operations are $O(\log N)$.
     * Status: Stress-tested
     */

    struct FT {
        vector<ll> s;
        FT(int n) : s(n) {}
        void update(int pos, ll dif) { // a[pos] += dif
            for (; pos < sz(s); pos |= pos + 1) s[pos] += dif;
        }
        ll query(int pos) { // sum of values in [0, pos)
            ll res = 0;
            for (; pos > 0; pos &= pos - 1) res += s[pos - 1];
            return res;
        }
        int lower_bound(ll sum) { // min pos st sum of [0, pos] >= sum
            // Returns n if no sum is >= sum, or -1 if empty sum is.
            if (sum <= 0) return -1;
            int pos = 0;
            for (int pw = 1 << 25; pw; pw >>= 1) {
                if (pos + pw <= sz(s) && s[pos + pw - 1] < sum)
                    pos += pw, sum -= s[pos - 1];
            }
            return pos;
        }
    };

} // namespace kactl
//using namespace kactl;
int l[maxn], r[maxn];
bool good[maxn], take[maxn];
vector<int> order;
string s;
int depth[maxn];
int t, tin[maxn], tout[maxn];

void dfs(int c) {
    if (l[c] != -1) {
        dfs(l[c]);
    }
    order.push_back(c);
    if (r[c] != -1) {
        dfs(r[c]);
    }
}
vector<vector<int>> adj;
void dfs1(int c, int p, int d) {
    tin[c] = t++;
    depth[c] = d;
    for (auto &i : adj[c]) {
        if (i != p) {
            dfs1(i, c, d + 1);
        }
    }
    tout[c] = t;
}

void test_case() {
    int n, k;
    cin >> n >> k >> s;
    for (int i = 0; i < n; ++i) {
        cin >> l[i] >> r[i];
        --l[i], --r[i];
    }
    dfs(0);
    vector<int> ind(n);
    for (int i = 0; i < n; ++i) {
        ind[order[i]] = i;
    }
    int root = ind[0];
    adj.resize(n);
    for (int i = 0; i < n; ++i) {
        if (l[order[i]] != -1) {
            adj[i].push_back(ind[l[order[i]]]);
            adj[ind[l[order[i]]]].push_back(i);
        }
        if (r[order[i]] != -1) {
            adj[i].push_back(ind[r[order[i]]]);
            adj[ind[r[order[i]]]].push_back(i);
        }
    }
    dfs1(root, -1, 0);
    string new_s;
    for (int i = 0; i < n; ++i) {
        new_s.push_back(0);
    }
    for (int i = 0; i < n; ++i) {
        new_s[i] = s[order[i]];
    }
    swap(new_s, s);
    for (int i = n - 1; i >= 0; --i) {
        if (s[i] < s[i + 1] || (s[i] == s[i + 1] && good[i + 1])) {
            good[i] = true;
        }
    }
    kactl::HLD<false> h(adj);
    kactl::FT f(n + 1);
    for (int i = 0; i < n; ++i) {
        if (good[i]) {
            if (f.query(tin[i] + 1) != 0) {
                continue;
            }
            int require = depth[i] + 1 - h.queryPath(root, i);
            if (require <= k) {
                h.modifyPath(root, i, 1);
                k -= require;
            }
        } else if (!h.queryPath(i, i)) {
            f.update(tin[i], 1);
            f.update(tout[i], -1);
        }
    }
    int cnt = 0;
    string sol;
    for (int i = 0; i < n; ++i) {
        sol += s[i];
        if (h.queryPath(i, i)) {
            ++cnt;
            sol += s[i];
        }
    }
    cout << sol << "\n";
}

int main() {
    setIO("5");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
