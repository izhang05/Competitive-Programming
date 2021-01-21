#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
//    freopen("solution.out", "w", stdout);
    freopen("1.in", "r", stdin);
#endif

    int n, k;
    cin >> n >> k;
    int a[n], t[n];
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int current = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i]) {
            current += t[i];
        }
    }
    for (int i = 0; i < k; ++i) {
        if (!a[i]) {
            current += t[i];
        }
    }
    int sol = current;
    for (int i = 1; i < n - k + 1; ++i) {
        if (!a[i - 1]) {
            current -= t[i - 1];
        }
        if (!a[i + k - 1]) {
            current += t[i + k - 1];
        }
        sol = max(sol, current);
    }
    cout << sol << "\n";
    return 0;
}
