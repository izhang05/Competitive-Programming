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

int ask(int x, int y) {
    cout << "? " << x << " " << y << endl;
    int res;
    cin >> res;
    return res;
}

void ans(int x, int y) {
    cout << "! " << x << " " << y << endl;
}

void test_case() {
    int n, m;
    cin >> n >> m;
    int a = ask(1, 1), b = ask(n, 1);
    int x, y;
    if (b > a) {
        x = n - b;
        y = ask(x, 1) + 1;
    } else if (b < a) {
        x = a + 1;
        y = ask(x, 1) + 1;
    } else {
        if (n % 2 == 1 && a == (n + 1) / 2 - 1) {
            x = (n + 1) / 2;
            y = ask(x, 1) + 1;
        } else {
            y = a + 1;
            x = ask(1, y) + 1;
        }
    }
    ans(x, y);
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
