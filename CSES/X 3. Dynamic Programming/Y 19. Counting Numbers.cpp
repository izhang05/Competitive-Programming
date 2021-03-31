#include <bits/stdc++.h>

using namespace std;

mt19937 rng((uint32_t) chrono::steady_clock::now().time_since_epoch().count());
//#define DEBUG
void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen("19.in", "r", stdin);
    freopen("19.out", "w", stdout);
    freopen("19.out", "w", stderr);
#endif
}
template<class T>
void print(T a, string sep = " ", string end = "\n") {
    for (auto i : a) {
        cout << i << sep;
    }
    cout << end;
}
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 25;

long long dp[maxn][10];

long long solve(long long x) {
    if (x == -1) {
        return 0;
    }
    if (x == 0) {
        return 1;
    }
    vector<int> cur;
    while (x) {
        cur.push_back(x % 10);
        x /= 10;
    }
    reverse(cur.begin(), cur.end());
    int n = cur.size();
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i < cur[0]; ++i) {
        dp[0][i] = 1;
    }
    bool end = true;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 1; j < 10; ++j) {
            ++dp[i + 1][j];
        }
        for (int j = 0; j < 10; ++j) {
            if (dp[i][j] == 0) {
                continue;
            }
            for (int k = 0; k < 10; ++k) {
                if (k != j) {
                    dp[i + 1][k] += dp[i][j];
                }
            }
        }
        if (end) {
            for (int j = 0; j < cur[i + 1]; ++j) {
                if (j != cur[i]) {
                    ++dp[i + 1][j];
                }
            }
        }
        if (cur[i] == cur[i + 1]) {
            end = false;
        }
    }
    long long sol = end;
    for (int i = 0; i < 10; ++i) {
        sol += dp[n - 1][i];
    }
#ifdef DEBUG
    print(cur, "", ": ");
    cout << sol << "\n";
#endif
    return sol + 1;
}

int main() {
    setIO();
    long long a, b;
    cin >> a >> b;
    cout << solve(b) - solve(a - 1) << "\n";
    return 0;
}
