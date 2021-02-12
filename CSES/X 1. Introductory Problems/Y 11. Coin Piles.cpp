#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    //freopen("solution.out", "w", stdout);
    freopen("1.in", "r", stdin);
#endif
}


int main() {
    setIO();

    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        if ((a + b) % 3 == 0 && max(a, b) / 2 <= min(a, b)) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    return 0;
}
