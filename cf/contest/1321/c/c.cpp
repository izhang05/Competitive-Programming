/* Author: izhang
 * Time: 02-06-2023 22:48:21
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
    int sol = 0;
    bool found = true;
    while (found) {
        found = false;
        pair<char, int> mx;
        for (int i = 0; i < n; ++i) {
            if ((i > 0 && s[i - 1] + 1 == s[i]) || (i < n && s[i + 1] + 1 == s[i])) {
                mx = max(mx, {s[i], i});
                found = true;
            }
        }
        if (found) {
            string tmp;
            for (int i = 0; i < n; ++i) {
                if (i != mx.second) {
                    tmp += s[i];
                }
            }
            swap(s, tmp);
            ++sol;
        }
    }
    cout << sol << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
