#include <bits/stdc++.h>

using namespace std;

const int inf = 0x3f3f3f3f, mod = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    int t;
    cin >> t;
    while (t--) {
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        if (a == b) {
            cout << min(x, y) / a << "\n";
            continue;
        }
        if (a < b) {
            swap(a, b);
        }
        long long lo = 0, hi = inf, mid, sol = -1;
        while (lo <= hi) {
            mid = (lo + hi) / 2;
            long long right = floorl((x - mid * b) * 1.0l / (a - b)), left = ceill((y - mid * a) * 1.0l / (b - a));
            // k<= c && k >= d
            if (max(left, 0ll) <= min(right, mid)) {
                sol = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        cout << sol << "\n";
    }
    return 0;
}
