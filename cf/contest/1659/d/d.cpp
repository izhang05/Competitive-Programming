/* Author: izhang
 * Time: 04-17-2022 10:35:03
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
    vector<int> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    vector<int> a(n, -1);
    int last = -1;
    for (int i = 0; i < n; ++i) {
//        dbg() << a;
        if (last == i - 1) {
            if (c[i] >= i + 1) {
                c[i] -= i + 1;
                assert(last + 1 < n);
                a[++last] = 1;
            }
            while (c[i]--) {
                assert(last + 1 < n);
                a[++last] = 1;
            }
            if (last + 1 < n) {
                a[++last] = 0;
            }
        } else {
            c[i] -= a[i] * i + last - i + 1;
//            dbg() << i << " " << c[i];
            while (c[i]--) {
                assert(last + 1 < n);
                a[++last] = 1;
            }
            if (last + 1 < n) {
                a[++last] = 0;
            }
        }
        if (last >= n - 1) {
            break;
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " \n"[i == n - 1];
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
