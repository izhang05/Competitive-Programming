/* Author: izhang
 * Time: 02-18-2022 16:30:10
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7; //998244353;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

struct edge {
    int t, u, v, c;
    bool operator<(const edge &rhs) const {
        return t < rhs.t;
    }
};

void test_case() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<edge> a(m);
    for (auto &i : a) {
        cin >> i.t >> i.u >> i.v >> i.c;
    }
    sort(a.begin(), a.end());
    ++n;
    vector<multiset<int>> to(n), from(n);
    for (auto &i : a) {
        if (!i.u) {
            from[i.v].insert(i.c);
        }
    }

    long long to_cost = 0, from_cost = 0;
    for (int i = 1; i < n; ++i) {
        if (from[i].empty()) {
            cout << -1 << "\n";
            return;
        }
        from_cost += *from[i].begin();
    }
    int bad = n - 1;
    long long sol = INFL;
    int j = 0;
    for (int i = 0; i < m;) {
        int cur_t = a[i].t;
        while (i < m && a[i].t == cur_t) {
            if (!a[i].v) {
                if (!to[a[i].u].empty()) {
                    to_cost -= *to[a[i].u].begin();
                } else {
                    --bad;
                }
                to[a[i].u].insert(a[i].c);
                to_cost += *to[a[i].u].begin();
            }
            ++i;
        }
        while (j < m && a[j].t <= cur_t + k) {
            if (!a[j].u) {
                from_cost -= *from[a[j].v].begin();
                from[a[j].v].erase(from[a[j].v].find(a[j].c));
                if (from[a[j].v].empty()) {
                    cout << (sol == INFL ? -1 : sol) << "\n";
                    return;
                }
                from_cost += *from[a[j].v].begin();
            }
            ++j;
        }
        if (!bad) {
            sol = min(sol, to_cost + from_cost);
        }
    }
    cout << sol << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
