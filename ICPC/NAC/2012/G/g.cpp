#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
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


int main() {
//    cin.tie(0)->sync_with_stdio(0);
//    cin.exceptions(cin.failbit);
    int n, m, k;
    cin >> n >> m >> k;
        vector<pair<int, int>> r, b;
        for (int i = 0; i < m; ++i) {
            char c;
            int u, v;
            cin >> c >> u >> v;
            --u, --v;
            if (c == 'R') {
                r.emplace_back(u, v);
            } else {
                b.emplace_back(u, v);
            }
        }
        UF dr(n), db(n);
        int mn = 0, mx = 0;
        for (auto &i: r) {
            dr.join(i.first, i.second);
        }
        for (auto &i: b) {
            if (db.join(i.first, i.second)) {
                ++mx;
            }
            if (dr.join(i.first, i.second)) {
                ++mn;
            }
        }
        cout << (mn <= k && mx >= k) << "\n";
//    while (n != 0) {
//        cin >> n >> m >> k;
//    }
}