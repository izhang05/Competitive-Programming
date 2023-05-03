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
const int mxn = 25;

void solve() {
    int n;
    cin >> n;
    vector<vector<char>> goal(n, vector<char>(n)), cur(n, vector<char>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> goal[i][j];
            cur[i][j] = '.';
        }
    }
    int k;
    cin >> k;
    vector<vector<char>> s(k, vector<char>(k));
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < k; ++j) {
            cin >> s[i][j];
        }
    }
    for (int _ = 0; _ < 4; ++_) {
        // apply all possible stamps
        for (int i = 0; i < n - k + 1; ++i) {
            for (int j = 0; j < n - k + 1; ++j) {
                bool good = true;
                for (int l = 0; l < k; ++l) {
                    for (int m = 0; m < k; ++m) {
                        if (goal[i + l][j + m] == '.' && s[l][m] == '*') {
                            good = false;
                        }
                    }
                }
                if (good) {
                    for (int l = 0; l < k; ++l) {
                        for (int m = 0; m < k; ++m) {
                            if (cur[i + l][j + m] == '.') {
                                cur[i + l][j + m] = s[l][m];
                            }
                        }
                    }
                }
            }
        }
        // rotate 90 deg counter clockwise
        for (int i = 0; i < k; ++i) {
            reverse(s[i].begin(), s[i].end());
        }
        for (int i = 0; i < k; ++i) {
            for (int j = i + 1; j < k; ++j) {
                swap(s[i][j], s[j][i]);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (goal[i][j] != cur[i][j]) {
                cout << "NO"
                     << "\n";
                return;
            }
        }
    }
    cout << "YES"
         << "\n";
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
