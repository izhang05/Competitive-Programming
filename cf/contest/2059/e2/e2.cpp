/* Author: izhang
 * Time: 02-02-2025 10:33:01
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

struct Node {
    pair<int, int> val;
    int weight, size;
    Node *left, *right;

    Node(pair<int, int> c) : val(c), weight(rand()), size(1), left(nullptr), right(nullptr) {}
};

inline int size(Node *treap) { return treap ? treap->size : 0; }

void split(Node *treap, Node *&left, Node *&right, int val) {
    if (!treap) {
        left = right = NULL;
        return;
    }

    if (size(treap->left) < val) {
        split(treap->right, treap->right, right, val - size(treap->left) - 1);
        left = treap;
    } else {
        split(treap->left, left, treap->left, val);
        right = treap;
    }
    treap->size = 1 + size(treap->left) + size(treap->right);
}

void merge(Node *&treap, Node *left, Node *right) {
    if (left == NULL) {
        treap = right;
        return;
    }
    if (right == NULL) {
        treap = left;
        return;
    }

    if (left->weight < right->weight) {
        merge(left->right, left->right, right);
        treap = left;
    } else {
        merge(right->left, left, right->left);
        treap = right;
    }
    treap->size = 1 + size(treap->left) + size(treap->right);
}

vector<pair<int, int>> sol;

void each(Node *treap) {
    if (treap) {
        each(treap->left);
        sol.push_back(treap->val);
        each(treap->right);
    }
}

ostream &operator<<(ostream &os, Node *n) {
    if (!n) return os;
    os << n->left;
    os << n->val.first + 1 << " " << n->val.second << "\n";
    os << n->right;
    return os;
}


void test_case() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n * m);
    for (int i = 0; i < n * m; ++i) {
        cin >> a[i];
    }
    vector<int> b(n * m);
    for (int i = 0; i < n * m; ++i) {
        cin >> b[i];
    }
    Node *treap = nullptr;
    for (int i = 0; i < n * m; ++i) {
        if (b[i] == a[i - size(treap)]) {
            continue;
        } else {
            if (size(treap) < i % m) {
                int add = (i % m) - size(treap);
                for (int j = i - add; j <= i; ++j) {
                    merge(treap, treap, new Node({j / m, b[j]}));
                }
            } else {
                Node *left, *right;
                split(treap, left, right, i % m);
                merge(left, left, new Node({i / m, b[i]}));
                merge(treap, left, right);
            }
        }
    }
    cout << size(treap) << "\n";
    sol.clear();
    each(treap);
    reverse(sol.begin(), sol.end());
    for (auto &i: sol) {
        cout << i.first + 1 << " " << i.second << "\n";
    }
}

int main() {
    setIO("1");

    int test_case_number = 1;
    cin >> test_case_number;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}









///* Author: izhang
// * Time: 02-02-2025 10:33:01
//**/
//#include <bits/stdc++.h>
//
//using namespace std;
//
//#if defined LOCAL || defined DEBUG
//
//#include <debug.h>
//
//#else
//
//struct dbg {
//    template<class c>
//    dbg &operator<<(const c &) { return *this; }
//};
//
//#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
//#endif
//
////#define DEBUG
//void setIO(const string &name) {
//    ios_base::sync_with_stdio(false);
//    cin.tie(nullptr);
//    cin.exceptions(istream::failbit);
//#ifdef LOCAL
//    freopen(("in" + name + ".txt").c_str(), "r", stdin);
//    freopen("out.txt", "w", stdout);
//    freopen("out.txt", "w", stderr);
//#endif
//}
//
//const int inf = 0x3f3f3f3f, mod = 1e9 + 7; //998244353;
//const long long INFL = 0x3f3f3f3f3f3f3f3f;
//
//namespace kactl {
//#define rep(i, from, to) for (int(i) = from; (i) < (to); ++(i))
//#define all(x) x.begin(), (x).end()
//#define sz(x) (int) (x).size()
//    typedef long long ll;
//    typedef pair<int, int> pii;
//    typedef vector<int> vi;
//
//    /**
//     * Author: someone on Codeforces
//     * Date: 2017-03-14
//     * Source: folklore
//     * Description: A short self-balancing tree. It acts as a
//     *  sequential container with log-time splits/joins, and
//     *  is easy to augment with additional data.
//     * Time: $O(\log N)$
//     * Status: stress-tested
//     */
//
//    struct Node {
//        Node *l = nullptr, *r = nullptr;
//        pair<int, int> val;
//        int y, size = 1;
//
//        Node(pair<int, int> val) : val(val), y(rand()) {}
//
//        void recalc();
//    };
//
//    int cnt(Node *n) { return n ? n->size : 0; }
//
//    void Node::recalc() { size = cnt(l) + cnt(r) + 1; }
//
//    template<class F>
//    void each(Node *n, F f) {
//        if (n) {
//            each(n->l, f);
//            f(n->val);
//            each(n->r, f);
//        }
//    }
//
//    pair<Node *, Node *> split(Node *n, int k) {
//        if (!n) return {};
//        if (cnt(n->l) >= k) { // "n->val >= k" for lower_bound(k)
//            auto pa = split(n->l, k);
//            n->l = pa.second;
//            n->recalc();
//            return {pa.first, n};
//        } else {
//            auto pa = split(n->r, k - cnt(n->l) - 1); // and just "k"
//            n->r = pa.first;
//            n->recalc();
//            return {n, pa.second};
//        }
//    }
//
//    Node *merge(Node *l, Node *r) {
//        if (!l) return r;
//        if (!r) return l;
//        if (l->y > r->y) {
//            l->r = merge(l->r, r);
//            l->recalc();
//            return l;
//        } else {
//            r->l = merge(l, r->l);
//            r->recalc();
//            return r;
//        }
//    }
//
//    Node *ins(Node *t, Node *n, int pos) {
//        auto pa = split(t, pos);
//        return merge(merge(pa.first, n), pa.second);
//    }
//
//    // Example application: move the range [l, r) to index k
//    void move(Node *&t, int l, int r, int k) {
//        Node *a, *b, *c;
//        tie(a, b) = split(t, l);
//        tie(b, c) = split(b, r - l);
//        if (k <= l) t = merge(ins(a, b, k), c);
//        else t = merge(a, ins(c, b, k - r));
//    }
//
//}
//using namespace kactl;
//
//void test_case() {
//    int n, m;
//    cin >> n >> m;
//    vector<int> a(n * m);
//    for (int i = 0; i < n * m; ++i) {
//        cin >> a[i];
//    }
//    vector<int> b(n * m);
//    for (int i = 0; i < n * m; ++i) {
//        cin >> b[i];
//    }
//    Node *treap = nullptr;
//    int sol = 0;
//    for (int i = 0; i < n * m; ++i) {
//        if (b[i] == a[i - sol]) {
//            continue;
//        } else {
////            if (treap == nullptr) {
////                Node tmp = Node({i / n, b[i]});
////                treap = &tmp;
////                continue;
////            }
//            if (sol < i % m) {
//                int add = (i % m) - sol;
//                for (int j = i - add; j <= i; ++j) {
//                    Node tmp = Node({j / n, b[j]});
//                    Node *cur = &tmp;
//                    cur->recalc();
//                    treap = merge(treap, cur);
//                    ++sol;
//                }
//            } else {
//                Node tmp = Node({i / n, b[i]});
//                Node *cur = &tmp;
//                cur->recalc();
//                treap = ins(treap, cur, sol - (i % m));
//                ++sol;
//            }
//        }
//    }
//    if (treap) {
//        treap->recalc();
//    }
////    each(treap, [](pair<int, int> val) {
////        cout << val.first + 1 << " " << val.second << "\n";
////    });
//    cout << sol << " ";
//    cout << cnt(treap) << "\n";
//}
//
//int main() {
//    setIO("1");
//
//    int test_case_number = 1;
//    cin >> test_case_number;
//    while (test_case_number--) {
//        test_case();
//    }
//    return 0;
//}
