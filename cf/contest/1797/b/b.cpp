/* Author: izhang
 * Time: 04-17-2023 09:54:41
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
    int n, k;
    cin >> n >> k;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }
    int cnt = 0;
    for (int i = 0; i < n / 2; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[i][j] != a[n - 1 - i][n - 1 - j]) {
                ++cnt;
            }
        }
    }
    if (n % 2 == 1) {
        for (int i = 0; i < n / 2; ++i) {
            if (a[n / 2][i] != a[n / 2][n - 1 - i]) {
                ++cnt;
            }
        }
    }
    cout << ((cnt <= k && ((cnt % 2 == k % 2) || (n % 2 == 1))) ? "YES" : "NO") << "\n";
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
