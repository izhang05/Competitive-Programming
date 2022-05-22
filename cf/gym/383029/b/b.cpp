/* Author: izhang
 * Time: 05-21-2022 14:00:05
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

set<long long> nums;
void gen(long long n, int len) {
    nums.insert(n);
    if (len == 9) {
        return;
    }
    n *= 10;
    gen(n + 1, len + 1);
    gen(n + 3, len + 1);
    gen(n + 5, len + 1);
    gen(n + 9, len + 1);
}

void test_case() {
    long long n;
    cin >> n;
    gen(1, 1);
    gen(3, 1);
    gen(5, 1);
    gen(9, 1);
    cout << *nums.lower_bound(n) << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
