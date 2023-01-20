/* Author: izhang
 * Time: 01-19-2023 20:54:02
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
    int n, l;
    cin >> n >> l;
    vector<long long> c(30, INFL);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    for (int i = 1; i < 30; ++i) {
        c[i] = min(c[i], 2 * c[i - 1]);
    }
    for (int i = 28; i >= 0; --i) {
        c[i] = min(c[i], c[i + 1]);
    }
    long long sol = 0;
    for (int i = 0; i < 30; ++i) {
        sol = min(sol, c[i]);
        if (l & (1 << i)) {
            sol += c[i];
        }
    }
    dbg() << c;
    cout << sol << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
