/* Author: izhang
 * Time: 02-11-2024 18:15:09
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
    int x, y;
    cin >> x >> y;
    if (x == y) {
        cout << 0 << "\n";
        return;
    }
    if (__builtin_popcount(x) == 1 || __builtin_popcount(y) == 1) {
        if (__builtin_popcount(x) != 1) {
            cout << "inf"
                 << "\n";
        } else if (__builtin_popcount(y) != 1) {
            cout << "-inf"
                 << "\n";
        } else {
            int tx = 0, ty = 0;
            while (x % 2 == 0) {
                ++tx;
                x /= 2;
            }
            while (y % 2 == 0) {
                ++ty;
                y /= 2;
            }
            cout << tx - ty << "\n";
        }
        return;
    }
    int tx = 0, ty = 0;
    while (x % 2 == 0) {
        ++tx;
        x /= 2;
    }
    while (y % 2 == 0) {
        ++ty;
        y /= 2;
    }

    if (tx > ty) {
        cout << "-inf"
             << "\n";
    } else if (ty > tx) {
        cout << "inf"
             << "\n";
    } else {
        cout << (y - x) / 2 << "\n";
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
