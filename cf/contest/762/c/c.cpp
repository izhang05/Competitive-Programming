/* Author: izhang
 * Time: 03-15-2022 01:05:51
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

void test_case() {
    string a, b;
    cin >> a >> b;
    int n = int(a.size()), m = int(b.size());
    map<int, set<int>> occ;
    for (int i = 0; i < n; ++i) {
        occ[a[i]].insert(i);
    }
    vector<int> pre(m), suf(m + 1, -1);
    suf[m] = inf;
    int max_suf = -1;
    for (int i = m - 1; i >= 0; --i) {
        auto it = occ[b[i]].lower_bound(suf[i + 1]);
        if (it == occ[b[i]].begin()) {
            break;
        }
        suf[i] = *prev(it);
        max_suf = max(max_suf, m - i);
    }
    pre[0] = -1;
    pair<int, int> sol{-1, -1};
    for (int i = 0; i < m; ++i) {
        auto it = occ[b[i]].upper_bound(pre[max(0, i - 1)]);
        if (it == occ[b[i]].end()) {
            break;
        }
        pre[i] = *it;
        auto it1 = upper_bound(suf.begin(), suf.end(), pre[i]);
        sol = max(sol, {i + suf.end() - it1, i});
    }
    dbg() << imie(pre) imie(suf);
    dbg() << sol;
    if (max_suf > sol.first) {
        for (int i = m - max_suf; i < m; ++i) {
            cout << b[i];
        }
        cout << "\n";
        return;
    }
    if (sol == make_pair(-1, -1)) {
        cout << "-\n";
        return;
    }
    for (int i = 0; i <= sol.second; ++i) {
        cout << b[i];
    }
    for (int i = max(sol.second + 1, int(upper_bound(suf.begin(), suf.end(), pre[sol.second]) - suf.begin())); i < m; ++i) {
        cout << b[i];
    }
    cout << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
