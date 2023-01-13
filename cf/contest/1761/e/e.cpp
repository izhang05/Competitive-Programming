/* Author: izhang
 * Time: 11-26-2022 16:07:14
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
//    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen(("in" + name + ".txt").c_str(), "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("out.txt", "w", stderr);
#endif
}
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 4e3 + 5;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
bool adj[maxn][maxn];
int deg[maxn];

namespace kactl {
#define rep(i, from, to) for (int(i) = from; (i) < (to); ++(i))
#define all(x) x.begin(), (x).end()
#define sz(x) (int) (x).size()
    typedef long long ll;
    typedef pair<int, int> pii;
    typedef vector<int> vi;
    /**
     * Author: Lukas Polacek
     * Date: 2009-10-26
     * License: CC0
     * Source: folklore
     * Description: Disjoint-set data structure.
     * Time: $O(\alpha(N))$
     */

    struct UF {
        vi e;
        UF(int n) : e(n, -1) {}
        bool sameSet(int a, int b) { return find(a) == find(b); }
        int size(int x) { return -e[find(x)]; }
        int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
        bool join(int a, int b) {
            a = find(a), b = find(b);
            if (a == b) return false;
            if (e[a] > e[b]) swap(a, b);
            e[a] += e[b];
            e[b] = a;
            return true;
        }
    };
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

} // namespace kactl
//using namespace kactl;

void test_case() {
    int n;
    cin >> n;
    kactl::UF dsu(n);
    bool sep = true;
    for (int i = 0; i < n; ++i) {
        deg[i] = 0;
        string s;
        cin >> s;
        for (int j = 0; j < n; ++j) {
            adj[i][j] = s[j] - '0';
            if (adj[i][j]) {
                ++deg[i];
                sep = false;
                dsu.join(i, j);
            }
        }
    }
    if (sep) {
        cout << 1 << "\n";
        cout << 1 << "\n";
        return;
    }
    map<int, vector<int>> comps;
    for (int i = 0; i < n; ++i) {
        comps[dsu.find(i)].push_back(i);
    }
    if (comps.size() == 1) {
        cout << 0 << "\n";
        return;
    }
    for (auto &i : comps) {
        int m = (int) i.second.size();
        bool bad = false;
        for (int j = 0; j < m; ++j) {
            for (int k = j + 1; k < m; ++k) {
                if (!adj[i.second[j]][i.second[k]]) {
                    bad = true;
                    break;
                }
            }
        }
        if (bad) {
            for (int j = 0; j < m; ++j) {
                kactl::UF cur(m);

            }
        }
        //                    cout << 1 << "\n";
        //                    cout << i.second[j] + 1 << "\n";
        //                    return;
    }
    if (comps.size() == 2) {
        if (comps.begin()->second.size() <= comps.rbegin()->second.size()) {
            cout << comps.begin()->second.size() << "\n";
            for (auto &i : comps.begin()->second) {
                cout << i + 1 << " ";
            }
            cout << "\n";
        } else {
            cout << comps.rbegin()->second.size() << "\n";
            for (auto &i : comps.rbegin()->second) {
                cout << i + 1 << " ";
            }
            cout << "\n";
        }
    } else {
        cout << 2 << "\n";
        cout << 1 << " ";
        for (int i = 0; i < n; ++i) {
            if (!dsu.sameSet(i, 0)) {
                cout << i + 1 << "\n";
                return;
            }
        }
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
