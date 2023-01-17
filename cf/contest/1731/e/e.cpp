/* Author: izhang
 * Time: 01-15-2023 21:55:01
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e6 + 5;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
vector<long long> phi(maxn), phi_sum(maxn);

void test_case() {
    int n;
    long long m;
    cin >> n >> m;
    long long sol = m, mx_cnt = maxn - 1;
    while (m > 0 && mx_cnt > 0) {
        int lo = 1, hi = (int) min(mx_cnt, m), res = 1, mid;
        while (lo <= hi) {
            mid = (lo + hi) / 2;
            if (mid <= phi_sum[n / (mid + 1)]) {
                res = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        long long mx = phi_sum[n / (res + 1)] / res, take = min(m / res, mx);
        dbg() << res << " " << mx << " " << take << " " << m;
        m -= take * res;
        sol += take;
        mx_cnt = res - 1;
    }
    if (m > 0) {
        cout << -1 << "\n";
        return;
    }
    cout << sol << "\n";
}

int main() {
    setIO("1");
    for (int i = 0; i < maxn; i++) {
        phi[i] = i;
    }
    phi[1] = 0;
    for (int i = 2; i < maxn; i++) {
        if (phi[i] == i) {
            for (int j = i; j < maxn; j += i) {
                phi[j] -= phi[j] / i;
            }
        }
    }
    for (int i = 1; i < maxn; ++i) {
        phi_sum[i] = phi_sum[i - 1] + phi[i];
    }
    int test_case_number = 1;
    cin >> test_case_number;
    while (test_case_number--) {
        dbg() << "Starting test:" << test_case_number;
        test_case();
    }
    return 0;
}
