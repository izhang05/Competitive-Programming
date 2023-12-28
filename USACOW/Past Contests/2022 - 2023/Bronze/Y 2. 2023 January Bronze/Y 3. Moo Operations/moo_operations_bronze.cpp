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
const int inf = 1e9;

void solve() {
    string s;
    cin >> s;
    int n = int(s.size());
    int mn = inf;
    for (int i = 1; i < n - 1; ++i) {
        if (s[i] == 'O') {
            int cur = 2;
            if (s[i - 1] == 'M') {
                --cur;
            }
            if (s[i + 1] == 'O') {
                --cur;
            }
            mn = min(mn, cur);
        }
    }
    if (mn == inf) {
        cout << -1 << "\n";
        return;
    }
    cout << n - 3 + mn << "\n";
}

int main() {
    setIO("1");
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
