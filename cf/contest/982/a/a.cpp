/* Author: izhang
 * Time: 11-24-2022 18:19:09
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
    string s;
    cin >> s;
    if (n == 1) {
        if (s == "0") {
            cout << "NO"
                 << "\n";
        } else {
            cout << "YES"
                 << "\n";
        }
        return;
    }
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == s[i + 1] && s[i] == '1') {
            cout << "NO"
                 << "\n";
            return;
        }
    }
    for (int i = 0; i < n - 2; ++i) {
        if (s[i] == '0' && s[i + 1] == '0' && s[i + 2] == '0') {
            cout << "NO"
                 << "\n";
            return;
        }
    }
    if ((s[0] == '0' && s[1] == '0') || (s[n - 1] == '0' && s[n - 2] == '0')) {
        cout << "NO"
             << "\n";
        return;
    }
    cout << "YES"
         << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
