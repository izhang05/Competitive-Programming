/* Author: izhang
 * Time: 09-06-2025 18:39:38
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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
template<class T>
using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void test_case() {
    int n;
    cin >> n;
    indexed_set<pair<int, int>> sl, sr;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        sl.insert({l, i});
        sr.insert({r, i});
        a[i] = {l, r};
    }
    int sol = n;
    for (int i = 0; i < n; ++i) {
        int cur = sr.order_of_key({a[i].first, -1}) + n - sl.order_of_key({a[i].second, n + 1});
        sol = min(sol, cur);
    }
    cout << sol << "\n";
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
