/* Author: izhang05
 * Time: 07-12-2021 15:40:21
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

int main() {
    setIO("1");

    long long n, a, b;
    cin >> n >> a >> b;
    if (a * b >= 6 * n) {
        cout << a * b << "\n";
        cout << a << " " << b << "\n";
        return 0;
    }
    bool s = false;
    if (a > b) {
        swap(a, b);
        s = true;
    }
    pair<long long, pair<long long, long long>> sol;
    sol.first = 1e18;
    for (long long i = a; i * i <= 6 * n; ++i) {
        long long nb = (6 * n + i - 1) / i;
        if (nb > b) {
            sol = min(sol, {nb * i, {i, nb}});
        }
    }
    if (s) {
        swap(sol.second.first, sol.second.second);
    }
    cout << sol.first << "\n";
    cout << sol.second.first << " " << sol.second.second << "\n";
    return 0;
}
