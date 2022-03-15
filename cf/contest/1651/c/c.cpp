/* Author: izhang
 * Time: 03-10-2022 13:15:13
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
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    long long sol = 0, cur = abs(a[0] - b[0]), mn = cur;
    for (int i = 1; i < n; ++i) {
        cur -= abs(a[0] - b[i - 1]);
        cur += abs(a[0] - b[i]);
        cur += abs(a[i] - b[i - 1]);
        mn = min(mn, cur);
    }
    sol += mn;
    cur = abs(a[n - 1] - b[n - 1]), mn = cur;
    for (int i = n - 2; i >= 0; --i) {
        cur -= abs(a[n - 1] - b[i + 1]);
        cur += abs(a[n - 1] - b[i]);
        cur += abs(a[i] - b[i + 1]);
        mn = min(mn, cur);
    }
    sol += mn;
    cur = abs(a[0] - b[n - 1]);
    for (int i = 0; i < n - 1; ++i) {
        cur += abs(b[i] - a[i + 1]);
    }
    sol = min(sol, cur);
    cur = abs(b[0] - a[n - 1]);
    for (int i = 0; i < n - 1; ++i) {
        cur += abs(a[i] - b[i + 1]);
    }
    sol = min(sol, cur);

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
