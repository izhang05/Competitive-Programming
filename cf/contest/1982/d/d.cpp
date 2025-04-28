/* Author: izhang
 * Time: 06-25-2024 10:35:01
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, mxn = 505;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
int grid[mxn][mxn];
bool mount[mxn][mxn];

void test_case() {
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }
    long long a = 0, b = 0;
    vector<vector<int>> pre(n, vector<int>(m + 1));
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < m; ++j) {
            mount[i][j] = s[j] - '0';
            if (mount[i][j]) {
                b += grid[i][j];
            } else {
                a += grid[i][j];
            }
            pre[i][j + 1] = pre[i][j] + mount[i][j];
        }
    }
    long long diff = abs(a - b);
    int g = -1;
    for (int i = 0; i + k <= n; ++i) {
        for (int j = 0; j + k <= m; ++j) {
            int ones = 0;
            for (int l = i; l < i + k; ++l) {
                ones += pre[l][j + k] - pre[l][j];
            }
            int zeroes = k * k - ones, val = abs(zeroes - ones);
            if (val != 0) {
                if (g == -1) {
                    g = val;
                } else {
                    g = __gcd(g, val);
                }
            }
        }
    }
    if (diff == 0) {
        cout << "YES"
             << "\n";
        return;
    }
    if (g == -1) {
        cout << "NO"
             << "\n";
        return;
    }
    cout << (diff % g == 0 ? "YES" : "NO") << "\n";
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
