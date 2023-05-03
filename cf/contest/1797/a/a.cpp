/* Author: izhang
 * Time: 04-17-2023 09:54:41
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

int n, m;
bool corner(int x, int y) {
    return (x == 1 || x == n) && (y == 1 || y == m);
}

void test_case() {
    cin >> n >> m;
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (corner(a, b) || corner(c, d)) {
        cout << 2 << "\n";
    } else if (a == 1 || b == 1 || c == 1 || d == 1 || a == n || b == m || c == n || d == m) {
        cout << 3 << "\n";
    } else {
        cout << 4 << "\n";
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
