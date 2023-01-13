/* Author: izhang
 * Time: 11-12-2022 19:16:25
**/
#include <bits/stdc++.h>

using namespace std;

vector<int> x, v;
int n;

bool possible(double t) {
    // returns true if it is possible for everybody to meet up in t seconds
    double max_l = 0, min_r = 1e18;
    for (int i = 0; i < n; ++i) {
        // every person can reach range [x_i - v_i * t, x_i + v_i * t]
        double cur_l = x[i] - t * v[i], cur_r = x[i] + t * v[i];
        max_l = max(max_l, cur_l);
        min_r = min(min_r, cur_r);
    }
    // possible if the maximum left bound is smaller than the minimum right bound
    return max_l <= min_r;
}

int main() {
    cin >> n;
    x.resize(n), v.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    double lo = 0, hi = 1e9, sol;
    while (hi - lo > 1e-6) {
        // binary search on the time
        double mid = (hi + lo) / 2;
        if (possible(mid)) {
            hi = mid;
            sol = mid;
        } else {
            lo = mid;
        }
    }
    // print answers to 9 decimal places
    cout << fixed << setprecision(9) << sol << "\n";
    return 0;
}
