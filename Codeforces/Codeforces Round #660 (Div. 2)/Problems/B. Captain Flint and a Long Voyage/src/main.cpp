#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int count = 0;
        for (int i = 0; i < n - (n + 3) / 4; ++i) {
            ++count;
            cout << 9;
        }
        for (int i = count; i < n; ++i) {
            cout << 8;
        }
        cout << "\n";
    }
    return 0;
}
