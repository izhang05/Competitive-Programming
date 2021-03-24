#include <bits/stdc++.h>

using namespace std;

mt19937 rng((uint32_t) chrono::steady_clock::now().time_since_epoch().count());
//#define DEBUG
void setIO(string name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
    freopen((name + ".out").c_str(), "w", stderr);
#endif
}
const int inf = 0x3f3f3f3f, mod = 998244353, maxn = 2e5 + 5;
long long p[maxn];

int main() {
    setIO("1");

    int n, m;
    cin >> n >> m;
    string a, b;
    cin >> a >> b;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    p[0] = 1;
    for (int i = 0; i < maxn - 1; ++i) {
        p[i + 1] = (p[i] * 2) % mod;
    }
    long long sol = 0, cnt = 0;
    for (int i = m - 1; i >= 0; --i) {
        if (b[i] == '1') {
            ++cnt;
        }
        if (i < n && a[i] == '1') {
#ifdef DEBUG
            cout << i << " " << p[i] * cnt << "\n";
#endif
            sol += p[i] * cnt;
        }
        sol %= mod;
    }
    cout << sol << "\n";
    return 0;
}
