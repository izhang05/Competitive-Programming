/* Author: izhang05
 * Time: 08-21-2021 14:00:04
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
int n;
vector<int> c;

bool check(int x) {
    vector<int> cnt(n);
    for (int i = 0; i < x - 1; ++i) {
        ++cnt[c[i]];
    }
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += cnt[i];
        if (sum > i) {
            return false;
        }
    }
    return true;
}

int main() {
    setIO("greedy");
    cin >> n;
    c.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
        c[i] = n - c[i] - 1;
    }
    int lo = 1, hi = n, mid, sol;
    while (lo <= hi) {
        mid = (lo + hi) / 2;
        if (check(mid)) {
            sol = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    cout << n - sol << "\n";
    return 0;
}
