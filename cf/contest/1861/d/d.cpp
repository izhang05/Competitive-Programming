/* Author: izhang
 * Time: 09-22-2023 14:34:24
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
    int cur = 1;
    for (int i = 1; i < n; ++i) {
        if (a[i] <= a[i - 1]) {
            ++cur;
        }
    }
    int pre = 0, sol = cur - 1;
    for (int i = 0; i < n; ++i) {
        if (i + 1 < n && a[i + 1] <= a[i]) {
            --cur;
        }
        if (i == 0 || a[i] >= a[i - 1]) {
            ++pre;
        }
        dbg() << i << " " << pre << " " << cur;
        sol = min(sol, pre + cur - 1);
    }
    dbg();
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
