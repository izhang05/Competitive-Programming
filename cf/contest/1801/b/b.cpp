/* Author: izhang
 * Time: 06-02-2023 16:00:02
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
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end());
    multiset<int> seen;
    vector<int> mx(n + 1, -inf);
    for (int i = n - 1; i >= 0; --i) {
        mx[i] = max(mx[i + 1], a[i].second);
    }
    int sol = inf;
    vector<int> nxt(n);
    nxt[n - 1] = n;
    for (int i = n - 2; i >= 0; --i) {
        if (a[i].first == a[i + 1].first) {
            nxt[i] = nxt[i + 1];
        } else {
            nxt[i] = i + 1;
        }
    }
    dbg() << a;
    dbg() << nxt;
    dbg() << mx;
    for (int i = 0; i < n; ++i) {
        if (i == 0 || a[i].first != a[i - 1].first) {
            for (int j = i; j < nxt[i]; ++j) {
                seen.insert(a[j].second);
            }
        }
        seen.erase(seen.find(a[i].second));
        int cur_mx = mx[nxt[i]];
        if (cur_mx < a[i].first) {
            auto it = seen.lower_bound(a[i].first);
            if (it != seen.begin()) {
                cur_mx = max(cur_mx, *prev(it));
            }
            if (it != seen.end()) {
                if (abs(a[i].first - *it) < abs(a[i].first - cur_mx)) {
                    cur_mx = *it;
                }
            }
        }
        sol = min(sol, abs(a[i].first - cur_mx));
        seen.insert(a[i].second);
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
