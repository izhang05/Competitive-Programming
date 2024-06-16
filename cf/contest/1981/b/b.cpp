/* Author: izhang
 * Time: 06-01-2024 16:30:01
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
    long long n, m;
    cin >> n >> m;
    if (m == 0) {
        cout << n << "\n";
        return;
    }
    long long l = max(0ll, n - m), r = n + m;
    long long sol = l | r;
    for (int i = 0; i < 40; ++i) {
        if (l & (1ll << i)) {
            continue;
        }
        long long cur = l;
        for (int j = 0; j < i; ++j) {
            if (cur & (1ll << j)) {
                cur ^= (1ll << j);
            }
        }
        cur |= (1ll << i);
        if (cur <= r) {
            sol |= (1ll << i);
        }
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
