/* Author: izhang
 * Time: 12-04-2023 20:19:01
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
    string ss = s;
    int n = int(s.size());
    sort(ss.begin(), ss.end());
    if (s == ss) {
        cout << s << "\n";
        return;
    }
    map<char, set<int>> occ;
    for (int i = 0; i < n; ++i) {
        occ[s[i]].insert(i);
    }
    string sol, t;
    int i = 0;
    while ((int) sol.size() < n) {
        if (t.empty()) {
            t += s[i];
            occ[s[i]].erase(i);
            if (occ[s[i]].empty()) {
                occ.erase(s[i]);
            }
            ++i;
            continue;
        }
        if (occ.empty()) {
            while (!t.empty()) {
                sol += t.back();
                t.pop_back();
            }
            break;
        }
        if (t.back() <= occ.begin()->first) {
            sol += t.back();
            t.pop_back();
        } else {
            t += s[i];
            occ[s[i]].erase(i);
            if (occ[s[i]].empty()) {
                occ.erase(s[i]);
            }
            ++i;
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
