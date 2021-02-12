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

    int n;
    cin >> n;
    const int mod = 1e9 + 7;
    long long sol = 2;
    for (int i = 0; i < n - 1; ++i) {
        sol *= 2;
        sol %= mod;
    }
    cout << sol << "\n";
    return 0;
}
