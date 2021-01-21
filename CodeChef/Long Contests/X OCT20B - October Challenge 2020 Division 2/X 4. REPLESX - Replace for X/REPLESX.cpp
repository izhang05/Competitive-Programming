#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
//freopen("solution.out", "w", stdout);
    freopen("1.in", "r", stdin);
#endif
}


int main() {
    setIO();

    int t;
    cin >> t;
    while (t--) {
        int n, x, p, k;
        cin >> n >> x >> p >> k;
        --p, --k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        if (a[p] == x) {
            cout << 0 << "\n";
        } else {
            if (p > k) {
                if (x > p) {
                    cout << -1 << "\n";
                } else {
                    int lo = 0, hi = k
                }
            }
        }
    }
    return 0;
}
