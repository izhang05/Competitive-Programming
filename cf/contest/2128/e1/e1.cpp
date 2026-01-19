/* Author: izhang
 * Time: 07-28-2025 17:40:33
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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int lo = 0, hi = n, sol, l, r;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        vector<int> pre(n + 1);
        int mn = inf, ind;
        bool found = false;
        for (int i = 0; i < n; ++i) {
            pre[i + 1] = pre[i];
            if (a[i] >= mid) {
                ++pre[i + 1];
            } else {
                --pre[i + 1];
            }
            if (i + 1 - k >= 0 && pre[i + 1 - k] < mn) {
                mn = pre[i + 1 - k];
                ind = i + 1 - k;
            }
            if (pre[i + 1] >= mn) {
                sol = mid;
                lo = mid + 1;
                r = i + 1;
                l = ind + 1;
                found = true;
                break;
            }
        }
        if (!found) {
            hi = mid - 1;
        }
    }
    cout << sol << " " << l << " " << r << "\n";
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
