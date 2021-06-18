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
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        pair<int, int> sol{inf, 0};
        for (int i = 0; i + k < n; ++i) {
            sol = min(sol, {a[i + k] - a[i], a[i] + (a[i + k] - a[i]) / 2});
        }
        cout << sol.second << "\n";
    }
    return 0;
}
