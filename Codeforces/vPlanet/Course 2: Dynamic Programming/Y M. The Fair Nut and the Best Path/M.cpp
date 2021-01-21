#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    //freopen("solution.out", "w", stdout);
    freopen("1.in", "r", stdin);
#endif

    int n;
    cin >> n;
    int w[n], u[n - 1], v[n - 1], c[n - 1];
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        cin >> u[i] >> v[i] >> c[i];
    }

    return 0;
}
