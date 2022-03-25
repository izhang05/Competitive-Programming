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
        Node *l = nullptr, *r = nullptr, *p = nullptr;
        int val, y, size = 1, ind;
        long long sum;
        Node(int val, int ind) : val(val), y(rand()), ind(ind), sum(val) {}
        void recalc();
    };

    int cnt(Node *n) { return n ? n->size : 0; }
    void set_par(Node *n, Node *p) {
        if (n) {
            n->p = p;
        }
    }
    void Node::recalc() {
        size = cnt(l) + cnt(r) + 1;
        sum = val;
        if (l) {
            sum += l->sum;
        }
        if (r) {
            sum += r->sum;
        }
    }

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
            set_par(n->l, nullptr);
            auto pa = split(n->l, k);
            n->l = pa.second;
            set_par(n->l, n);
            n->recalc();
            return {pa.first, n};
        } else {
            set_par(n->r, nullptr);
            auto pa = split(n->r, k - cnt(n->l) - 1); // and just "k"
            n->r = pa.first;
            set_par(n->r, n);
            n->recalc();
            return {n, pa.second};
        }
    }

    Node *merge(Node *l, Node *r) {
        if (!l) return r;
        if (!r) return l;
        if (l->y > r->y) {
            l->r = merge(l->r, r);
            set_par(l->r, l);
            l->recalc();
            return l;
        } else {
            r->l = merge(l, r->l);
            set_par(r->l, r);
            r->recalc();
            return r;
        }
    }

    Node *ins(Node *t, Node *n, int pos) {
        auto pa = split(t, pos);
        return merge(merge(pa.first, n), pa.second);
    }

    Node *get_par(const Node *n) {
        while (n->p) {
            n = n->p;
        }
        return const_cast<Node *>(n);
    }
} // namespace kactl
using namespace kactl;

void test_case() {
    int q;
    cin >> q;
    vector<Node *> nodes(q);
    for (int ind = 0; ind < q; ++ind) {
        int t;
        cin >> t;
        if (t == 1) {
            int val;
            cin >> val;
            nodes[ind] = new Node(val, ind);
        } else if (t == 2) {
            int y, z;
            cin >> y >> z;
            --y, --z;
            if (get_par(nodes[y]) != get_par(nodes[z])) {
                nodes[get_par(nodes[y])->ind] = merge(get_par(nodes[y]), get_par(nodes[z]));
            }
        } else if (t == 3) {
            int y, z;
            cin >> y >> z;
            --y;
            if (get_par(nodes[y])->size > z) {
                Node *a, *b;
                tie(a, b) = split(get_par(nodes[y]), z);
                if (a) {
                    nodes[a->ind] = a;
                }
                if (b) {
                    nodes[b->ind] = b;
                }
            }
        } else if (t == 4) {
            int y;
            cin >> y;
            --y;
            cout << get_par(nodes[y])->sum << "\n";
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
