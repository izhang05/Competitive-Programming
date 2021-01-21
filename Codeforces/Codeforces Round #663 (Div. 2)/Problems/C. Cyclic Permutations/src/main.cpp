#include <bits/stdc++.h>

using namespace std;
const int mod = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n;
    cin >> n;
    long long sol = 4;
    for (int i = 4; i <= n; ++i) {
        sol *= i;
        sol %= mod;
    }
    cout << sol << "\n";
    return 0;
}
