#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        a[i] = s[i] - '0';
    }
    for (int i = 0; i < a[0]; ++i) {
        cout << '(';
    }
    int cur = a[0];
    cout << a[0];
    for (int i = 1; i < n; ++i) {
        if (cur < a[i]) {
            for (int j = 0; j < a[i] - cur; ++j) {
                cout << '(';
            }
        } else if (cur > a[i]) {
            for (int j = 0; j < cur - a[i]; ++j) {
                cout << ')';
            }
        }
        cur = a[i];
        cout << a[i];
    }
    for (int i = 0; i < cur; ++i) {
        cout << ')';
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solve();
    }
}
