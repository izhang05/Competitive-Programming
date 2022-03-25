/* Author: izhang
 * Time: 03-22-2022 16:28:35
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7; //998244353;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
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
        int val, y, size = 1;
        bool l_flip = false, l_set = false;
        Node(int val) : val(val), y(rand()) {}
        void recalc(), prop(Node *);
    };

    int cnt(Node *n) { return n ? n->size : 0; }
    void Node::prop(Node *n) {
        if (l) {

        }
        if (r) {

        }
    }
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
    int n, q;
    cin >> n >> q;
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
