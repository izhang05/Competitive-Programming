#include <bits/stdc++.h>

using namespace std;

void solve() {
    int lo, hi, n;
    cin >> lo >> hi >> n;
    int mid;
    while (lo <= hi) {
        mid = (lo + hi) / 2;
        cout << mid << endl;
        string s;
        cin >> s;
        if (s == "CORRECT") {
            return;
        }
        if (s == "TOO_SMALL") {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        solve();
    }
}
