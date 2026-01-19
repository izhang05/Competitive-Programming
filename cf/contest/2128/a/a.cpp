/* Author: izhang
 * Time: 08-04-2025 17:14:46
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
    int n, c;
    cin >> n >> c;
    vector<__int128> a(n);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        a[i] = x;
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; ++i) {
        bool pos = true;
        __int128 mult = 1;
        for (int j = i; j >= 0; --j) {
            if (mult > 1e9 || mult * a[j] > c) {
                pos = false;
                break;
            }
            mult *= 2;
        }
        if (!pos) {
            cout << n - i << "\n";
            return;
        }
    }
    cout << 0 << "\n";
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
