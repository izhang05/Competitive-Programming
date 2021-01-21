#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    //freopen("solution.out", "w", stdout);
    freopen("1.in", "r", stdin);
#endif
    int t, n, k;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        vector<string> s(n);
        for (int i = 0; i < n; ++i) {
            cin >> s[i];
        }
    }
    return 0;
}
