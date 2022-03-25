/* Author: izhang
 * Time: 03-22-2022 16:28:35
**/
#include <bits/stdc++.h>

using namespace std;

#if defined LOCAL || defined DEBUG
#include <debug.h>
#include <ostream>
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 3e5 + 5;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
const long long m1 = 1e9 + 9, p = 9973;

long long pw[maxn]; // Stores the powers of p modulo m1

void calc_pow() {
    pw[0] = 1;
    for (int i = 1; i < maxn; ++i) {
        pw[i] = (pw[i - 1] * p) % m1;
    }
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
        Node *l = 0, *r = 0;
        char val;
        int y, c = 1;
        long long hash;
        Node(char val) : val(val), y(rand()), hash(val) {}
        void recalc();
        friend ostream &operator<<(ostream &os, const Node &node);
    };

    int cnt(Node *n) { return n ? n->c : 0; }
    void Node::recalc() {
        c = cnt(l) + cnt(r) + 1;
        hash = 0;
        if (l) {
            hash = l->hash;
        }
        hash = (hash + pw[cnt(l)] * val) % m1;
        if (r) {
            hash = (hash + pw[cnt(l) + 1] * r->hash) % m1;
        }
    }
    ostream &operator<<(ostream &os, const Node &node) {
        os << "val: " << node.val << " c: " << node.c << " hash: " << node.hash;
        return os;
    }

    template<class F>
    void each(Node *n, F f) {
        if (n) {
            each(n->l, f);
            f(n);
            each(n->r, f);
        }
    }

    pair<Node *, Node *> split(Node *n, int k) {
        if (!n) return {};
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
        if (!l) return r;
        if (!r) return l;
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
        if (k <= l) t = merge(ins(a, b, k), c);
        else
            t = merge(a, ins(c, b, k - r));
    }
} // namespace kactl
using namespace kactl;

void test_case() {
    Node *treap = nullptr, *treap_rev = nullptr;
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    for (int i = 0; i < n; ++i) {
        treap = merge(treap, new Node(s[i]));
    }
    for (int i = n - 1; i >= 0; --i) {
        treap_rev = merge(treap_rev, new Node(s[i]));
    }
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int l, r;
            cin >> l >> r;
            --l;
            Node *a, *b, *c;
            tie(a, b) = split(treap, l);
            tie(b, c) = split(b, r - l);
            treap = merge(a, c);

            tie(a, b) = split(treap_rev, n - r);
            tie(b, c) = split(b, r - l);
            treap_rev = merge(a, c);
            n -= r - l;
        } else if (t == 2) {
            char c;
            int pos;
            cin >> c >> pos;
            --pos;
            treap = ins(treap, new Node(c), pos);
            treap_rev = ins(treap_rev, new Node(c), n - pos);
            ++n;
        } else if (t == 3) {
            int l, r;
            cin >> l >> r;
            --l;
            Node *a, *b, *c;
            tie(a, b) = split(treap, l);
            tie(b, c) = split(b, r - l);
            long long val = b->hash;
            treap = merge(a, merge(b, c));

            tie(a, b) = split(treap_rev, n - r);
            tie(b, c) = split(b, r - l);
            cout << (val == b->hash ? "yes" : "no") << "\n";
            treap_rev = merge(a, merge(b, c));
        }
    }
}

int main() {
    setIO("1");
    calc_pow();
    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
