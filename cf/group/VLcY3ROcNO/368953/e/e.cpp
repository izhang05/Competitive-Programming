/* Author: red_panda_fanclub
 * Time: 03-13-2022 11:00:11
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e3 + 5;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
long long pre[maxn][maxn];

void test_case() {
    int n;
    cin >> n;
    while (n--) {
        char c;
        cin >> c;
        int x1, y1, x2, y2, v;
        cin >> x1 >> y1 >> x2 >> y2 >> v;
        ++x1, ++y1, ++x2, ++y2;
        if (c == 'B') {
            v *= -1;
        }
        pre[x1][y1] += v, pre[x1][y2] -= v, pre[x2][y1] -= v, pre[x2][y2] += v;
    }
    pair<long long, int> sol{-INFL, 0};
    for (int i = 1; i < maxn; ++i) {
        for (int j = 1; j < maxn; ++j) {
            pre[i][j] += pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];
            if (pre[i][j] > sol.first) {
                sol = {pre[i][j], 1};
            } else if (pre[i][j] == sol.first) {
                ++sol.second;
            }
        }
    }
    cout << sol.first << " " << sol.second << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
