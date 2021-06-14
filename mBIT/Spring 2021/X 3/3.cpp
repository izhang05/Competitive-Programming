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

long long p(long long n){
    long long res = 1;
    for (int i = 0; i < n; ++i) {
        res *= 2;
    }
    return res;
}

void solve() {
    long long n, k;
    cin >> n >> k;
    if (n <= 4) {
        cout << -1 << "\n";
        return;
    }
    if (n % 2 == 0) {
        long long mx = 1e18;
        for (int i = 0; i < n - 1; ++i) {
            cout << mx - i << " ";
        }
        cout << mx - (n - 2) - k + (long long) p(n / 2 - 1) << "\n";
    } else {

    }
}

int main() {
    setIO("3");

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
