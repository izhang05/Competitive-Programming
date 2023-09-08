/* Author: izhang
 * Time: 09-04-2023 19:28:29
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

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, mxn = 15;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
bool grid[0][mxn][mxn], vis[mxn][mxn];
char ans[mxn][mxn];

void test_case() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string cur;
        cin >> cur;
        for (int j = 0; j < n; ++j) {
            grid[0][i][j] = (cur[j] == '.');
        }
    }
    string s;
    cin >> s;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                grid[i + 1][k][n - 1 - j] = grid[i][j][k];
            }
        }
    }

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                vis[j][k] |= grid[i][j][k];
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!vis[i][j]) {
                cout << "invalid grille" << "\n";
                return;
            }
        }
    }
    int cur = 0;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                if (grid[i][j][k]) {
                    if (cur < int(s.size())) {
                        ans[j][k] = s[cur++];
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << ans[i][j];
        }
    }
    cout << "\n";
//    for (int i = 0; i < 4; ++i) {
//        for (int j = 0; j < n; ++j) {
//            for (int k = 0; k < n; ++k) {
//                cout << grid[i][j][k] << " ";
//            }
//            cout << "\n";
//        }
//        cout << "\n";
//    }
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
