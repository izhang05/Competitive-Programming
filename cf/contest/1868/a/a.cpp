/* Author: izhang
 * Time: 09-11-2023 18:23:44
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
    vector<int> cur(m);
    for (int i = 0; i < m; ++i) {
        cur[i] = i;
    }
    rotate(cur.begin(), prev(cur.end()), cur.end());
    if (m == 1) {
        cout << 0 << "\n";
    } else {
        cout << min(n + 1, m) << "\n";
    }
    for (int i = 0; i < n; ++i) {
        for (auto &j : cur) {
            cout << j << " ";
        }
        cout << "\n";
        rotate(cur.begin(), prev(cur.end()), cur.end());
        if (cur[0] == 0) {
            rotate(cur.begin(), prev(cur.end()), cur.end());
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
