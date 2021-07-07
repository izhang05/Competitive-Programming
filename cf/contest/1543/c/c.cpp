/* Author: izhang05
 * Time: 07-07-2021 10:35:04
**/
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7;
long double sol = 0;
const long double eps = 1e-18;

void solve(long double c, long double m, long double p, long double v, long double prob, long long len) {
#ifdef DEBUG
    cout << c << "\t" << m << "\t" << p << "\t" << v << "\t" << prob << "\t" << len << "\t" << (len + 1) * prob * p << "\n";
#endif
    sol += (len + 1) * prob * p;
    if (c < eps && m < eps) {
        return;
    }
    if (c > eps) {
        long double sub = min(c, v), add = sub / 2;
        if (m > eps) {
            solve(c - sub, m + add, p + add, v, prob * c, len + 1);
        } else {
            solve(c - sub, m, p + sub, v, prob * c, len + 1);
        }
    }
    if (m > eps) {
        long double sub = min(m, v), add = sub / 2;
        if (c > eps) {
            solve(c + add, m - sub, p + add, v, prob * m, len + 1);
        } else {
            solve(c, m - sub, p + sub, v, prob * m, len + 1);
        }
    }
}

int main() {
    setIO("1");

    int t;
    cin >> t;
    while (t--) {
        sol = 0;
        long double c, m, p, v;
        cin >> c >> m >> p >> v;
        solve(c, m, p, v, 1, 0);
        cout << fixed << setprecision(16) << sol << "\n";
    }

    return 0;
}
