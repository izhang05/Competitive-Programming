/* Author: izhang05
 * Time: 09-13-2021 21:29:12
**/
#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifndef TEST
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
    freopen((name + ".out").c_str(), "w", stderr);
#endif
}

typedef unsigned long long ull;
typedef __uint128_t L;
struct FastMod {
    ull b, m;
    explicit FastMod(ull b) : b(b), m(ull((L(1) << 64) / b)) {}
    ull red(ull a) const {
        ull q = (ull) ((L(m) * a) >> 64);
        ull r = a - q * b; // can be proven that 0 <= r < 2*b
        return r >= b ? r - b : r;
    }
};

int main() {
    setIO("exercise");
    ull n, m;
    cin >> n >> m;
    auto f = FastMod(m);
    return 0;
}
