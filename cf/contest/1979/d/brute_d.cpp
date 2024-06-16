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

bool good(string &s, int k) {
    for (int i = 1; i < k; ++i) {
        if (s[i] != s[i - 1]) {
            return false;
        }
    }
    for (int i = k; i < int(s.size()); ++i) {
        if (s[i] == s[i - k]) {
            return false;
        }
    }
    return true;
}

void test_case() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    if (good(s, k)) {
        cout << k << "\n";
        return;
    }
    for (int i = 1; i <= n; ++i) {
        string cur;
        for (int j = i; j < n; ++j) {
            cur += s[j];
        }
        for (int j = i - 1; j >= 0; --j) {
            cur += s[j];
        }
        if (good(cur, k)) {
            cout << i << "\n";
            return;
        }
    }
    cout << -1 << "\n";
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
