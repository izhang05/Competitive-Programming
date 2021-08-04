/* Author: izhang05
 * Time: 08-03-2021 17:13:23
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
const long double eps = 1e-18;
const int maxn = 1e5 + 5;
long long a[maxn], n, k;

long long cnt(long double x) {
    long long res = 0;
    long double val = 0;
    for (int i = 0; i < n; ++i) {
        long long cur = (long long) ((sqrt(1 + 4 * (long double) a[i] / x) - 1) / 2);
        res += cur;
        val += (long double) (a[i]) / (cur + 1);
    }
    if (res <= k) {
        return round(val);
    } else {
        return -1;
    }
}

int main() {
    setIO("tallbarn");
    cin >> n >> k;
    k -= n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    long double lo = 0, hi = 1e18, mid;
    long long sol = -1;
    while (hi - lo > eps) {
        mid = (lo + hi) / 2;
        long long val = cnt(mid);
        if (val > 0) {
            sol = val;
            hi = mid;
        } else {
            lo = mid;
        }
    }
    cout << sol << "\n";
    return 0;
}
