#include<bits/stdc++.h>

using namespace std;

void solve() {
    long long n;
    cin >> n;
    if (n <= 44) {
        cout << 0 << "\n";
        return;
    }
    long long cur = 44, mx = 50, sol = 0;
    while (cur < n) {
        int cur_mx = min(n, mx - 1);
        sol += (cur_mx - cur);
        cur *= 10;
        cur += 4;
        mx *= 10;
    }
    cout << sol << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
