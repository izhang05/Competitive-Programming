/* Author: izhang
 * Time: 03-12-2022 22:27:01
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
const int inf = 0x3f3f3f3f, mod = 998244353, maxn = 105;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
long long p[maxn];

void test_case() {
    p[0] = 2022;
    int n, m;
    cin >> n >> m;
    for (int i = 1; i < n; ++i) {
        p[i] = p[i - 1] * 2022;
        p[i] %= mod;
    }
    long long sol = INFL;
    vector<int> nums(m);
    for (int i = 0; i < m; ++i) {
        nums[i] = i + 1;
    }
    do {
        long long cur = 0;
        for (int i = 0; i < n; ++i) {
            cur += p[i] * nums[i % m];
            dbg() << p[i] << " " << nums[i % m] << " " << p[i] * nums[i % m];
        }
        sol = min(sol, cur);
    } while (next_permutation(nums.begin(), nums.end()));
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
