/* Author: izhang
 * Time: 06-15-2025 15:54:30
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
int n, m, k;

int grid[mxn][mxn];

bool valid(int x, int y) {
    return x >= 0 && y >= 0 && x < n && y < m;
}


void test_case() {
    cin >> n >> m >> k;
    int tot = 0;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < m; ++j) {
            grid[i][j] = s[j];
            if (grid[i][j] == 'g') {
                ++tot;
            }
        }
    }
    int sol = inf;
    for (int i = 0; i < n; ++i) {
        int cur = 0;
        for (int j = max(0, i - (k - 1)); j <= min(i + (k - 1), n - 1); ++j) {
            for (int l = 0; l <= min(k - 1, m - 1); ++l) {
                if (grid[j][l] == 'g') {
                    ++cur;
                }
            }
        }
        if (grid[i][0] == '.') {
            sol = min(sol, cur);
        }
        for (int j = 1; j < m; ++j) {
            if (j - k >= 0) {
                for (int l = max(0, i - (k - 1)); l <= min(i + (k - 1), n - 1); ++l) {
                    if (grid[l][j - k] == 'g') {
                        --cur;
                    }
                }
            }
            if (j + (k - 1) < m) {
                for (int l = max(0, i - (k - 1)); l <= min(i + (k - 1), n - 1); ++l) {
                    if (grid[l][j + k - 1] == 'g') {
                        ++cur;
                    }
                }
            }
            if (grid[i][j] == '.') {
                sol = min(sol, cur);
            }
        }
    }

    cout << tot - sol << "\n";
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
