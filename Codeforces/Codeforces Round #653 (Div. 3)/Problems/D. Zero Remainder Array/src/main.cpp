#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            a[i] = a[i] % k;
        }
        int x = 0;
        map<int, int> values;
        bool all_zero = true;
        for (int i : a) {
            if (i == 0) {
                continue;
            }
            all_zero = false;
            if (values.find(i) == values.end()) {
                values[i] = 1;
            } else {
                ++values[i];
            }
        }
        if (all_zero) {
            cout << 0 << "\n";
        } else {
            long long sol = 0;
            for (auto i : values) {
                sol = max(sol, (long long) (i.second - 1) * k + k - i.first + 1);
            }
            cout << sol << "\n";
        }
    }
    return 0;
}
