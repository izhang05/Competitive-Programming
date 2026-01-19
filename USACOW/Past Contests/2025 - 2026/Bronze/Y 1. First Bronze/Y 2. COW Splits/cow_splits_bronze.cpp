#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (n % 2 == 1) {
        cout << -1 << "\n";
        return;
    }
    string s1, s2;
    for (int i = 0; i < 3 * n; ++i) {
        if (i < (n / 2) * 3) {
            s1.push_back(s[i]);
        } else {
            s2.push_back(s[i]);
        }
    }
    if (s1 == s2) {
        cout << 1 << "\n";
        for (int i = 0; i < 3 * n - 1; ++i) {
            cout << 1 << " ";
        }
        cout << 1 << "\n";
        return;
    }
    cout << 2 << "\n";
    vector<int> sol(3 * n, 2);
    for (int i = 0; i < n / 2; ++i) {
        int j = i + n / 2;
        bool found = false;
        for (int k = 3 * j; k < 3 * j + 2; ++k) {
            if (s[k] == s[3 * i]) {
                sol[k] = sol[k + 1] = sol[3 * i] = sol[3 * i + 1] = 1;
                found = true;
                break;
            }
        }
        if (!found) {
            sol[3 * i + 1] = sol[3 * i + 2] = sol[3 * j] = sol[3 * j + 1] = 1;
        }
    }
    for (auto &i: sol) {
        if (i == -1) {
            i = 2;
        }
    }

    for (int i = 0; i < 3 * n; ++i) {
        cout << sol[i] << " \n"[i == 3 * n - 1];
    }
    return;

    cout << 3 << "\n";
    for (int i = 0; i < 3 * n - 1; ++i) {
        if (s[i] == 'C') {
            cout << 1 << " ";
        } else if (s[i] == 'O') {
            cout << 2 << " ";
        } else {
            cout << 3 << " ";
        }
    }
    if (s[3 * n - 1] == 'C') {
        cout << 1 << "\n";
    } else if (s[3 * n - 1] == 'O') {
        cout << 2 << "\n";
    } else {
        cout << 3 << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    int t, k;
    cin >> t >> k;
    while (t--) {
        solve();
    }
    return 0;
}
