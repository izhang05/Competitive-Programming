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
    vector<string> cur;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        if (int(cur.size()) < int(s.size())) {
            cur.resize(s.size());
        }
        for (int j = 0; j < int(s.size()); ++j) {
            cur[j] += s[j];
        }
    }
    for (int i = 0; i < n; ++i) {
        if (int(cur.size()) <= i) {
            cout << "YES"
                 << "\n";
        } else {
            string rev_s = cur[i];
            reverse(rev_s.begin(), rev_s.end());
            cout << (cur[i] == rev_s ? "YES" : "NO") << "\n";
        }
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
