/* Author: izhang
 * Time: 06-06-2024 19:30:01
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
    long long lo = n, hi = (long long) n * (long long) 1e9, mid, sol = -1;
    while (lo <= hi) {
        mid = (lo + hi) / 2;
        long long sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += (mid / a[i]) + 1;
        }
        if (sum <= mid) {
            sol = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    if (sol == -1) {
        cout << -1 << "\n";
    } else {
        for (int i = 0; i < n; ++i) {
            cout << sol / a[i] + 1 << " ";
        }
        cout << "\n";
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
