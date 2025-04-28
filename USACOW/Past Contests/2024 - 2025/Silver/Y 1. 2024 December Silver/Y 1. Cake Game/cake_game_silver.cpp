#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    long long tot = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        tot += a[i];
    }
    long long cur = 0;
    for (int i = 0; i <= n / 2; ++i) {
        cur += a[i];
    }
    long long sol = cur;
    for (int i = 1; i + n / 2 < n; ++i) {
        cur -= a[i - 1];
        cur += a[i + n / 2];
        sol = min(sol, cur);
    }
    cout << sol << " " << tot - sol << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
