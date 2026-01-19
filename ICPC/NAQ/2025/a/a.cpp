/* Author: izhang
 * Time: 10-11-2025 13:55:04
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
    int r, g, b;
    cin >> r >> g >> b;
    int cr, cg, cb;
    cin >> cr >> cg >> cb;
    r -= cr, g -= cg, b -= cb;
    int x, y;
    cin >> x >> y;
    r = max(0, r);
    g = max(0, g);
    b = max(0, b);

    int sol = r + b;
    x -= r;
    y -= b;
    if (x < 0 || y < 0 || x + y < g) {
        cout << -1 << "\n";
        return;
    }
    cout << sol + g << "\n";
}


int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
