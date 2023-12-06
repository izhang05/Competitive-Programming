/* Author: izhang
 * Time: 10-27-2023 14:30:17
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
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen(("in" + name + ".txt").c_str(), "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("out.txt", "w", stderr);
#endif
}
const int inf = 0x3f3f3f3f, mod = 1e9 + 7; //998244353;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

int ask(int i) {
    cout << "? " << i + 1 << endl;
    int ret;
    cin >> ret;
    return ret;
}

void guess(int i) {
    cout << "! " << i << endl;
}

void test_case() {
    int n, k;
    cin >> n >> k;
    int sol = 0, cur = 0;
    while (cur + 2 * k < n) {
        sol ^= cur;
        cur += k;
    }
    sol ^= ask(n - 2 * k - 1);
    sol ^= ask(n - k - 1);
    guess(sol);
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
