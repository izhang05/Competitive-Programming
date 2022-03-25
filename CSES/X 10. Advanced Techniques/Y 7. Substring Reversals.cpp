#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
    freopen((name + ".out").c_str(), "w", stderr);
#endif
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

long long rnd(long long l, long long r) {
    return uniform_int_distribution<long long>(l, r)(rng);
}
namespace kactl {
#define rep(i, from, to) for (int(i) = from; (i) < (to); ++(i))
#define all(x) x.begin(), (x).end()
#define sz(x) (int) (x).size()
    typedef long long ll;
    typedef pair<int, int> pii;
    typedef vector<int> vi;
    /**
     * Author: someone on Codeforces
     * Date: 2017-03-14
     * Source: folklore
     * Description: A short self-balancing tree. It acts as a
     *  sequential container with log-time splits/joins, and
     *  is easy to augment with additional data.
     * Time: $O(\log N)$
     * Status: stress-tested
     */

    struct Node {
        Node *l = nullptr, *r = nullptr;
        char val;
        int y, size = 1;
        Node(char val) : val(val), y(rng()) {}
        void recalc();
    };

    int cnt(Node *n) { return n ? n->size : 0; }
    void Node::recalc() { size = cnt(l) + cnt(r) + 1; }

    template<class F>
    void each(Node *n, F f) {
        if (n) {
            each(n->l, f);
            f(n->val);
            each(n->r, f);
        }
    }

    pair<Node *, Node *> split(Node *n, int k) {
        if (!n)
            return {};
        if (cnt(n->l) >= k) { // "n->val >= k" for lower_bound(k)
            auto pa = split(n->l, k);
            n->l = pa.second;
            n->recalc();
            return {pa.first, n};
        } else {
            auto pa = split(n->r, k - cnt(n->l) - 1); // and just "k"
            n->r = pa.first;
            n->recalc();
            return {n, pa.second};
        }
    }

    Node *merge(Node *l, Node *r) {
        if (!l)
            return r;
        if (!r)
            return l;
        if (l->y > r->y) {
            l->r = merge(l->r, r);
            l->recalc();
            return l;
        } else {
            r->l = merge(l, r->l);
            r->recalc();
            return r;
        }
    }

    Node *ins(Node *t, Node *n, int pos) {
        auto pa = split(t, pos);
        return merge(merge(pa.first, n), pa.second);
    }

    // Example application: move the range [l, r) to index k
    void move(Node *&t, int l, int r, int k) {
        Node *a, *b, *c;
        tie(a, b) = split(t, l);
        tie(b, c) = split(b, r - l);
        if (k <= l)
            t = merge(ins(a, b, k), c);
        else
            t = merge(a, ins(c, b, k - r));
    }

} // namespace kactl
using namespace kactl;
const int inf = 0x3f3f3f3f, mod = 1e9 + 7;

int main() {
    setIO("7");
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    Node *treap = nullptr, *treap_rev = nullptr;
    for (int i = 0; i < n; ++i) {
        treap = merge(treap, new Node(s[i]));
        treap_rev = merge(treap_rev, new Node(s[n - i - 1]));
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        --l;
        Node *a, *b, *c, *d, *e, *f;
        tie(a, b) = split(treap, l);
        tie(b, c) = split(b, r - l);
        tie(d, e) = split(treap_rev, n - r);
        tie(e, f) = split(e, r - l);

        treap = merge(merge(a, e), c);
        treap_rev = merge(merge(d, b), f);
    }
    each(treap, [](char val) {
        cout << val;
    });
    cout << "\n";
    return 0;
}
