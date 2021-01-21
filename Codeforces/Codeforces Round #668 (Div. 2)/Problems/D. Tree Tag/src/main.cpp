#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, a, b, da, db;
        cin >> n >> a >> b >> da >> db;
        int x, y;
        for (int i = 0; i < n - 1; ++i) {
            cin >> x >> y;
        }
        if (da >= db) {
            cout << "Alice" << "\n";
            continue;
        }
        cout << "Bob" << "\n";
    }
    return 0;
}
