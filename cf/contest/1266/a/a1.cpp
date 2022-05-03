/* Author: izhang
 * Time: 04-28-2022 09:22:18
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
    string s;
    cin >> s;
    int n = int(s.size());
    bool zero = false, even = false;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += s[i] - '0';
        if (s[i] - '0' == 0) {
            if (zero) {
                even = true;
            }
            zero = true;
        } else if ((s[i] - '0') % 2 == 0) {
            even = true;
        }
    }
    if (sum % 3 != 0) {
        cout << "cyan"
             << "\n";
        return;
    }
    cout << (zero && even ? "red" : "cyan") << "\n";
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
// Rating: 3
// A bit too hard - low solve count, requires some math knowledge
