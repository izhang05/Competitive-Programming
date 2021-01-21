#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
//    freopen("solution.out", "w", stdout);
//    freopen("1.in", "r", stdin);
#endif
    int n, p, q, r;
    cin >> n >> p >> q >> r;
    vector<long long> potion(n);
    for (int i = 0; i < n; ++i) {
        cin >> potion[i];
    }
    vector<long long> dp0(n);
    vector<long long> dp1(n);
    vector<long long> dp2(n);
    dp0[0] = potion[0] * p;
    for (int i = 1; i < n; ++i) {
        dp0[i] = max(dp0[i - 1], potion[i] * p);
    }
    dp1[0] = dp0[0] + potion[0] * q;
    for (int i = 1; i < n; ++i) {
        dp1[i] = max(dp1[i - 1], dp0[i] + q * potion[i]);
    }
    dp2[0] = dp1[0] + potion[0] * r;
    for (int i = 1; i < n; ++i) {
        dp2[i] = max(dp2[i - 1], dp1[i] + r * potion[i]);
    }
    cout << dp2[n - 1] << "\n";
    return 0;
}
