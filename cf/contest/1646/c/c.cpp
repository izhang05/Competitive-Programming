/* Author: izhang
 * Time: 03-17-2022 20:53:04
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxf = 15;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
long long fact[maxf];

void test_case() {
    long long n;
    cin >> n;
    long long sol = INFL;
    for (int i = 0; i < (1 << maxf); ++i) {
        long long cur = n, cost = 0;
        for (int j = 0; j < maxf; ++j) {
            if (i & (1 << j)) {
                cur -= fact[j];
                ++cost;
            }
        }
        if (cur >= 0) {
            sol = min(sol, cost + __builtin_popcountll(cur));
        }
    }
    cout << sol << "\n";
}

int main() {
    setIO("1");
    fact[0] = 1;
    for (int i = 1; i < maxf; ++i) {
        fact[i] = fact[i - 1] * i;
    }
    int test_case_number = 1;
    cin >> test_case_number;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
