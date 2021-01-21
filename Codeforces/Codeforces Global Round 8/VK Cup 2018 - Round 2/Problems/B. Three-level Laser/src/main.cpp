#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, u;
    cin >> n >> u;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    double sol = 0;
    int hi = 1;
    for (int i = 0; i < n - 1; ++i) {
        while (a[hi] - a[i] <= u) {
            ++hi;
            if (hi >= n) {
                break;
            }
        }
        --hi;
        sol = max(sol, double(a[hi] - a[i + 1]) / (a[hi] - a[i]));
    }
    if (sol == 0) {
        cout << -1 << "\n";
    } else {
        cout << setprecision(9) << sol << "\n";
    }
    return 0;
}
