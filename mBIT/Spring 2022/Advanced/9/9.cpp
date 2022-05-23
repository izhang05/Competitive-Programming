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

namespace kactl {
#define rep(i, from, to) for (int(i) = from; (i) < (to); ++(i))
#define all(x) x.begin(), (x).end()
#define sz(x) (int) (x).size()
    typedef long long ll;
    typedef pair<int, int> pii;
    typedef vector<int> vi;
    /**
     * Author: Lukas Polacek, Simon Lindholm
     * Date: 2019-12-26
     * License: CC0
     * Source: folklore
     * Description: Disjoint-set data structure with undo.
     * If undo is not needed, skip st, time() and rollback().
     * Usage: int t = uf.time(); ...; uf.rollback(t);
     * Time: $O(\log(N))$
     * Status: tested as part of DirectedMST.h
     */

    struct RollbackUF {
        vi e;
        vector<pii> st;
        RollbackUF(int n) : e(n, -1) {}
        int size(int x) { return -e[find(x)]; }
        int find(int x) { return e[x] < 0 ? x : find(e[x]); }
        int time() { return sz(st); }
        void rollback(int t) {
            for (int i = time(); i-- > t;)
                e[st[i].first] = st[i].second;
            st.resize(t);
        }
        bool join(int a, int b) {
            a = find(a), b = find(b);
            if (a == b) return false;
            if (e[a] > e[b]) swap(a, b);
            st.push_back({a, e[a]});
            st.push_back({b, e[b]});
            e[a] += e[b];
            e[b] = a;
            return true;
        }
    };

}// namespace kactl
//using namespace kactl;

const int inf = 0x3f3f3f3f, mod = 1e9 + 7;//998244353;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

void test_case() {
    int n, k;
    cin >> n >> k;
    vector<int> x(n), sol(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }
    int t;
    cin >> t;
    multiset<int> l;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        l.insert(a);
    }
    for (int i = 0; i < n; ++i) {
        if (l.find(x[i] - t) != l.end()) {
            sol[i] = -1;
            l.erase(l.find(x[i] - t));
        } else if (l.find(x[i] + t) != l.end()) {
            sol[i] = 1;
            l.erase(l.find(x[i] + t));
        } else {
            dbg() << "bad " << 0 << " " << i;
            cout << 0 << "\n";
            return;
        }
    }
    for (int i = 0; i < k - 1; ++i) {
        cin >> t;
        for (int j = 0; j < n; ++j) {
            int a;
            cin >> a;
            l.insert(a);
        }
        for (int j = 0; j < n; ++j) {
            auto it = l.find(x[j] + sol[j] * t);
            if (it == l.end()) {
                dbg() << "bad " << i + 1 << " " << j;
                cout << 0 << "\n";
                return;
            }
            l.erase(it);
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << sol[i] << " \n"[i == n - 1];
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
