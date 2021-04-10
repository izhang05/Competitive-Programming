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

void solve() {
    cout << "\n";
    int n;
    cin >> n;
    if (n <= 30) {
        for (int i = 1; i < n + 1; ++i) {
            cout << i << " " << 1 << "\n";
        }
        return;
    }
    n -= 30;
    bool l = true;
    for (int i = 0; i < 30; ++i) {
        if (l) {
            cout << i + 1 << " " << 1 << "\n";
        } else {
            cout << i + 1 << " " << i + 1 << "\n";
        }
        if (n & (1 << i)) {
            if (l) {
                for (int j = 2; j < i + 2; ++j) {
                    cout << j << " " << i+1 << "\n";
                }
                for (int j = i; j >= 1; --j) {
                    cout << j << " " << i + 1 << "\n";
                }
            }
            l ^= 1;
        }
    }
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
