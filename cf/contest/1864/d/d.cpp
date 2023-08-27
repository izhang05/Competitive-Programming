/* Author: izhang
 * Time: 08-26-2023 10:35:02
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, mxn = 3005;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
bool grid[mxn][mxn], flip[mxn][mxn], pre_diag[2 * mxn], pre_diag2[2 * mxn];

void test_case() {
    int n;
    cin >> n;
    for (int i = 0; i < 2 * n + 5; ++i) {
        pre_diag[i] = pre_diag2[i] = false;
    }
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < n; ++j) {
            grid[i][j] = s[j] == '1';
            flip[i][j] = false;
        }
    }
    int sol = 0;
    bool left = false;
    for (int i = 0; i < n; ++i) {
        bool cur = left;
        for (int j = 0; j < n; ++j) {
            cur ^= pre_diag2[i + j];
            if (j != 0) {
                cur ^= pre_diag[i - (j - 1) + n] ^ flip[i][j - 1];
            }
            if (cur ^ grid[i][j]) {
                ++sol;
                pre_diag2[i + j] ^= true;
                pre_diag[i - j + n] ^= true;
                flip[i][j] = true;
            }
        }
        left ^= pre_diag2[i];
    }
    cout << sol << "\n";
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
