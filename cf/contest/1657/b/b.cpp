/* Author: izhang
 * Time: 03-22-2022 10:45:04
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
    int n, b, x, y;
    cin >> n >> b >> x >> y;
    vector<int> a(n);
    if (x <= b) {
        a[0] = x;
    } else {
        a[0] = -y;
    }
    for (int i = 1; i < n; ++i) {
        if (a[i - 1] + x <= b) {
            a[i] = a[i - 1] + x;
        } else {
            a[i] = a[i - 1] - y;
        }
    }
    cout << accumulate(a.begin(), a.end(), 0ll) << "\n";
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
