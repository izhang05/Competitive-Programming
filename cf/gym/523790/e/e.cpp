#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    int even = 0;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] % 2 == 0) {
            ++even;
        }
    }
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
//    int odd = n - even;
    int add_even = 0, add_odd = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] == b[i]) {
            continue;
        }
//        if (b[i] % 2 == 1) {
//            cout << "NO" << "\n";
//            return;
//        }
        if ((b[i] - a[i]) % 2 == 0) {
            ++add_even;
        } else {
            ++add_odd;
        }
    }
    if (add_even == 0 && add_odd == 0) {
        cout << "YES" << "\n";
        return;
    }
    if (n % 2 == 1) {
        if (even % 2 == 1) {
            cout << "NO" << "\n";
            return;
        }
        cout << (add_odd <= 1 ? "YES" : "NO") << "\n";
    } else {
        if (even % 2 == 0) {
            cout << (add_odd == 0 ? "YES" : "NO") << "\n";
            return;
        } else {
            cout << (add_odd == 1 ? "YES" : "NO") << "\n";
        }
    }

}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}