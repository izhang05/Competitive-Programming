/* Author: izhang
 * Time: 04-01-2024 19:10:10
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
    if (n == 1) {
        cout << "yoink a\n"
                "yoink b\n"
                "*slaps a on top of b*\n"
                "yeet b\n"
                "go touch some grass" << "\n";
    } else if (n == 2) {
        cout << "yoink a\n"
                "bruh b is lowkey just 0\n"
                "rip this b fell off by a\n"
                "vibe check a ratios b\n"
                "simp for 7\n"
                "bruh a is lowkey just b\n"
                "yeet a\n"
                "go touch some grass" << "\n";
    } else if (n == 3) {
        cout << "yoink n\n"
                "yoink a\n"
                "bruh m is lowkey just a[0]\n"
                "bruh i is lowkey just 1\n"
                "vibe check n ratios i\n"
                "simp for 9\n"
                "yeet m\n"
                "go touch some grass\n"
                "vibe check a[i] ratios m\n"
                "bruh m is lowkey just a[i]\n"
                "*slaps 1 on top of i*\n"
                "simp for 5" << "\n";
    } else if (n == 4) {
        cout << " ";
    }
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
