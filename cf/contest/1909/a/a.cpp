/* Author: izhang
 * Time: 05-13-2024 17:10:01
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
    int n;
    cin >> n;
    bool px = false, py = false, nx = false, ny = false;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        if (x > 0) {
            px = true;
        } else if (x < 0) {
            nx = true;
        }
        if (y > 0) {
            py = true;
        } else if (y < 0) {
            ny = true;
        }
    }
    if (!(px & nx) || !(py & ny)) {
        cout << "YES"
             << "\n";
    } else {
        cout << "NO"
             << "\n";
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
