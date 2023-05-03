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
    string s, t;
    cin >> s >> t;
    int n = int(s.size());
    map<char, set<char>> m;
    map<char, int> vis;
    for (int i = 0; i < n; ++i) {
        m[s[i]].insert(t[i]);
    }
    for (auto &i : m) {
        if (i.second.size() > 1) {
            cout << -1 << "\n";
            return;
        }
    }
    int sol = 0;
    for (auto &i : m) {
        if (*i.second.begin() != i.first) {
            ++sol;
        }
    }
    for (auto &i : m) {

    }

    cout << sol << "\n";
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
