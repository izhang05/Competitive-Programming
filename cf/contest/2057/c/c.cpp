/* Author: izhang
 * Time: 01-04-2025 09:32:03
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
    long long l, r;
    cin >> l >> r;
    long long a = 0;
    for (int i = 30; i >= 0; --i) {
        long long cur = 1ll << i;
        if ((l & cur) != (r & cur)) {
            a += cur;
            cout << a << " " << a - 1 << " ";
            if (a + 1 <= r) {
                cout << a + 1 << "\n";
            } else {
                cout << a - 2 << "\n";
            }
            return;
        }
        a += l & cur;
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
