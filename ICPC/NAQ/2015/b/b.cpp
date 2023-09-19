/* Author: izhang
 * Time: 09-18-2023 19:48:20
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

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, mxn = 25;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

long double binom[mxn][mxn];


void test_case() {
    int r, s, x, y, w;
    cin >> r >> s >> x >> y >> w;
    long double prob = 0;
    for (int i = x; i <= y; ++i) {
        long double cur = binom[y][i];
//        dbg() << s << " " << i << " " << cur;
        cur *= pow((long double) (s - r + 1) / s, i);
//        dbg() << cur;
        cur *= pow((long double) (r - 1) / s, y - i);
//        dbg() << cur;

        prob += cur;
    }
    dbg() << prob;
    cout << (prob * w - 1e-8 > 1.0 ? "yes" : "no") << "\n";
}

int main() {
    setIO("1");
    binom[0][0] = 1;
    for (int i = 1; i < mxn; ++i) {
        binom[i][0] = 1;
        for (int j = 1; j <= i; ++j) {
            binom[i][j] = binom[i - 1][j - 1] + binom[i - 1][j];
        }
    }
    int test_case_number = 1;
    cin >> test_case_number;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
