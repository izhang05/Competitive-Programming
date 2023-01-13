/* Author: izhang
 * Time: 08-19-2022 19:00:01
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e5 + 5;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

bitset<maxn> dp;

void test_case() {
    for (int i = 3; i <= 10; ++i) {
        int sol = 0;
        for (int j = 0; j < 1 << i; ++j) {
            bool a = true, b = false;
            for (int k = 0; k < i - 2; ++k) {
                string cur;
                for (int l = k; l < k + 3; ++l) {
                    if (j & (1 << l)) {
                        cur.push_back('1');
                    } else {
                        cur.push_back('0');
                    }
                }
                if (cur == "001") {
                    a = false;
                } else if (cur == "110") {
                    b = true;
                }
            }
            if (a && b) {
                ++sol;
            }
        }
        cout << sol << "\n";
    }
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
