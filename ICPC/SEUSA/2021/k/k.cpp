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

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, mxn = 26;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
bool dp[1 << mxn];

void test_case() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < (1 << n); ++i) {
        if (__builtin_popcount(i) <= 2) {
            dp[i] = true;
            continue;
        }
        vector<int> cur;
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                cur.push_back(j);
            }
            if (cur.size() == 3) {
                break;
            }
        }
        bool good = true;
        for (int j = 0; j < 3; ++j) {
            good &= dp[i ^ (1 << cur[j])];
        }
        dp[i] = good & ((a[cur[0]] ^ a[cur[1]] ^ a[cur[2]]) != 0);
    }
    int sol = 0;
    for (int i = 0; i < (1 << n); ++i) {
        if (dp[i]) {
            sol = max(sol, __builtin_popcount(i));
        }
    }
    dbg() << sol;
    cout << n - sol << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
