#include <bits/stdc++.h>

using namespace std;

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

const int inf = 0x3f3f3f3f, mod = 1e9 + 7;


int main() {
    setIO("1");

    int n;
    cin >> n;
    long double p;
    cin >> p;
    long double sol = 1;
    while (n) {
        if (n % 2) {
            sol = sol * (1 - p) + (1 - sol) * p;
        }
        p = 2 * p * (1 - p);
        n >>= 1;
    }
    cout << fixed << setprecision(10) << sol << "\n";
    return 0;
}
