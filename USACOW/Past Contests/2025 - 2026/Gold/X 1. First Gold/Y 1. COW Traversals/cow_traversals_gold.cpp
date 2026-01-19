#include <bits/stdc++.h>

using namespace std;

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, mxn = 2e5 + 5;

int nxt[mxn];
vector<int> val[mxn];

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
        vi e, v;

        UF(int n) : e(n, -1), v(n, -1) {}

        bool sameSet(int a, int b) { return find(a) == find(b); }

        int size(int x) { return -e[find(x)]; }

        int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }

        bool join(int a, int b) {
            a = find(a), b = find(b);
            int cur_val = v[b];
            if (a == b) return false;
            if (e[a] > e[b]) swap(a, b);
            e[a] += e[b];
            e[b] = a;
            v[a] = cur_val;
            return true;
        }
    };

}
//using namespace kactl;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    int n, m;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> nxt[i];
        --nxt[i];
    }
    cin >> m;
    vector<pair<int, int>> q(m);
    for (int i = 0; i < m; ++i) {
        char c;
        cin >> q[i].first >> c;
        --q[i].first;
        if (c == 'C') {
            q[i].second = 0;
        } else if (c == 'O') {
            q[i].second = 1;
        } else {
            q[i].second = 2;
        }
        val[q[i].first].push_back(q[i].second);
    }

    kactl::UF dsu(n);
    for (int i = 0; i < n; ++i) {
        if (val[i].empty()) {
            dsu.join(i, nxt[i]);
        } else {
            dsu.v[dsu.find(i)] = val[i].back();
        }
    }
    array<int, 3> cur{0, 0, 0};
    for (int i = 0; i < n; ++i) {
        if (dsu.v[dsu.find(i)] != -1) {
            ++cur[dsu.v[dsu.find(i)]];
        }
    }

    vector<array<int, 3>> sol(m);
    for (int i = m - 1; i >= 0; --i) {
        sol[i] = cur;
        int root = dsu.find(q[i].first);
        cur[dsu.v[root]] -= -dsu.e[root];
        val[q[i].first].pop_back();
        dsu.v[root] = -1;

        if (val[q[i].first].empty()) {
            int nxt_root = dsu.find(nxt[q[i].first]);
            if (dsu.v[nxt_root] != -1) {
                cur[dsu.v[nxt_root]] += -dsu.e[root];
            }
            dsu.join(q[i].first, nxt[q[i].first]);
        } else {
            dsu.v[root] = val[q[i].first].back();
            cur[dsu.v[root]] += -dsu.e[root];
        }
    }

    for (auto &i: sol) {
        cout << i[0] << " " << i[1] << " " << i[2] << "\n";
    }
    return 0;
}
