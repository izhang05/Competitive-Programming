#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(string name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
    freopen((name + ".out").c_str(), "w", stderr);
#endif
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int i = 0;
    cout << 1;
    for (int j = 1; j < n; ++j) {
        if (s[j] <= s[j - 1]) {
            cout << " " << 1;
            i = j;
        } else {
            cout << " " << j - i + 1;
        }
    }
    cout << "\n";
}

int main() {
    setIO("1");
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solve();
    }
}
