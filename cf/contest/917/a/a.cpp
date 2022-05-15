/* Author: izhang
 * Time: 05-08-2022 21:13:16
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
const int maxn = 5e3 + 5;
bool good[maxn][maxn];

void test_case() {
    string s;
    cin >> s;
    int n = int(s.size());
    for (int i = 0; i < n - 1; ++i) {
        int open = 0, closed = 0, q = 0;
        for (int j = i; j + 1 < n; ++j) {
            if (s[j] == '(') {
                ++open;
            } else if (s[j] == '?') {
                ++q;
            } else {
                ++closed;
            }
            if (open + q - closed < 0) {
                break;
            }
            ++j;
            if (s[j] == '(') {
                ++open;
            } else if (s[j] == '?') {
                ++q;
            } else {
                ++closed;
            }
            if (open + q - closed < 0) {
                break;
            }
            good[i][j] = true;
        }
    }
    long long sol = 0;
    for (int i = 1; i < n; ++i) {
        int open = 0, closed = 0, q = 0;
        for (int j = i; j >= 1; --j) {
            if (s[j] == '(') {
                ++open;
            } else if (s[j] == '?') {
                ++q;
            } else {
                ++closed;
            }
            if (closed + q - open < 0) {
                break;
            }
            --j;
            if (s[j] == '(') {
                ++open;
            } else if (s[j] == '?') {
                ++q;
            } else {
                ++closed;
            }
            if (closed + q - open < 0) {
                break;
            }
            dbg() << j << " " << i << " " << good[j][i];
            sol += good[j][i];
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
