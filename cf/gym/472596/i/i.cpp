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
    int n, m;
    cin >> n >> m;
    if (n % 2 == 0 && m % 2 == 0) {
        cout << -1 << "\n";
        return;
    }
    if (n % 2 == 1) {
        for (int i = 1; i <= n; ++i) {
            cout << i << " " << 1 << "\n";
        }
        for (int i = 1; i <= n; ++i) {
            if (i % 2 == 1) {
                for (int j = 2; j <= m; ++j) {
                    cout << i << " " << j << "\n";
                }
            }
        }
        for (int i = 1; i <= n; ++i) {
            if (i % 2 == 0) {
                for (int j = 2; j <= m; ++j) {
                    cout << i << " " << j << "\n";
                }
            }
        }
    } else {
        for (int i = 1; i <= m; ++i) {
            cout << 1 << " " << i << "\n";
        }
        for (int i = 1; i <= m; ++i) {
            if (i % 2 == 1) {
                for (int j = 2; j <= n; ++j) {
                    cout << j << " " << i << "\n";
                }
            }
        }
        for (int i = 1; i <= m; ++i) {
            if (i % 2 == 0) {
                for (int j = 2; j <= n; ++j) {
                    cout << j << " " << i << "\n";
                }
            }
        }
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
