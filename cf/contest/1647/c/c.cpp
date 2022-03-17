/* Author: izhang
 * Time: 03-15-2022 02:03:45
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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < m; ++j) {
            a[i][j] = s[j] - '0';
        }
    }
    if (a[0][0] == 1) {
        cout << -1 << "\n";
        return;
    }
    vector<array<int, 4>> sol;
    for (int i = n - 1; i >= 0; --i) {
        for (int j = m - 1; j >= 1; --j) {
            if (a[i][j] == 1) {
                sol.push_back({i, j - 1, i, j});
            }
        }
        if (a[i][0] == 1) {
            sol.push_back({i - 1, 0, i, 0});
        }
    }
    cout << sol.size() << "\n";
    for (auto &i : sol) {
        for (int j = 0; j < 4; ++j) {
            cout << i[j] + 1 << " \n"[j == 3];
        }
    }
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
