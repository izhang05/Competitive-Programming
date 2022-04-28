#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen((name + ".in").c_str(), "r", stdin);
//    freopen((name + ".out").c_str(), "w", stdout);
//    freopen((name + ".out").c_str(), "w", stderr);
#endif
}
const int maxn = 1e6 + 5;


void solve() {
    int n;
    cin >> n;
    int sol = 1;
    for (int i = 3; i * i <= n; i++) {
        if (n % i == 0) {
            sol = max({sol, __builtin_popcount(i), __builtin_popcount(n / i)});
        }
    }
    cout << sol << "\n";
}

int main() {
    setIO("1");

    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solve();
    }
}

