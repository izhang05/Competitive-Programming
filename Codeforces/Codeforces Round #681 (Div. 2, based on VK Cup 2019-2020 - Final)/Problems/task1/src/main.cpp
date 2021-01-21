#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 4 * n; i > 2 * n + 2; i -= 2) {
            cout << i << " ";
        }
        cout << 2 * n + 2 << "\n";
    }
    return 0;
}
