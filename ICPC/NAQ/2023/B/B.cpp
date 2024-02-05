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

const int inf = 0x3f3f3f3f, mod = 9302023, mxn = 1e6 + 5;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
pair<int, int> dp[mxn][6];
string s;

void t(int x, int y, pair<int, int> p) {
    if (p.first > dp[x][y].first) {
        dp[x][y] = p;
    } else if (dp[x][y].first == p.first) {
        dp[x][y].second += p.second;
        dp[x][y].second %= mod;
    }
}

bool eq(int x, string &cur) {
    int m = int(cur.size());
    for (int i = x; i >= x - m + 1; --i) {
        if (s[i] != cur[i - x + m - 1]) {
            return false;
        }
    }
    return true;
}

void test_case() {
    cin >> s;
    for (auto &i: dp) {
        for (auto &j: i) {
            j = {-inf, 0};
        }
    }
    dp[0][1] = {0, 1};
    vector<string> w{"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    int n = int(s.size());
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < min(i + 2, 6); ++j) {
            t(i + 1, min(5, j + 1), dp[i][j]);
            for (auto &k: w) {
                if (j >= int(k.size()) && eq(i, k)) {
                    t(i + 1, 1, {dp[i][j].first + int(k.size()) - 1, dp[i][j].second});
                }
            }
        }
    }
    pair<int, int> sol{-inf, 0};
    for (int i = 0; i < 6; ++i) {
//        cout << dp[n-1][i].first << " " << sol.first << "\n";
        if (dp[n][i].first > sol.first) {
            sol = dp[n][i];
        } else if (dp[n][i].first == sol.first) {
            sol.second += dp[n][i].second;
            sol.second %= mod;
        }
    }
//    for (int i = 0; i <= n; ++i) {
//        for (int j = 0; j < 6; ++j) {
//            cout << dp[i][j].first << " ";
//        }
//        cout << "\n";
//    }
    cout << n - sol.first << "\n" << sol.second << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
