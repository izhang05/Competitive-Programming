/* Author: izhang
 * Time: 08-08-2023 13:45:01
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
    map<long long, long long> cnt;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ++cnt[a[i]];
    }
    int q;
    cin >> q;
    while (q--) {
        long long x, y;
        cin >> x >> y;
        long long lo = -1e9, hi = x / 2, mid;
        bool found = false;
        while (lo <= hi) {
            mid = (lo + hi) / 2;
            long long other = x - mid, prod = mid * other;
            if (prod == y) {
                dbg() << prod << " " << other;
                if (mid != other) {
                    cout << cnt[mid] * cnt[other] << " ";
                } else {
                    cout << (cnt[mid] * (cnt[mid] - 1)) / 2 << " ";
                }
                found = true;
                break;
            } else if (prod > y) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        if (!found) {
            cout << 0 << " ";
        }
    }
    cout << "\n";
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
