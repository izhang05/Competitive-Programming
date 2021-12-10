/* Author: izhang05
 * Time: 11-23-2021 17:40:22
**/
#include <bits/stdc++.h>

using namespace std;

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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 5e5 + 5, k = 500;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

struct query {
    int l, r, ind;
    bool operator<(query other) const {
        if (l / k != other.l / k) {
            return l < other.l;
        }
        return (l / k & 1) ? (r < other.r) : (r > other.r);
    }
};
int cur = 0;
set<int> occ[maxn];

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> sol(m);
    vector<query> q(m);
    for (int i = 0; i < m; ++i) {
        cin >> q[i].l >> q[i].r >> q[i].ind;
    }
    sort(q.begin(), q.end());
    int l = 0, r = -1;
    for (auto &i : q) {
        while (r < i.r) {
            ++r;
            add(r);
        }
        while (l > i.l) {
            --l;
            add(l);
        }
        while (r > i.r) {
            remove(r);
            --r;
        }
        while (l < i.l) {
            remove(l);
            ++l;
        }
        sol[i.ind] = cur;
    }
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        solve();
    }
    return 0;
}
