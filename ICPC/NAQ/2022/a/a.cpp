/* Author: izhang
 * Time: 09-09-2023 01:31:45
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
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<long long> pre(n + 1);
    for (int i = 0; i < n; ++i) {
        pre[i + 1] = pre[i] + a[i];
    }
    long long mx = a[n - 1];
    int ind = n - 1;
    while (true) {
        int lo = 0, hi = ind - 1, mid, res = -1;
        while (lo <= hi) {
            mid = (lo + hi) / 2;
            long long diff = pre[ind] - pre[mid + 1];
            if (diff < mx) {
                if (diff + a[mid] >= mx) {
                    res = mid;
                    break;
                }
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        if (res == -1) {
            break;
        }
        mx += pre[ind] - pre[res];
        ind = res;
    }
    cout << n - ind << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
