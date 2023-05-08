/* Author: izhang
 * Time: 05-07-2023 20:26:31
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
    string s, t;
    cin >> s >> t;
    vector<set<int>> occ(26);
    int n = int(s.size());
    for (int i = 0; i < n; ++i) {
        occ[s[i] - 'a'].insert(i);
    }
    int sol = 1, cur = -1;
    for (auto &i : t) {
        auto it = occ[i - 'a'].upper_bound(cur);
        dbg() << i - 'a' << " " << occ[i - 'a'] << " " << cur;
        if (it == occ[i - 'a'].end()) {
            ++sol;
            cur = -1;
            it = occ[i - 'a'].upper_bound(cur);
            if (it == occ[i - 'a'].end()) {
                cout << -1 << "\n";
                return;
            }
        }
        cur = *it;
    }
    cout << sol << "\n";
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
