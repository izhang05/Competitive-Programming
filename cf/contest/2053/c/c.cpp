/* Author: izhang
 * Time: 12-28-2024 09:34:05
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

long long k;

long long solve(long long l, long long r, long long add, long long cnt) {
    dbg() << l << " " << r << " " << add << " " << cnt;
    if (r - l + 1 < k) {
        return 0;
    }
    if (l == r) {
        return cnt * l + add;
    }
    long long m = (l + r) / 2;
    if ((r - l + 1) % 2 == 0) {
        return solve(l, m, 2 * add + cnt * (m + 1 - l), cnt * 2);
    } else {
        return cnt * m + add + solve(l, m - 1, 2 * add + cnt * (m + 1 - l), cnt * 2);
    }
}

void test_case() {
    long long n;
    cin >> n >> k;
    cout << solve(1, n, 0, 1) << "\n";
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
