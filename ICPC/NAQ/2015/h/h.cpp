/* Author: izhang
 * Time: 09-18-2023 19:12:07
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
    string s;
    cin >> s;
    int n = int(s.size());
    int m = 0;
    while (m * m < n) {
        ++m;
    }
    vector<vector<char>> grid(m, vector<char>(m));
    int cur = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            if (cur < n) {
                grid[i][j] = s[cur++];
            } else {
                grid[i][j] = '*';
            }
        }
    }
    vector<vector<char>> new_grid(m, vector<char>(m));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            new_grid[j][m - i - 1] = grid[i][j];
        }
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            if (new_grid[i][j] != '*') {
                cout << new_grid[i][j];
            }
        }
    }
    cout << "\n";
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
