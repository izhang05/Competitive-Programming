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
const int mxn = 755;

bool p[mxn][mxn], route[mxn][mxn];

int main() {
    setIO("1");
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        string s;
        cin >> s;
        for (int j = i + 1; j < n; ++j) {
            p[i][j] = s[j - (i + 1)] - '0';
        }
    }
    int sol = 0;
    for (int i = n - 1; i >= 0; --i) {
        for (int j = i + 1; j < n; ++j) {
            int cur = 0;
            for (int k = i + 1; k < j; ++k) {
                cur += route[i][k] * p[k][j];
            }
            cur %= 2;
            if (cur != p[i][j]) {
                route[i][j] = true;
                ++sol;
            }
        }
    }
    cout << sol << "\n";
    return 0;
}
