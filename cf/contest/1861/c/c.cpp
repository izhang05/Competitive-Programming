/* Author: izhang
 * Time: 09-06-2023 15:00:18
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
    int so = -1, unso = inf;
    int cur = 0;
    for (auto &i : s) {
        if (i == '+') {
            ++cur;
        } else if (i == '-') {
            --cur;
            so = min(so, cur);
            if (unso > cur) {
                unso = inf;
            }
        } else if (i == '0') {
            if (so == cur || cur < 2) {
                cout << "NO"
                     << "\n";
                return;
            }
            unso = min(unso, cur);
        } else if (i == '1') {
            if (unso != inf) {
                cout << "NO"
                     << "\n";
                return;
            }
            so = cur;
        }
    }
    cout << "YES"
         << "\n";
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
