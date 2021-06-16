#include <bits/stdc++.h>

using namespace std;

const int inf = 0x3f3f3f3f, mod = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    bool pos = true;
    for (int i = 1; i < n - 1; ++i) {
        if (a[i] <= a[i - 1] && a[i] <= a[i + 1]) {
            pos = false;
            break;
        }
    }
    cout << (pos ? "YES" : "NO") << "\n";
    return 0;
}
