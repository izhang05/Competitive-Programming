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
        int n;
        cin >> n;
        vector<int> a(n);
        long long sum = 0;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            sum += a[i];
        }
        if (sum % n != 0) {
            cout << -1 << "\n";
            continue;
        }
        int sol = 0;
        long long b = sum / n;
        for (int i = 0; i < n; ++i) {
            if (a[i] > b) {
                ++sol;
            }
        }
        cout << sol << "\n";
    }
    return 0;
}
