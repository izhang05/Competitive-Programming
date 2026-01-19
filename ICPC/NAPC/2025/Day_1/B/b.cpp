#include<bits/stdc++.h>

using namespace std;

long double eps = 1e-9, tau = 8 * atan(1);

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    int n;
    cin >> n;
    vector<long double> angles;
    for (int i = 0; i < n; ++i) {
        long double x, y;
        cin >> x >> y;
        long double ang = atan2(y, x);
        ang /= tau;
        if (ang < 0) {
            angles.push_back(ang + 1);
        } else {
            angles.push_back(ang);
        }
    }
    vector<pair<long double, bool>> events;
    for (auto &i: angles) {
        events.emplace_back(i, true);
        events.emplace_back(i - .5, false);
        events.emplace_back(i + .5, false);
    }
    sort(events.begin(), events.end());
    long long mn = 1e18;
    long long count = 0;
    for (auto &i: events) {
        if (i.second) {
            --count;
        } else {
            ++count;
        }
        if (0.0 <= i.first && i.first <= 1.0) {
            mn = min(mn, count);
        }
    }
    cout << mn << "\n";
}


int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

}
