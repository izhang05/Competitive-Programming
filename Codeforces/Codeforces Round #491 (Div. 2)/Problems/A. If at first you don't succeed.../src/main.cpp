#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b, c, n;
    cin >> a >> b >> c >> n;
    a -= c, b -= c;
    if (a < 0 || b < 0) {
        cout << -1 << "\n";
    } else if (a + b + c + 1 <= n) {
        cout << n - (a + b + c) << "\n";
    } else {
        cout << -1 << "\n";
    }
    return 0;
}
