/* Author: izhang
 * Time: 10-15-2023 00:45:01
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

} // namespace kactl
//using namespace kactl;
const int inf = 0x3f3f3f3f, mod = 1e9 + 7; //998244353;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

void test_case() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<pair<int, int>> e(q);
    map<int, vector<int>> r, c;
    for (int i = 0; i < q; ++i) {
        cin >> e[i].first >> e[i].second;
        --e[i].first, --e[i].second;
        r[e[i].first].push_back(e[i].second);
        c[e[i].second].push_back(e[i].first);
    }
    kactl::UF col(m);
    for (auto &i : r) {
        for (int j = 1; j < (int) i.second.size(); ++j) {
            col.join(i.second[0], i.second[j]);
        }
    }
    long long sol = m - (int) c.size();
    map<int, set<int>> occ;
    set<int> comps;
    for (int i = 0; i < m; ++i) {
        comps.insert(col.find(i));
    }
    for (auto &i : c) {
        set<int> &cur = occ[col.find(i.first)];
        for (auto &j : i.second) {
            cur.insert(j);
        }
    }
    sol += (int) occ.size() - 1;
    set<int> total;
    for (auto &i : occ) {
        for (auto &j : i.second) {
            total.insert(j);
        }
    }
    sol += n - (int) total.size();
    dbg() << c.size() << " " << comps.size();

    kactl::UF row(n);
    for (auto &i : c) {
        for (int j = 1; j < (int) i.second.size(); ++j) {
            row.join(i.second[0], i.second[j]);
        }
    }
    long long sol2 = n - (int) r.size();
    occ.clear();
    comps.clear();
    for (int i = 0; i < n; ++i) {
        comps.insert(row.find(i));
    }
    for (auto &i : r) {
        set<int> &cur = occ[row.find(i.first)];
        for (auto &j : i.second) {
            cur.insert(j);
        }
    }
    sol2 += (int) occ.size() - 1;
    total.clear();
    for (auto &i : occ) {
        for (auto &j : i.second) {
            total.insert(j);
        }
    }
    sol2 += m - (int) total.size();
    dbg() << r.size() << " " << comps.size();
    cout << min(sol, sol2) << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
