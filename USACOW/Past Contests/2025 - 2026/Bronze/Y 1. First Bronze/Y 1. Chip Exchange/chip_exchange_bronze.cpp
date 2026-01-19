#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long a, b, ca, cb, goal;
    cin >> a >> b >> ca >> cb >> goal;
    long long s = b / cb;
    a += ca * s;
    b -= cb * s;
    if (goal <= a) {
        cout << 0 << "\n";
        return;
    }
    long long sol = cb - 1 - b;
    b = cb - 1;
    long long rem = goal - a, full = (rem + ca - 1) / ca;
    if (ca <= cb) {
        sol += cb * (full - 1);
        cout << sol + rem - (full - 1) * ca << "\n";
        return;
    }
    cout << sol + rem << "\n";
}


int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
