/* Author: izhang
 * Time: 10-15-2023 00:45:01
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
    vector<long long> a(2 * n);
    for (int i = 0; i < 2 * n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    long long sol = (a[n - 1] - a[0]) * (a[2 * n - 1] - a[n]);
    long long mn_dif = INFL;
    for (int i = 1; i < n; ++i) {
        mn_dif = min(mn_dif, a[i + n - 1] - a[i]);
    }
    sol = min(sol, (a[2 * n - 1] - a[0]) * (mn_dif));
    for (int i = n; i < 2 * n - 1; ++i) {
        long long cur = (a[i] - a[0]);
        int gaps = i - (n - 1);
        long long other = a[2 * n - 1] - a[i - gaps];
        sol = min(sol, cur * other);
    }
    cout << sol << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
