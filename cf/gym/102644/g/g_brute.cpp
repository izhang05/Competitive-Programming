#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
    freopen((name + ".out").c_str(), "w", stderr);
#endif
}
const int inf = 0x3f3f3f3f, mod = 1e9 + 7;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

void solve() {
    long long n, k;
    cin >> n >> k;
    vector<long long> sol(k + 1);
    for (int i = 0; i < n; ++i) {
        cin >> sol[i];
    }
    vector<long long> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    long long p, q, r;
    cin >> p >> q >> r;
    for (long long i = n; i <= k; ++i) {
        for (int j = 1; j <= n; ++j) {
            sol[i] += (sol[i - j] * c[j - 1]) % mod;
            sol[i] %= mod;
        }
        sol[i] += p + i * q + i * i * r;
        sol[i] %= mod;
    }
    cout << sol[k] << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        solve();
    }
    return 0;
}
