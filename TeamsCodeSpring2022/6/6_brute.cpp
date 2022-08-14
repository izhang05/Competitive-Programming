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

}
//using namespace kactl;

void test_case() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<pair<int, pair<int, int>>> edges;

    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        --a, --b;
        edges.push_back({c, {a, b}});
    }
    sort(edges.begin(), edges.end());

    vector<int> cur;
    for (int i = 0; i < q; ++i) {
        int que;
        cin >> que;
        --que;
        cur.push_back(que);
        kactl::UF dsu(n);
        int patience = 0;
        bool good = false;
        for (int j = 0; j < int(edges.size()) && !good; ++j) {
            patience = edges[j].first;
            dsu.join(edges[j].second.first, edges[j].second.second);
            for (int k = 0; k < int(cur.size()) && !good; ++k) {
                for (int l = k + 1; l < int(cur.size()); ++l) {
                    if (dsu.sameSet(cur[k], cur[l])) {
                        good = true;
                        break;
                    }
                }
            }
        }
        if (good) {
            cout << patience << "\n";
        } else {
            cout << -1 << "\n";
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
