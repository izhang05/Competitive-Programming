/* Author: izhang
 * Time: 06-15-2025 15:54:21
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
    long long n, a, b, x, y;
    cin >> n >> a >> b >> x >> y;
    if (x > y) {
        swap(a, b);
        swap(x, y);
    }
    // x <= y
    if (x == y) {
        if (a > b) {
            swap(a, b);
        }
    }
    long long sol = 0;
    if (a <= n) {
        sol = 1 + (n - a) / x;
        n -= sol * x;
    }
    if (b <= n) {
        sol += 1 + (n - b) / y;
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
