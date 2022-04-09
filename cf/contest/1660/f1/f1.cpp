/* Author: izhang
 * Time: 03-31-2022 11:08:49
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
    int n;
    cin >> n;
    string s;
    cin >> s;
    long long sol = 0;
    for (int i = 0; i < n; ++i) {
        int plus = 0, minus = 0, num = 0;
        char pre = ' ';
        for (int j = i; j < n; ++j) {
            if (s[j] == '+') {
                ++plus;
                pre = '+';
            } else {
                ++minus;
                if (pre == '-') {
                    ++num;
                    pre = ' ';
                } else {
                    pre = '-';
                }
            }
            if (plus == minus) {
                dbg() << i << " " << j;
                ++sol;
            } else if (minus > plus && ((minus - plus) % 3 == 0 && (minus - plus) / 3 <= num)) {
                dbg() << i << " " << j;
                ++sol;
            }
        }
    }
    cout << sol << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    cin >> test_case_number;
    while (test_case_number--) {
        dbg() << test_case_number;
        test_case();
    }
    return 0;
}
