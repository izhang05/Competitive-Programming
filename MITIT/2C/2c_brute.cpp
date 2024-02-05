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

int n, k;

map<string, bool> dp;

bool solve(string s) {
    if (dp.find(s) != dp.end()) {
        return dp[s];
    }
    bool cur = true;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'W') {
            if ((i == 0 || s[i - 1] != 'G') && (i == n - 1 || s[i + 1] != 'G')) {
                s[i] = 'R';
                cur &= solve(s);
                s[i] = 'W';
            }
            if ((i == 0 || s[i - 1] != 'R') && (i == n - 1 || s[i + 1] != 'R')) {
                s[i] = 'G';
                cur &= solve(s);
                s[i] = 'W';
            }
        }
    }
    dp[s] = !cur;
//    cout << s << " " << dp[s] << "\n";
    return dp[s];
}

void test_case() {
    dp.clear();
    cin >> n >> k;
    string s;
    cin >> s;
    cout << (solve(s) ? "Amy" : "Aimee") << "\n";
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
