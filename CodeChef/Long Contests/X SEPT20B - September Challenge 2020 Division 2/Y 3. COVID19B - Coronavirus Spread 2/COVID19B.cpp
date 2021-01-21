#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
//freopen("solution.out", "w", stdout);
    freopen("2.in", "r", stdin);
#endif
}


int main() {
    setIO();

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int best = 1e9, worst = 0, cur, mx, less[6];
        for (int i = 0; i < n; ++i) {
            for (int &j : less) {
                j = 0;
            }
            cur = 1, mx = a[i];
            for (int j = 0; j < i; ++j) {
                if (a[j] <= a[i]) {
                    for (int k = 0; k < a[j]; ++k) {
                        ++less[k];
                    }
                }
                if (a[j] > a[i]) {
                    ++cur;
                }
                mx = max(mx, a[j]);
            }
            int mn = 5;
            for (int j = i + 1; j < n; ++j) {
                if (a[j] < mx) {
                    ++cur;
                }
                mn = min(mn, a[j]);
            }
            cur += less[mn];
            best = min(best, cur);
            worst = max(worst, cur);
        }
        cout << best << " " << worst << "\n";
    }
    return 0;
}
