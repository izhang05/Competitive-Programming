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


int main() {
    setIO("1");
    int n, m;
    cin >> n >> m;
    set<pair<int, int>> wins;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < n; ++j) {
            if (s[j] == 'W') {
                wins.insert({i, j});
            } else if (s[j] == 'L') {
                wins.insert({j, i});
            }
        }
    }
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        long long cnt = 0;
        for (int j = 0; j < n; ++j) {
            if (wins.find({j, x}) != wins.end() && wins.find({j, y}) != wins.end()) {
                ++cnt;
            }
        }
        cout << cnt * n + cnt * (n - 1) << "\n";
    }
    return 0;
}
