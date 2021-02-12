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

    int n, sol = 0, i = 5;
    cin >> n;
    while (n / i) {
        sol += n / i;
        i *= 5;
    }
    cout << sol << "\n";
    return 0;
}
