/* Author: izhang
 * Time: 03-27-2022 10:35:01
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
    int l, r;
    cin >> l >> r;
    int n = r - l + 1;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int lo = 0, hi = 1 << 17, mid;
    while (lo <= hi) {
        mid = (lo + hi) / 2;
        vector<int> cur(n);
        for (int i = 0; i < n; ++i) {
            cur[i] = i ^ mid;
        }
        sort(cur.begin(), cur.end());
        if (cur == a) {
            cout << mid << "\n";
            return;
        } else if (cur < a) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
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