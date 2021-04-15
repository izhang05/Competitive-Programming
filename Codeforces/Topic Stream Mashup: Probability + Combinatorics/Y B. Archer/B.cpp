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

const int inf = 0x3f3f3f3f, mod = 1e9 + 7;


int main() {
    setIO("1");

    long double a, b, c, d;
    cin >> a >> b >> c >> d;
    long double sol = 0, pa = a / b, pb = c / d, cur = 1;
    for (int i = 0; i < (int) 1e5; ++i) {
        sol += cur * pa;
        cur *= (1 - pa);
        cur *= (1 - pb);
    }
    cout << fixed << setprecision(15) << sol << "\n";
    return 0;
}
