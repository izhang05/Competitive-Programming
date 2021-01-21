#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    //freopen("solution.out", "w", stdout);
    freopen("1.in", "r", stdin);
#endif
}


int main() {
    setIO();

    int k, m, n;
    cin >> k >> m >> n;
    cout << max(0, (10 * k - n + m - 1) / m) << "\n";
    return 0;
}
