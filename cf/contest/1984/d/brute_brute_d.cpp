/* Author: izhang
 * Time: 06-09-2024 10:35:01
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

const long long m1 = 1e9 + 9, p = 9973;
const int maxn = 3e5 + 5;

void test_case() {
    string s;
    cin >> s;
    int n = int(s.size());
    set<string> sol;
    for (int i = 0; i < n; ++i) {
        string cur;
        for (int j = i; j < n; ++j) {
            cur += s[j];
            vector<int> pos(n + 1, false);
            pos[0] = true;
            int len = j - i + 1;
            for (int k = 1; k <= n; ++k) {
                if (s[k - 1] == 'a') {
                    pos[k] = pos[k - 1];
                }
                if (pos[k] || k - len < 0 || !pos[k - len]) {
                    continue;
                }
                pos[k] = true;
                for (int l = k - len; l < k; ++l) {
                    if (s[l] != cur[l - (k - len)]) {
                        pos[k] = false;
                        break;
                    }
                }
            }
            if (pos[n]) {
                sol.insert(cur);
            }
        }
    }
    sol.erase("a");
    dbg() << sol;
    cout << sol.size() << "\n";
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
