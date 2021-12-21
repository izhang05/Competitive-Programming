#include <bits/stdc++.h>

using namespace std;

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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 3e3 + 5;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

long long dp[2 * maxn][2];
long long new_dp[2 * maxn][2];

void add(long long &a, long long b) {
    a += b;
    a %= mod;
}

int main() {
    setIO("1");

    int n;
    cin >> n;
    vector<pair<int, int>> a;
    for (int i = 0; i < n; ++i) {
        int b;
        cin >> b;
        a.emplace_back(b, 0);
    }
    for (int i = 0; i < n; ++i) {
        int b;
        cin >> b;
        a.emplace_back(b, 1);
    }
    n *= 2;
    sort(a.begin(), a.end());
    memset(dp, 0, sizeof(dp));
    memset(new_dp, 0, sizeof(new_dp));
    dp[0][0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < 2; ++k) {
                long long cur = dp[j][k];
#ifdef DEBUG
                cout << i << " " << j << " " << k << " " << cur << "\n";
#endif
                if (!cur) {
                    continue;
                }
                if (!a[i].second) {
                    // take cow
                    add(new_dp[j + 1][k], cur);
                    // don't take cow
                    add(new_dp[j][1], cur);
                } else {
                    // take barn
                    if (j) {
                        add(new_dp[j - 1][k], (cur * j) % mod);
                    }
                    // don't take barn
                    if (!k) {
                        add(new_dp[j][k], cur);
                    }
                }
            }
        }
        swap(dp, new_dp);
        memset(new_dp, 0, sizeof(new_dp));
    }
    cout << (dp[0][0] + dp[0][1]) % mod << "\n";
}
