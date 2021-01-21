#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int infected = 0;
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        long long sum = 0;
        long long sum_without = 0;
        bool sol = true;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            sum += a[i];
            if (a[i] != x) {
                sol = false;
                sum_without += a[i];
            } else {
                ++infected;
            }
        }
        if (sol) {
            cout << 0 << "\n";
            continue;
        }
        if (n * x == sum || infected > 0) {
            cout << 1 << "\n";
            continue;
        }
        cout << 2 << "\n";
    }
    return 0;
}
