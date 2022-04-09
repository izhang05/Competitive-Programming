/* Author: izhang
 * Time: 03-31-2022 11:08:49
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 2e3 + 5;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
int grid[maxn][maxn];

void test_case() {
    int n;
    cin >> n;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < n; ++j) {
            grid[i][j] = s[j] - '0';
            cnt += grid[i][j];
        }
    }
    int sol = inf;
    for (int i = 0; i < n; ++i) {
        int x = i, cur = 0;
        for (int j = 0; j < n; ++j) {
            x = (x + 1) % n;
            cur += grid[x][j];
        }
        sol = min(sol, n - cur + cnt - cur);
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
