/* Author: izhang
 * Time: 03-22-2022 10:45:04
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
    string s;
    cin >> n >> s;
    int last = -1, sol = 0, last_close = -1;
    for (int i = 0; i < n; ++i) {
        if (last_close == -1) {
            if (i + 1 >= n) {
                break;
            }
            if (s[i] == ')' && s[i + 1] == '(') {
                last_close = i;
            } else {
                ++sol;
                last = i + 1;
            }
            ++i;
        } else {
            if (s[i] == ')') {
                ++sol;
                last = i;
                last_close = -1;
            }
        }
    }
    cout << sol << " " << n - last - 1 << "\n";
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
