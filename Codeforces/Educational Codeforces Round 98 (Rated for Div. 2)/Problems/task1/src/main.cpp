#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int x, y;
        cin >> x >> y;
        int sol = 2 * min(x, y);
        if (x != y) {
            sol += 2 * (max(x, y) - min(x, y)) - 1;
        }
        cout << sol << "\n";
    }
    return 0;
}
