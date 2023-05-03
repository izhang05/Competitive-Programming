/* Author: izhang
 * Time: 05-03-2023 10:07:42
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
    int m;
    cin >> m;
    vector<vector<int>> a(2, vector<int>(m));
    string s;
    for (int i = 0; i < 2; ++i) {
        cin >> s;
        for (int j = 0; j < m; ++j) {
            if (s[j] == 'B') {
                a[i][j] = 1;
            }
        }
    }
    int x = 0, y = 0;
    if (a[x][y]) {
        while (true) {
            dbg() << x << " " << y;
            if (a[1 - x][y] == 1) {
                x = 1 - x;
            }
            if (y == m - 1) {
                cout << "YES"
                     << "\n";
                return;
            }
            if (!a[x][y + 1]) {
                break;
            }
            ++y;
        }
    }
    x = 1, y = 0;
    if (a[x][y]) {
        while (true) {
            dbg() << x << " " << y;
            if (a[1 - x][y] == 1) {
                x = 1 - x;
            }
            dbg() << x << " " << y;
            if (y == m - 1) {
                cout << "YES"
                     << "\n";
                return;
            }
            if (!a[x][y + 1]) {
                break;
            }
            ++y;
        }
    }
    cout << "NO"
         << "\n";
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
