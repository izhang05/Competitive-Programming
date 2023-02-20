/* Author: izhang
 * Time: 02-18-2023 23:15:34
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
    string sol = s, orig;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'p') {
            for (int j = i; j < n; ++j) {
                string cur = orig;
                for (int k = j; k >= i; --k) {
                    if (s[k] == 'd') {
                        cur += 'p';
                    } else {
                        cur += 'd';
                    }
                }
                for (int k = j + 1; k < n; ++k) {
                    cur += s[k];
                }
                sol = min(sol, cur);
                dbg() << i << " " << j << " " << cur << " " << sol;
            }
            break;
        } else {
            orig += 'd';
        }
    }
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
