/* Author: izhang
 * Time: 08-01-2022 15:36:02
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

long long tri(long long x) {
    return (x * (x + 1)) / 2;
}

void test_case() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    if (n == 1) {
        cout << a[0] + k - 1 << "\n";
        return;
    }
    if (k <= n) {
        long long cur = 0;
        for (int i = 0; i < k; ++i) {
            cur += a[i];
        }
        long long mx = cur;
        for (int i = k; i < n; ++i) {
            cur += a[i] - a[i - k];
            mx = max(mx, cur);
        }
        cout << mx + tri(k - 1) << "\n";
    } else {
        long long sol = 0;
        for (auto &i : a) {
            sol += i;
        }
        vector<int> last(n);
        int rem = k % (n - 1);
        if (rem == 0) {
            rem = n - 1;
        }
        for (int i = rem - 1, cnt = 0; i >= 0; --i, ++cnt) {
            last[i] = cnt;
        }
        sol += tri(rem - 1);
        k -= rem;
        dbg() << rem;
        for (int i = 1; i < n && k; ++i, --k) {
            dbg() << i << " " << i + rem - last[i] - 1;
            sol += i + rem - last[i] - 1;
        }
        sol += 2 * tri(n - 1) * (k / (n - 1));
        cout << sol << "\n";
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
