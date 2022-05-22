/* Author: izhang
 * Time: 05-21-2022 17:15:02
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
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    a.push_back(1);
    a.push_back(n);
    int lo = a[0], hi = a[0];
    vector<int> mn(n + 2, 0), mx(n + 2, n);
    mn[0] = mx[0] = a[0];
    for (int i = 1; i < n + 2; ++i) {
        if (a[i] > lo && a[i] < hi) {
            cout << "NO"
                 << "\n";
            return;
        }
        if (a[i] == lo && a[i] == hi) {
            continue;
        }
        if (a[i] <= lo) {
            lo = a[i];
            for (int j = 0; j <= i; ++j) {
                mn[j] = max(mn[j], a[i]);
            }
        } else if (a[i] >= hi) {
            hi = a[i];
            for (int j = 0; j <= i; ++j) {
                mx[j] = min(mx[j], a[i]);
            }
        }
    }
    set<int> avail;
    for (int i = 0; i < n; ++i) {
        avail.insert(i + 1);
    }
    dbg() << mn;
    dbg() << mx;
    for (int i = 0; i < n; ++i) {
        auto it = avail.lower_bound(mn[i]);
        if (it == avail.end() || *it > mx[i]) {
            cout << "NO"
                 << "\n";
            return;
        }
        avail.erase(it);
    }
    cout << "YES"
         << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
