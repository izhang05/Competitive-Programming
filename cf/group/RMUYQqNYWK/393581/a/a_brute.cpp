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

bool good(const string &s, int k) {
    int cnt = 0;
    for (auto &i : s) {
        if (i == '1') {
            ++cnt;
        }
    }
    bool found = false;
    if (k == 0) {
        found = true;
    }
    int len = -inf;
    for (auto &i : s) {
        if (i == '0') {
            ++len;
            if (len >= k) {
                found = true;
            }
        } else {
            len = 0;
        }
    }
    return (cnt % 2 == 1) && found;
}

void test_case() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    long long sol = 0;
    for (int i = 0; i < n; ++i) {
        string cur;
        for (int j = i; j < n; ++j) {
            cur += s[j];
            if (good(cur, k)) {
                ++sol;
            }
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
