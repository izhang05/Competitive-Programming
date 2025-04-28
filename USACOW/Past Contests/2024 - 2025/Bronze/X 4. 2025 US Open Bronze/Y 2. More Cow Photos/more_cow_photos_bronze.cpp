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

void solve() {
    int n;
    cin >> n;
    map<int, int> cnt;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        ++cnt[a];
    }
    int sol = 0;
    bool extra = false;
    for (auto &i: cnt) {
        if (i.second >= 2) {
            sol += 2;
            extra = false;
        }
        if (i.second == 1) {
            extra = true;
        }
    }
    if (extra) {
        cout << sol + 1 << "\n";
    } else {
        cout << sol - 1 << "\n";
    }
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
