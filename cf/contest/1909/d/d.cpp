/* Author: izhang
 * Time: 05-13-2024 17:10:01
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
    long long k;
    cin >> n >> k;
    vector<long long> a(n);
    bool equal = false;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        equal |= a[i] == k;
    }
    sort(a.begin(), a.end());
    if (a[0] < k && a.back() > k) {
        cout << -1 << "\n";
        return;
    }
    if (equal) {
        if (a[0] != k || a.back() != k) {
            cout << -1 << "\n";
        } else {
            cout << 0 << "\n";
        }
        return;
    }
    for (auto &i : a) {
        i = abs(i - k);
    }
    sort(a.begin(), a.end());
    dbg() << a;
    long long g = a[0];
    for (int i = 1; i < n; ++i) {
        g = __gcd(g, a[i]);
    }
    long long sol = 0;
    for (auto &i : a) {
        sol += i / g - 1;
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
