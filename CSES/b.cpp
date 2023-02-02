#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include <debug.h>
#else
struct dbg {
    template<class c>
    dbg &operator<<(const c &) { return *this; }
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
#endif

const int inf = 0x3f3f3f3f, mod = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    int m = int(t.size());
    bool same = true;
    char c = t[0];
    for (int i = 1; i < m; ++i) {
        if (t[i] != c) {
            same = false;
        }
    }
    long long sol = 0;
    if (!same) {
        int cur = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == t[cur]) {
                ++cur;
                if (cur == m) {
                    ++sol;
                    cur = 0;
                }
            } else {
                cur = 0;
            }
        }
    } else {
        int pre = -1;
        for (int i = 0; i < n; ++i) {
            if (s[i] != c) {
                long long len = i - pre - 1;
                if (len >= m) {
                    sol += len - m + 1;
                }
                pre = i;
            }
        }
        long long len = n - pre - 1;
        if (len >= m) {
            sol += len - m + 1;
        }
    }
    cout << sol << "\n";
    return 0;
}
